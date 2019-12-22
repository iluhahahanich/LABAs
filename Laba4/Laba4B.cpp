#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int length(char* str) {
	int n = 0;
	while (str[n]) {
		++n;
	}
	return n;
}
bool is_number(char* str) {
	bool is_numb = true;
	int i = 0;
	while (str[i]) {
		if (str[i] < '0' || str[i] > '9') {
			is_numb = false;
			break;
		}
		++i;
	}
	return is_numb;
}
bool is_palindrome(char* str) {
	bool is_pal = true;
	int n = length(str);
	for (int i = 0; i < n / 2; ++i) {
		if (str[i] != str[n - 1 - i]) {
			is_pal = false;
			break;
		}
	}
	return is_pal;
}
int main() {
	ifstream in("input.txt");
	ofstream out("output.txt");
	char line[301], str[301]; 
	while (in.getline(line, 301)) {
		char tmp[301] = "there is no palindromes";
		int i = 0;
		int count = 0;
		while (line[i] && count < 2) {
			int length = 0;
			while (line[i] != ' ' && line[i]) {
				str[length] = line[i];
				++i;
				++length;
			}
		    str[length] = '\0';

			if (is_number(str)) {
				if (is_palindrome(str)) {
					++count;
					for (int i = 0; i < length; i++) {  
						tmp[i] = str[i];
					}
					tmp[length] = '\0';
				}
			}
			while (line[i] == ' ') {
				++i;
			}
		}
		out << tmp <<'\n';
	}
in.close();
out.close();
}