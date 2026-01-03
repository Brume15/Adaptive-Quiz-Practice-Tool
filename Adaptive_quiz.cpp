#include "Question.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{

    // Load from file
    map<string, vector<Question>> bank =
        fetch_file_Question("quizTextFile.txt");

    cout << "\nAvailable Topics:\n";
    for (auto &topic : bank)
    {
        cout << topic.first << " " << endl;
    }
    Question print_user_topic;
    print_user_topic.user_Interest_topic();

    // Question interested_topic;
    // string selected_topic = interested_topic.user_Interest_topic();

    return 0;
}
