
#include "Question.h"
#include <iostream>
// #include <string>

using namespace std;

int main()
{
    Question q1{
        "What is capital of Pakistan?",
        {"Rawalpindi", "Islamabad", "Lahore", "karachi"},
        2

    };

    q1.displayQuestion();
    cout << "Enter the correct Index: " << endl;
    int answer;
    cin >> answer;
    if (q1.checkQuestion(answer))
    {
        cout << "Correct " << endl;
    }
    else
    {
        cout << "Incorrect " << endl;
    }

    return 0;
}