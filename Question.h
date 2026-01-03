#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Question
{
public:
    string text;
    vector<string> choices;
    int correctIndex;
    string difficulty;

    Question();
    Question(string t, vector<string> c, int correct, string d);
    string user_Interest_topic() const;
    void displayQuestion() const;
    bool checkQuestion(int userIndex) const;
};
// FILE LOADER (NOT a class member)
map<string, vector<Question>> fetch_file_Question(const string &file_name);
#endif
