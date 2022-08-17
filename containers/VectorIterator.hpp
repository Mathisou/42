#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <cstddef>
# include <iterator>
# include <iostream>
# include <string>

namespace ft
{
    template <class T, class Category = std::random_access_iterator_tag, class Distance = ptrdiff_t,
    	    class Pointer = T*, class Reference = T&>

    class VectorIterator
    {
        public:

            typedef Category iterator_category;
            typedef T value_type;
            typedef Distance difference_type;
            typedef Pointer pointer;
            typedef Reference reference;
            
        protected:

            pointer _ptr;

        public:

            VectorIterator(){}

            VectorIterator(const VectorIterator &other){_ptr = other.get_ptr();}

            VectorIterator(pointer ptr): _ptr(ptr){}

            ~VectorIterator(){}

            pointer get_ptr() const {return _ptr;}

            operator VectorIterator<const T>(void) const{return VectorIterator<const T>(this->_ptr);}

            VectorIterator &operator=(const VectorIterator<const T> &other){if (this != &other)_ptr = other.get_internal_pointer();return *this;}

            VectorIterator& operator++() {_ptr++; return *this;}

            VectorIterator operator++(int) {VectorIterator retval = *this; ++(*this); return retval;}

            VectorIterator& operator--() {_ptr--; return *this;}

            VectorIterator operator--(int) {VectorIterator retval = *this; --(*this); return retval;}

            VectorIterator operator+(int n) const {VectorIterator tmp(*this); tmp += n; return tmp;}

            // friend VectorIterator	operator + (std::ptrdiff_t n, VectorIterator it){VectorIterator tmp(it.get_ptr());tmp += n;return (tmp);}

            VectorIterator operator-(int n) const {VectorIterator tmp(*this); tmp -= n; return tmp;}
            
            VectorIterator &operator+=(int n){_ptr += n;return *this;}

            VectorIterator &operator-=(int n){_ptr -= n;return *this;}

            difference_type operator-( VectorIterator const & x )
            {
                return x._ptr - _ptr;
            }

            difference_type operator+( VectorIterator const & x )
            {
                return x._ptr + _ptr;
            }

            
            bool operator == (const VectorIterator<const T> &other) const {return (_ptr == other.get_ptr());}

            bool operator != (const VectorIterator<const T> &other) const {return (_ptr != other.get_ptr());}

            bool operator>(const VectorIterator<const T> &other) const {return _ptr > other.get_ptr();}

            bool operator>=(const VectorIterator<const T> &other) const {return _ptr >= other.get_ptr();}

            bool operator<(const VectorIterator<const T> &other) const {return _ptr < other.get_ptr();}

            bool operator<=(const VectorIterator<const T> &other) const {return _ptr <= other.get_ptr();}


            value_type operator*() const {return *_ptr;}

            value_type &operator [] (int n) const{return _ptr[n];}

            // value_type operator->() const {return _ptr;}


    };
    template<class T>

    std::ostream& operator<<( std::ostream & o, VectorIterator<T> const & i ){o << i.get_ptr();return o;}
}

#endif