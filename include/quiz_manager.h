#ifndef QUIZ_MANAGING_H
#define QUIZ_MANAGING_H

#include <map>
#include <vector>
#include <string>
#include "question.h"
using namespace std;
class QuizManaging
{
private:
    vector<Question> total_questions;
    int currentScore;
    int correctAnswers;
    map<string, int> topicScores;

public:
    QuizManaging(const vector<Question> &qs) : total_questions(qs), currentScore(0), correctAnswers(0) {}
    void administerQuiz();
    int getScore() const { return currentScore; }
    // map<string, int> getTopicScores() const { return topicScores; }
};

#endif