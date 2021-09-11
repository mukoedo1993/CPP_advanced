//Declaration of Scores.hpp


#ifndef SCORES_HPP
#define SCORES_HPP
#include<iostream>
#include "GameEntry.hpp"
#include"../exceptions/IndexOutOfBounds.hpp"
#include<memory>

using std::string;


class Scores {
	public:
	Scores(int maxEnt = 10);
	~Scores();
	void add(const GameEntry& e);
	GameEntry remove(int i)
		throw(IndexOutOfBounds);
	
	private:
		int maxEntries;			//maximum number of entries
		int numEntries;			//minimum number of entries
		GameEntry* entries;			//array of entries
	
	
};


#endif
