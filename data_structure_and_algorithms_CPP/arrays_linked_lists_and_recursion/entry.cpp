

#include<iostream>
#include"Scores_impl.hpp"

int main()
{
	GameEntry entry1("Tom", 13), entry2("Shijunn", 17);
	Scores scores(12);
	scores.add(entry1);
	scores.add(entry2);
	scores.add(entry1);
	auto mkft1 = scores.remove(1);
	std::cout << mkft1.getName() << std::endl;
}
