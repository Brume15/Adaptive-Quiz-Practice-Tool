#include "question.h"
#include "question_loader.h"

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
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

    string line, currentTopic, difficulty;
    Question q;
    vector<string> tempChoices;

    while (getline(open_file, line))
    {
        if (line.rfind("Topic:", 0) == 0)
        {
            q = Question(); // reset question
            currentTopic = line.substr(7);
            transform(currentTopic.begin(), currentTopic.end(), currentTopic.begin(), ::toupper);
            // cout << "Current Topic: " << currentTopic << endl;
            q.set_topic(currentTopic);
            tempChoices.clear();
        }
        else if (line.rfind("QUESTION:", 0) == 0)
        {
            q.set_text(line.substr(10));
        }
        else if (line.size() > 2 && line[1] == ')')
        {
            tempChoices.push_back(line.substr(3));
        }
        else if (line.rfind("ANSWER:", 0) == 0)
        {
            q.set_correctIndex(line.back() - 'A');
        }
        else if (line.rfind("DIFFICULTY:", 0) == 0)
        {
            difficulty = line.substr(12);
            q.set_difficulty(difficulty);
            // cout << "difficulty: " << difficulty << endl;
            q.set_choices(tempChoices);
            bank[currentTopic].push_back(q);
        }
    }
    return bank;
}
