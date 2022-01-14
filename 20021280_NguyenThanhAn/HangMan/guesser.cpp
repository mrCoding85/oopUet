
#include<bits/stdc++.h>
#include"guesser.h"
#include"draw.h"
#include"util.h"
#include"mode.h"
using namespace std;

const int MAX_GUESSES=7;

int getUserWordLength()
{
    int	wordLength;
    cout<<endl<<"Enter your word length: ";
    cin>>wordLength;
    return	wordLength;
}

void initialize(int &wordLength,string &secretWord,int &incorrectGuess,	set<char> &previousGuesses,bool &stop)
{
    wordLength=getUserWordLength();
    secretWord=string(wordLength,	'-');
    incorrectGuess=0;
    previousGuesses=set<char>();
    stop=false;
}


void render(int	incorrectGuess,const set<char>&previousGuesses,const string &secretWord)
{
    system("cls");
    cout<<endl<<"Incorrect guess =	"<<incorrectGuess<<"  previous guesses = ";
    for	(char c:	previousGuesses)
        cout<<c;
    cout<<"   secretWord = "<<secretWord<<endl;
    getDrawingBotGuessing(incorrectGuess);
}


char getNextGuess(const	set<char> &previousGuesses,string &secretWord)
{

    static	vector<string>	wordList = readWordListFromFile("botGuessingMode\\dictionary.txt");
    set <char> remainingChars = getRemainingChars(previousGuesses);

    if	(remainingChars.size()	==	0)
        return 0;
    if	(isAllDash(secretWord))
        return	getVowelGuess(remainingChars);
    vector<string>	filteredWordList = getSuitableWords(wordList, secretWord, remainingChars);
    if (filteredWordList.size()==0) {updateVocabulary(wordList); return 0;}
    if (filteredWordList.size()==1){
        if(!guessOnlyWord(filteredWordList[0]))
        {   updateVocabulary(wordList);
            return 0;}
        else {  secretWord=filteredWordList[0];
                return '1';}
    }
    map<char,int>	occurenceCount	=	getOccurenceCount(remainingChars,	filteredWordList);
     return	getMaxOccurenceChar(remainingChars,	occurenceCount);
}
vector<string>	getSuitableWords(const vector<string> &wordList,const string &secretWord,const set<char> &remainingChars)
{
    vector<string>	result;
    for	(const string&word : wordList)
        if(isSuitableWord(word,	secretWord,	remainingChars))
            result.push_back(word);
    return	result;
}
set<char>getRemainingChars(const set<char>&	previousGuesses)
{
        set<char>	remainingChars;
        for	(char c='a';c<=	'z';	c++)
                remainingChars.insert(c);
        for	(char c: previousGuesses)
            remainingChars.erase(c);
        return	remainingChars;
}

char selectRandomChar(const	set<char> &s)
{
    int	r=rand() % s.size();
    for	(char c: s)
    {
        if	(r--==	0)	return	c;
    }
    return	0;
}

string	getUserAnswer(char	guess)
{
    string	answer;
    cout<<endl<<"I guess "<<guess	<<	", please enter your mask: ";
    cin	>>	answer;
    transform(answer.begin(),	answer.end(),	answer.begin(),	::tolower);
    return	answer;
}

void update(char guess,const string &mask,	int &incorrectGuess,set<char> &previousGuesses,string &secretWord,	bool &stop)
{
    if	(!isGoodMask(guess,	mask,	secretWord))
        throw	invalid_argument("mistake entering answer");
    previousGuesses.insert(guess);
    if	(isAllDash(mask))
    {
        incorrectGuess	++;
        if	(incorrectGuess	==	MAX_GUESSES)	stop =  true;
    }	else{
            updateSecretWord(mask,	secretWord);
            if	(isAllNotDash(secretWord))	stop =  true;
        }
}
bool isGoodMask(char guess,const string &mask,const	string &secretWord)
{
    if	(mask.length()	!=	secretWord.length())	return false;
    for	(unsigned int i	= 0; i<secretWord.length() ;i++)
        if	(mask[i]	!=	'-')
        {
            if	(mask[i]	!=	guess)	return false;
            if	(secretWord[i]	!=	'-'	&&	secretWord[i]	!=	mask[i]) return false;
        }
    return true;
}

void updateSecretWord(const	string &mask, string &secretWord)
{
    for	(unsigned int i	= 0; i<secretWord.length() ;i++)
        if	(mask[i]	!=	'-')
            secretWord[i] = mask[i];
}
char getVowelGuess(const	set<char>&	remainingChars)
{
    char	vowel[]	=	{'e','a','o','i','u'};
    for	(char c:vowel)
    {
        if	(remainingChars.find(c)	!=	remainingChars.end())
        return	c;
    }
    return 0;
}

map <char,int> getOccurenceCount(const set<char> &remainingChars, const vector<string> &wordList)
{
    map <char,int> count;
    for	(char c: remainingChars)	count[c] = 0;
    for	(const string word:wordList)
    {
        for	(char c: word)
            if	(count.find(c)	!=	count.end())
                count[c]++;
    }
    return	count;
}
char getMaxOccurenceChar(const set<char> &remainingChars,const map <char,int> &count)
{
    char best=0;
    int	best_count=0;
    for	(auto	p: count)
        if	(p.second	>	best_count)	{
    best = p.first;
    best_count = p.second;
    }
    return	best;
}
bool guessOnlyWord(const string &word)
{
    cout<<" Your guessed word is  "<<word<<"  isn't it ?<yes/no>";
    string answer="";
    while (answer!="yes"&&answer!="no")
    {
        cin>>answer;
        answer=getLowerCaseString(answer);
    }
    if(answer=="yes") return true;
    else return false;

}
bool checkWordList(const vector <string> &wordList, const string &word)
{
    string str=getLowerCaseString(word);
    for (auto x:wordList )
        if (x==str)
        return false;
    return true;
}
void updateVocabulary(const vector<string> wordList)
{
    cout<<" can you help us to update our word list(YES/NO): "<<endl;
    string  word,answer="";
    while (answer!="yes"&&answer!="no")
    {
        cin>>answer;
       answer=getLowerCaseString(answer);
    }
    if (answer=="no") return;
    cout<<"your word:  ";
    cin>>word;
    if (checkWordList(wordList,word))
    {
        ofstream file("botGuessingMode\\dictionary.txt",ios::app);
        file<<word;
        file.close();
    }
    else cout<<"we already have this word ";


}
