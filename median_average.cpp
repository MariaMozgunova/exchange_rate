#include "median_average.hpp"

void MedianAverage::find_median(int l, int r, int k) {
    double pivot = data[(l + r) / 2];
    int prev_l = l, prev_r = r;

    while (l <= r) {
        while (data[l] < pivot) {
            l++;
        }

        while (data[r] > pivot) {
            r--;
        }

        if (l <= r) {
            std::swap(data[l], data[r]);
            r--;
            l++;
        }
    }

    if (prev_l < r && k <= r) {
        find_median(prev_l, r, k);
    } else if (prev_r > l && k >= l) {
        find_median(l, prev_r, k);
    }
}

MedianAverage::MedianAverage() : data({}), average(0) {}

void MedianAverage::add(double rate) {
    average = (average * data.size() + rate) / (data.size() + 1);
    data.push_back(rate);
}

std::pair<double, double> MedianAverage::evaluate() {
    std::pair<double, double> res;
    res.second = average;
        
    if (data.size() == 0) {
        res.first = 0;
    } else {
        find_median(0, data.size() - 1, data.size() / 2);
        double median = data[data.size() / 2];

        if (data.size() % 2 == 0) {
            find_median(0, data.size() - 1, data.size() / 2 - 1);
            median += data[data.size() / 2 - 1];
            median /= 2;
        }

        res.first = median;
    }

    return res;
}

void MedianAverage::print_data() {
    for (double d : data) {
        std::cout << d << ' ';
    }

    std::cout << '\n';
}