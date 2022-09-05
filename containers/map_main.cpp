#include "map.hpp"
#include <map>
#include <iostream>

int main()
{
	ft::map<int, char> my_map;
	std::map<int, char> map;

	map.insert(std::make_pair(1, 'a'));
	map.insert(std::make_pair(-3, 'a'));
	map.insert(std::make_pair(18, 'a'));
	map.insert(std::make_pair(2, 'a'));
	map.insert(std::make_pair(-3, 'a'));
	map.insert(std::make_pair(18, 'b'));

	for (std::map<int, char>::iterator it = map.begin(); it != map.end(); it++)
		std::cout << it->first << std::endl;

	std::cout << std::endl << "and mine now lol :" << std::endl;

	my_map.insert(ft::make_pair(1, 'a'));
	my_map.insert(ft::make_pair(-3, 'a'));
	my_map.insert(ft::make_pair(18, 'a'));
	my_map.insert(ft::make_pair(2, 'a'));
	my_map.insert(ft::make_pair(-3, 'a'));
	my_map.insert(ft::make_pair(18, 'b'));

	int i = 0;
	for (ft::map<int, char>::iterator it = my_map.begin(); it != my_map.end() && i < 6; it++,i++){
		std::cout << it->first << std::endl;
	}
}