#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fileName = "";
    string word = "";
    int wordCounter = 0;
    int sentenceCounter = 0;
    int lastFilledPosition = -1;

    cout << "Enter a text file: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file)
    {
        cerr << "Can't open the file." << endl;
        return 1;
    }

    // first: count all words
    while (file >> word)
    {
        wordCounter++;
    }
    string wordList[wordCounter] = {};
    int wordListFrequencies[wordCounter] = {0};
    // maybe not the most memory efficient solution ... (better: use 'vector' or 'map')

    // reset file pointer to begin of the file
    file.clear();
    file.seekg(0, std::ios::beg);

    // read the file again
    while (file >> word)
    {
        // read chars of the word
        for (int i = 0; i < word.length(); i++) // length() or size() are aliases
        {
            // set to lower case
            word[i] = tolower(word[i]);

            // check if punctuation
            if (word[i] == '.' || word[i] == '?' || word[i] == '!' || word[i] == ',')
            {
                if (word[i] != ',')
                {
                    sentenceCounter++;
                }
                word[i] = '\0'; // remove punctuation
            }
        }

        // search word in word list
        bool found = false;
        for (int i = 0; i < lastFilledPosition + 1; i++)
        {
            if (wordList[i] == word)
            {
                found = true;
                wordListFrequencies[i]++; // update frequency
            }
        }

        // create new element in wordList and wordListFrequencies
        if (!found)
        {
            lastFilledPosition++;
            wordList[lastFilledPosition] = word;
            wordListFrequencies[lastFilledPosition]++;
        }
    }

    // output counters:
    cout << "Total words: " << wordCounter << endl
         << endl;
    cout << "Word frequency: " << endl;

    for (int i = 0; i <= lastFilledPosition; i++)
    {
        cout << wordList[i] << ": " << wordListFrequencies[i] << endl;
    }

    cout << endl;
    cout << "Total sentences: " << sentenceCounter << endl;

    file.close();
    return 0;
}
