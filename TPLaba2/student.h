#pragma once
#pragma once
#include <string>
#include <iostream>
#include "vector.h"

class Student {
public:
	Student();
	Student(std::string FIO, int group, vector<int> score);
	Student(const Student& original);

	~Student();

	std::string getFIO() const;
	int getGroup() const;
	vector<int> getScore() const;

	void setFIO(std::string FIO);
	void setGroup(int group);
	void setScore(vector<int> score);

	void add_score(int grade);
	int delete_score(int number);

	Student& operator= (const Student& original);

	friend std::ostream& operator<< (std::ostream& os, const Student& stud);

	friend Student& operator>> (Student& stud, std::string FIO);
	friend Student& operator>> (Student& stud, int group);
	friend Student& operator>> (Student& stud, vector<int> score);

private:
	std::string FIO;
	int group = 0;
	vector<int> score;
};