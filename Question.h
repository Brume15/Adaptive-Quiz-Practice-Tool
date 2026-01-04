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
    // Getters
    std::string Get_text() const { return text; };
    std::vector<std::string> Get_choices() const { return choices; };
    int Get_correctIndex() const { return correctIndex; };
    std::string Get_difficulty() const { return difficulty; };
    std::string Get_topic() const { return topic; };
    // Setters
    void set_text(const std::string &t) { text = t; };
    void set_choices(const std::vector<std::string> &c) { choices = c; };
    void set_correctIndex(int correct) { correctIndex = correct; };
    void set_difficulty(const std::string &d) { difficulty = d; };
    void set_topic(const std::string &t) { topic = t; };

    Question(std::string t,
             std::vector<std::string> c,
             int correct,
             std::string d,
             std::string topic);

    void displayQuestion() const;
    bool checkQuestion(int userIndex) const;

    std::string getTopic() const;

    // friend std::map<std::string, std::vector<Question>> fetch_file_Question(const std::string &file_name);
    // std::map<std::string, std::vector<class Question>> fetch_file_Question(const std::string &file_name);
};

#endif
