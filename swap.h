#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student {
public:
	string m_name;
	string m_des;
	int* scores;
	int *m_age;
	int ScoreCount;
public:
	Student();
	~Student();
	Student(int);
	Student(string,string);
	void setName(string);
	Student(const Student &st);
	void AddScoer(int scores);
	void ShowScore();
	 Student Compare(const Student& stu)const;
	int GetScores() const;
	//Student(Student st);
};
