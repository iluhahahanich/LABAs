#include <iostream>
#include <fstream>
using namespace std;
char* myStrncat(char* strDest, const char* strSource, size_t count) {
	int last = 0;
	while (strDest[last]) {
		++last;
	}	
	int n = 0;
	while (n < count && strSource[n]) {
		strDest[last++] = strSource[n++];
	}
	strDest[last] = '\0';
	return strDest;
}
int main() {
	ifstream in("input.txt");       //in every line of input file must be TWO strings and ONE number
	ofstream out("output.txt");
	char str[301], strSource[301]; 
	int n;
	while (in >> str) {
		in >> strSource >> n;
		out << myStrncat(str, strSource, n) << '\n';
	}
	in.close();
	out.close();
}
