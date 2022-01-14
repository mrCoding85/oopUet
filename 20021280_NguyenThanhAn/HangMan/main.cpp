#include <ctime>
#include <cctype>
#include<bits/stdc++.h>
#include <conio.h>
#include"mode.h"
using namespace std;

void playGame(const int &mode);

int main()
{

    cout << "PRESS ANY KEYS TO CONTINUE.\n";
    getch();
    gameIntro();
    bool playing = true;

    while (playing)
    {
        system("cls");
        mainMenu();         //render menu chinh cua game
        int mode;
        cin>>mode;          //chon che do choi
        if(mode <1||mode>4)
        {
            cout<<"PLEASE TRY AGAIN!!!"<<endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            continue;

        }

        if (mode==3){     //xem credit
            credit();
            cout<<"Press any keys to continue."<<endl;
            getch();
            continue;
        }

        if (mode==4) break;  //thoat khoi tro choi

        string play="yes";
        while (play=="yes")
        {
            playGame(mode);
            keep_playing(play);
        }

    }
    gameOutTro(); // see you next time!!
}
void playGame(const int &mode) // chon che do
{
    switch(mode)
    {
        case 1:{ // che do nguoi doan, may nghi

            ruleOfStandardMode();
            standardMode();
            break;
        }
        case 2: {  //che do may doan, nguoi nghi

            ruleOfBotGuessingMode();
            botGuessingMode();
            break;
        }
        default:{return;}
    }
}


