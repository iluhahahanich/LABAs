#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;
int main() {
	int n;
	cout << " n = ";
	cin >> n;
	int const size = 10001;
	double a[size];
	cout << "press 'y' to fill array with radom numbers";
	if (_getch() == 'y') {
		cout << "\ninterval [x,y] \n";
		double x, y;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		srand(time(0));
		for (int i = 0; i < n; ++i) {
			a[i] = (double)rand() / RAND_MAX * (y - x)  + x;
			cout << "a[" << i << "] = " << a[i] << '\n';
		}
	} 
	else {
		for (int i = 0; i < n; ++i) {
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}
	}
	double p;
	cout << "p = ";
	cin >> p;
	int kol1 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < p) {
			++kol1;
		}
	}
	cout << "the number of a[i] less then '" << p << "' = " << kol1 << '\n';

	//2nd part
	double sum = 0;
	int i = n - 1;
	while ((i >= 0) && (a[i] >= 0)) {
		sum += a[i];
		--i;
	}
	if (i == -1) {
		cout << "there are no negative numbers\n";
	}
	else {
		if (i == n - 1) {
			cout << "there are no positive numbers\n";
		}
		else {
			cout << "the sum after the last negative a[i] = " << sum << "\n";
		}
	}
	//3rd part
	int j;
	for (int i = 0; i < n; ++i) {
		if (a[i] < p) {
			j = i;
			while ((a[j - 1] >= p) && (j > 0)) {
				swap(a[j - 1], a[j]);
				--j;
			}
		}
	}
	cout << "sorted array ";
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	return 0;
}