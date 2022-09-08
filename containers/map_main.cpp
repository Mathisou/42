#include "map.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "utils/BST.hpp"

int main()
{
	std::map<int, char> map;
	std::ofstream map_outfile("outfiles/map.txt");

	map.insert(std::make_pair(1, 'a'));
	map.insert(std::make_pair(2, 'a'));
	map.insert(std::make_pair(3, 'a'));
	map.insert(std::make_pair(4, 'a'));
	map.insert(std::make_pair(5, 'a'));
	map.insert(std::make_pair(6, 'a'));
	map.erase(5);
	map.erase(1);
	map_outfile << map.count(-3) << std::endl;
	// map_outfile << map.equal_range(2).first->first << " " << map.equal_range(2).second->first << std::endl;


	int i = 0;
	for (std::map<int, char>::iterator it = map.begin(); it != map.end(); it++, i++){
		map_outfile << it->first << std::endl;
	}

	ft::map<int, char> my_map;
	std::ofstream my_map_outfile("outfiles/my_map.txt");

	my_map.insert(ft::make_pair(50, 'a'));
	// my_map.insert(ft::make_pair(2, 'a'));
	// my_map.insert(ft::make_pair(3, 'a'));
	// my_map.insert(ft::make_pair(4, 'a'));
	// my_map.insert(ft::make_pair(5, 'a'));
	// my_map.insert(ft::make_pair(6, 'b'));
	// my_map.erase(5);
	// my_map.erase(1);
	for (int i = 0;i < 10000;i++)
		my_map.insert(ft::make_pair(i, 'a'));	
	my_map_outfile << my_map.count(-3) << ", size: " << my_map.size() << std::endl;
	// my_map_outfile << my_map.equal_range(2).first->first << " " << my_map.equal_range(2).second->first << std::endl;

	i = 0;
	for (ft::map<int, char>::iterator it = my_map.begin(); it != my_map.end(); it++,i++)
		my_map_outfile << it->first << std::endl;
	
	// ft::map<int, char> copy = my_map;
	// love u ;)
}