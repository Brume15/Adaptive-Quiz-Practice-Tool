#include "Question.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Test manual question
    // Question q1(
    //     "What is capital of Pakistan?",
    //     {"Rawalpindi", "Islamabad", "Lahore", "Karachi"},
    //     1,
    //     "EASY");

    // q1.displayQuestion();

    // int answer;
    // cin >> answer;

    // if (q1.checkQuestion(answer - 1))
    //     cout << "Correct\n";
    // else
    //     cout << "Incorrect\n";

    // Load from file
    map<string, vector<Question>> bank =
        fetch_file_Question("quizTextFile.txt");

    cout << "\nAvailable Topics:\n";
    for (auto &topic : bank)
    {
        cout << topic.first << " " << endl;
    }
    Question interested_topic;
    string selected_topic = interested_topic.user_Interest_topic();

    const vector<Question> math_quiz = bank["Math"];
    const vector<Question> cs_quiz = bank["Computer Science"];
    const vector<Question> history_quiz = bank["History"];
    const vector<Question> science_quiz = bank["Science"];
    const vector<Question> programming_quiz = bank["Programming"];

    const vector<Question> sports_quiz = bank["Sports"];
    const vector<Question> geography_quiz = bank["Geography"];

    cout << "Math Quiz Questions:\n";
    if (selected_topic == "Math")
    {
        for (const auto &question : math_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "Computer Science")
    {
        for (const auto &question : cs_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "History")
    {
        for (const auto &question : history_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "Science")
    {
        for (const auto &question : science_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "Programming")
    {
        for (const auto &question : programming_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "Sports")
    {
        for (const auto &question : sports_quiz)
        {
            question.displayQuestion();
            cout << endl;
        }
    }
    else if (selected_topic == "Geography")
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

    return 0;
}
