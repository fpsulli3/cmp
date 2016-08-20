#pragma once

#include "func.h"
#include "integrals.h"

namespace cmp {
	
	template <int m, int N>
	class BesselFunction : public Func1D {
	private:

		class BesselInnerFunction : public Func1D {
		private:
			double a;

		public:
			BesselInnerFunction(double a) : a(a) {}

			// Inherited via Func1D
			virtual double operator()(double x) const override
			{
				return cos(m*x - a*sin(x));
			}
			virtual double getMinX() const override
			{
				return -DBL_MAX;
			}
			virtual double getMaxX() const override
			{
				return DBL_MAX;
			}
		};

	public:

		// Inherited via Func1D
		virtual double operator()(double x) const override
		{
			const double PI = 3.14159265358979;
			BesselInnerFunction f(x);
			return simpInt(f, 0, PI, N)/PI;
		}

		virtual double getMinX() const override
		{
			return -DBL_MAX;
		}

		virtual double getMaxX() const override
		{
			return DBL_MAX;
		}
	};
}