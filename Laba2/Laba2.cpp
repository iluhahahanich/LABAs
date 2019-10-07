#include <iostream>
#include <ctime>
using namespace std;
int main() {
    int n;
	cout << " n = ";
	cin >> n;
	int const size = 10001;
	int a[size];
	for (int i = 0; i < n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	int p;
	cout << "p = ";
	cin >> p;
	int kol1 = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] < p ) {
			++kol1;
		}
	}
	cout <<"the number of a[i] less then '" << p << "' = "  << kol1 << '\n';
//2nd part
	int sum = 0;
	int i = n - 1;
	while (( i >= 0) && (a[i] >= 0 )) {
		sum += a[i];
		--i;
	}
	if (i == -1) {
		cout << "there are no negative numbers\n";
	}
	else {
		if (i == n - 1) {
			cout << "there are no positive numbers after\n";
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