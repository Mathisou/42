#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

# include <cstddef>
# include <iterator>

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

            VectorIterator(const VectorIterator &other){_ptr = other.get_internal_pointer();}

            VectorIterator(pointer ptr): _ptr(ptr){}

            ~VectorIterator(){}

            pointer get_ptr(){return _ptr;}

            VectorIterator& operator++() {_ptr++; return *this;}

            VectorIterator operator++(int) {VectorIterator retval = *this; ++(*this); return retval;}

            VectorIterator& operator--() {_ptr--; return *this;}

            VectorIterator operator--(int) {VectorIterator retval = *this; --(*this); return retval;}

            VectorIterator operator+(int n) const {_ptr + n; return *this;}

            VectorIterator operator-(int n) const {_ptr - n; return *this;}
            
            bool operator==(VectorIterator &other) const {return _ptr == other.get_ptr();}

            bool operator!=(VectorIterator &other) const {return !(*this == other);}

            bool operator>(VectorIterator &other) const {return _ptr > other.get_ptr();}

            bool operator>=(VectorIterator &other) const {return _ptr >= other.get_ptr();}

            bool operator<(VectorIterator &other) const {return _ptr < other.get_ptr();}

            bool operator<=(VectorIterator &other) const {return _ptr <= other.get_ptr();}

            // value_type operator*() const {return *_ptr;}

            // value_type operator->() const {return _ptr;}


    };
}

#endif