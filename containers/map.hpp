#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "iterators/reverse_iterator.hpp"
# include "iterators/MapIterator.hpp"
# include "utils/BST.hpp"

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> >

    class map
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
		typedef BST<value_type>										    	map_node;
		typedef typename Alloc::template rebind<map_node>::other		    node_allocator_type;

		private:

			key_compare									_compare;
			allocator_type								_alloc;
			BST<value_type, Compare>  					_BST;
			_BST.insertion()

        public:

			class value_compare
			{
				friend class map;
				
				private:

					Compare _comp;

				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					value_compare(Compare c): _comp(c){}

					bool operator()( const value_type& lhs, const value_type& rhs ) const{return _comp(lhs.first, rhs.first)}

			}

		map(): _compare(), _alloc(), _rdb(){}

		explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _rdb(){}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _rdb(){
			insert(first, last);
		}

		map( const map& other ): _compare(other._comp), _alloc(other._comp), _rdb(other._rdb){}

		~map(){clear();}

		map& operator=( const map& other ){
			if (*this == other)
				return *this;
			clear();
			insert(other.begin(), other.end());
			return *this;
		}

		allocator_type get_allocator() const{return _alloc;}

		///////////////////////////// ELEMENT ACCESS \\\\\\\\\\\\\\\\\\\\\\\\\\\\/

		T& at( const Key& key ){
			iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map");
			else
				return (*it).second;
		}

		const T& at( const Key& key ) const{
			const_iterator it = find(key);
			if (it == end())
				throw std::out_of_range("map");
			else
				return (*it).second;
		}

		T& operator[]( const Key& key ){
			return insert(ft::make_pair(key, T())).first->second;
		}

		T& operator[]( Key&& key ){
			return insert(ft::make_pair(key, T())).first->second;
		}

        /////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

		iterator begin(){return iterator()}

		const_iterator begin() const{}

		iterator end(){}

		const_iterator end() const{}

		reverse_iterator rbegin(){}

		const_reverse_iterator rbegin() const{}

		reverse_iterator rend(){}

		const_reverse_iterator rend() const{}


        /////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/



        /////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/



        //////////////////////////////// LOOKUP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/



        /////////////////////////////// OBSERVERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/



        ////////////////////////// NON-MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\/




    };
}

#endif