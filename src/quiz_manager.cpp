
#include "quiz_manager.h"
#include "question.h"
#include <iostream>
using namespace std;

void QuizManaging::administerQuiz()
{
    for (const auto &question : total_questions)
    {
        question.displayQuestion();
        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (question.checkQuestion(userAnswer - 1))
        {
            currentScore++;
            correctAnswers++;
            topicScores[question.getTopic()]++;
            cout << "Correct!\n\n";
        }
        else
        {
            cout << "Wrong!\n\n";
        }
    }
}
