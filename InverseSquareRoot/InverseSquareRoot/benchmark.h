#pragma once
#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_	///< Header guard
#include <vector>
#include <chrono>

/**\file benchmark.h
 * \brief Declarations of all necessary bencmarking and test functionalities
 */

/**
 * \brief Vectors used in testing
 */
namespace test_vectors {
	extern std::vector<double> degree2_numbers;
	extern std::vector<double> prime_6_k_plus_minus_1;
	extern std::vector<double> rand_doubles;
	extern std::vector<double> rand_small_doubles;
}

/**
 * \brief Benchmarking functionalities
 */
namespace benchmark {

	/**
	 * \brief Variable which determines the number of decimals to be printed
	 */
	extern const int precision_output;

	/**
	 * \brief Measures time for call of f on every element of vec
	 * \param f Function to be called on every element of vec
	 * \param vec Vector on whose elements f is called
	 * \return Duration of the for loop of f(elem) for elem: vec
	 */
	std::chrono::duration<double> measure_time(double(*f)(double), std::vector<double> vec);

	/**
	* \brief Measures time for call of f on every element of vec and err
	* \param f Function to be called on every element of vec and err
	* \param vec Vector on whose elements f is called (first parametar of f)
	* \param err Error on which f is called (second parametar of f)
	* \return Duration of the for loop of f(elem, err) for elem: vec
	*/
	std::chrono::duration<double> measure_time(double(*f)(double, double), std::vector<double> vec, double err);

	/**
	 * \brief Calculates (elementwise) absolute difference between every element of vectors v1 and v2
	 * \param v1 Vector 1
	 * \param v2 Vector 2
	 * \return Vector which contains the elementwise absolute difference between vectors v1 and v2
	 */
	std::vector<double> abs_difference(std::vector<double> v1, std::vector<double> v2);

	/**
	 * \brief Calculates the arithmetic mean of the vector vec
	 * \param vec Vector for which the mean is calculated
	 * \return Arithmetic mean of the vector vec
	 */
	double calculate_mean(std::vector<double> vec);

	/**
	 * \brief Calculates the mean squared error of vectors v1 and v2
	 * \param v1 First vector
	 * \param v2 seccond vector
	 * \return Mean squared error on vectors v1 and v2
	 */
	double calculate_mse(std::vector<double> v1, std::vector<double> v2);

	/**
	 * \brief Calculates the standard deviation of vector vec
	 * \param vec Vector for which the standard deviation is calculated
	 * \return Standard deviation of vector vec
	 */
	double calculate_standard_deviation(std::vector<double> vec);

}

#endif
