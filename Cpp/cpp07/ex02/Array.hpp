#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
	public:
	Array<T>(): _array(NULL), _size(0){}
	Array<T>(unsigned int n) : _array(new T[n]), _size(n){}
	Array<T>(Array const & save) : _array(NULL), _size(0){*this = save;}
	~Array<T>(){
		if (_array != NULL)
			delete [] _array;
	}
	Array &		operator=( Array const & rhs ){
		if (this != &rhs){
			if (_array != NULL)
				delete [] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0;i < _size;i++)
				_array[i] = rhs._array[i];
		}
		return (*this);
	}
	T		&operator[](unsigned int const n) const{
		if (n >= _size)
			throw out_of_range();
		else
			return _array[n];
	}
	class	out_of_range : public std::exception{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of range !");
			};
	};
	unsigned int size() const{return _size;}
	private:
	T *_array;
	unsigned int _size;
};

#endif
 