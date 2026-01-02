
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
class Question
{
private:
    std::string text;
    std::vector<std::string> choices;
    int correctIndex;

public:
    Question(std::string t, std::vector<std::string> c, int correct);
    void displayQuestion() const;
    bool checkQuestion(int userIndex) const;
};

#endif