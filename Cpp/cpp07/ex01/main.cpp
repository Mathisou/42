#include "iter.hpp"

class Awesome{
	public:
	Awesome(): _n(42){}
	int getN() const {return this->_n;}
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.getN();return o; }

template<typename T>
void Print(T const & a){
	std::cout << a << std::endl;
}

template<typename T>
void Foo(T const & a){
	if (a > 2147483647 / 2)
		std::cerr << "out of range" << std::endl;
	else{
		T result = a * 2;
		std::cout << result << std::endl;
	}
}

int main()
{ 
	int tab[] = { 0, 1, 2, 3, 4 };

	std::cout << std::endl << "\033[1;37mtab: { 0, 1, 2, 3, 4 }\033[0m" << std::endl;
	std::cout << std::endl << "Print tab:" << std::endl;
	iter( tab, 5, Print );
	std::cout << std::endl << "Foo tab:" << std::endl;
	iter( tab, 5, Foo );

	std::cout << std::endl << "\033[1;37mAwesome tab2[5]\033[0m" << std::endl;
	std::cout << std::endl << "Print tab2:" << std::endl;
	Awesome tab2[5];
	iter( tab2, 5, Print );

	int randArray[15];
	for(int i = 0; i < 15; i++)
		randArray[i] = rand() %RAND_MAX;

	std::cout << std::endl << "Print tab:" << std::endl;
	iter( randArray, 15, Print );
	std::cout << std::endl << "Foo tab:" << std::endl;
	iter( randArray, 15, Foo );
	return 0;
}