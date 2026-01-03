#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>
#include <map>

// Forward declaration
std::map<std::string, std::vector<class Question>> fetch_file_Question(const std::string &file_name);

class Question
{
private:
    std::string text;
    std::vector<std::string> choices;
    int correctIndex;
    std::string difficulty;
    std::string topic;

public:
    Question(); // default constructor
    Question(std::string t,
             std::vector<std::string> c,
             int correct,
             std::string d,
             std::string topic);

    void displayQuestion() const;
    bool checkQuestion(int userIndex) const;

    std::string getTopic() const;

    friend std::map<std::string, std::vector<Question>> fetch_file_Question(const std::string &file_name);
};

#endif
