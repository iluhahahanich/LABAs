#pragma once
#include <iostream>
using namespace std;
class Fraction {
private:
	int numerator;
	int denominator;
	Fraction(){}
public:
	Fraction(int a, int b): numerator(a), denominator(b) {
		if (denominator == 0) {
			cout << "Denominator cannot be 0";
			exit(-1);
		}
		reduction();
	}
	Fraction(const Fraction& a): numerator(a.numerator), denominator(a.denominator){}
	void getNumerator();
	void getDenominator();
	void getFraction();
    void reduction();
	Fraction operator+ (const Fraction& x);
	Fraction operator- (const Fraction& x);
	Fraction operator* (const Fraction& x);
	Fraction operator/ (const Fraction& x);
};
