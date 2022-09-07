#ifndef MAP_HPP
# define MAP_HPP

# include <stdexcept>
# include "iterators/reverse_iterator.hpp"
# include "iterators/MapIterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key,T> > >
    class map
	{
		public: 
			typedef Key 													    key_type;
			typedef T 														    mapped_type;
			typedef ft::pair<key_type, mapped_type>					    		value_type;
			typedef Compare 												    key_compare;
			typedef Allocator 													allocator_type;
			typedef typename allocator_type::reference 						    reference;
			typedef typename allocator_type::const_reference				    const_reference;
			typedef typename allocator_type::pointer 						    pointer;
			typedef typename allocator_type::const_pointer 					    const_pointer;
			typedef BST<value_type, key_compare>								map_node;

			typedef ft::MapIterator<map_node, Compare>					    	iterator;
			typedef ft::ConstMapIterator<map_node, const Compare>				const_iterator;
			typedef ft::reverse_iterator<iterator> 							    reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					    const_reverse_iterator;

			typedef ptrdiff_t 											    difference_type;
			typedef size_t 													    size_type;

		private:

			key_compare									_compare;
			allocator_type								_alloc;
			map_node 									_BST;
			map_node									*_root;

        public:

			class value_compare
			{				

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

			iterator begin(){return iterator(_BST.FindMin(_root), _compare);}

			const_iterator begin() const{return const_iterator(_BST.FindMin(_root), _compare);}

			iterator end(){return iterator(_BST.FindMax(_root), _compare);}

			const_iterator end() const{return const_iterator(_BST.FindMax(_root), _compare);}

			reverse_iterator rbegin(){return reverse_iterator(end());}

			const_reverse_iterator rbegin() const{return const_reverse_iterator(end());}

			reverse_iterator rend(){return reverse_iterator(begin());}

			const_reverse_iterator rend() const{return const_reverse_iterator(begin());}


			/////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			bool empty() const{
				if (size() == 0)
					return true;
				return false;
			}

			size_type size() const{
				int count = 0;
				for (ft::MapIterator<T, Compare> it = begin(); it != end(); it++)
					count++;
				return count;
			}

			size_type max_size() const{
				return _alloc.max_size();
			}

			/////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			void clear(){ 
				erase(begin(), end());
			}

			ft::pair<iterator, bool> insert( const value_type& value ){
				ft::pair <map_node*, bool> ret = _BST.insertion(_root, value);
				_root = ret.first;
				return ft::make_pair(iterator(ret.first), ret.second);
			}

			iterator insert( iterator hint, const value_type& value ){
				(void)hint;
				ft::pair <map_node*, bool> ret = _BST.insertion(_root, value);
				_root = ret.first;
				return iterator(ret.first);
			}

			void erase( iterator pos ){
				_root = _BST.deletion(_root, *pos);
			}

			void erase( iterator first, iterator last ){
				while (first != last)
					erase(first++);
			}

			size_type erase( const Key& key ){
				if (find(key) == end())
					return (0);
				_root = _BST.deletion(_root, ft::make_pair(key, mapped_type()));
				return (1);
			}

			void swap( map& other ){
				_BST.swap(other);
			}

			//////////////////////////////// LOOKUP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			size_type count( const Key& key ) {
				if (find(key) == end())
					return 0;
				return 1;
			}

			iterator find( const Key& key ){
				iterator it = begin();
				for (; it != end() && it->first != key;it++)
					;
				return it;
			}

			const_iterator find( const Key& key ) const{
				const_iterator it = begin();
				for (; it != end() && it->first != key;it++)
					;
				return it;
			}

			ft::pair<iterator,iterator> equal_range( const Key& key ){
				iterator not_less = begin();
				for (; not_less != end() && not_less->first < key;not_less++)
					;
				if (not_less == end())
					return (ft::make_pair(end(), end()));
				iterator greater = not_less;
				for (; greater != end() && greater->first <= key;greater++)
					;
				if (greater == end())
					return (ft::make_pair(not_less, end()));
				return (ft::make_pair(not_less, greater));
			}

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const{
				return (ft::make_pair(lower_bound(key), upper_bound(key)));
			}

			iterator lower_bound( const Key& key ){
				iterator not_less = begin();
				for (; not_less != end() && not_less->first < key;not_less++)
					;
				return not_less;
			}

			const_iterator lower_bound( const Key& key ) const{
				const_iterator not_less = begin();
				for (; not_less != end() && not_less->first < key;not_less++)
					;
				return not_less;
			}

			iterator upper_bound( const Key& key ){
				iterator greater = begin();
				for (; greater != end() && greater->first <= key;greater++)
					;
				return (greater);
			}

			const_iterator upper_bound( const Key& key ) const{
				const_iterator greater = begin();
				for (; greater != end() && greater->first <= key;greater++)
					;
				return (greater);
			}

			/////////////////////////////// OBSERVERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			key_compare key_comp() const{
				return key_compare();
			}

			value_compare value_comp() const{
				return value_compare(key_compare());
			}

			////////////////////////// NON-MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\/

			friend bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return (lhs == rhs);
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