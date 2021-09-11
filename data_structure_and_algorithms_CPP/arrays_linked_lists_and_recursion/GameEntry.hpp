#ifndef GAMEENTRY_HPP
#define GAMEENTRY_HPP

#include<iostream>
using std::string;

class GameEntry {					// a game score entry
public:
	GameEntry(const string& n="", int s=0);	//ctor.
	string getName() const;			//get player game
	int getScore() const;				// get score

private:
	string name;					// player's name
	int score;					// player's score
	
};

GameEntry::GameEntry(const string& n, int s)
	: name(n), score(s) { }
	
string GameEntry::getName() const {return name;}
int GameEntry::getScore() const {return score;}

#endif
