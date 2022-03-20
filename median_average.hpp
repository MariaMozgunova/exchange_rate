#include <vector>
#include <algorithm>
#include <iostream>

#pragma once

class MedianAverage {
    std::vector<double> data;
    double average;

    void find_median(int l, int r, int k);

public:
    MedianAverage();
 
    void add(double rate);

    std::pair<double, double> evaluate();

    void print_data();
};