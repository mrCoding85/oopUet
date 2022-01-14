#include <ctime>
#include <cctype>
#include <bits/stdc++.h>
#include "draw.h"
#include "word.h"
#include "mode.h"
#include "guesser.h"

using namespace std;

int MAX_BAD_GUESSES=7;
const int MAX_HINT=2;

void standardMode()
{
        srand(time(0));
        bool choosing = true;
        int choice ;

        while ( choosing ){
            chooseDifficulty();
            int difficulty;
            cin >> difficulty;
            if ( difficulty < 1 || difficulty > 4){
                    cout<<"PLEASE ENTER AGAIN"<<endl;
                    this_thread::sleep_for(chrono::milliseconds(2000));
                    continue;
            }
            else {
                switch ( difficulty ){
                    case 1 : MAX_BAD_GUESSES = 7;
                            break;
                    case 2 : MAX_BAD_GUESSES = 5;
                            break;
                    case 3 : MAX_BAD_GUESSES = 3;
                            break;
                    case 4 : MAX_BAD_GUESSES = 1;
                            break;
;
                }
                choice = difficulty;
                break;
            }
        }

        string level=chooseLevel();
        string word = chooseWord_inClassicMode(level);
        string guessedWord = string(word.length(), '-');
        int badGuessCount = 0;
        int hintCount=2;
        double scorePlus=(level[level.length()-1]-'1')*5, scoreMinus=0;
        string charTyped="";
        double timePlayBegin=clock();

        do {
            renderStandardMode(guessedWord, badGuessCount,charTyped,choice);
            char guess = readAGuess();
            if (guess=='1')
            {
                if(guessWordImmediate(word))
                    {
                        scorePlus+=2;
                        break;}
                else{   badGuessCount=MAX_BAD_GUESSES;
                    break;}
            }
            else if(guess=='2')
            {
                if (hintCount>0)
                {
                    getHint(guessedWord,word,charTyped);
                    hintCount--;
                    scoreMinus+=1;
                    continue;
                }
                else {
                        cout <<"No hints are available!!!"<<endl;
                        this_thread::sleep_for(chrono::milliseconds(2000));
                        continue;
                    }
            }
            if(tryAnotherCharacter(charTyped,guess)){
                    cout<<"please try a different letter";
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    cout<<"\a\a"; continue;
            }
            charTyped+=guess;
            if (contains(word, guess))
                guessedWord = update(guessedWord, word, guess);
            else badGuessCount++;

        } while (badGuessCount < MAX_BAD_GUESSES && word != guessedWord);

        double timePlayEnd=clock();
        double totalTimePlay=(timePlayEnd-timePlayBegin)/CLOCKS_PER_SEC;
        double totalScore=0;

        displayResult_StandardMode(badGuessCount < MAX_BAD_GUESSES, word,badGuessCount);
        if (badGuessCount < MAX_BAD_GUESSES)
        {
            double totalScore=getScore(badGuessCount,totalTimePlay,scorePlus,scoreMinus);
            system("cls");
        }

}
void botGuessingMode()
{
    srand(time(0));
    int	wordLength;
    string	secretWord;
    int	incorrectGuess;
    set<char> previousGuesses;
    bool stop;

    initialize(wordLength,secretWord,incorrectGuess,previousGuesses,stop);
    render(incorrectGuess,previousGuesses,secretWord);

    do	{
        char	guess	=	getNextGuess(previousGuesses,	secretWord);
        if	(guess	==	0)	{
            cout	<<	"I give up,	hang me"	<<	endl;
            return ;
            }
        if (guess=='1') break;
        do	{
            try	{
                string	mask	=	getUserAnswer(guess);
                update(guess,	mask,	incorrectGuess,	previousGuesses,	secretWord,	stop);
                break;
                }
            catch	(invalid_argument	e)	{
            cout	<<	"Invalid mask, try again"	<<	endl;
												}
            }
        while	(true);
        render(incorrectGuess,	previousGuesses,	secretWord);
        }
    while	(!stop);
    playAnimationBotGuessing(incorrectGuess	==	MAX_BAD_GUESSES,	secretWord);
}

void keep_playing(string &play)
{
    cout<<"TRY AGAIN ? (YES/NO):"<<endl;
    cin>>play;
    play=getLowerCaseString(play);
    while (play!="yes"&&play!="no")
    {
        cin>>play;
        play=getLowerCaseString(play);
    }
}
