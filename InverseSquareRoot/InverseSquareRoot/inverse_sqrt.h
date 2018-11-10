#pragma once
#ifndef _INVERSE_SQRT_H_
#define _INVERSE_SQRT_H_

namespace inv_sqrt {

	/**
	* \brief Finds the inverse square root
	* \param x Number of which the inverse square root is calculated
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
	* \param x Number of which the inverse square root is calculated
	* \return Return value of approximate inverse square root of x
	*
	* Warning:
	* This function works ONLY on sizeof(double) == sizeof(__int64) == 8.
	* This function assumes IEEE 754 floating point format.
	* If above conditions are not met, this function should not be used.
	* This function was not heavily tested and should not be used without further testing.
	*/
	double fast_inverse_square_root(double x);

}

#endif
