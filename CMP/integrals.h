#pragma once

namespace cmp {
	class Func1D;

	double trapInt(Func1D& f, double a, double b, int N);
	double trapInt(Func1D& f, double a, double b, double err);
	double simpInt(Func1D& f, double a, double b, int N);
}