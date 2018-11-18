#pragma once
#ifndef _INVERSE_SQRT_H_
#define _INVERSE_SQRT_H_

namespace inv_sqrt {

	/**
	 * \brief Acceptable error used in iterative methods
	 */
	extern const double error;

	/**
	 * \brief Finds the inverse square root of number x using the cmath library
	 * \param x Number for which the inverse square root is calculated
	 * \return Return value of approximate inverse square root of x
	 */
	double cmath_inv_sqrt(double x);

	/**
	* \brief Finds the inverse square root
	* \param x Number for which the inverse square root is calculated
	* \return Return value of approximate inverse square root of x
	*
	* Warning:
	* This function works ONLY on sizeof(float) == sizeof(int) == 4.
	* This function assumes IEEE 754 floating point format.
	* If above conditions are not met, this function should not be used.
	*/
	float fast_inverse_square_root(float x);

	/**
	* \brief Finds the inverse square root
	* \param x Number for which the inverse square root is calculated
	* \return Return value of approximate inverse square root of x
	*
	* Warning:
	* This function works ONLY on sizeof(double) == sizeof(__int64) == 8.
	* This function assumes IEEE 754 floating point format.
	* If above conditions are not met, this function should not be used.
	* This function was not heavily tested and should not be used without further testing.
	*/
	double fast_inverse_square_root(double x);

	/**
	 * \brief Finds the inverse square root using Newton's method
	 * \param s Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of s
	 */
	double newtons_method(double s, double err = error);

	/**
	 * \brief Optimized version of Newton's method - less costly arithmetic operations
	 * \param s Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of s
	 */
	double newtons_method_optimized_1(double s, double err = error);

	/**
	 * \brief Second possible optimized version of Newton's method - less costly arithmetic operations
	 * \param s Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of s
	 */
	double newtons_method_optimized_2(double s, double err = error);

	/**
	 * \brief Finds the inverse square root using Regula Falsi method - version 1
	 * \param s Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of s
	 */
	double regula_falsi_method_version_1(double s, double err = error);

	/**
	 * \brief Finds the inverse square root using Regula Falsi method - version 2
	 * \param s Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of s
	 */
	double regula_falsi_method_version_2(double s, double err = error);
	
	/**
	 * \brief Finds the inverse square root using binary search
	 * \param x Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of x
	 * Finds the number of iterations based on the param err and does binary search for that number of iterations
	 */
	double binary_search(double x, double err = error);

	/**
	 * \brief Finds the inverse square root using binary search
	 * \param x Number for which the inverse square root is calculated
	 * \param err Approximation error for which the result is considered correct
	 * \return Return value of approximate inverse square root of x
	 */
	double binary_search_version_2(double x, double err = error);

}

#endif
