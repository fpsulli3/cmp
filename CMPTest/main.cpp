#include <iostream>
#include "func.h"
#include "integrals.h"
#include "bessel.h"

class SinFunc : public cmp::Func1D {
	// Inherited via Func1D
	virtual double operator()(double x) const override
	{
		return sin(3*x);
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

int main(int arc, char**argv) {
	SinFunc sinFunc;
	double a = -0.26;
	double b = 5.12;// 3.14159265358979;
	int N = 100;

	double trapS = cmp::trapInt(sinFunc, a, b, N);
	double trapS2 = cmp::trapInt(sinFunc, a, b, 0.01);
	double trapS3 = cmp::trapInt(sinFunc, a, b, 0.001);
	double trapS4 = cmp::trapInt(sinFunc, a, b, 0.0001);
	double trapS5 = cmp::trapInt(sinFunc, a, b, 0.00001);
	double simpS = cmp::simpInt(sinFunc, a, b, N);
	double rombS = cmp::rombergInt<16>(sinFunc, a, b, 0.001);

	double acceptedValue = 0.550328;
	std::cout << "Accepted value: 0.550328" << std::endl;
	std::cout << "Trapzoid rule (N=" << N << "): " << trapS << ", %error: " << (trapS - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Trapzoid rule (adaptive, err: 0.01): " << trapS2 << ", %error: " << (trapS2 - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Trapzoid rule (adaptive, err: 0.001): " << trapS3 << ", %error: " << (trapS3 - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Trapzoid rule (adaptive, err: 0.0001): " << trapS4 << ", %error: " << (trapS4 - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Trapzoid rule (adaptive, err: 0.00001): " << trapS5 << ", %error: " << (trapS5 - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Simpson's rule: (N=" << N << "): " << simpS << ", %error: " << (simpS - acceptedValue) / acceptedValue << std::endl;
	std::cout << "Romberg itegration (adaptive, err: 0.0001): " << rombS << ", %error: " << (rombS - acceptedValue) / acceptedValue << std::endl;

	cmp::BesselFunction<1, 1000> J1;
	std::cout << "J1(0.00) = " << J1(0.00) << std::endl;
	std::cout << "J1(0.25) = " << J1(0.25) << std::endl;
	std::cout << "J1(0.50) = " << J1(0.50) << std::endl;
	std::cout << "J1(0.75) = " << J1(0.75) << std::endl;

	system("PAUSE");
}