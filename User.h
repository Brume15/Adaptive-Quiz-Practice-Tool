//
// Created by sufiy on 12/15/2025.
//

#ifndef ADAPTIVEQUIZ_USER_H
#define ADAPTIVEQUIZ_USER_H
#include <string>
#include <iostream>
#include "Question.h"
#include <vector>
using namespace std;

class User {
private:
    string username;
    int numCorrectAnswers;
    int numWrongAnswers;
    int numRetryWrongAnswers;
    int numRetryCorrectAnswers;
    vector<Question> wrongQuestions; //push_back(value) //pop_back(value)
public:
    User() {
        username = "";
        numWrongAnswers = 0;
        numCorrectAnswers = 0;
        numRetryWrongAnswers = 0;
        numRetryCorrectAnswers = 0;
    }
    void setUsername(string name) {
        username = name;
    }
    string getUsername() {
        return username;
    }
    int getNumCorrectAnswers() {
        return numCorrectAnswers;
    }
    int getNumWrongAnswers() {
        return numWrongAnswers;
    }
    void addWrongAnswers() {
        numWrongAnswers++;
    }
    void addCorrectAnswers() {
        numCorrectAnswers++;
    }
    void addWrongQuestions(Question a) {
        wrongQuestions.push_back(a);
    }
    vector<Question> getWrongQuestions() {
        return wrongQuestions;
    }
    void clearWrongQuestions() {
        wrongQuestions.clear();
    }
    void addRetryWrongAnswers() {
        numRetryWrongAnswers++;
    }
    void addRetryCorrectAnswers() {
        numRetryCorrectAnswers++;
    }
    int getNumRetryWrongAnswers() {
        return numRetryWrongAnswers;
    }
    int getNumRetryCorrectAnswers() {
        return numRetryCorrectAnswers;
    }


};

#endif //ADAPTIVEQUIZ_USER_H