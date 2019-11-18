#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <cmath>
#define PI atan(1) * 4
using namespace std;
vector<vector<int>> vectorsFromFile(string filename) {
	ifstream fin(filename);
	vector<vector<int>> a;
	int tmp;
	while (fin >> tmp) {
		int x1, x2, y1, y2;
		x1 = tmp;
		fin >> y1;
		fin >> x2;
		fin >> y2;
		a.push_back({ x1, y1, x2, y2 });
	}
	return a;
	fin.close();
}
double length(vector<int> coord) {
	return hypot(coord[1] - coord[3], coord[0] - coord[2]);
}
map<double, vector<vector<int>>> kollinGroups(vector<vector<int>> &a) {
	map<double,vector<vector<int>>> ans;
	for (auto& coord : a) {
		ans[acos((coord[2] - coord[0]) / length(coord))].push_back(coord);
	}
	return ans;
}
void getGroups(map<double, vector<vector<int>>>& a, string filename) {
	ofstream fout(filename);
	for (auto& mp : a) {
		for (auto& coord : mp.second) {
			fout << coord[0] << " " << coord[1] << " " << coord[2] << " " << coord[3] << "\n";
		}
		fout << '\n';
	}
	fout.close();
}

void mySort(vector<vector<int>>& a) {
	int d = a.size() / 2;
	while (d > 0) {
		for (int i = 0; i < a.size() - d; i++) {
			int j = i;
			while ((j >= 0) && (length(a[j]) > length(a[j + d]))) {
				swap(a[j], a[j + d]);
				j--;
			}
		}
		d = d / 2;
	}
}
int main() {
	vector<vector<int>> a = vectorsFromFile("vectors.txt");
	int numb_of_vectors = a.size();
	map<double, vector<vector<int>>> groups = kollinGroups(a);
	getGroups(groups, "vector_groups.txt");

	for (auto& gr : groups) {
		mySort(gr.second);
	}
	string filename = to_string(groups.size()) + "_groups_for_" + to_string(numb_of_vectors) + "_vectors.txt";
	getGroups(groups, filename);
}
