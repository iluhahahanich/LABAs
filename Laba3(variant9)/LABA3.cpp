#include <iostream>
#include <ctime>
#include <cassert>
using namespace std;
void writeMatrix(int** a,int n,int m) {
	cout << "initial matrix:";
	for (int i = 0; i < n; ++i) {
		cout << '\n';
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
	}
}
void setMatrix(int** a,int n,int m) {
	for (int i = 0; i < n; i++){
		for (int j = i % 2; j < m; j+=2){	
			a[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = (i % 2 == 0)  ; j < m; j += 2) {
			a[i][j] = rand() % 100 - 50;
		}
	}
}
int main() {
	int n, m;
	cout << "number of rows: ";
	cin >> n;
	assert(n <= 10);
	cout << "number of columns: ";
	cin >> m;
	assert(m <= 10);
	int** a = new int* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	setMatrix(a, n, m);
	writeMatrix(a,n,m);
//----1st task-------------------------------------------------------------------------------
	bool such_rows = false;
	for (int i = 0; i < n; ++i) {
		int sum = 0;
		bool true_row = false;
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 0) {
				true_row = true;
				break;
			}
		}
		if (true_row) {
			such_rows = true;
			for (int j = 0; j < m; ++j) {        
				sum += a[i][j];
			}
			cout << '\n' <<"the sum: " << sum << " ,row with number " << i + 1;
		}
	}
	if(!such_rows) {
		cout << '\n' << "there is no required rows";
	}
//---- 2nd task-------------------------------------------------------------------
	int* min_in_row = new int[n];
	int* max_in_column = new int[m];
	for (int i = 0; i < n; ++i) {
		min_in_row[i] = a[i][0];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] < min_in_row[i]) {
				min_in_row[i] = a[i][j];
			}
		}
	}
	
	for (int j = 0; j < m; ++j) {
	      max_in_column[j] = a[0][j];
		for (int i = 0; i < n; ++i) {
			if (a[i][j] > max_in_column[j]) {
				max_in_column[j] = a[i][j];
			}
		}
	}

	int k = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((a[i][j] == max_in_column[j]) && (a[i][j] == min_in_row[i])) {
				++k;
			}
		}
	}
	cout << "\nnumber of good points: " << k;

	delete[] max_in_column;
	delete[] min_in_row;
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[]a;



}
