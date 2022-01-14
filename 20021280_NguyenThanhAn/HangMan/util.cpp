#include<bits/stdc++.h>
using namespace std;
bool isAllDash(const string &s)
{
    for	(char c: s)
        if	(c != '-')	return false;
    return true;

}
bool isAllNotDash(const	string &s)
{
    for	(char c: s)
        if	(c	==	'-')	return false;
    return true;
}
bool isSuitableWord(const string &word, const string &secretWord,const set<char> &remainingChars)
{
    if	(word.length()	!=	secretWord.length())	return false;
    for	(unsigned int i = 0; i < word.length();	i++)	{
        if	(secretWord[i]	!=	'-')
        {
            if	(tolower(word[i])	!=	tolower(secretWord[i]))	return false;
            }
        else if	(remainingChars.find(word[i])	==	remainingChars.end())
            return false;
				}
    return true;
}
