#include <bits/stdc++.h>
using namespace std;


string chooseWord_inClassicMode(const string &level);
char readAGuess();
bool contains(const string& word,const char& guess);
string update(string& guessedWord, const string& word, const char& guess);
string getLowerCaseString(const string& s);
string chooseLevel();
string chooseTopic(const string &level);
void getHint(string &guessedWord, const string &word,const string &charTyped);
bool tryAnotherCharacter(const string &charTyped, const char &guess);
bool guessWordImmediate(const string & word);
vector<string> readWordListFromFile(const string &nameFile);
