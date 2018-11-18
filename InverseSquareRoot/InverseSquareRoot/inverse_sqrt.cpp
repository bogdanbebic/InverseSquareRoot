#include "inverse_sqrt.h"
#include <cmath>

/**
 * \brief Constant defined for testing purposes
 */
const double inv_sqrt::error = 1e-2;

double inv_sqrt::cmath_inv_sqrt(double x) {
	return 1.0 / sqrt(x);
}

float inv_sqrt::fast_inverse_square_root(float x) {
	auto i = 0x5f3759df - (*reinterpret_cast<int*>(&x) >> 1);
	auto y = *reinterpret_cast<float*>(&i);
	y = y * (1.5F - x * 0.5F * y * y);	// 1st iteration
	// y = y * (1.5F - x * 0.5F * y * y);	// 2nd iteration, this can be removed
	return y;
}

double inv_sqrt::fast_inverse_square_root(double x) {
	auto i = 0x5fe6ec85e7de30da - (*reinterpret_cast<__int64*>(&x) >> 1);
	auto y = *reinterpret_cast<double*>(&i);
	y = y * (1.5 - x * 0.5 * y * y);	// 1st iteration
	// y = y * (1.5F - x * 0.5F * y * y);	// 2nd iteration, this can be removed
	return y;
}

double inv_sqrt::newtons_method(const double s, const double err) {
	const double c = 1 / s;
	double x, x_prev;

	s > 1 ? x = 1 : x = c;

	do {
		x_prev = x;
		x -= (x * x - c) / (2 * x);
	} while (abs(x - x_prev) > err);

	return x;
}

// BUG: DOES NOT WORK
double inv_sqrt::newtons_method_optimized_1(const double s, const double err) {
	const double c = 1 / (2 * s);
	double x_prev, x = s > 1 ? 1 : 2 * c;

	do {
		x_prev = x;
		x = 0.5 * x - c / x;
	} while (abs(x - x_prev) > err);

	return x;
}

// BUG: DOES NOT WORK
double inv_sqrt::newtons_method_optimized_2(const double s, const double err) {
	double x, x_prev;

	s > 1 ? x = 1 : x = 1 / s;

	do {
		x_prev = x;
		x *= 0.5 * (1 - s * x * x);
	} while (abs(x - x_prev) > err);

	return x;
}

double inv_sqrt::regula_falsi_method_version_1(const double s, const double err) {
	const double c = 1 / s;
	double b = s > 1 ? 1 : c, a = 0;
	double x_prev, x = b;

	do {
		x_prev = x;
		const double f_b = b * b - c;
		x = b - f_b / (b + a);
		if ((x * x - c) * f_b < 0)
			a = x;
		else
			b = x;
	} while (abs(x - x_prev) > err);

	return x;
}

double inv_sqrt::regula_falsi_method_version_2(const double s, const double err) {
	const double c = 1 / s;
	double b = s > 1 ? 1 : c, a = 0;
	double x_prev, x = b;

	do {
		x_prev = x;
		x = (a * b + c) / (b + a);
		if ((x * x - c) * (b * b - c) < 0)
			a = x;
		else
			b = x;
	} while (abs(x - x_prev) > err);

	return x;
}


double inv_sqrt::binary_search(double x, double err) {
	const double s = 1 / x;
	double a, b, mid;
	a = 0;
	s > 1 ? b = s :b = 1;

	const auto n = static_cast<int>(log2((b - a) / err));

	for (int i = 0; i < n; i++) {
		mid = (b + a) / 2;
		if ((mid*mid - s) == 0) return mid;
		else if (((mid*mid - s)*(a*a - s)) < 0) b = mid;
		else a = mid;
	}
	
	return mid;
}
double inv_sqrt::binary_search_version_2(double x, double err) {
	const double s = 1 / x;
	double a, b, mid, mid_pred;
	a = mid = 0;
		
	s > 1 ? b = s : b = 1;
		
	do {
		mid_pred = mid;
		mid = (b + a) / 2;
		if ((mid*mid - s) == 0) return mid;
		else if (((mid*mid - s)*(a*a - s)) < 0) b = mid;
		else a = mid;

	} while (abs(mid - mid_pred) > err);
	
	return mid;
}
