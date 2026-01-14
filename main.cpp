// This is the Driver file
#include "AQ_PT.h"
#include "user.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {

    vector<Question> selectedQuestions;
    // key: string, value: vector of question class datatype
    map <string, vector<Question>> questionsBank;
    vector<Question> mathQuestions;
    vector<Question> scienceQuestions;


    Question q1, q2, q3;




    q1.setQuestionText("What is 18 + 2");
    vector<string> choice1 = {"50", "4", "20", "9", "15"};
    q1.setAnswerChoices(choice1);
    q1.setCorrectAnswerIndex(3);
    q1.setexactAnswer("20");

    q2.setQuestionText("What is 5 + 5: ");
    vector<string> choice2 = {"20", "50", "10", "11", "3"};
    q2.setAnswerChoices(choice2);
    q2.setCorrectAnswerIndex(3);
    q2.setexactAnswer("10");

    q3.setQuestionText("what is matter");
   vector<string> choice3 = {
        "Anything that has weight and occupy space",
        "The name of a person or place",
        "The force that pulls a body down to earth",
        "The president of America"
    };
    q3.setAnswerChoices(choice3);
    q3.setCorrectAnswerIndex(1);


    mathQuestions.push_back(q1);
    mathQuestions.push_back(q2);
    scienceQuestions.push_back(q3);

    //store quesitons in map vector
    questionsBank["Math"] = mathQuestions;
    questionsBank["Science"] = scienceQuestions;

    User user; // userclass object

    string selectedTopicName;




    string topic;
    do {
        cout << "Choose a topic: " << endl
             << "(1) Math" << endl
             << "(2) Science " << endl
             << "(3) Q to quit" << endl << endl;

        cout << "Your answer: ";
        cin >> topic;



        if (topic == "1" || topic == "Math") {
            selectedQuestions = questionsBank["Math"];
            selectedTopicName = "Math";
        }
        else if (topic == "2" || topic == "Science") {
            selectedQuestions = questionsBank["Science"];
            selectedTopicName = "Science";
        }
        else if (topic == "q" || topic == "Q") {
            cout << "Exiting quiz..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Try again" << endl << endl;
            continue;
        }




        for (int i = 0; i < selectedQuestions.size(); i++) {
            bool result = selectedQuestions[i].ask();
            if (result) {
                cout << "Correct!" << endl;
            }
            else {
                cout << "Incorrect!" << endl;
            }

            user.setAttemptAndCorrect(selectedTopicName, result);
            cout << endl << endl;
        }

    }while(true);

    user.showProgress();



    return 0;
}