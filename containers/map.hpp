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

			key_compare									_comp;
			allocator_type								_alloc;
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

			map(): _comp(), _alloc(), _root(){}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _comp(comp), _alloc(alloc), _root(){}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _comp(comp), _alloc(alloc), _root(){
				insert(first, last);
			}

			map( const map& other ): _comp(other._comp), _alloc(other._alloc), _root(){insert(other.begin(), other.end());}

			~map(){clear();}

			map& operator=( const map& other )
			{
				std::cout << "operator=" << std::endl;
				if (&other == this)
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
					throw std::out_of_range("map::at:  key not found");
				else
					return (*it).second;
			}

			const T& at( const Key& key ) const{
				const_iterator it = find(key);
				if (it == end())
					throw std::out_of_range("map::at:  key not found");
				else
					return (*it).second;
			}

			T& operator[]( const Key& key ){
				insert(ft::make_pair(key, T()));
				return find(key)->second;
			}

			/////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
			#include <iostream>
			iterator begin(){return iterator(_root->FindMin(_root), _comp);}

			const_iterator begin() const{return const_iterator(_root->FindMin(_root), _comp);}

			iterator end(){return iterator(_root->FindMax(_root), _comp);}

			const_iterator end() const{return const_iterator(_root->FindMax(_root), _comp);}

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
				for (const_iterator it = begin(); it != end(); it++)
					count++;
				return count;
			}

			size_type max_size() const{
				return _alloc.max_size();
			}

			/////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			void clear(){ 
				erase(this->begin(), this->end());
			}

			ft::pair<iterator, bool> insert( const value_type& value ){
				ft::pair <map_node*, bool> ret = _root->insertion(_root, value);
				_root = ret.first;
				return ft::make_pair(iterator(ret.first), ret.second);
			}

			iterator insert( iterator hint, const value_type& value ){
				(void)hint;
				ft::pair <map_node*, bool> ret = _root->insertion(_root, value);
				_root = ret.first;
				return iterator(ret.first);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				ft::pair <map_node*, bool> ret;
				for (;first != last;first++){
					ret = _root->insertion(_root, *first);
					_root = ret.first;
				}
			}

			void erase( iterator pos ){
				_root = _root->deletion(_root, *pos);
			}

			void erase( iterator first, iterator last ){
				while (first != last)
					erase(first++);
			}

			size_type erase( const Key& key ){
				if (find(key) == end())
					return (0);
				_root = _root->deletion(_root, ft::make_pair(key, mapped_type()));
				return (1);
			}

			void swap( map& other ){
				_root->swap(other);
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
				const_iterator it = lhs.begin();
				const_iterator it2 = rhs.begin();
				for (; it != lhs.end() && it2 != rhs.end(); it++, it2++)
					if (it->first != it2->first)
						return false;
				if (it == lhs.end() && it2 == rhs.end())
					return true;
				return false;
			}

			friend bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				const_iterator it = lhs.begin();
				const_iterator it2 = rhs.begin();
				for (; it != lhs.end() && it2 != rhs.end(); it++, it2++)
					if (it->first != it2->first)
						return true;
				if (it == lhs.end() && it2 == rhs.end())
					return false;
				return true;
			}

			friend bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}

			friend bool operator<=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				const_iterator first1 = lhs.begin();
				const_iterator last1 = lhs.end();
				const_iterator first2 = rhs.begin();
				const_iterator last2 = rhs.end();
				for (; first1!=last1 && first2!=last2; first1++, first2++){
					if (*first1 <= *first2)
						return true;
					if (*first1 > *first2){}
						return false;
				}
				if (first1 == last1 && first2 != last2)
					return true;
				return false;
			}

			friend bool operator>( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
			}

			friend bool operator>=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs ){
				const_iterator first1 = rhs.begin();
				const_iterator last1 = rhs.end();
				const_iterator first2 = lhs.begin();
				const_iterator last2 = lhs.end();
				for (; first1!=last1 && first2!=last2; first1++, first2++){
					if (*first1 <= *first2)
						return true;
					if (*first1 > *first2){}
						return false;
				}
				if (first1 == last1 && first2 != last2)
					return true;
				return false;
			}

			friend void swap( ft::map<Key,T,Compare,Allocator>& lhs, ft::map<Key,T,Compare,Allocator>& rhs ){
				lhs.swap(rhs);
			}

    };
}

#endif