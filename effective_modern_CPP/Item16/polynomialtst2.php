#ifndef POLYNOMAILTST1_PHP
#define POLYNOMAILTST1_PHP

#include<vector>


//Not thread-safe example:
class Polynomial {
	public:
	using RootsType = std::vector<double>;
	
	RootsType roots() const
	{
		if (!rootsAreValid) {
			
			//client code part
			
			//finally... 
			rootsAreValid = true;
		}
	}
	
	private:
	  mutable bool rootsAreValid{ false };
	  mutable RootsType rootVals{};
};


#endif
