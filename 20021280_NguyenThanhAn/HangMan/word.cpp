#include <bits/stdc++.h>
#include"word.h"
using namespace std;


string chooseLevel()
{
     vector <string> level_list =readWordListFromFile("standardMode\\level.txt");
    cout<< endl <<"THERE ARE "<<level_list.size()<<" LEVELS"<<endl;
    for (int i=0;i<level_list.size();i++)
    {
        cout<<i+1<<". "<<level_list[i]<<endl;
    }
    int level=0;
    while(level<1||level>level_list.size())
    {
        cout<<"Choose your level : ";
        cin>>level;
        if(level<1 || level>level_list.size())   cout<<"Please try again."<<endl;
    }
    return level_list[level-1];
}
string chooseTopic(const string &level)
{
    string file_topic="standardMode\\"+level+"\\level_topic.txt";
    vector<string> topic_list=readWordListFromFile(file_topic);
    cout<<endl<<"THERE ARE "<<topic_list.size()<<" TOPICS IN "<<level<<endl;
    for (int i=0;i<topic_list.size();i++)
    {
        cout<<i+1<<". "<<topic_list[i]<<endl;
    }
    int topic=0;

    while(topic<1||topic>topic_list.size())
    {   cout<<"Choose your topic: ";
        cin>>topic;
        if(topic<1||topic>topic_list.size())    cout<<"Please try again."<<endl;
    }

    return topic_list[topic-1];
}
vector<string> readWordListFromFile(const string &nameFile)
{
    ifstream file(nameFile);
    vector <string> wordList;
    if(file.is_open())
    {
        while (!file.eof())
        {
            if(file)
            {
                string word;
                file>>word;
                wordList.push_back(word);
            }
        }
    }
    file.close();
    return wordList;

}
string chooseWord_inClassicMode(const string &level)
{

    string topic=chooseTopic(level);
    string nameOfFile="standardMode\\"+level+ "\\" +topic+".txt";
    vector <string> wordlist=readWordListFromFile(nameOfFile);
    if(wordlist.size()>0){
        int randomIndex = rand() % wordlist.size();
        return getLowerCaseString(wordlist[randomIndex]);
    }
    else return "";
}

char readAGuess()
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return  tolower(input);
}

bool contains(const string& word,const char& c)
{
	return (word.find_first_of(c) != string::npos);
}

string update(string& guessedWord,const string& word, const char& guess)
{
	for (int i = word.length(); i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}
string getLowerCaseString(const string& s){
    string res=s;
    transform(s.begin(),s.end(),res.begin(),::tolower);
    return res;
}
void getHint(string &guessedWord, const string &word,const string &charTyped)
{
    set<char> arr;
    for (int i=0;i<word.size();i++)
    {
        if (guessedWord[i]=='-')
            arr.insert(word[i]);
    }
    int i=rand()%arr.size();
    char hint;
    for (char c: arr)
    {
        if (i-- ==0) {hint =c;break;}
    }

    for (int i=0;i<word.length();i++)
    {
        if(word[i]==hint)
            guessedWord[i]=hint;
    }
}
bool tryAnotherCharacter(const string &charTyped, const char &guess)
{
    for (int i=0;i<charTyped.length();i++)
        if(guess==charTyped[i]) return true;
    return false;
}

bool guessWordImmediate(const string & word)
{
    string word_immediate;
    cout<<"Word you guess immediately: ";
    cin>>word_immediate;
    word_immediate=getLowerCaseString(word_immediate);
    if(word!=word_immediate) return false;
    return true;
}


