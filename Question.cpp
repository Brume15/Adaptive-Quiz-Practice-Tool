#include "Question.h"
#include <iostream>

using namespace std;
string user_topic;
cout << "Enter your topic of interest: ";
getline(cin, user_topic);
cout << "You selected: " << user_topic << endl;
cout << "Topic Based Quiz Questions:\n";
if (user_topic == "Math")
{
    for (const auto &question : math_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "Computer Science")
{
    for (const auto &question : cs_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "History")
{
    for (const auto &question : history_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "Science")
{
    for (const auto &question : science_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "Programming")
{
    for (const auto &question : programming_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "Sports")
{
    for (const auto &question : sports_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else if (user_topic == "Geography")
{
    for (const auto &question : geography_quiz)
    {
        question.displayQuestion();
        cout << endl;
    }
}
else
{
    cout << "No questions available for the selected topic.\n";
}
}

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
