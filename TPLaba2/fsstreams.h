#pragma once
#pragma once
#include <sstream>
#include <fstream>
#include <string>
#include "vector.h"

std::string vec_to_str(vector<char> vec);

vector<std::string> sent_seperate(std::ifstream& fin);

vector<std::string> word_seperate(std::string text);

bool checker(vector<std::string> words, std::string word);

vector<std::string> text_process(std::ifstream& fin, std::string word);