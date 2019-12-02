#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
class Student {
private:
	static int identifier;
	const int _id;
	char* _name;
	int _course;
	int _group;
	const int _stud_record_number;
	Student();
public:
	Student(char* name, int course, int group, int credit_number);
	Student(const Student& s);
	void setName(char* name);
	void setCourse(int course);
	void setGroup(int group);
	int getId() const;
	char* getName() const;
	int getCourse() const;
	int getGroup() const;
	int getRecordNumber() const;
	friend ostream& operator<< (ostream& out, const Student& s);
	virtual double averageMark() const;
};
class StudentAfterFirstSession : public Student {
private:
	int _fst_sess_marks[4];
	StudentAfterFirstSession();
public:
	StudentAfterFirstSession(char* name, int course, int group, int credit_number, int marks1[4]);
	StudentAfterFirstSession(const StudentAfterFirstSession& other);
	virtual double averageMark() const override;
	friend ostream& operator<< (ostream& out, const StudentAfterFirstSession& s);
	int getMark(const int numb_of_subj) const;
	void setMark(const int numb_of_subj, const int mark);
};
class StudentAfterSecondSession : public StudentAfterFirstSession {
private:
	int _sec_sess_marks[5];
	StudentAfterSecondSession();
public:
	StudentAfterSecondSession(char* name, int course, int group, int credit_number, int marks1[4], int marks2[5]);
	StudentAfterSecondSession(const StudentAfterSecondSession& other);
	double averageMark() const override;
	friend ostream& operator<< (ostream& out, const StudentAfterSecondSession& s);
	int getMark(const int numb_of_subj) const;
	void setMark(const int numb_of_subj, const int mark);
};
#endif  // CLASS_H