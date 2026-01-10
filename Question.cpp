#include "Question.h"
#include <iostream>

using namespace std;
// Default constructor implementation for Question class
Question::Question()
    : correctIndex(0) {}

// Parameterized constructor Intialization List
Question::Question(string t,
                   vector<string> c,
                   int correct,
                   string d,
                   string topic)
    : text(t), choices(c), correctIndex(correct),
      difficulty(d), topic(topic) {}

void Question::displayQuestion() const
{
    cout << text << endl;
    for (int i = 0; i < choices.size(); i++)
    {
        cout << i + 1 << ") " << choices[i] << endl;
    }
}

bool Question::checkQuestion(int userIndex) const
{
    return userIndex == correctIndex;
}

string Question::getTopic() const
{
    return topic;
}

// void Question::calculate_topic_score() const
// {
//     // Implementation for calculating topic score

// }
// void Question::total_score() const
// {
//     // Implementation for calculating total score
// }