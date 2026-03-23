#pragma once

#include <iostream>
#include <cmath>

class Complex {
	public: double Re, Im;

	public: 
		Complex(double re = 0, double im = 0) : Re(), Im() {
			Re = re;
			Im = im;
		};

		Complex operator +(const Complex& c)const
		{
			return Complex(Re + c.Re, Im + c.Im);
		}

		Complex operator *(const Complex& c)const
		{
			return Complex(c.Re * Re, Re * c.Im + c.Re * Im);
		}

		Complex operator -(const Complex& c)const
		{
			return Complex(Re - c.Re, Im - c.Im);
		}

		Complex operator /(const Complex& c)const
		{
			return Complex((Re * c.Re + Im * c.Im) / (c.Re * c.Re + c.Im * c.Im), (-1 * Re * c.Im + c.Re * Im) / (c.Re * c.Re + c.Im * c.Im));
		}

		double Mod() {
			return std::sqrt(Re * Re + Im * Im);
		}

		Complex Conjugate() {
			return Complex(Re, -Im);
		}

		double Arg() {
			const double PI = acos(-1.0);

			double mod = Mod();

			if (mod == 0) {
				return 0.0;
			}
			
			if (Re > 0) {
				return atan(Im / Re);
			}
			else if (Re < 0) {
				if (Im >= 0) {
					return PI + atan(Im / Re);
				}
				else {
					return -PI - atan(Im / Re);
				}
			}
			else { 
				if (Im > 0) {
					return PI / 2;
				}
				else if (Im < 0) {
					return -PI / 2;
				}
				else {
					return 0.0;
				}
			}
		}
};

inline std::ostream& operator << (std::ostream& o, const Complex& c)
{
	return o << '(' << c.Re << ", " << c.Im << ')';
}


