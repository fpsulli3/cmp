#pragma once

#include <set>

namespace cmp {
	class Func1D {
	public:
		virtual double operator()(double x) const = 0;
		virtual double getMinX() const = 0;
		virtual double getMaxX() const = 0;
	};
}