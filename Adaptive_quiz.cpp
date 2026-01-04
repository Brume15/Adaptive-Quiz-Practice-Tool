#include "Question.h"
#include "loadingFileQuestions.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

int main()
{

    auto bank = fetch_file_Question("quizTextFile.txt");
    cout << "1) Math" << endl;
    cout << "2) Computer Science" << endl;
    cout << "3) History" << endl;
    cout << "4) Geography" << endl;
    cout << "5) Programming" << endl;
    cout << "6) Science" << endl;
    cout << "7) Sports" << endl;
    string userTopic;
    cout << "Enter topic: ";
    getline(cin, userTopic);

    if (bank.find(userTopic) == bank.end())
    {
        cout << "No such topic.\n";
        return 0;
    }

    for (const auto &q : bank[userTopic])
    {
        q.displayQuestion();

        int answer;
        cout << "Your answer: ";
        cin >> answer;

        if (q.checkQuestion(answer - 1))

            cout << "Correct!\n\n";
        else
            cout << "Wrong!\n\n";
    }
    return 0;
}
