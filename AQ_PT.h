// This file contails the Class declarations
#ifndef ADAPTIVE_QUIZ___PRACTICE_TOOL_AQ_PT_H
#define ADAPTIVE_QUIZ___PRACTICE_TOOL_AQ_PT_H
#include <string>
#include <vector>
using namespace std;

class Question {
private:
    string questionText;
    vector<string> answerChoices;
    int correctAnswerIndex;
    string exactAnswer;
public:
    bool ask();
    void setQuestionText(string s);
    void setAnswerChoices(vector<string> choices);
    void setexactAnswer(string e);
    void setCorrectAnswerIndex(int a);



};

#endif //ADAPTIVE_QUIZ___PRACTICE_TOOL_AQ_PT_H