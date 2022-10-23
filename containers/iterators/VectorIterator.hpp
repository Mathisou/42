#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include "../utils/utils.hpp"
# include <ostream>

namespace ft
{
    template <class T, class Category = ft::random_access_iterator_tag, class Distance = ptrdiff_t,
    	    class Pointer = T*, class Reference = T&>

    class VectorIterator
    {
        public:

            typedef Category iterator_category;
            typedef T value_type;
            typedef Distance difference_type;
            typedef Pointer pointer;
            typedef Reference reference;
            
        private:

            pointer _ptr;

        public:

            VectorIterator(){}

            VectorIterator(const VectorIterator &other){_ptr = other.get_ptr();}

            VectorIterator(pointer ptr): _ptr(ptr){}

            ~VectorIterator(){}

            pointer get_ptr() const {return _ptr;}

            operator VectorIterator<const T>(void) const{return VectorIterator<const T>(this->_ptr);}

            VectorIterator &operator=(const VectorIterator<const T> &other){if (this != &other)_ptr = other.get_ptr();return *this;}

            VectorIterator& operator++() {_ptr++; return *this;}

            VectorIterator operator++(int) {VectorIterator retval = *this; ++(*this); return retval;}

            VectorIterator& operator--() {_ptr--; return *this;}

            VectorIterator operator--(int) {VectorIterator retval = *this; --(*this); return retval;}

            VectorIterator operator+(int n) const {VectorIterator tmp(*this); tmp += n; return tmp;}

            VectorIterator operator-(int n) const {VectorIterator tmp(*this); tmp -= n; return tmp;}
            
            VectorIterator &operator+=(int n){_ptr += n;return *this;}

            VectorIterator &operator-=(int n){_ptr -= n;return *this;}

            difference_type operator-( const VectorIterator & x ) const{return _ptr - x._ptr;}

            difference_type operator+( VectorIterator const & x ) const {return x._ptr + _ptr;}
            
            bool operator == (const VectorIterator<const T> &other) const {return (_ptr == other.get_ptr());}

            bool operator != (const VectorIterator<const T> &other) const {return (_ptr != other.get_ptr());}

            bool operator>(const VectorIterator<const T> &other) const {return _ptr > other.get_ptr();}

            bool operator>=(const VectorIterator<const T> &other) const {return _ptr >= other.get_ptr();}

            bool operator<(const VectorIterator<const T> &other) const {return _ptr < other.get_ptr();}

            bool operator<=(const VectorIterator<const T> &other) const {return _ptr <= other.get_ptr();}

            reference operator*() const {return *_ptr;}

            value_type *operator->() const{return (_ptr);}

            value_type &operator [] (int n) const{return _ptr[n];}

    };

    template <class iterator>
	VectorIterator<iterator> operator + (
            typename VectorIterator<iterator>::difference_type n,
            const VectorIterator<iterator> &rev_it)
	{
		return VectorIterator<iterator>(rev_it.get_ptr() + n);
	}

    template <class iterator>
	VectorIterator<iterator> operator - (
            typename VectorIterator<iterator>::difference_type n,
            const VectorIterator<iterator> &rev_it)
	{
		return VectorIterator<iterator>(rev_it.get_ptr() - n);
	}

    template<class T>

    std::ostream& operator<<( std::ostream & o, VectorIterator<T> const & i ){o << i.get_ptr();return o;}
}

#endif