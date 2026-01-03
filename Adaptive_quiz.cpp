#include "Question.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
map<string, vector<Question>> fetch_file_Question(const string &file_name)
{
    ifstream open_file(file_name);
    map<string, vector<Question>> bank;

    if (!open_file)
    {
        cout << "File not opening...\n";
        return bank;
    }

    string line, currentTopic;
    Question q;

    while (getline(open_file, line))
    {
        if (line.rfind("Topic:", 0) == 0)
        {
            q = Question();
            currentTopic = line.substr(7);
            q.topic = currentTopic;
        }
        else if (line.rfind("QUESTION:", 0) == 0)
        {
            q.text = line.substr(10);
            q.choices.clear();
        }
        else if (line.size() > 2 && line[1] == ')')
        {
            q.choices.push_back(line.substr(3));
        }
        else if (line.rfind("ANSWER:", 0) == 0)
        {
            q.correctIndex = line.back() - 'A';
        }
        else if (line.rfind("DIFFICULTY:", 0) == 0)
        {
            q.difficulty = line.substr(12);
            bank[currentTopic].push_back(q);
        }
    }

    return bank;
}
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
