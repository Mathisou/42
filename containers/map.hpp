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
			typedef ft::ConstMapIterator<map_node, Compare>						const_iterator;
			typedef ft::reverse_iterator<iterator> 							    reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					    const_reverse_iterator;

			typedef ptrdiff_t 											    	difference_type;
			typedef size_t 													    size_type;

		private:

			key_compare									_comp;
			allocator_type								_alloc;
			map_node									*_root;
			map_node									*_end;
			std::allocator<map_node>					_bstalloc;

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

			map(): _comp(), _alloc(), _root(NULL), _end(){
				// _alloc = Allocator();
				// _comp = Compare();
				_end = _bstalloc.allocate(1);
				_end->right = NULL;
				_end->is_end = true;
				_end->left = NULL;
			}

			explicit map( const Compare& comp, const Allocator& alloc = Allocator() ): _comp(comp), _alloc(alloc), _root(NULL){
				_end = _bstalloc.allocate(1);
				_end->right = NULL;
				_end->is_end = true;
				_end->left = NULL;
			}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = nullptr ) : _comp(comp), _alloc(alloc), _root()
			{
				_end = _bstalloc.allocate(1);
				_end->right = NULL;
				_end->is_end = true;
				_end->left = NULL;
				insert(first, last);
			}

			map( const map& other ): _comp(other._comp), _alloc(other._alloc), _root(), _end(){
				_end = _bstalloc.allocate(1);
				_end->right = NULL;
				_end->is_end = true;
				_end->left = NULL;
				insert(other.begin(), other.end());}

			~map(){clear();_bstalloc.deallocate(_end, 1);}

			map& operator=( const map& other )
			{
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
					throw std::out_of_range("map::at");
				else
					return (*it).second;
			}

			const T& at( const Key& key ) const{
				const_iterator it = find(key);
				if (it == end())
					throw std::out_of_range("map::at");
				else
					return (*it).second;
			}

			mapped_type& operator[]( const key_type& key ){
				insert(ft::make_pair(key, mapped_type()));
				return find(key)->second;
			}

			/////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
			#include <iostream>
			iterator begin(){
				map_node *ret = _root->FindMin(_root);
				if (!ret)
					return iterator(_end, _comp);
				return iterator(_root->FindMin(_root), _comp);
			}

			const_iterator begin() const{
				map_node *ret = _root->FindMin(_root);
				if (!ret)
					return const_iterator(_end, _comp);
				return const_iterator(_root->FindMin(_root), _comp);
			}

			iterator end(){return iterator(_end, _comp);}

			const_iterator end() const{return const_iterator(_end, _comp);}

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
				const_iterator ite = end();
				for (const_iterator it = begin(); it != ite; it++)
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
				map_node *max = _root->FindMax(_root);
				if (max)
					max->right = NULL;
				ft::pair <map_node*, bool> ret = _root->insertion(_root, value);
				_root = ret.first;
				max = _root->FindMax(_root);
				max->right = _end;
				_end->right = max;
				iterator it = find(value.first);
				return ft::make_pair(it, ret.second);
			}

			iterator insert( iterator hint, const value_type& value ){
				(void)hint;
				map_node *max = _root->FindMax(_root);
				if (max)
					max->right = NULL;
				ft::pair <map_node*, bool> ret = _root->insertion(_root, value);
				_root = ret.first;
				max = _root->FindMax(_root);
				max->right = _end;
				_end->right = max;
				return find(value.first);
			}

			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				ft::pair <map_node*, bool> ret;
				map_node *max;
				for (;first != last;first++){
					max = _root->FindMax(_root);
					if (max)
						max->right = NULL;
					ret = _root->insertion(_root, *first);
					_root = ret.first;
					max = _root->FindMax(_root);
					max->right = _end;
					_end->right = max;
				}
			}

			void erase( iterator pos ){
				_root = _root->deletion(_root, *pos);
				map_node *max = _root->FindMax(_root);
				max->right = _end;
				_end->right = max;
			}

			void erase( iterator first, iterator last ){
				map_node *max;
				while (first != last){
					_root = _root->deletion(_root, *first++);
					max = _root->FindMax(_root);
					max->right = _end;
					_end->right = max;
				}
			}

			size_type erase( const Key& key ){
				if (find(key) == end())
					return (0);
				_root = _root->deletion(_root, ft::make_pair(key, mapped_type()));
				map_node *max = _root->FindMax(_root);
				max->right = _end;
				_end->right = max;
				return (1);
			}

			void swap( map& other ){
				key_compare									tmpcomp = _comp;
				allocator_type								tmpalloc = _alloc;
				map_node									*tmproot = _root;
				map_node									*tmpend = _end;
				std::allocator<map_node>					tmpbstalloc = _bstalloc;

				_comp = other._comp;
				_alloc = other._alloc;
				_root = other._root;
				_end = other._end;
				_bstalloc = other._bstalloc;

				other._comp = tmpcomp;
				other._alloc = tmpalloc;
				other._root = tmproot;
				other._end = tmpend;
				other._bstalloc = tmpbstalloc;
				
				
			}

			//////////////////////////////// LOOKUP \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

			size_type count( const Key& key ) const {
				if (find(key) == end())
					return 0;
				return 1;
			}

			iterator find( const Key& key ) {
				iterator it = begin();
				for (; it != end() && it->first != key;it++)
					;
				if (it == end())
					return end();
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
				for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
				{
					if (*first1 < *first2)
						return true;
					if (*first2 < *first1)
						return false;
				}
				if ((first1 == last1 && first2 == last2) || (first1 == last1 && first2 != last2))
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
				for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
				{
					if (*first1 < *first2)
						return true;
					if (*first2 < *first1)
						return false;
				}
				if ((first1 == last1 && first2 == last2) || (first1 == last1 && first2 != last2))
					return true;
				return false;
			}

			friend void swap( ft::map<Key,T,Compare,Allocator>& lhs, ft::map<Key,T,Compare,Allocator>& rhs ){
				lhs.swap(rhs);
			}

    };
}

#endif