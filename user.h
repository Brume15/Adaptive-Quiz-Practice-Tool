//
// Created by Double G on 12/20/2025.
//

#ifndef ADAPTIVE_QUIZ___PRACTICE_TOOL_USER_H
#define ADAPTIVE_QUIZ___PRACTICE_TOOL_USER_H
// this is the user class file
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class User {
private:
    map <string, int> attemptsPerTopic;
    map <string, int> correctPerTopic;
public:
    void setAttemptAndCorrect(string topic, bool wasCorrect) {
        attemptsPerTopic[topic] += 1;
        if (wasCorrect == true) {
            correctPerTopic[topic] += 1;
        }
    }

    double getAccuracy(string topic) {
        if (attemptsPerTopic[topic] == 0) {
            return 0;
        }
        return (double) correctPerTopic[topic] / attemptsPerTopic[topic] * 100;
    }

    void showProgress() {
        cout << endl <<"----- User Progress -----" << endl;

        for (auto pair : attemptsPerTopic) {
            string topic = pair.first;
            int attempts = pair.second;
            int correct = correctPerTopic[topic];

            double accuracy = getAccuracy(topic);

            cout << "Topic: " << topic << endl;
            cout << "Attempts: " << attempts << endl;
            cout << "Correct: " << correct << endl;
            cout << "Accuracy: " << accuracy << "% " << endl << endl;
        }


    }
};
#endif //ADAPTIVE_QUIZ___PRACTICE_TOOL_USER_H