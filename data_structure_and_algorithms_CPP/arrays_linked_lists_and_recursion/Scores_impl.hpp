#include "Scores.hpp"

/*
*Here, we allocate the desired amount of storage for the array using the
* "new" operator. C++ represents a dynamic array as a pointer to its first element,
* and this command returns such a pointer. The class destructor, "Scores", deletes
* this array.
*
*/

Scores::Scores(int maxEnt) {
	maxEntries = maxEnt;			//save the max size
	entries = new GameEntry[maxEntries];	// allocate array storage
	numEntries = 0;			// initially no elements
}

Scores::~Scores() {
	delete[] entries;			//destructor
}

/*
*Insert game entry e into the collection of high scores. If this causes the number
*of entries to exceed maxEntries, the smallest is removed.
*/
void Scores::add(const GameEntry& e) {	//add a game entry
	int newScore = e.getScore();		// score to add
	if (numEntries == maxEntries) {	// the array is full
		if (newScore <= entries[maxEntries-1].getScore())
			return;		// not high enough - ignore
	}
	else numEntries++; 			//if not full, one more entry
	
	int i = numEntries-2;			// start with the next to last
	while (i>= 0 && newScore > entries[i].getScore() ) {
		entries[i+1] = entries[i];	//shift right if smaller
		i--;
	}
	entries[i+1] = e;
}

/*
Remove and return the game entry e at index i in the entries array. If index i is outside the bounds of the entries array, then this function throws an exception; otherwise,
the entries array is updated to remove the object at index i and all objects previously stored at indices higher than i are "shifted left" to fill in for the removed object.
*/

GameEntry Scores::remove(int i)throw(IndexOutOfBounds) {
	if((i < 0) || (i >= numEntries))
		throw IndexOutOfBounds("Invalid index");
	GameEntry e = entries[i];
	for (int j = i+1; j < numEntries; j++)
		entries[j-1] = entries[j];	//shift entries left
	numEntries--;				//one fewer entry
	return e;				// return the removed object
}
