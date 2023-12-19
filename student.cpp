#include "student.h"

Student::Student() {};
Student::Student(std::string FIO, int group, vector<int> score)
{
	this->FIO = FIO;
	this->group = group;
	this->score = score;
}
Student::Student(const Student& original)
{
	this->FIO = original.getFIO();
	this->group = original.getGroup();
	this->score = original.getScore();
}

Student::~Student() {}

std::string Student::getFIO() const
{
	return FIO;
}
int Student::getGroup() const
{
	return group;
}
vector<int> Student::getScore() const
{
	return score;
}

void Student::setFIO(std::string FIO)
{
	this->FIO = FIO;
}
void Student::setGroup(int group)
{
	this->group = group;
}
void Student::setScore(vector<int> score)
{
	this->score = score;
}

void Student::add_score(int grade)
{
	score.push_back(grade);
}
int Student::delete_score(int number)
{
	return score.pop(number);
}

Student& Student::operator= (const Student& original)
{
	this->FIO = original.getFIO();
	this->group = original.getGroup();
	this->score = original.getScore();
	return (*this);
}

std::ostream& operator<< (std::ostream& os, const Student& stud)
{
	os << "Surname & initials: " << stud.FIO << std::endl;
	os << "Group: " << stud.group << std::endl;
	os << "Scores:";
	for (int i = 0; i < stud.score.length(); i++)
	{
		os << " " << stud.score[i];
	}
	os << std::endl;
	return os;
}

Student& operator>> (Student& stud, std::string FIO)
{
	stud.setFIO(FIO);
	return stud;
}
Student& operator>> (Student& stud, int group)
{
	stud.setGroup(group);
	return stud;
}
Student& operator>> (Student& stud, vector<int> score)
{
	stud.setScore(score);
	return stud;
}