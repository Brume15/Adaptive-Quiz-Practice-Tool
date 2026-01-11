#include <iostream>
#include <vector>
using namespace std;

class Question
{
private:
    string text;
    vector<string> choices;
    int correctAnswerIndex;

public:
    Question(string t, vector<string> c, int correctIndex)
    {
        text = t;
        choices = c;
        correctAnswerIndex = correctIndex;
    }

    bool askQuestion()
    {
        cout << text << endl;

        for (int i = 0; i < choices.size(); i++)
        {
            cout << i << ". " << choices[i] << endl;
        }

        int userAnswer;
        cout << "Enter the correct option number: ";
        cin >> userAnswer;

        if (userAnswer == correctAnswerIndex)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Question q1(
        "What is 2 + 2?",
        {"1", "2", "4", "5"},
        2);

    if (q1.askQuestion())
        cout << "Correct!" << endl;
    else
        cout << "Incorrect!" << endl;

    return 0;
}
