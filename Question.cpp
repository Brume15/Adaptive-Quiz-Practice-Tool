#include "Question.h"
#include <iostream>

using namespace std;

Question::Question()
    : correctIndex(0) {}

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
