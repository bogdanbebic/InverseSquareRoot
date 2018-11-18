#include "benchmark.h"
#include <algorithm>


std::vector<double> test_vectors::degree2_numbers { 1.0,
	2.0,
	4.0,
	8.0,
	16.0,
	32.0,
	64.0,
	128.0,
	256.0,
	512.0,
	1024.0,
	2048.0,
	4096.0,
	8192.0,
	16384.0,
	32768.0,
	65536.0,
	131072.0,
	262144.0,
	524288.0,
	1048576.0,
	2097152.0,
	4194304.0,
	8388608.0,
	16777216.0,
	33554432.0,
	67108864.0,
	134217728.0,
	268435456.0,
	536870912.0,
	1073741824.0,
	2147483648.0 };

std::vector<double> test_vectors::prime_6_k_plus_minus_1 { 2.0,
	3.0,
	5.0,
	7.0,
	11.0,
	13.0,
	17.0,
	19.0,
	23.0,
	25.0,
	29.0,
	31.0,
	35.0,
	37.0,
	41.0,
	43.0,
	47.0,
	49.0,
	53.0,
	55.0,
	59.0,
	61.0,
	65.0,
	67.0,
	71.0,
	73.0,
	77.0,
	79.0,
	83.0,
	85.0,
	89.0,
	91.0 };

std::vector<double> test_vectors::rand_doubles { 1144320.645309646,
	4462204.263678968,
	1090735.1556845629,
	100795.00089993354,
	2951523.655396142,
	1080443.3812610917,
	2538568.3853803077,
	359354.443787361,
	1559165.4330839787,
	6394174.116641273,
	105251.64417288385,
	28351.65998440603,
	82225.52072992308,
	347026.1992692884,
	1500588.6178198732,
	6070387.211596543,
	4673490.87700648,
	88812.31278744114,
	420009.3647098323,
	924096.4866563639,
	72761.43078013894,
	3138656.072930423,
	3427667.7048330856,
	273268.4715420793,
	833663.2941157968,
	188326.8607780595,
	884676.2472547512,
	3005103.5106215533,
	5046236.086916425,
	7891790.92111017,
	1733625.6102553639,
	470678.2034495795 };

std::vector<double> test_vectors::rand_small_doubles { 0.41108501816673615,
	0.7605106430441397,
	0.9563457029745919,
	0.5398124359861848,
	0.12406602721699889,
	0.4811323712618395,
	0.00510880022995952,
	0.9978593933473487,
	0.6320603785935238,
	0.8538739667142123,
	0.3100078675463397,
	0.5897939100046153,
	0.9662387210066078,
	0.04711283148541068,
	0.5169842805618755,
	0.13606621624378712,
	0.9866282294733738,
	0.42742413008480284,
	0.7191563575227381,
	0.7188135137096138,
	0.34650437231120057,
	0.6480626452242616,
	0.340588780083807,
	0.21343141904866836,
	0.8737222316521727,
	0.7437086401083514,
	0.8947137933251047,
	0.6615749637926043,
	0.1748457355148776,
	0.27219347347391654,
	0.671243419393269,
	0.6039474492069155 };

/**
 * \brief 52 is the magic number for precision in IEEE 754 floating point double precision
 */
const int benchmark::precision_output = 52;

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
