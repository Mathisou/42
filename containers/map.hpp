#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "reverse_iterator.hpp"

namespace ft
{
    template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> >
>   class map
    {

        typedef Key 													    key_type;
		typedef T 														    mapped_type;
		typedef ft::pair<const key_type, mapped_type>					    value_type;
		typedef size_t 													    size_type;
		typedef std::ptrdiff_t 											    difference_type;
		typedef Compare 												    key_compare;
		typedef Alloc 													    allocator_type;
		typedef typename allocator_type::reference 						    reference;
		typedef typename allocator_type::const_reference				    const_reference;
		typedef typename allocator_type::pointer 						    pointer;
		typedef typename allocator_type::const_pointer 					    const_pointer;
		typedef ft::MapIterator<map_node, value_type>					    iterator;
		typedef ft::ConstMapIterator<map_node, const value_type, iterator>	const_iterator;
		typedef ft::reverse_iterator<iterator> 							    reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					    const_reverse_iterator;
		typedef BSTNode<value_type>										    map_node;
		typedef typename Alloc::template rebind<map_node>::other		    node_allocator_type;
	private:
		key_compare			_compare;
		allocator_type		_alloc;
		node_allocator_type	_node_alloc;
		map_node			*_root;
		map_node			*_end;
		map_node			*_rend;
		size_type			_size;

        public:
        class value_compare
        {
            friend class map;
            
            protected:

                Compare _comp;

            public:

                typedef bool result_type;
                typedef value_type first_argument_type;
                typedef value_type second_argument_type;

                value_compare(Compare c): _comp(c){}

                bool operator()( const value_type& lhs, const value_type& rhs ) const{return _comp(lhs.first, rhs.first)}


        }
    };
}

#endif