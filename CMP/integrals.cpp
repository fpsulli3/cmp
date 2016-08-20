#include "integrals.h"
#include "func.h"

namespace cmp {
	double errori(double Ii, double Ip) {
		return (1.0 / 3.0)*(Ii - Ip);
	}

	double trapInt(Func1D& f, double a, double b, int N) {
		double h = (b - a) / N;
		double s = 0.5*f(a) + 0.5*f(b);
		for (int i = 1; i < N; i++) {
			s += f(a + i*h);
		}
		return h*s;
	}

	double trapInt(Func1D& f, double a, double b, double err) {
		double s = 0.5*f(a) + 0.5*f(b);
		double h = (b-a);
		double Ip = s*h;

		double error = DBL_MAX;
		int i = 0;
		do {
			int twoi = (int)pow(2, i);
			int twoip1 = (int)pow(2, i + 1);

			double start = a + (b - a) / twoip1;
			int n = twoi;
			double jmp = (b - a) / twoi;

			for (int k = 0; k < n; k++) {
				s += f(start + k*jmp);
			}

			h = (b-a)/ twoip1;
			double Ii = s*h;
			error = abs(errori(Ii, Ip));
			Ip = Ii;
			++i;
		} while (error > err);

		return Ip;
	}

	double simpInt(Func1D& f, double a, double b, int N) {
		if (N % 2) {
			return 0;
		}

		double h = (b - a) / N;
		double s = f(a) + f(b);
		for (int i = 1; i < N; i++) {
			s += 2 * (1 + i % 2) * f(a + i*h);
		}

		return s*h / 3;
	}
}