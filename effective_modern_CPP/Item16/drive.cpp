#include"polynomialtst2.hpp"
#include<vector>
#include<thread>
#include<mutex>
#include<iostream>
int main() {
	Polynomial_2 tst1;
	std::thread trd1(&Polynomial_2::roots, &tst1);
	std::thread trd2(&Polynomial_2::roots, &tst1);
	
	trd1.join();
	trd2.join();
	
	

}
