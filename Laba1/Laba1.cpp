#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int k;
	double x;
	cout << "x = ";
	cin >> x;
	cout << "k = ";
	cin >> k;
	int a = 1;
	double  slag = 1, rez = 1;
	while (fabs(slag) >= pow(10, -k)) {
		slag = slag * (-1) * a / (a + 1) * x;
		rez += slag;
		a += 2;
	}
	cout << "using Talor  " << fixed << setprecision(k) << rez << '\n';
	double rez1;
	rez1 = 1 / sqrt(1 + x);
	cout << "using formula  " << fixed << setprecision(k) << rez1 << '\n';
	double dif;
	dif = rez - rez1;
	cout << "difference " << dif;
}