#include "Class.h"
void Fraction::getNumerator() {
	cout << numerator;
}
void Fraction::getDenominator() {
	cout << denominator;
}
void Fraction::getFraction() {
	int int_part = numerator / denominator, fract_part_numerator = abs(numerator) % denominator;
	if (int_part && fract_part_numerator) {
		cout << int_part << " " << fract_part_numerator << "/" << denominator;
	}
	else {
		if (!int_part && fract_part_numerator) {
			cout << numerator << "/" << denominator;
		}
		else {
			cout << int_part;
		}
	}
	cout << '\n';
}
void Fraction::reduction() {
	int x = numerator;
	int y = denominator;
	while (y) {;
		x %= y;
		swap(x, y);
	}
	numerator /= x;
	denominator /= x;

	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
}

Fraction Fraction::operator+ (const Fraction& x) {
	return Fraction(numerator * x.denominator + x.numerator * denominator, denominator * x.denominator);
}
Fraction Fraction::operator- (const Fraction& x) {
	return Fraction(numerator * x.denominator - x.numerator * denominator, denominator * x.denominator);
}
Fraction Fraction::operator* (const Fraction& x) {
	return Fraction(numerator * x.numerator, denominator * x.denominator);
}
Fraction Fraction::operator/ (const Fraction& x) {
	return Fraction(numerator * x.denominator, denominator * x.numerator);
}