#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "iterators/reverse_iterator.hpp"
# include "iterators/MapIterator.hpp"
# include "utils/BST.hpp"
# include "utils/pair.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
	{
			typedef Key 													    key_type;
			typedef T 														    mapped_type;
			typedef ft::pair<const key_type, mapped_type>					    value_type;
			typedef Compare 												    key_compare;
			typedef Allocator 													    allocator_type;
			typedef typename allocator_type::reference 						    reference;
			typedef typename allocator_type::const_reference				    const_reference;
			typedef typename allocator_type::pointer 						    pointer;
			typedef typename allocator_type::const_pointer 					    const_pointer;
			typedef BST									    					map_node;

			typedef ft::MapIterator<map_node, value_type>					    iterator;
			typedef ft::ConstMapIterator<map_node, const value_type, iterator>	const_iterator;
			typedef ft::reverse_iterator<iterator> 							    reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					    const_reverse_iterator;

			typedef std::ptrdiff_t 											    difference_type;
			typedef size_t 													    size_type;

		private:

			key_compare									_compare;
			allocator_type								_alloc;
			map_node 									_BST;

        public:

			class value_compare
			{
				// friend class map;
				
				private:

					Compare _comp;

				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;

					value_compare(Compare c): _comp(c){}

					bool operator()( const value_type& lhs, const value_type& rhs ) const{return _comp(lhs.first, rhs.first);}

			};

			map(): _compare(), _alloc(), _BST(){}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _BST(){}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _BST(){
				insert(first, last);
			}

			map( const map& other ): _compare(other._comp), _alloc(other._comp), _BST(other._BST){}

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

			T& operator[]( Key& key ){
				return insert(ft::make_pair(key, T())).first->second;
			}

			/////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			iterator begin(){}

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