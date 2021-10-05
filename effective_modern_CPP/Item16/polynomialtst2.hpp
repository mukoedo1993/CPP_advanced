#ifndef POLYNOMAILTST2_PHP
#define POLYNOMAILTST2_PHP

#include<vector>
#include<thread>
#include<mutex>
#include<iostream>
//Not thread-safe example:
class Polynomial_2 {
	public:
	using RootsType = std::vector<double>;
	
	RootsType roots() const
	{
		std::lock_guard<std::mutex> g(m);	//lock mutex
	
		if (!rootsAreValid) {			// if cache not valid
			int i = 17;
			//client code part. Here, compute/store roots
			int j = i /5;
			std::cout << std::boolalpha << rootsAreValid << std::endl;
			//finally... 
			rootsAreValid = true;
		}
		return rootVals;
	}						// unlock mutex
	
	private:
	  mutable std::mutex m; 	//It is worth noting that because std::mutex is move-only type, a side effect of adding m is that 
	  //Polynomial loses the ability to be copied. It can still be moved, however.
	  
	  mutable bool rootsAreValid{ false };
	  mutable RootsType rootVals{};
};


#endif
