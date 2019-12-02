#include "Class.h"
Student::Student(char* name, int course, int group, int credit_number) 
	: _id(++identifier), _name(name), _course(course), _group(group), _stud_record_number(credit_number) {}

Student::Student(const Student& s) 
	: _id(s._id), _name(s._name), _course(s._course), _group(s._group), _stud_record_number(s._stud_record_number) {}

void Student::setName(char* name) {
	_name = name;
}
void Student::setCourse(int course) {
	_course = course;
}
void Student::setGroup(int group) {
	_group = group;
}
int Student::getId() const {
	return _id;
}
char* Student::getName() const {
	return _name;
}
int Student::getCourse() const {
	return _course;
}
int Student::getGroup() const {
	return _group;
}
int Student::getRecordNumber() const {
	return _stud_record_number;
}
double Student::averageMark() const{
	return 0;
}
ostream& operator<< (ostream& out, const Student& s) {
	out  << "name: " << s._name 
		<< "\nid: " << s._id 
		<< "\ncourse: " << s._course 
		<< "\ngroup: " << s._group 
		<< "\nstud record number: " << s._stud_record_number;
	return out;
}
ostream& operator<< (ostream& out, const StudentAfterFirstSession& s) {
	out << "name: " << s.getName() 
		<< "\nid: " << s.getId() 
		<< "\ncourse: " << s.getCourse() 
		<< "\ngroup: " << s.getGroup() 
		<< "\nstud record number: " << s.getRecordNumber()
		<< "\nfirst session marks: ";
	for (int i = 0; i <= 3; ++i) {
		out << s._fst_sess_marks[i] << " ";
	}
	return out;
}
ostream& operator<< (ostream& out, const StudentAfterSecondSession& s) {
	out << "name: " << s.getName()
		<< "\nid: " << s.getId()
		<< "\ncourse: " << s.getCourse()
		<< "\ngroup: " << s.getGroup()
		<< "\nstud record number: " << s.getRecordNumber()
		<< "\nfirst session marks: ";
	for (int i = 0; i <= 3; ++i) {
		out << s.StudentAfterFirstSession::getMark(i) << " ";
	}
	out << "\nsecond session marks: ";
	for (int i = 0; i <= 4; ++i) {
		out << s._sec_sess_marks[i] << " ";
	}
	return out;
}
StudentAfterFirstSession::StudentAfterFirstSession(char* name, int course, int group, int credit_number, int marks1[4])
	: Student(name, course, group, credit_number), _fst_sess_marks{ marks1[0], marks1[1], marks1[2], marks1[3] } {}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& other)
	: Student(other) {
	for (int i = 0; i < 4; i++) {
		_fst_sess_marks[i] = other._fst_sess_marks[i];
	}
}
int StudentAfterFirstSession::getMark(const int numb_of_subj) const {
	if (numb_of_subj < 4) {
		return _fst_sess_marks[numb_of_subj];
	}
}
void StudentAfterFirstSession::setMark(const int numb_of_subj, const int mark){
	if (numb_of_subj < 4) {
		_fst_sess_marks[numb_of_subj] = mark;
	}
}
int StudentAfterSecondSession::getMark(const int numb_of_subj) const {
	if (numb_of_subj < 5) {
		return _sec_sess_marks[numb_of_subj];
	}
}
void StudentAfterSecondSession::setMark(const int numb_of_subj, const int mark) {
	if (numb_of_subj < 5) {
		_sec_sess_marks[numb_of_subj] = mark;
	}
}
double StudentAfterFirstSession::averageMark() const {
	return (_fst_sess_marks[0] + _fst_sess_marks[1] + _fst_sess_marks[2] + _fst_sess_marks[3]) / 4;
}
StudentAfterSecondSession::StudentAfterSecondSession(char* name, int course, int group, int credit_number, int marks1[4], int marks2[5]) 
	: StudentAfterFirstSession(name, course, group, credit_number, marks1), _sec_sess_marks{ marks2[0], marks2[1], marks2[2], marks2[3], marks2[4] } {}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& other)
	: StudentAfterFirstSession(other) {
	for (int i = 0; i < 5; i++) {
		_sec_sess_marks[i] = other._sec_sess_marks[i];
	}
}
double StudentAfterSecondSession::averageMark() const {
	return (StudentAfterFirstSession::averageMark() * 4 + _sec_sess_marks[0] + _sec_sess_marks[1] + _sec_sess_marks[2] + _sec_sess_marks[3] + _sec_sess_marks[4]) / 9;
}
