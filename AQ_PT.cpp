// This file contains the Class Definitions

#include "AQ_PT.h"

#include <iostream>
#include <string>
using namespace std;

void Question :: setQuestionText(string s) {
    questionText = s;
}

void Question :: setAnswerChoices(vector<string> choices) {
        answerChoices = choices;

}

void Question :: setexactAnswer(string e) {
    exactAnswer = e;
}

void Question :: setCorrectAnswerIndex(int a) {
    correctAnswerIndex = a;
}

bool Question :: ask() {
    cout << questionText << endl;
    for (int i = 0; i < answerChoices.size(); i++) {
        cout << "(" << (i + 1) <<") "
             << answerChoices[i] << endl;
    }
    int answer;
    string secondanswer;
    cout << "Your answer:";
    cin >> answer;
    secondanswer = to_string(answer);

    if (answer == correctAnswerIndex || secondanswer == exactAnswer) {
        return true;
    }
    else {
        return false;
    }

}
