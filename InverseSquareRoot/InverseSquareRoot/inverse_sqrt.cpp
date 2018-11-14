
#include <cmath>

namespace inv_sqrt {
	
	float fast_inverse_square_root(float x) {
		auto i = 0x5f3759df - (*reinterpret_cast<int*>(&x) >> 1);
		auto y = *reinterpret_cast<float*>(&i);
		y = y * (1.5F - x * 0.5F * y * y);	// 1st iteration
		// y = y * (1.5F - x * 0.5F * y * y);	// 2nd iteration, this can be removed
		return y;
	}

	double fast_inverse_square_root(double x) {
		auto i = 0x5fe6ec85e7de30da - (*reinterpret_cast<__int64*>(&x) >> 1);
		auto y = *reinterpret_cast<double*>(&i);
		y = y * (1.5 - x * 0.5 * y * y);	// 1st iteration
		// y = y * (1.5F - x * 0.5F * y * y);	// 2nd iteration, this can be removed
		return y;
	}

	double newtons_method(const double s, const double err = 1e-5) {
		const double c = 1 / s;
		double x, x_prev;

		s > 1 ? x = 1 : x = c;

		do {
			x_prev = x;
			x -= (x * x - c) / (2 * x);
		} while (abs(x - x_prev) > err);

		return x;
	}

	double newtons_method_optimized_1(const double s, const double err = 1e-5) {
		const double c = 1 / (2 * s);
		double x, x_prev;

		s > 1 ? x = 1 : x = c;

		do {
			x_prev = x;
			x = 0.5 * x - c / x;
		} while (abs(x - x_prev) > err);

		return x;
	}

	double newtons_method_optimized_2(const double s, const double err = 1e-5) {
		double x, x_prev;

		s > 1 ? x = 1 : x = 1 / s;

		do {
			x_prev = x;
			x *= 0.5 * (1 - s * x * x);
		} while (abs(x - x_prev) > err);

		return x;
	}

	double binary_search(double x, double err = 1e-5) {
		double result = 0.0;

		// TODO: implement

		return result;
	}

}
