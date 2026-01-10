// loadingFileQuestions.h

#ifndef loadingQuestions_H
#define loadingQuestions_H

#include "Question.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<Question>> fetch_file_Question(const string &file_name);

#endif