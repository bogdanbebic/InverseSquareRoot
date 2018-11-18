#include <iostream>
#include <iomanip>
#include "benchmark.h"
#include "inverse_sqrt.h"

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

int main() {
	std::cout << std::setprecision(benchmark::precision_output) << std::fixed;
	
	auto time_cmath = calc_time_for_all_test_vectors(inv_sqrt::cmath_inv_sqrt);
	auto time_fast_inv_sqrt = calc_time_for_all_test_vectors(inv_sqrt::fast_inverse_square_root);
	auto time_newton = calc_time_for_all_test_vectors(inv_sqrt::newtons_method, inv_sqrt::error);
	/*	BUG: fix
	auto time_newton_opt1 = calc_time_for_all_test_vectors(inv_sqrt::newtons_method_optimized_1, inv_sqrt::error);
	*/
	/*	BUG: fix
	auto time_newton_opt2 = calc_time_for_all_test_vectors(inv_sqrt::newtons_method_optimized_2, inv_sqrt::error);
	*/
	auto time_regula_falsi_1 = calc_time_for_all_test_vectors(inv_sqrt::regula_falsi_method_version_1, inv_sqrt::error);
	auto time_regula_falsi_2 = calc_time_for_all_test_vectors(inv_sqrt::regula_falsi_method_version_2, inv_sqrt::error);
	auto time_bin_search = calc_time_for_all_test_vectors(inv_sqrt::binary_search, inv_sqrt::error);
	auto time_bin_search_version_2 = calc_time_for_all_test_vectors(inv_sqrt::binary_search_version_2, inv_sqrt::error);

	std::cout << "cmath:" 
		<< std::endl << time_cmath.count() << std::endl;
	std::cout << "Fast inverse sqrt:" 
		<< std::endl << time_fast_inv_sqrt.count() << std::endl;
	std::cout << "Newton:" 
		<< std::endl << time_newton.count() << std::endl;

	/* BUG: fix
	std::cout << "Newton v2 (opt1):" 
		<< std::endl << time_newton_opt1.count() << std::endl;
	std::cout << "Newton v3 (opt2):" 
		<< std::endl << time_newton_opt2.count() << std::endl;
	*/

	std::cout << "Regula Falsi v1:"
		<< std::endl << time_regula_falsi_1.count() << std::endl;
	std::cout << "Regula Falsi v2:"
		<< std::endl << time_regula_falsi_2.count() << std::endl;
	std::cout << "Binary search (calculates number of iterations):"
		<< std::endl << time_bin_search.count() << std::endl;
	std::cout << "Binary search:"
		<< std::endl << time_bin_search_version_2.count() << std::endl;

	system("pause");
}
