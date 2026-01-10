#include "Question.h"
// #include "loadingFileQuestions.cpp"
#include "loadingFileQuestions.h"
#include "QuizManaging.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{

    auto bank = fetch_file_Question("quizTextFile.txt");
    cout << "bank size: " << bank.size() << endl;
    cout << "Welcome to the Adaptive Quiz!\n";
    cout << "----------------------------------\n";

    cout << "Enter \"start\" to begin the quiz: ";
    string startInput;
    getline(cin, startInput);
    transform(startInput.begin(), startInput.end(), startInput.begin(), ::toupper);

    while (startInput == "START" && bank.size() > 0)
    {
        cout << "Starting the quiz...\n\n";
        cout << "1) Math" << endl;
        cout << "2) Computer Science" << endl;
        cout << "3) History" << endl;
        cout << "4) Geography" << endl;
        cout << "5) Programming" << endl;
        cout << "6) Science" << endl;
        cout << "7) Sports" << endl;
        string userTopic, userDifficulty;

        cout << "Enter topic: ";
        getline(cin, userTopic);
        transform(userTopic.begin(), userTopic.end(), userTopic.begin(), ::toupper);

        if (bank.find(userTopic) == bank.end())
        {
            cout << "No such topic.\n";
            return 0;
        }
        else
        {
            cout << "Enter difficulty (Easy, Medium, Hard): ";
            getline(cin, userDifficulty);

            transform(userDifficulty.begin(), userDifficulty.end(), userDifficulty.begin(), ::toupper);
            for (const auto &q : bank[userTopic])
            {

                if (q.Get_difficulty() == userDifficulty)
                {

                    vector<Question> selectedQuestions = {q};
                    QuizManaging quiz(selectedQuestions);
                    quiz.administerQuiz();
                    cout << "Your total score: " << quiz.getScore() << "\n";
                }
            }
        }
    }
    return 0;
}
