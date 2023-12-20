#include "fsstreams.h"
#include "student.h"
#include <iostream>

double get_arithm_score(Student stud);
void student_bubble_sort(vector<Student>& studs);
bool check_45(Student stud);
bool cin_error_check(std::istream& cin);
void show_students(const vector<Student>& stud);
bool student_menu(Student& stud);
bool iostream_menu(vector<Student>& studs);
bool fsstreams_menu(std::ifstream& fin);
bool menu();

int main(void)
{
	while (menu()) {};
	return 0;
}

double get_arithm_score(Student stud)
{
	vector<int> scores = stud.getScore();
	int sr = 0, N = scores.length();
	double ret;
	for (int i = 0; i < N; i++)
	{
		sr += scores[i];
	}
	ret = (double)sr / (double)N;
	return ret;
}

void student_bubble_sort(vector<Student>& studs)
{
	Student buff;
	bool bubbleflag;
	int n = studs.length();
	for (int i = 0; i < n; i++)
	{
		bubbleflag = true;
		for (int j = 0; j < n - 1; j++)
		{
			if (get_arithm_score(studs[j]) > get_arithm_score(studs[j + 1]))
			{
				buff = studs[j];
				studs[j] = studs[j + 1];
				studs[j + 1] = buff;
				bubbleflag = false;
			}
		}
		if (bubbleflag)
		{
			return;
		}
	}
}

bool check_45(Student stud)
{
	int n = stud.getScore().length();
	for (int i = 0; i < n; i++)
	{
		if (stud.getScore()[i] != 4 && stud.getScore()[i] != 5)
		{
			return false;
		}
	}
	return true;
}

/*
	bool check_45(Student stud)
{
	bool fiveflag = false;
	bool fourflag = false;
	int n = stud.getScore().length();
	for (int i = 0; i < n; i++)
	{
		if (stud.getScore()[i] == 4)
		{
			fourflag = true;
		} else
		if (stud.getScore()[i] == 5)
		{
			fiveflag = true;
		}
		if (fourflag && fiveflag)
		{
			return true;
		}
	}
	return false;
}
*/

bool cin_error_check(std::istream& cin)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
	return false;
}

bool menu()
{
	int answer;
	vector<Student> studs;
	std::ifstream fin;
	std::cout << "What part of program do you want to run?" << std::endl;
	std::cout << "\t1 - iostream" << std::endl;
	std::cout << "\t2 - fstream and sstream" << std::endl;
	std::cout << "\t0 - exit the program" << std::endl;
	std::cin >> answer;
	if (cin_error_check(std::cin))
	{
		std::cout << "Wrong answer" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	system("cls");
	switch (answer)
	{
	case 1:
		while (iostream_menu(studs)) {}
		break;
	case 2:
		while (fsstreams_menu(fin)) {}
		break;
	case 0:
		return false;
	}
	return true;
}

void show_students(const vector<Student>& stud)
{
	if (stud.length() == 0)
	{
		std::cout << "There is no students yet." << std::endl;
		return;
	}
	int n = stud.length();
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ". Student." << std::endl << stud[i] << std::endl;
	}
}

