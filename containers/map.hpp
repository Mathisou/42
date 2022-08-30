#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "iterators/reverse_iterator.hpp"
# include "iterators/MapIterator.hpp"
# include "utils.hpp"
# include "utils/BST.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
	{
			typedef Key 													    key_type;
			typedef T 														    mapped_type;
			typedef ft::pair<const key_type, mapped_type>					    value_type;
			typedef Compare 												    key_compare;
			typedef Allocator 													allocator_type;
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
			map_node									*_root;

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

			map(): _compare(), _alloc(), _BST(), _root(){}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _BST(), _root(){}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _compare(comp), _alloc(alloc), _BST(), _root(){
				insert(first, last);
			}

			map( const map& other ): _compare(other._comp), _alloc(other._comp), _BST(other._BST), _root(other._root){}

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

			iterator begin(){return _BST.FindMin(_root)->value;}

			const_iterator begin() const{return _BST.FindMin(_root)->value;}

			iterator end(){return _BST.FindMax(_root)->value;}

			const_iterator end() const{return _BST.FindMax(_root)->value;}

			reverse_iterator rbegin(){return _BST.FindMax(_root)->value;}

			const_reverse_iterator rbegin() const{return _BST.FindMax(_root)->value;}

			reverse_iterator rend(){return _BST.FindMin(_root)->value;}

			const_reverse_iterator rend() const{return _BST.FindMin(_root)->value;}


			/////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			bool empty() const{
				if (size() == 0)
					return true;
				return false;
			}

			size_type size() const{

			}

			size_type max_size() const{

			}

			/////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			void clear(){ 

			}

			ft::pair<iterator, bool> insert( const value_type& value ){
				_BST.insertion(_root, value);
			}

			iterator insert( iterator hint, const value_type& value ){
				(void)hint;
				_BST.insertion(_root, value);
			}

			void erase( iterator pos ){
				_BST.deletion(_root, *pos);
			}

			void erase( iterator first, iterator last ){
				for (;first != last;first++)
					_BST.deletion(_root, *first);
			}

			void swap( map& other ){
				_BST.swap(other);
			}

			//////////////////////////////// LOOKUP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			size_type count( const Key& key ) const{

			}

			iterator find( const Key& key ){

			}

			const_iterator find( const Key& key ) const{

			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){

			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{

			}

			iterator lower_bound( const Key& key ){

			}

			const_iterator lower_bound( const Key& key ) const{

			}

			iterator upper_bound( const Key& key ){

			}

			const_iterator upper_bound( const Key& key ) const{

			}

			/////////////////////////////// OBSERVERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			key_compare key_comp() const{

			}

			value_compare value_comp() const{

			}

			////////////////////////// NON-MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\/

			friend bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}

			friend bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return !(lhs == rhs);
			}

			friend bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}

			friend bool operator<=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return !(rhs < lhs);
			}

			friend bool operator>( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return (rhs < lhs);
			}

			friend bool operator>=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return !(rhs > lhs);
			}

			void swap( ft::map<Key,T,Compare,Allocator>& lhs, ft::map<Key,T,Compare,Allocator>& rhs ){
				lhs.swap(rhs);
			}

    };
}

#endif