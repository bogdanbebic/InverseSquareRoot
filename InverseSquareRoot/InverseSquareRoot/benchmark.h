#pragma once
#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_
#include <vector>
#include <chrono>

namespace benchmark {

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
