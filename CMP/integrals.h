#pragma once

namespace cmp {
	class Func1D;

	double trapInt(Func1D& f, double a, double b, int N);
	double trapInt(Func1D& f, double a, double b, double err);
	double simpInt(Func1D& f, double a, double b, int N);

	template <int M>
	double rombergInt(Func1D& f, double a, double b, double err) {
		double s = 0.5*f(a) + 0.5*f(b);
		double h = (b - a);

		double R[M];
		R[0] = s*h;

		double error = DBL_MAX;
		int k = 0;
		int m = 1;
		do {
			int i = m - 1;
			int twoi = (int)pow(2, i);
			int twoip1 = (int)pow(2, i + 1);

			double start = a + (b - a) / twoip1;
			int n = twoi;
			double jmp = (b - a) / twoi;

			for (int k = 0; k < n; k++) {
				s += f(start + k*jmp);
			}

			h = (b - a) / twoip1;
			double Ii = s*h;

			for (k = 0; k < m && abs(error) > err; ++k) {
				double c = 1.0 / (pow(4.0, k+1) - 1.0);
				double r = R[k];
				R[k] = Ii;
				error = c*(Ii - r);
				Ii += error;
			}

			R[k] = Ii;
			++m;
		} while (m < M && abs(error) > err);

		return R[k];
	}
}