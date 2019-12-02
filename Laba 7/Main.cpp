#include "Functions.h"
int Student::identifier = 1000;
int main() {
	srand(time(0));
	vector<StudentAfterSecondSession> stream;
	stream.push_back(StudentAfterSecondSession((char*)"A", 1, 4, 1923100, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"B", 1, 4, 1923101, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"C", 1, 4, 1923102, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"D", 1, 4, 1923103, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"E", 1, 3, 1923104, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"F", 1, 3, 1923105, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"G", 1, 3, 1923106, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"H", 1, 2, 1923107, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"J", 1, 2, 1923108, randMarks(4), randMarks(5)));
	stream.push_back(StudentAfterSecondSession((char*)"K", 1, 1, 1923109, randMarks(4), randMarks(5)));
	cout << averageMarkOfTheGroupAfterFIRSTsess(stream, 4) << '\n';
	cout << averageMarkOfTheGroupAfterSECONDsess(stream, 4) << '\n';
	
	vector<Student*> students;
	students.push_back(new StudentAfterSecondSession((char*)"AA", 1, 4, 1923110, randMarks(4), randMarks(5)));
	students.push_back(new StudentAfterSecondSession((char*)"BB", 1, 2, 1923111, randMarks(4), randMarks(5)));
	students.push_back(new StudentAfterSecondSession((char*)"CC", 1, 1, 1923112, randMarks(4), randMarks(5)));
	students.push_back(new StudentAfterSecondSession((char*)"DD", 1, 4, 1923113, randMarks(4), randMarks(5)));
	students.push_back(new StudentAfterFirstSession((char*)"EE", 1, 5, 1923114, randMarks(4)));
	students.push_back(new StudentAfterFirstSession((char*)"FF", 1, 3, 1923115, randMarks(4)));
	students.push_back(new Student((char*)"GG", 1, 2, 1923100));
	cout << averageForAll(students);
}

