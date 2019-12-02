#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Class.h"
double averageMarkOfTheGroupAfterFIRSTsess(const vector <StudentAfterSecondSession>& stdnts, const int group_numb) {
	double sum = 0;
	int n = 0;
	for (auto& x : stdnts) {
		if (x.getGroup() == group_numb) {
			sum += x.StudentAfterFirstSession::averageMark();
			++n;
		}
	}
	return sum / n;
}

double averageMarkOfTheGroupAfterSECONDsess(const vector <StudentAfterSecondSession>& stdnts, const int group_numb) {
	double sum = 0;
	int n = 0;
	for (auto& x : stdnts) {
		if (x.getGroup() == group_numb) {
			sum += x.averageMark();
			++n;
		}
	}
	return sum / n;
}
double averageForAll(const vector<Student*>& students) {
	double sum = 0;
	int n = 0;
	for (auto& student : students) {
		sum += student->averageMark();
		++n;
	}
	return sum / n;
}
int* randMarks(const int n) {
	int* ans = new int[n] ;
	for (int i = 0; i < n; ++i) {
		ans[i] = rand() % 7 + 4;
	}
	return ans;
}
#endif // FUNCTIONS_H