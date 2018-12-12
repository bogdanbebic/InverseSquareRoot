#include <iostream>
#include <iomanip>
#include "benchmark.h"
#include "inverse_sqrt.h"

/** \file main.cpp
 *	\brief Bencmarks the inverse sqrt algorithms
 */

std::chrono::duration<double> calc_time_for_all_test_vectors(double(*f)(double)) {
	auto time = benchmark::measure_time(f, test_vectors::rand_small_doubles);
	time += benchmark::measure_time(f, test_vectors::rand_doubles);
	time += benchmark::measure_time(f, test_vectors::degree2_numbers);
	time += benchmark::measure_time(f, test_vectors::prime_6_k_plus_minus_1);
	return time;
}

std::chrono::duration<double> calc_time_for_all_test_vectors(double(*f)(double, double), double error) {
	auto time = benchmark::measure_time(f, test_vectors::rand_small_doubles, error);
	time += benchmark::measure_time(f, test_vectors::rand_doubles, error);
	time += benchmark::measure_time(f, test_vectors::degree2_numbers, error);
	time += benchmark::measure_time(f, test_vectors::prime_6_k_plus_minus_1, error);
	return time;
}

std::vector<double> calc_inv_sqrt_for_test_vectors(double(*f)(double)) {
	std::vector<double> vec;
	auto n = test_vectors::rand_small_doubles.size() + test_vectors::degree2_numbers.size()
		+ test_vectors::prime_6_k_plus_minus_1.size() + test_vectors::rand_doubles.size();
	vec.reserve(n);
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem));
	}
	return vec;
}

std::vector<double> calc_inv_sqrt_for_test_vectors(double(*f)(double, double), double error) {
	std::vector<double> vec;
	auto n = test_vectors::rand_small_doubles.size() + test_vectors::degree2_numbers.size()
		+ test_vectors::prime_6_k_plus_minus_1.size() + test_vectors::rand_doubles.size();
	vec.reserve(n);
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem, error));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem, error));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem, error));
	}
	for (auto elem : test_vectors::rand_small_doubles) {
		vec.push_back(f(elem, error));
	}
	return vec;
}

double calculate_mse_from_cmath(double(*f)(double)) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f);

	return benchmark::calculate_mse(cmath_vec, vec);
}

double calculate_mse_from_cmath(double(*f)(double, double), double error) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f, error);

	return benchmark::calculate_mse(cmath_vec, vec);
}

double calculate_mean_error_from_cmath(double(*f)(double)) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f);
	return benchmark::calculate_mean(benchmark::abs_difference(cmath_vec, vec));
}

double calculate_mean_error_from_cmath(double(*f)(double, double), double error) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f, error);
	return benchmark::calculate_mean(benchmark::abs_difference(cmath_vec, vec));
}

double calculate_standard_deviation_of_error_from_cmath(double(*f)(double)) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f);
	return benchmark::calculate_standard_deviation(benchmark::abs_difference(cmath_vec, vec));
}

double calculate_standard_deviation_of_error_from_cmath(double(*f)(double, double), double error) {
	auto cmath_vec = calc_inv_sqrt_for_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto vec = calc_inv_sqrt_for_test_vectors(f, error);
	return benchmark::calculate_standard_deviation(benchmark::abs_difference(cmath_vec, vec));
}

int main() {
	std::cout << std::setprecision(benchmark::precision_output) << std::fixed;

	// Time calculation and output
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Time calculation - in milliseconds" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	
	std::cout << "cmath:" 
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::cmath_inv_sqrt).count() << std::endl;
	std::cout << "Fast inverse sqrt:" 
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::fast_inverse_square_root).count() << std::endl;
	std::cout << "Newton:" 
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::newtons_method, inv_sqrt::error).count() << std::endl;
	std::cout << "Regula Falsi v1:"
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::regula_falsi_method_version_1, inv_sqrt::error).count() << std::endl;
	std::cout << "Regula Falsi v2:"
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::regula_falsi_method_version_2, inv_sqrt::error).count() << std::endl;
	std::cout << "Binary search (calculates number of iterations):"
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::binary_search, inv_sqrt::error).count() << std::endl;
	std::cout << "Binary search:"
		<< std::endl << calc_time_for_all_test_vectors(inv_sqrt::binary_search_version_2, inv_sqrt::error).count() << std::endl;

	// MSE calculation and output
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "MSE calculation - relative to cmath" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << "Fast inverse sqrt:"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::fast_inverse_square_root) << std::endl;
	std::cout << "Newton:"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::newtons_method, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v1:"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::regula_falsi_method_version_1, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v2:"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::regula_falsi_method_version_2, inv_sqrt::error) << std::endl;
	std::cout << "Binary search (calculates number of iterations):"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::binary_search, inv_sqrt::error) << std::endl;
	std::cout << "Binary search:"
		<< std::endl << calculate_mse_from_cmath(inv_sqrt::binary_search_version_2, inv_sqrt::error) << std::endl;

	// Mean error calculation and output
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Mean error calculation - relative to cmath" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << "Fast inverse sqrt:"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::fast_inverse_square_root) << std::endl;
	std::cout << "Newton:"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::newtons_method, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v1:"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::regula_falsi_method_version_1, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v2:"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::regula_falsi_method_version_2, inv_sqrt::error) << std::endl;
	std::cout << "Binary search (calculates number of iterations):"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::binary_search, inv_sqrt::error) << std::endl;
	std::cout << "Binary search:"
		<< std::endl << calculate_mean_error_from_cmath(inv_sqrt::binary_search_version_2, inv_sqrt::error) << std::endl;

	// Standard deviation of error and output
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Standard deviation of error - relative to cmath" << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	std::cout << "Fast inverse sqrt:"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::fast_inverse_square_root) << std::endl;
	std::cout << "Newton:"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::newtons_method, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v1:"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::regula_falsi_method_version_1, inv_sqrt::error) << std::endl;
	std::cout << "Regula Falsi v2:"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::regula_falsi_method_version_2, inv_sqrt::error) << std::endl;
	std::cout << "Binary search (calculates number of iterations):"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::binary_search, inv_sqrt::error) << std::endl;
	std::cout << "Binary search:"
		<< std::endl << calculate_standard_deviation_of_error_from_cmath(inv_sqrt::binary_search_version_2, inv_sqrt::error) << std::endl;

	system("pause");
}
