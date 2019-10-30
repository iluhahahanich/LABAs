#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
void showDataInFile(string file) {
	ifstream fin(file);
	string tmp;
	while (getline(fin, tmp)) {
		cout << tmp << '\n';
	}
	fin.close();
}
int main() {
	string fin_file, fout_file;
	cout << "name of the input file: ";
	cin >> fin_file;
	fin_file += ".txt";
	cout << "name of the output file: ";
	cin >> fout_file;
	fout_file += ".txt";
	ifstream  fin(fin_file);
	ofstream fout(fout_file);

	vector <bool> is_empty;
	string str;
	while (getline(fin, str)) {
		if (!str[0]) {
			is_empty.push_back(true);
		}
		else {
			int j = 0;
			while (str[j] == ' ') {
				++j;
			}
			if (j == str.length()) {
				is_empty.push_back(true);
			}
			else {
				is_empty.push_back(false);
			}
		}
	}

	for (int i = 0; i < is_empty.size(); i++){
		if (is_empty[i]) {
			int start_line = i + 1;
			fout << "from line " << start_line;
			while (i < is_empty.size() && is_empty[i]) {
				++i;
			}
			fout << " to line " << i << " ----- " << " number of lines: " << i + 1 - start_line << '\n';
		}
	}
	fin.close();
	fout.close();

	cout << "press 'y' if you want to see data in INPUT file\n";
	if (_getch() == 'y') {
		cout << "input:\n";
		showDataInFile(fin_file);
	}
	cout << "press 'y' if you want to see data in OUTPUT file\n";	
	if (_getch() == 'y') {
		cout << "output:\n";
		showDataInFile(fout_file);
	}
}