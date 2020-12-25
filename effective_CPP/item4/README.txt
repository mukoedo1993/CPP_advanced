Data members that are const or are references must be initialized; they can't be assigned.
To avoid having to memorize when data members must be initialized in the member initialization list and when it's optional,
 the easiest choice is to always use the initialization list. It's sometimes required, and it's often more efficient than assignments.
 
 The order is always the same: base classes are initialized before derived classes, and within a class, data members are initialized in the 
 order in which they are declared. In ABEntry, for example, theName will always be initialized first, theAddress second, thePhones third, and
 numTimesConsulted last. This is true even if they are listed in a different order on the member initialization list (sometimes that's unfortunately
 legal). To avoid reader confusion, as well as the possibility of some truly obscure behavioral bugs, always list memebrs in the initialization list in 
 the same order as they're declared in the class.
