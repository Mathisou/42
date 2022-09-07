#include "map.hpp"
#include <map>
#include <iostream>

int main()
{
	ft::map<int, char> my_map;
	std::map<int, char> map;

	map.insert(std::make_pair(1, 'a'));
	map.insert(std::make_pair(2, 'a'));
	map.insert(std::make_pair(3, 'a'));
	map.insert(std::make_pair(4, 'a'));
	map.insert(std::make_pair(5, 'a'));
	map.insert(std::make_pair(6, 'a'));
	map.erase(5);
	map.erase(1);
	std::cout << map.count(-3) << std::endl;
	std::cout << map.equal_range(2).first->first << " " << map.equal_range(2).second->first << std::endl;


	int i = 0;
	for (std::map<int, char>::iterator it = map.begin(); it != map.end(); it++, i++){
		std::cout << it->first << std::endl;
	}
	std::cout << std::endl << "and mine now lol :" << std::endl;

	my_map.insert(ft::make_pair(1, 'a'));
	my_map.insert(ft::make_pair(2, 'a'));
	my_map.insert(ft::make_pair(3, 'a'));
	my_map.insert(ft::make_pair(4, 'a'));
	my_map.insert(ft::make_pair(5, 'a'));
	my_map.insert(ft::make_pair(6, 'b'));
	my_map.erase(5);
	my_map.erase(1);
	std::cout << my_map.count(-3) << std::endl;
	std::cout << my_map.equal_range(2).first->first << " " << my_map.equal_range(2).second->first << std::endl;

	i = 0;
	for (ft::map<int, char>::iterator it = my_map.begin(); it != my_map.end(); it++,i++)
		std::cout << it->first << std::endl;
	// love u ;)
}