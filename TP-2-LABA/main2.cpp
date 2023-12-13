#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    string text;

    if (inputFile) {

        while (getline(inputFile, text)) {

            size_t start = 0;
            // look for end of sentence
            size_t finish = text.find_first_of(".!?", start);
            //cout << text << endl;
            while (finish < text.size()) {

                if (finish != string::npos)
                {
                    // end of sentence was found, do something here.
                    //cout << start << ' ' << finish << endl;
                    string sentence = text.substr(start, finish - start + 1);
                    if (sentence[sentence.size() - 1] == '!' || sentence[sentence.size() - 1] == '?')
                        cout << sentence << endl;
                    // now find start of next sentence
                    start = text.find_first_not_of(" \t\n", finish + 1);
                    finish = text.find_first_of(".!?", start);
                }
            }
        }
    }
    return 0;
}