#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../utils.hpp"

namespace ft
{
	template <typename T, class Compare >

    class MapIterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:

			typedef typename T::value_type                                                                  value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            
			T *         _node;
			T *         _last_node;
			Compare     _comp;

            MapIterator(const Compare& comp = Compare()) : _node(), _last_node(), _comp(comp){}

            MapIterator(T * node_p, T * last_node, const Compare& comp = Compare()): _node(node_p), _last_node(last_node), _comp(comp){}

            MapIterator(const MapIterator& other) : _node(other._node), _last_node(other._last_node), _comp(){}

            ~MapIterator(){}

            // operator MapIterator<const T, const U>(void) const{return MapIterator<const T, const U>(this->_ptr);}

            MapIterator &operator=(const MapIterator &other){
                if (this == &other)
                    return *this;
                _node = other._node;
                _last_node = other._last_node;
                _comp = other._comp;
                return *this;
            }

            MapIterator& operator++(){

            }

            MapIterator operator++(int){

            }

            MapIterator& operator--() {

            }

            MapIterator operator--(int) {

            }

            // MapIterator operator+(int n) const {MapIterator tmp(*this); tmp += n; return tmp;}

            // // friend MapIterator	operator + (std::ptrdiff_t n, MapIterator it){MapIterator tmp(it.get_ptr());tmp += n;return (tmp);}

            // MapIterator operator-(int n) const {MapIterator tmp(*this); tmp -= n; return tmp;}
            
            // MapIterator &operator+=(int n){_node += n;return *this;}

            // MapIterator &operator-=(int n){_node -= n;return *this;}

            // difference_type operator-( MapIterator const & x ){return x._node - _node;}

            // difference_type operator+( MapIterator const & x ){return x._node + _node;}
            
            bool operator == (const MapIterator &other) const {return (_node == other.get_node());}

            bool operator != (const MapIterator &other) const {return (_node != other.get_node());}

            bool operator>(const MapIterator &other) const {return _node > other.get_node();}

            bool operator>=(const MapIterator &other) const {return _node >= other.get_node();}

            bool operator<(const MapIterator &other) const {return _node < other.get_node();}

            bool operator<=(const MapIterator &other) const {return _node <= other.get_node();}


            reference operator*() const {return _node->value;}

            // value_type &operator [] () const{return &_node->value;}

            pointer operator->() const {return &_node->value;}


    };
    template<class T, class U>

    std::ostream& operator<<( std::ostream & o, MapIterator<T, U> const & i ){o << i.get_node();return o;}

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

            ConstMapIterator(const ConstMapIterator &other){_ptr = other._node;}

            ConstMapIterator(pointer ptr): _ptr(ptr){}

            ~ConstMapIterator(){}

            pointer get_ptr() const {return _ptr;}

            operator ConstMapIterator<const T, const U, const MapIterator>(void) const{return ConstMapIterator<const T, const U, const MapIterator>(this->_ptr);}

            ConstMapIterator &operator=(const ConstMapIterator<const T, const U, const MapIterator> &other){if (this != &other)_ptr = other._node;return *this;}

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
            
            bool operator == (const ConstMapIterator<const T, const U, const MapIterator> &other) const {return (_ptr == other._node);}

            bool operator != (const ConstMapIterator<const T, const U, const MapIterator> &other) const {return (_ptr != other._node);}

            bool operator>(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr > other._node;}

            bool operator>=(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr >= other._node;}

            bool operator<(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr < other._node;}

            bool operator<=(const ConstMapIterator<const T, const U, const MapIterator> &other) const {return _ptr <= other._node;}


            value_type operator*() const {return *_ptr;}

            value_type &operator [] (int n) const{return _ptr[n];}

            // value_type operator->() const {return _ptr;}
    };
    template<class T, class U, class MapIterator>

    std::ostream& operator<<( std::ostream & o, ConstMapIterator<T, U, MapIterator> const & i ){o << i.get_ptr();return o;}
}

#endif 