#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;


void renderStandardMode(const string& guessedWord,const int& badGuessCount, const string& charTyped, int& choice);
void displayResult_StandardMode(bool won, const string& word, const int &badGuessCount);
const string& getNextImage(const string images[], int imageCount, int n);
double  getScore(const int &badGuessCount,const double &totalTimePlay, const double &scorePlus,const double &scoreMinus );
void ruleOfStandardMode();
void renderBotGuessingMode(const string &yourWord, const string &computerGuessWord);
void ruleOfBotGuessingMode();
void gameIntro();
void gameOutTro();
void getDrawingBotGuessing(const int &incorrectGuess);
void playAnimationBotGuessing(bool isLosing,const string &word);
void fall_down();
void mainMenu();
void chooseDifficulty();
void showDifficulty( int& choice);
void credit();
