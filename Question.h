//
// Created by sufiy on 12/15/2025.
//
#include <iostream>
using namespace std;

#ifndef ADAPTIVEQUIZ_QUESTIONS_H
#define ADAPTIVEQUIZ_QUESTIONS_H

class Question {
private:
    string question;
    string answerChoices;
    char correctAnswer;
    bool isCorrectAnswer;
    string difficulty;
    string topic;
public:
    Question() {
        question = "";
        answerChoices = "";
        isCorrectAnswer = false;
    };
    char getCorrectAnswer() {
        return correctAnswer;
    }
    string getQuestion() {
        return question;
    }
    void setQuestion(string Question) {
        question = Question;
    }
    void setCorrectAnswer(char answer) {
        correctAnswer = answer;
    }
    string getAnswerChoices() {
        return answerChoices;
    }
    void setAnswerChoices(string answers) {
        answerChoices = answers;
    }
    void setDifficulty(string diff) {
        difficulty = diff;
    }
    string getDifficulty() {
        return difficulty;
    }
    void setTopic(string name) {
        topic = name;
    }
    string getTopic() {
        return topic;
    }
    ~Question() {
    };
};


#endif //ADAPTIVEQUIZ_QUESTIONS_H