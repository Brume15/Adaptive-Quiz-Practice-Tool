#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "Question.h"   // your Question class
#include "User.h"

using namespace std;

int main() {
    User player;
    string username;

    cout << "Enter your username:  ";
    cin >> username;
    player.setUsername(username);

    ifstream file("C:/Users/sufiy/CLionProjects/AdaptiveQuiz/BIO_Questions.txt");  // open your quiz file
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<Question> easyQuizQuestions;
    vector<Question> mediumQuizQuestions;
    vector<Question> hardQuizQuestions;

    string line;
    Question q;

    while (true) {
        // Read question text
        if (!getline(file, line)) break;
        if (line.empty()) continue;

        // Read answer choices
        q.setDifficulty(line);

        if (!getline(file, line)) break;
        q.setQuestion(line);

        // Read answer choices
        if (!getline(file, line)) break;
        q.setAnswerChoices(line);

        // Read correct answer
        if (!getline(file, line)) break;
        if (!line.empty()) {
            q.setCorrectAnswer(line[0]);   // first char of line
        }

        // Read topic (skip blank lines)
        do {
            if (!getline(file, line)) break;
        } while (line.empty());

        q.setTopic(line);


        if (q.getDifficulty() == "EASY") {
            easyQuizQuestions.push_back(q);
        }
        else if (q.getDifficulty() == "MEDIUM") {
            mediumQuizQuestions.push_back(q);
        }
        else if (q.getDifficulty() == "HARD") {
            hardQuizQuestions.push_back(q);
        }

        // Skip possible blank line between questions
        getline(file, line);
    }

    file.close();

    // The topics print
    int numberOfQuestionsAsked = 0;
    set<string> topics;

    for (int i = 0; i < easyQuizQuestions.size(); i++) {
        topics.insert(easyQuizQuestions[i].getTopic());
    }
    for (int i = 0; i < mediumQuizQuestions.size(); i++) {
        topics.insert(mediumQuizQuestions[i].getTopic());
    }
    for (int i = 0; i < hardQuizQuestions.size(); i++) {
        topics.insert(hardQuizQuestions[i].getTopic());
    }

    //This prints out the topics list
    for (string topic : topics) {
        cout << "[ " << topic << " ]" << endl;
    }

    cout << "Pick a topic or select 'ALL' ()" << endl;

    string userTopic;
    cin.ignore();
    getline(cin, userTopic);


    // Here I make a new vector to store questions that have
    // the same topic as the one user answered
    if ((userTopic != "ALL")||(userTopic != "all")) {

    // ===== Build topic-specific question lists =====
    vector<Question> easyTopic;
    vector<Question> mediumTopic;
    vector<Question> hardTopic;

    for (int i = 0; i < easyQuizQuestions.size(); i++) {
        if (userTopic == easyQuizQuestions[i].getTopic()) {
            easyTopic.push_back(easyQuizQuestions[i]);
        }
    }

    for (int i = 0; i < mediumQuizQuestions.size(); i++) {
        if (userTopic == mediumQuizQuestions[i].getTopic()) {
            mediumTopic.push_back(mediumQuizQuestions[i]);
        }
    }

    for (int i = 0; i < hardQuizQuestions.size(); i++) {
        if (userTopic == hardQuizQuestions[i].getTopic()) {
            hardTopic.push_back(hardQuizQuestions[i]);
        }
    }

    // ===== Ask topic-specific questions =====
    string currentDifficulty = "EASY";
    int easyIndex = 0;
    int mediumIndex = 0;
    int hardIndex = 0;

    while (easyIndex < easyTopic.size() ||
           mediumIndex < mediumTopic.size() ||
           hardIndex < hardTopic.size()) {

        Question p;
        bool picked = false;

        if (currentDifficulty == "EASY" && easyIndex < easyTopic.size()) {
            p = easyTopic[easyIndex++];
            picked = true;
        }
        else if (currentDifficulty == "MEDIUM" && mediumIndex < mediumTopic.size()) {
            p = mediumTopic[mediumIndex++];
            picked = true;
        }
        else if (currentDifficulty == "HARD" && hardIndex < hardTopic.size()) {
            p = hardTopic[hardIndex++];
            picked = true;
        }

        // Switch difficulty if empty
        if (!picked) {
            if (easyIndex < easyTopic.size()) currentDifficulty = "EASY";
            else if (mediumIndex < mediumTopic.size()) currentDifficulty = "MEDIUM";
            else if (hardIndex < hardTopic.size()) currentDifficulty = "HARD";
            else break;
            continue;
        }

        // If EASY questions are exhausted and user is still at EASY, stop quiz
        if (currentDifficulty == "EASY" && easyIndex >= easyTopic.size() && !(mediumIndex >= mediumTopic.size()) && !(hardIndex >= hardTopic.size())) {
            cout << endl;
            cout << "You have completed all EASY questions for this topic." << endl;
            cout << "Please review this topic before continuing." << endl;
            break;
        }


        // Ask question
        char answer;
        cout << p.getQuestion() << endl;
        cout << p.getAnswerChoices() << endl;
        cin >> answer;

        numberOfQuestionsAsked++;

        if (answer == p.getCorrectAnswer()) {
            cout << "Correct answer!" << endl;
            player.addCorrectAnswers();

            if (currentDifficulty == "EASY") currentDifficulty = "MEDIUM";
            else if (currentDifficulty == "MEDIUM") currentDifficulty = "HARD";
        }
        else {
            cout << "Wrong answer!" << endl;
            player.addWrongAnswers();
            player.addWrongQuestions(p);

            if (currentDifficulty == "HARD") currentDifficulty = "MEDIUM";
            else if (currentDifficulty == "MEDIUM") currentDifficulty = "EASY";
        }
    }

    // ===== Retry missed questions =====
    if (player.getNumCorrectAnswers() != numberOfQuestionsAsked) {
        char choice;
        cout << "Would you like to try your missed questions? [Y/N]" << endl;
        cin >> choice;

        if (choice == 'Y') {
            while (!player.getWrongQuestions().empty()) {
                vector<Question> wrongs = player.getWrongQuestions();
                player.clearWrongQuestions();

                for (int i = 0; i < wrongs.size(); i++) {
                    cout << wrongs[i].getQuestion() << endl;
                    cout << wrongs[i].getAnswerChoices() << endl;

                    char userAnswer;
                    cin >> userAnswer;

                    if (userAnswer == wrongs[i].getCorrectAnswer()) {
                        cout << "Correct answer!" << endl;
                        player.addRetryCorrectAnswers();
                    }
                    else {
                        cout << "Wrong answer!" << endl;
                        player.addRetryWrongAnswers();
                        player.addWrongQuestions(wrongs[i]);
                    }
                }
            }
        }
    }
}

    // This else statement happens when the user selects "ALL"
    else {

        // When user selects "ALL" this code happens
        string currentDifficulty = "EASY";
        int easyIndex = 0;
        int mediumIndex = 0;
        int hardIndex = 0;

        while (easyIndex < easyQuizQuestions.size() ||
               mediumIndex < mediumQuizQuestions.size() ||
               hardIndex < hardQuizQuestions.size()) {

            Question p;

            if (currentDifficulty == "EASY" && easyIndex < easyQuizQuestions.size()) {
                p = easyQuizQuestions[easyIndex++];
            }
            else if (currentDifficulty == "MEDIUM" && mediumIndex < mediumQuizQuestions.size()) {
                p = mediumQuizQuestions[mediumIndex++];
            }
            else if (currentDifficulty == "HARD" && hardIndex < hardQuizQuestions.size()) {
                p = hardQuizQuestions[hardIndex++];
            }
            else {
                break; // no more questions at this level
            }

            // Ask the question
            char answer;

            cout << p.getQuestion() << endl;
            numberOfQuestionsAsked++;
            cout << p.getAnswerChoices() << endl;
            cin >> answer;

            if (answer == p.getCorrectAnswer()) {
                cout << "Correct answer!" << endl;
                player.addCorrectAnswers();

                // Move up difficulty
                if (currentDifficulty == "EASY") currentDifficulty = "MEDIUM";
                else if (currentDifficulty == "MEDIUM") currentDifficulty = "HARD";
            }
            else {
                cout << "Wrong answer!" << endl;
                player.addWrongAnswers();
                player.addWrongQuestions(p);

                // Move down difficulty
                if (currentDifficulty == "HARD") currentDifficulty = "MEDIUM";
                else if (currentDifficulty == "MEDIUM") currentDifficulty = "EASY";
            }
        }

        if (player.getNumCorrectAnswers() == numberOfQuestionsAsked - 1) {
            ;
        }
        else {
            char choice;
            cout << "Would you like to try your missed questions? [Y/N]" << endl;
            cin >> choice;

            if (!(choice == 'N' || choice == 'Y')) {
                cout << "Invalid" << endl;
            }
            else if (choice == 'Y') {
                while (!player.getWrongQuestions().empty()) {
                    vector<Question> wrongs = player.getWrongQuestions();
                    player.clearWrongQuestions();

                    for (int i = 0; i < wrongs.size(); i++) {
                        cout << wrongs[i].getQuestion() << endl;
                        cout << wrongs[i].getAnswerChoices() << endl;

                        char userAnswer;
                        cin >> userAnswer;

                        if (userAnswer == wrongs[i].getCorrectAnswer()) {
                            cout << "Correct answer!" << endl;
                            player.addRetryCorrectAnswers();
                        }
                        else {
                            cout << "Wrong answer!" << endl;
                            player.addRetryWrongAnswers();
                            player.addWrongQuestions(wrongs[i]);
                        }
                    }
                }
            }
        }
    }

    // end display is here

    cout << endl;
    cout << "User: " << player.getUsername() << endl;
    cout << endl;
    cout << "Total number of questions: " << numberOfQuestionsAsked << endl;
    cout << "Correct answers: " << player.getNumCorrectAnswers() << endl;
    cout << "Wrong answers: " << player.getNumWrongAnswers() << endl;
    cout << endl;
    cout << "Retry correct answers: " << player.getNumRetryCorrectAnswers() << endl;
    cout << "Retry wrong answers: " << player.getNumRetryWrongAnswers() << endl;

    return 0;
}
