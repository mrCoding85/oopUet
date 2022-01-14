#include<bits/stdc++.h>
using namespace std;

int getUserWordLength();
void initialize(int &wordLength,string &secretWord,int &incorrectGuess,	set<char> &previousGuesses,bool &stop);
void render(int	incorrectGuess,const set<char>&previousGuesses,const string &secretWord);
vector<string>	getSuitableWords(const vector<string> &wordList,const string &secretWord,const set<char> &remainingChars);
char getNextGuess(const	set<char> &previousGuesses, string &secretWord);
set<char>getRemainingChars(const set<char>&	previousGuesses);
char selectRandomChar(const	set<char> &s);
string	getUserAnswer(char	guess);
void update(char guess,const string &mask,	int &incorrectGuess,set<char> &previousGuesses,string &secretWord,	bool &stop);
bool isGoodMask(char guess,const string &mask,const	string &secretWord);
void updateSecretWord(const	string &mask, string &secretWord);
char getVowelGuess(const set<char>  &remainingChars);
map <char,int> getOccurenceCount(const set<char> &remainingChars, const vector<string> &wordList);
char getMaxOccurenceChar(const set<char> &remainingChars,const map <char,int> &count);
bool checkWordList(const vector <string> &wordList, const string &word);
bool guessOnlyWord(const string &word);
void updateVocabulary(const vector<string> wordList);