bool student_menu(Student& stud)
{
	int answer;
	std::string FIO_buf;
	int group_buf;
	vector<int> score_buf;
	char c;
	std::cout << stud << std::endl;
	std::cout << "What do you want to do with student?" << std::endl;
	std::cout << "\t1 - Change surname and initials" << std::endl;
	std::cout << "\t2 - Change group" << std::endl;
	std::cout << "\t3 - Change scores" << std::endl;
	std::cout << "\t0 - Exit the student menu" << std::endl;
	std::cin >> answer;
	if (cin_error_check(std::cin))
	{
		std::cout << "Wrong input" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	system("cls");
	switch (answer)
	{
	case 1:
		std::cout << "Old surname and initials: " << stud.getFIO() << std::endl;
		std::cout << "New surname and initials: ";
		std::cin.ignore();
		getline(std::cin, FIO_buf);
		stud >> FIO_buf;
		std::cout << "Successfully changed." << std::endl;
		system("pause");
		system("cls");
		break;
	case 2:
		std::cout << "Old group: " << stud.getGroup() << std::endl;
		std::cout << "New group: ";
		std::cin >> group_buf;
		if (cin_error_check(std::cin))
		{
			group_buf = 0;
			std::cout << "Wrong input" << std::endl;
			system("pause");
			system("cls");
			return true;
		}
		stud >> group_buf;
		std::cout << "Successfully changed." << std::endl;
		system("pause");
		system("cls");
		break;
	case 3:
		std::cout << "Score: ";
		for (int i = 0; i < stud.getScore().length(); i++)
		{
			std::cout << stud.getScore()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "What do you want to do with scores?" << std::endl;
		std::cout << "1 - Add score" << std::endl;
		std::cout << "2 - Delete score" << std::endl;
		std::cout << "3 - Change all scores" << std::endl;
		std::cin >> answer;
		if (cin_error_check(std::cin))
		{
			std::cout << "Wrong input" << std::endl;
			system("pause");
			system("cls");
			return true;
		}
		system("cls");
		switch (answer)
		{
		case 1:
			std::cout << "Score: ";
			for (int i = 0; i < stud.getScore().length(); i++)
			{
				std::cout << stud.getScore()[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "Enter new score: ";
			std::cin >> answer;
			if (cin_error_check(std::cin))
			{
				std::cout << "Wrong input" << std::endl;
				system("pause");
				system("cls");
				return true;
			}
			if (answer >= 1 && answer <= 5)
			{
				stud.add_score(answer);
				std::cout << "Successfully added." << std::endl;
			}
			system("pause");
			system("cls");
			break;
		case 2:
			for (int i = 0; i < stud.getScore().length(); i++)
			{
				std::cout << i + 1 << ". " << stud.getScore()[i] << std::endl;
			}
			std::cout << "Which score need to be deleted?" << std::endl;
			std::cin >> answer;
			if (cin_error_check(std::cin) || answer < 1 || answer > stud.getScore().length())
			{
				std::cout << "Invalid number" << std::endl;
				system("pause");
				system("cls");
				return true;
			}
			stud.delete_score(answer - 1);
			std::cout << "Successfully deleted" << std::endl;
			system("pause");
			system("cls");
			break;
		case 3:
			std::cout << "Old scores: ";
			for (int i = 0; i < stud.getScore().length(); i++)
			{
				std::cout << stud.getScore()[i] << " ";
			}
			std::cout << std::endl;
			std::cout << "New scores: ";
			std::cin.ignore();
			while ((c = std::cin.get()))
			{
				if (c >= '1' && c <= '5')
				{
					score_buf.push_back(c - 48);
				}
				if (c == '\n')
				{
					break;
				}
			}
			stud >> score_buf;
			std::cout << "Successfully changed." << std::endl;
			system("pause");
			system("cls");
			break;
		}
		break;
	case 0:
		return false;
	}
	return true;
}

bool iostream_menu(vector<Student>& studs)
{
	int answer;
	Student buffer;
	std::string FIO_buf;
	int group_buf;
	vector<int> score_buf;
	char c;
	int k;
	bool flag45;
	show_students(studs);
	std::cout << "What do you want to do?" << std::endl;
	std::cout << "\t1 - Add Student object" << std::endl;
	std::cout << "\t2 - Choose Student" << std::endl;
	std::cout << "\t3 - Delete Student object" << std::endl;
	std::cout << "\t4 - Delete all Students" << std::endl;
	std::cout << "\t5 - Show only students with 4 or 5 scores" << std::endl;
	std::cout << "\t0 - Exit the iostream menu" << std::endl;
	std::cin >> answer;
	if (cin_error_check(std::cin))
	{
		std::cout << "Wrong answer" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	system("cls");
	switch (answer)
	{
	case 1:
		std::cout << "Enter surname & initials: ";
		std::cin.ignore();
		getline(std::cin, FIO_buf);
		std::cout << "Enter group: ";
		std::cin >> group_buf;
		if (cin_error_check(std::cin))
		{
			group_buf = 0;
		}
		std::cout << "Enter scores: ";
		std::cin.ignore();
		while ((c = std::cin.get()))
		{
			if (c >= '1' && c <= '5')
			{
				score_buf.push_back(c - 48);
			}
			if (c == '\n')
			{
				break;
			}
		}
		buffer >> FIO_buf >> group_buf >> score_buf;
		studs.push_back(buffer);
		student_bubble_sort(studs);
		std::cout << "Successfully added." << std::endl;
		system("pause");
		system("cls");
		break;
	case 2:
		show_students(studs);
		std::cout << "Enter the number of student:" << std::endl;
		std::cin >> answer;
		if (cin_error_check(std::cin) || answer < 1 || answer > studs.length())
		{
			std::cout << "Invalid number" << std::endl;
			system("pause");
			system("cls");
			return true;
		}
		system("cls");
		while (student_menu(studs[answer - 1])) {}
		student_bubble_sort(studs);
		break;
	case 3:
		show_students(studs);
		std::cout << "Enter the number of student you want to delete:" << std::endl;
		std::cin >> answer;
		if (cin_error_check(std::cin))
		{
			std::cout << "Invalid number" << std::endl;
			system("pause");
			system("cls");
			return true;
		}
		try {
			studs.pop(answer - 1);
			std::cout << "Successfully deleted" << std::endl;
		}
		catch (const vector_error& err) {
			std::cout << "Vector error: " << err.what() << std::endl;
		}
		system("pause");
		system("cls");
		break;
	case 4:
		studs.clear();
		std::cout << "Successfully deleted." << std::endl;
		system("pause");
		system("cls");
		break;
	case 5:
		k = 0;
		flag45 = false;
		for (int i = 0; i < studs.length(); i++)
		{
			if (check_45(studs[i]))
			{
				flag45 = true;
				std::cout << ++k << ". Student." << std::endl << studs[i] << std::endl;
			}
		}
		if (!flag45)
		{
			std::cout << "Where are no students with only 4 or 5 scores." << std::endl;
		}
		system("pause");
		system("cls");
		break;
	case 0:
		return false;
	}
	return true;
}

bool fsstreams_menu(std::ifstream& fin)
{
	std::string filename;
	std::string word;
	vector<std::string> sentences;
	int ans;
	std::cout << "Choose file by name: ";
	std::cin >> filename;
	std::cout << "Type word: ";
	std::cin >> word;
	fin.open(filename);
	if (!fin)
	{
		std::cout << "Cannot open this file" << std::endl;
		system("pause");
		system("cls");
		return true;
	}
	sentences = text_process(fin, word);
	int n = sentences.length();
	for (int i = 0; i < n; i++)
	{
		std::cout << sentences[i] << std::endl;
	}
	fin.close();
	std::cout << std::endl << "Continue?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - no" << std::endl;
	std::cin >> ans;
	system("cls");
	if (cin_error_check(std::cin))
	{
		return false;
	}
	if (ans == 1)
	{
		return true;
	}
	return false;;
}