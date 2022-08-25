#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>
# include <iostream>

namespace ft
{
 template <class T, class U, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t, class Pointer = U*, class Reference = U&>

    class MapIterator
    {
        public:

            typedef Category    iterator_category;
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            
        private:

            T *_ptr;

        public:

            MapIterator() : _ptr(NULL){}

            MapIterator(const MapIterator &other){_ptr = other.get_ptr();}

            MapIterator(pointer ptr): _ptr(ptr){}

            ~MapIterator(){}

            pointer get_ptr() const {return _ptr;}

            operator MapIterator<const T, const U>(void) const{return MapIterator<const T, const U>(this->_ptr);}

            MapIterator &operator=(const MapIterator<const T, const U> &other){if (this != &other)_ptr = other.get_ptr();return *this;}

            MapIterator& operator++() {_ptr++; return *this;}

            MapIterator operator++(int) {MapIterator retval = *this; ++(*this); return retval;}

            MapIterator& operator--() {_ptr--; return *this;}

            MapIterator operator--(int) {MapIterator retval = *this; --(*this); return retval;}

            MapIterator operator+(int n) const {MapIterator tmp(*this); tmp += n; return tmp;}

            // friend MapIterator	operator + (std::ptrdiff_t n, MapIterator it){MapIterator tmp(it.get_ptr());tmp += n;return (tmp);}

            MapIterator operator-(int n) const {MapIterator tmp(*this); tmp -= n; return tmp;}
            
            MapIterator &operator+=(int n){_ptr += n;return *this;}

            MapIterator &operator-=(int n){_ptr -= n;return *this;}

            difference_type operator-( MapIterator const & x ){return x._ptr - _ptr;}

            difference_type operator+( MapIterator const & x ){return x._ptr + _ptr;}
            
            bool operator == (const MapIterator<const T, const U> &other) const {return (_ptr == other.get_ptr());}

            bool operator != (const MapIterator<const T, const U> &other) const {return (_ptr != other.get_ptr());}

            bool operator>(const MapIterator<const T, const U> &other) const {return _ptr > other.get_ptr();}

            bool operator>=(const MapIterator<const T, const U> &other) const {return _ptr >= other.get_ptr();}

            bool operator<(const MapIterator<const T, const U> &other) const {return _ptr < other.get_ptr();}

            bool operator<=(const MapIterator<const T, const U> &other) const {return _ptr <= other.get_ptr();}


            value_type operator*() const {return *_ptr;}

            value_type &operator [] (int n) const{return _ptr[n];}

            // value_type operator->() const {return _ptr;}


    };
    template<class T, class U>

    std::ostream& operator<<( std::ostream & o, MapIterator<T, U> const & i ){o << i.get_ptr();return o;}

    template <class T, class U, class MapIterator, class Category = std::bidirectional_iterator_tag, class Distance = std::ptrdiff_t,
        class Pointer = U*, class Reference = U&>

    class ConstMapIterator
    {
        public:

            typedef Category    iterator_category;
            typedef T           value_type;
            typedef Distance    difference_type;
            typedef Pointer     pointer;
            typedef Reference   reference;
            
        private:

            T *_ptr;

        public:

            ConstMapIterator() : _ptr(NULL){}

            ConstMapIterator(const ConstMapIterator &other){_ptr = other.get_ptr();}

            ConstMapIterator(pointer ptr): _ptr(ptr){}

            ~ConstMapIterator(){}

            pointer get_ptr() const {return _ptr;}

            operator ConstMapIterator<const T, const U, const MapIterator>(void) const{return ConstMapIterator<const T, const U, const MapIterator>(this->_ptr);}

            ConstMapIterator &operator=(const ConstMapIterator<const T, const U, const MapIterator> &other){if (this != &other)_ptr = other.get_ptr();return *this;}

            ConstMapIterator& operator++() {_ptr++; return *this;}

            ConstMapIterator operator++(int) {ConstMapIterator retval = *this; ++(*this); return retval;}

            ConstMapIterator& operator--() {_ptr--; return *this;}

            ConstMapIterator operator--(int) {ConstMapIterator retval = *this; --(*this); return retval;}

            ConstMapIterator operator+(int n) const {ConstMapIterator tmp(*this); tmp += n; return tmp;}

            // friend ConstMapIterator	operator + (std::ptrdiff_t n, ConstMapIterator it){ConstMapIterator tmp(it.get_ptr());tmp += n;return (tmp);}

            ConstMapIterator operator-(int n) const {ConstMapIterator tmp(*this); tmp -= n; return tmp;}
            
            ConstMapIterator &operator+=(int n){_ptr += n;return *this;}

            ConstMapIterator &operator-=(int n){_ptr -= n;return *this;}

            difference_type operator-( ConstMapIterator const & x ){return x._ptr - _ptr;}

            difference_type operator+( ConstMapIterator const & x ){return x._ptr + _ptr;}
            
            bool operator == (const ConstMapIterator<const T, const U, const MapIterator> &other) const {return (_ptr == other.get_ptr());}

            bool operator != (const ConstMapIterator<const T, const U, const MapIterator> &other) const {return (_ptr != other.get_ptr());}

            bool operator>(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr > other.get_ptr();}

            bool operator>=(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr >= other.get_ptr();}

            bool operator<(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr < other.get_ptr();}

            bool operator<=(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr <= other.get_ptr();}


            value_type operator*() const {return *_ptr;}

            value_type &operator [] (int n) const{return _ptr[n];}

            // value_type operator->() const {return _ptr;}
    };
    template<class T, class U, class MapIterator>

    std::ostream& operator<<( std::ostream & o, ConstMapIterator<T, U, MapIterator> const & i ){o << i.get_ptr();return o;}
}

#endif 