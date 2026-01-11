// loadingFileQuestions.h

#ifndef question_loader_H
#define question_loader_H

#include "question.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, vector<Question>> fetch_file_Question(const string &file_name);

#endif