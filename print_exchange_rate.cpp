#define CURL_STATICLIB
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdio.h>
#include <unordered_map>
#include <stdexcept>
#include <cstdlib>
#include <signal.h>

#include "json.hpp"
#include "curl/curl.h"

#include "median_average.hpp"

// catch Ctrl-C to call destructors at exit
// https://stackoverflow.com/questions/4217037/catch-ctrl-c-in-c
static volatile int keep_running = 1;

void intHandler(int dummy) {
    keep_running = 0;
}

// write response to struct memory instead of std::cout
struct memory {
    char* response;
    size_t size;
};

static size_t cb(void* data, size_t size, size_t nmemb, void* userp) {
    size_t realsize = size * nmemb;
    struct memory* mem = (struct memory*)userp;

    char* ptr = (char*)realloc(mem->response, mem->size + realsize + 1);
    if (ptr == NULL)
        return 0;  

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}


void update_rate(nlohmann::json &valutes, std::unordered_map<std::string, MedianAverage*> &rate) {
    for (auto& v : valutes.items()) {
        if (rate.find(v.key()) == rate.end()) {
            rate[v.key()] = new MedianAverage();
        }

        double cur = v.value()["Value"];
        rate[v.key()]->add(cur);
        std::cout << v.key() << ": " << cur << '\n';
    }

    std::cout << "\n\n";
}

void make_request(CURL* curl, struct memory &chunk) {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.cbr-xml-daily.ru/daily_json.js");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::string error(curl_easy_strerror(res));
        throw std::runtime_error("curl_easy_perform() failed: " + error);
    }
}

// use class' destructor to do cleanup at exit
// https://stackoverflow.com/a/8053261/13907973
class AtExitExchangeRatePrint {
    std::unordered_map<std::string, MedianAverage*> &rate;
public:
    AtExitExchangeRatePrint(std::unordered_map<std::string, MedianAverage*>& r) : rate(r) {}
    ~AtExitExchangeRatePrint() {
        for (const auto& r : rate) {
            std::pair<double, double> ma = r.second->evaluate();
            std::cout << "=== " << r.first << " ===\n";
            std::cout << "MED: " << ma.first << " AVG: " << ma.second << "\n\n";
            delete r.second;
        }
    }
};


int main() {
    signal(SIGINT, intHandler);

    CURL* curl;
    curl = curl_easy_init();
    if (!curl) {
        throw std::runtime_error("can't initialize curl");
    }

    std::unordered_map<std::string, MedianAverage*> rate;
    AtExitExchangeRatePrint at_exit(rate);
    std::chrono::milliseconds timespan(10 * 1000); // 10 seconds
        
    while (keep_running) {
        struct memory chunk = { 0 };
        make_request(curl, chunk);

        if (!chunk.response) {
            throw std::runtime_error("didn't get response");
        }

        std::string data(chunk.response);
        free(chunk.response);
        chunk.response = 0;

        nlohmann::json data_json = nlohmann::json::parse(data);
        update_rate(data_json["Valute"], rate);
    
        std::this_thread::sleep_for(timespan);
    }

    curl_easy_cleanup(curl);
    
    return 0;
}