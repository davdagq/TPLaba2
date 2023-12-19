#pragma once
#include "fsstreams.h"
#include <iostream>

std::string vec_to_str(vector<char> vec)
{
	std::ostringstream os;
	std::string str;
	int n = vec.length();
	for (int i = 0; i < n; i++)
	{
		os << vec[i];
	}
	str = os.str();
	return str;
}

vector<std::string> sent_seperate(std::ifstream& fin)
{
	vector<char> sentence;
	vector<std::string> sentences;
	char c;
	bool flag = false;
	while ((c = fin.get()) != EOF)
	{
		if (c == ' ' && sentence.length() == 0)
		{
			continue;
		}
		if ((c < 'A' || c > 'Z') && sentence.length() == 0)
		{
			flag = true;
		}
		if (c != '\n' && flag == false)
		{
			sentence.push_back(c);
		}
		if (c == '.' || c == '?' || c == '!')
		{
			sentences.push_back(vec_to_str(sentence));
			sentence.clear();
			flag = false;
		}
	}
	return sentences;
}

vector<std::string> word_seperate(std::string text)
{
	std::istringstream is(text);
	vector<char> word;
	vector<std::string> words;
	char c;
	while ((c = is.get()) != EOF)
	{
		if (c == ' ' || c == '.' || c == '?' || c == '!' || c == ',' || c == ':' || c == ';' || c == '(' || c == ')' ||
			c == '\'' || c == '\"' || c == '\n' || c == '\0')
		{
			if (word.length() != 0)
			{
				words.push_back(vec_to_str(word));
				word.clear();
			}
			continue;
		}
		word.push_back(c);
	}
	return words;
}

bool checker(vector<std::string> words, std::string word)
{
	bool eqflag;
	int n = words.length();
	int k = (int)word.length();
	for (int i = 0; i < n; i++)
	{
		eqflag = true;
		if (k == words[i].length())
		{
			for (int j = 0; j < k; j++)
			{
				if (word[j] != words[i][j] && word[j] + ('a' - 'A') != words[i][j] && word[j] - ('a' - 'A') != words[i][j])
				{
					eqflag = false;
					break;
				}
			}
			if (eqflag)
			{
				return eqflag;
			}
		}
	}
	return false;
}

vector<std::string> text_process(std::ifstream& fin, std::string word)
{
	vector<std::string> sentences = sent_seperate(fin);
	vector<std::string> good_sentences;
	int n = sentences.length();
	for (int i = 0; i < n; i++)
	{
		if (checker(word_seperate(sentences[i]), word))
		{
			good_sentences.push_back(sentences[i]);
		}
	}
	return good_sentences;
}