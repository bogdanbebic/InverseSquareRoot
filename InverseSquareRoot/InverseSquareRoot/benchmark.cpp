#include "benchmark.h"
#include <algorithm>

std::chrono::duration<double> benchmark::measure_time(double(*f)(double), std::vector<double> vec) {
	const auto start = std::chrono::system_clock::now();
	for (double elem : vec) {
		double x = f(elem);
	}
	const auto end = std::chrono::system_clock::now();
	const std::chrono::duration<double> elapsed = end - start;
	return elapsed;
}

std::chrono::duration<double> benchmark::measure_time(double(*f)(double, double), std::vector<double> vec, double err) {
	const auto start = std::chrono::system_clock::now();
	for (double elem : vec) {
		double x = f(elem, err);
	}
	const auto end = std::chrono::system_clock::now();
	const std::chrono::duration<double> elapsed = end - start;
	return elapsed;
}

double benchmark::calculate_mean(std::vector<double> vec) {
	double mean = 0.0;
	for (auto elem : vec) {
		mean += elem;
	}
	mean /= vec.size();
	return mean;
}

double benchmark::calculate_mse(std::vector<double> v1, std::vector<double> v2) {
	double mse = 0.0;
	auto n = std::min(v1.size(), v2.size());
	for (auto i = 0; i < n; i++) {
		mse += std::abs(v1[i] * v1[i] - v2[i] * v2[i]);
	}
	mse /= n;
	return mse;
}

double benchmark::calculate_standard_deviation(std::vector<double> vec) {
	double standard_deviation = 0.0;
	const double mean = calculate_mean(vec);
	for (auto elem : vec) {
		standard_deviation += (elem - mean) * (elem - mean);
	}
	standard_deviation /= vec.size();
	standard_deviation = sqrt(standard_deviation);
	return standard_deviation;
}
