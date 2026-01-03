#include "Question.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Question::Question() {}

Question::Question(string t, vector<string> c, int correct, string d)
    : text(t), choices(c), correctIndex(correct), difficulty(d) {}

map<string, vector<Question>> fetch_file_Question(const string &file_name)
{
    ifstream file(file_name);
    map<string, vector<Question>> bank;

    if (!file)
    {
        cout << "File not opening...\n";
        return bank;
    }

    string line, currentTopic;
    Question q;

    while (getline(file, line))
    {
        if (line.rfind("Topic:", 0) == 0)
        {
            currentTopic = line.substr(7);
        }
        else if (line.rfind("QUESTION:", 0) == 0)
        {
            q = Question();
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
std::string Question::user_Interest_topic()
{
    //     cout << "Topic of interest: " << text << endl;
    //     cout << "Topics available: " << endl;
    //     cout << "1) Math" << endl;
    //     cout << "2) Computer Science" << endl;
    //     cout << "3) History" << endl;
    //     cout << "4) Geography" << endl;
    //     cout << "5) Programming" << endl;
    //     cout << "6) Science" << endl;
    //     cout << "7) Sports" << endl;

    string user_topic;
    cout << "Enter your topic of interest: ";
    getline(cin, user_topic);
    cout << "You selected: " << user_topic << endl;
    if (user_topic == "Math")
    {
        return "Math";
    }
    else if (user_topic == "Computer Science")
    {
        return "Computer Science";
    }
    else if (user_topic == "History")
    {
        return "History";
    }
    else if (user_topic == "Geography")
    {
        return "Geography";
    }
    else if (user_topic == "Programming")
    {
        return "Programming";
    }
    else if (user_topic == "Science")
    {
        return "Science";
    }
    else if (user_topic == "Sports")
    {
        return "Sports";
    }
    else
    {
        cout << "Invalid topic selected. Defaulting to 'General'.\n";
        return "General";
    }
}

void Question::displayQuestion() const
{
    cout << text << endl;
    for (int i = 0; i < choices.size(); i++)
    {
        cout << i + 1 << ") " << choices[i] << endl;
    }
    cout << "<Enter your answer (1-" << choices.size() << "): ";
    int userAnswer;
    cin >> userAnswer;
    if (checkQuestion(userAnswer - 1))
        cout << "Correct!\n";
    else
        cout << "Incorrect.\n";
    cout << endl;
}

bool Question::checkQuestion(int userIndex) const
{
    return userIndex == correctIndex;
}
