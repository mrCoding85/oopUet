#include <bits/stdc++.h>
#include <thread>
#include<chrono>
#include"draw.h"
#include <conio.h>
using namespace std;


void mainMenu()
{
    cout<<"MAIN MENU";cout<<"\n";
    this_thread::sleep_for(chrono::milliseconds(100));

    cout<<"1.CLASSIC MODE"<<endl;
    this_thread::sleep_for(chrono::milliseconds(70));
    cout<<"2.BOT VS HUMAN MODE"<<endl;
    this_thread::sleep_for(chrono::milliseconds(70));
    cout<<"3.CREDIT"<<endl;
    this_thread::sleep_for(chrono::milliseconds(70));
    cout<<"4.EXIT"<<endl << endl;
    this_thread::sleep_for(chrono::milliseconds(70));
    cout<<"Your choice : ";
}

const string INTRO[]={
       "|H    ||    A\\    |N\    | G|||||||  |M\    /|    A\\    |N\    |",
       "||    ||   /  \\   | \\   | |         | \\  / |   /  \\   | \\   |",
       "<+----+>  /----\\  |  \\  | |    =+=  |  \\/  |  /----\\  |  \\  |",
       "||    || /      \\ |   \\ | |     |   |      | /      \\ |   \\ |",
       "||    ||/        \\|    \\| ||||||||  |      |/        \\|    \\|",
       "                                                     THE_GAME        "

};
void gameIntro()
{
    int introduceCount=0;
    for (int i=0;i<7;i++)
    {
        cout<<INTRO[i]<<endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
    system("cls");
}

const string timeWar[]={

        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        "   |     \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n",

        " |--------------    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        " -----   \n",

};
const string FIGURE[] = {
        " |--------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        " |--------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
};

const string images[] = {

        "    O \n"
        "   /|\\ \n"
        "   | | \n",
        "    O \n"
        "   /|\\ \n"
        "   / \\ \n",
        " __O__ \n"
        "   | \n"
        "  / \\ \n",
        "  \\O/ \n"
        "   | \n"
        "  / \\ \n",
        " __O__ \n"
        "   | \n"
        "  / \\ \n",
        "   O \n"
        "  /|\\ \n"
        "  / \\ \n" ,
        "  O \n"
        "  /|\\ \n"
        "  / \\ \n" ,
        "   O \n"
        "  /|\\ \n"
        "  / \\ \n" ,
        "    O \n"
        "  /|\\ \n"
        "  / \\ \n" ,
        "   O \n"
        "  /|\\ \n"
        "  / \\ \n",
    " ------------- \n"
    " |          /   \n"
    " |         O   \n"
    " |        /|\\ \n"
    " |        / \\ \n"
    " |         \n"
    " ----- \n" ,
    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /|\\ \n"
    " |          / \\ \n"
    " |              \n"
    " ----- \n",
    " ------------- \n"
    " |            \\ \n"
    " |             O \n"
    " |            /|\\ \n"
    " |            / \\ \n"
    " | \n"
    " ----- \n",
    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /|\\ \n"
    " |          / \\ \n"
    " |              \n"
    " ----- \n"
};
void ruleOfStandardMode()
{
    system("cls");
    cout<<"INSERT 1 TO GUESS THE WORD IMMEDIATELY"<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"INSERT 2 TO USE A HINT"<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"YOU ONLY HAVE 2 CHANCES TO USE HINTS "<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"FOR EACH HINT YOU GET, YOUR SCORE WILL BE DECREASED BY 1"<<endl << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"Press any keys to continue." << endl;
    getch();
    system("cls");

}
void chooseDifficulty()
{
    system("cls");
    cout << "CHOOSE YOUR DIFFICULTY : " << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "1. EASY(7 LIFES)" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "2. NORMAL(5 LIFES)" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "3. HARD(3 LIFES)" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "4. INSANE(ONLY ONE LIFE)" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << "Your choice : " ;
}
void showDifficulty( int& choice )
{
    switch ( choice ){
        case 1 : cout << "Difficulty : Easy " << endl;
                break;
        case 2 : cout << "Difficulty : Medium " << endl;
                break;
        case 3 : cout << "Difficulty : Hard " << endl;
                break;
        case 4 : cout << "Difficulty : SUPER HARD" << endl;
                break;
    }

}
const string& getNextImage(const string images[], int imageCount, int n){

    static int currentFigure = 0;
    return images[(currentFigure++) % imageCount+n];
}
void renderStandardMode(const string& guessedWord,const int& badGuessCount, const string& charTyped, int& choice)
{
    system("cls");
    showDifficulty( choice );
	cout << FIGURE[badGuessCount] << endl;
	cout << guessedWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl;
	cout << "Letter you have typed " << charTyped<<endl;
}
void displayResult_StandardMode(bool won, const string& word, const int &badGuessCount)
{   double time_begin=clock();
    double time_end=clock();
    while ((time_end-time_begin)/CLOCKS_PER_SEC<10) {
        system("cls");
        if (won){
            cout << "Congratulations! You've won! || The word is "<< word <<endl;
            cout << "You saved the man!!\n";
            cout<<getNextImage(images,10,0);
        }
        else{
            cout << "You've lost. The correct word is " << word << endl;
            cout << getNextImage(images,4,10);
        }
        time_end=clock();
        this_thread::sleep_for(chrono::milliseconds(1000));

    }
}
double getScore(const int &badGuessCount,const double &totalTimePlay, const double &scorePlus,const double &scoreMinus )
{

    double totalScore=10-0.3*badGuessCount-0.01*totalTimePlay+scorePlus-scoreMinus;

    cout <<"You've spent " << totalTimePlay <<" seconds"<<endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    cout <<"Number of hints used : " << scoreMinus << endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    cout <<"Bonus score: " << scorePlus<<endl;
    this_thread::sleep_for(chrono::milliseconds(750));
    cout <<"Total score: "<<totalScore<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "Press any keys to continue." << endl;
    getch();

    return totalScore;
    system("cls");
}

void getDrawingBotGuessing(const int &incorrectGuess)
{
    cout << FIGURE[incorrectGuess]<<endl;
}
void ruleOfBotGuessingMode()
{
    system("cls");
    cout << "RULES : \n\n";
    cout <<"IN THIS MODE YOU ARE THE ONE CHOOSING THE WORD"<<endl;
    this_thread::sleep_for(chrono::milliseconds(700));
    cout <<"AND THE COMPUTER HAS 7 CHANCES TO GUESS YOURS"<<endl;
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << "You will choose the length of the word\n";
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << "For example :\nwhen the bot guesses 'a', you type in '-a--' if your word contains that letter and type in '----' if it doesn't \n";
    this_thread::sleep_for(chrono::milliseconds(700));
}
void playAnimationBotGuessing(bool	isLosing,	const	string&	word)
{
    system("cls");
    double time_begin=clock(),time_end=clock();

    while	((time_end-time_begin)/CLOCKS_PER_SEC<10)	{
        system("cls");
        if	(isLosing){
            cout<<endl<<"I've lost. My best word is: " << word <<endl;
            cout<<getNextImage(images,4,10);
        }
        else{
            cout<<endl<<"Haha,I win. The word is: " << word <<endl;
            cout<<getNextImage(images,10,0);
        }
            this_thread::sleep_for(chrono::milliseconds(500));
		time_end=clock();
    }
}
void fall_down()
{
    double time_begin=clock(), time_end=clock();
    int distance=1;
    while ((time_end-time_begin)/CLOCKS_PER_SEC<6)
    {
        system("cls");
        for (int i=0;i<distance;i++)
            cout<<endl;
        cout<<images[3];
        distance++;
        this_thread::sleep_for(chrono::milliseconds(400));
        time_end=clock();
    }
}
void gameOutTro()
{
    system("cls");
    cout<<"THANK YOU FOR PLAYING THE GAME !!!"<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}
void credit()
{
    system("cls");
    cout<<"NGO DUC BINH"<<endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    cout<<"ID: 20021494"<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}

