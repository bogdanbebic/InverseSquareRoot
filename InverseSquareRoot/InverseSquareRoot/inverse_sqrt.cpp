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

}
