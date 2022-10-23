#include "../map.hpp"
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "../utils/BST.hpp"

int main()
{
	std::map<int, char> map;
	std::ofstream map_outfile("outfiles/map.txt");

	map.insert(std::make_pair(1, 'b'));
	map.insert(std::make_pair(2, 'e'));
	map.insert(std::make_pair(3, 'b'));
	map.insert(std::make_pair(4, 'b'));
	map.insert(std::make_pair(5, 'b'));
	map.insert(std::make_pair(6, 'b'));
	map.erase(5);
	map.erase(1);

	// for (int i = 0;i < 10000;i++)
	//  	map.insert(std::make_pair(i, 'a'));	
	map_outfile << map.count(-3) << ", size: " << map.size() <<  ", find: " << map.find(6)->first << ", []: " << map[112] << ", good at:" << map.at(4) << ", wrong at:";
	try
	{
		map_outfile << map.at(7) << std::endl;
	}
	catch(const std::exception& e)
	{
		map_outfile << e.what() << '\n';
	}
	
	map_outfile << map.equal_range(2).first->first << " " << map.equal_range(2).second->first << std::endl;

	int i = 0;
	for (std::map<int, char>::iterator it = map.begin(); it != map.end(); it++, i++){
		map_outfile << it->first << std::endl;
	}
	{
		std::map<int, char> copy = map;
	}
	{
		map.clear();
		std::map<int, char> compare;
		map.insert(std::make_pair(1, 'a'));
		compare.insert(std::make_pair(1, 'a'));
		map_outfile << "SAME CONTENT:" << std::endl;
		map_outfile << "==: " << (map == compare) << std::endl;
		map_outfile << "!=: " << (map != compare) << std::endl;
		map_outfile << "<: " << (map < compare) << std::endl;
		map_outfile << "<=: " << (map <= compare) << std::endl;
		map_outfile << ">: " << (map > compare) << std::endl;
		map_outfile << ">=: " << (map >= compare) << std::endl;

		compare.clear();
		compare.insert(std::make_pair(2, 'b'));
		map_outfile << "DIFFERENT CONTENT:" << std::endl;
		map_outfile << "==: " << (map == compare) << std::endl;
		map_outfile << "!=: " << (map != compare) << std::endl;
		map_outfile << "<: " << (map < compare) << std::endl;
		map_outfile << "<=: " << (map <= compare) << std::endl;
		map_outfile << ">: " << (map > compare) << std::endl;
		map_outfile << ">=: " << (map >= compare) << std::endl;
	}

	ft::map<int, char> my_map;
	std::ofstream my_map_outfile("outfiles/my_map.txt");

	my_map.insert(ft::make_pair(1, 'b'));
	my_map.insert(ft::make_pair(2, 'e'));
	my_map.insert(ft::make_pair(3, 'b'));
	my_map.insert(ft::make_pair(4, 'b'));
	my_map.insert(ft::make_pair(5, 'b'));
	my_map.insert(ft::make_pair(6, 'b'));
	my_map.erase(5);
	my_map.erase(1);
	my_map_outfile << my_map.count(-3) << ", size: " << my_map.size() << ", find: " << my_map.find(6)->first <<  ", []: " << my_map[112] << ", good at:" << my_map.at(4) << ", wrong at:";
	try
	{
		my_map_outfile << my_map.at(7) << std::endl;
	}
	catch(const std::exception& e)
	{
		my_map_outfile << e.what() << '\n';
	}
	
	my_map_outfile << my_map.equal_range(2).first->first << " " << my_map.equal_range(2).second->first << std::endl;

	i = 0;
	for (ft::map<int, char>::iterator it = my_map.begin(); it != my_map.end(); it++,i++)
		my_map_outfile << it->first << std::endl;
	{
		ft::map<int, char> copy = my_map;
	}
	{
		my_map.clear();
		ft::map<int, char> compare;
		my_map.insert(ft::make_pair(1, 'a'));
		compare.insert(ft::make_pair(1, 'a'));
		my_map_outfile << "SAME CONTENT:" << std::endl;
		my_map_outfile << "==: " << (my_map == compare) << std::endl;
		my_map_outfile << "!=: " << (my_map != compare) << std::endl;
		my_map_outfile << "<: " << (my_map < compare) << std::endl;
		my_map_outfile << "<=: " << (my_map <= compare) << std::endl;
		my_map_outfile << ">: " << (my_map > compare) << std::endl;
		my_map_outfile << ">=: " << (my_map >= compare) << std::endl;

		compare.clear();
		compare.insert(ft::make_pair(2, 'b'));
		my_map_outfile << "DIFFERENT CONTENT:" << std::endl;
		my_map_outfile << "==: " << (my_map == compare) << std::endl;
		my_map_outfile << "!=: " << (my_map != compare) << std::endl;
		my_map_outfile << "<: " << (my_map < compare) << std::endl;
		my_map_outfile << "<=: " << (my_map <= compare) << std::endl;
		my_map_outfile << ">: " << (my_map > compare) << std::endl;
		my_map_outfile << ">=: " << (my_map >= compare) << std::endl;
	}

	// love u ;)
}