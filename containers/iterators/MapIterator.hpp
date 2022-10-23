#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "../utils/BST.hpp"

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
            
			T          *_node;
			Compare     _comp;

            MapIterator(const Compare& comp = Compare()) : _node(), _comp(comp){}

            MapIterator(T * node_p, const Compare& comp = Compare()): _node(node_p), _comp(comp){}

            MapIterator(const MapIterator& other) : _node(other._node), _comp(){}

            ~MapIterator(){}

            MapIterator &operator=(const MapIterator &other){
                if (this == &other)
                    return *this;
                _node = other._node;
                _comp = other._comp;
                return *this;
            }

            MapIterator& operator++(){
                T *tmp_p = NULL;
                T *tmp_r = _node;
                T *check = _node;
                if (check->right && check->right->is_end == true)
                {
                    _node = _node->right;
                    return *this;
                }
                while (1)
                {
                    if (tmp_r->right)
                    {
                        tmp_r = tmp_r->right;
                        while (tmp_r->left)
                            tmp_r = tmp_r->left;
                        if (tmp_p && _comp(tmp_p->value.first,tmp_r->value.first))
                            _node = tmp_p;
                        else
                            _node = tmp_r;
                        return *this;
                    }
                    else
                    {
                        tmp_p = _node;
                        while (_comp(tmp_p->parent->value.first,_node->value.first))
                            tmp_p = tmp_p->parent;
                        tmp_p = tmp_p->parent;
                        if (tmp_p->right == NULL || tmp_p->right->is_end == true)
                        {
                            _node = tmp_p;
                            return *this;
                        }
                        tmp_r = tmp_p;
                    }
                }
            }

            MapIterator operator++(int){
                MapIterator tmp(*this);
				operator++();
				return (tmp);
            }

            MapIterator& operator--() {
                if (_node->is_end == true){
                    _node = _node->right;
                    return *this;
                }
                T *tmp_p = NULL;
                T *tmp_l = _node;
                T *check = _node;
                if (check->left == NULL)
                {
                    while (check){
                        if (_comp(_node->value.first,check->value.first) || check->value.first == _node->value.first)
                            check = check->parent;
                        else
                            break;
                        if (check == NULL){
                            _node = _node->left;
                            return *this;
                        }
                    }
                }
                while (1)
                {
                    if (tmp_l->left)
                    {
                        tmp_l = tmp_l->left;
                        while (tmp_l->right)
                            tmp_l = tmp_l->right;
                        if (tmp_p && _comp(tmp_l->value.first,tmp_p->value.first))
                            _node = tmp_p;
                        else
                            _node = tmp_l;
                        return *this;
                    }
                    else
                    {
                        tmp_p = _node;
                        while (_comp(_node->value.first,tmp_p->parent->value.first))
                            tmp_p = tmp_p->parent;
                        tmp_p = tmp_p->parent;
                        if (tmp_p->left == NULL)
                        {
                            _node = tmp_p;
                            return *this;
                        }
                        tmp_l = tmp_p;
                    }
                }
                return *this;
            }

            MapIterator operator--(int) {
                MapIterator tmp(*this);
				operator--();
				return (tmp);
            }
            
            bool operator == (const MapIterator &other) const {return (_node == other._node);}

            bool operator != (const MapIterator &other) const {return (_node != other._node);}

            bool operator>(const MapIterator &other) const {return _node > other._node;}

            bool operator>=(const MapIterator &other) const {return _node >= other._node;}

            bool operator<(const MapIterator &other) const {return _node < other._node;}

            bool operator<=(const MapIterator &other) const {return _node <= other._node;}

            reference operator*() const {return _node->value;}

            pointer operator->() const {return &_node->value;}


    };
    template<class T, class U>

    std::ostream& operator<<( std::ostream & o, MapIterator<T, U> const & i ){o << i._node;return o;}


	template <typename T, class Compare >

    class ConstMapIterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        public:

			typedef typename T::value_type const                                                            value_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category    iterator_category;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type      difference_type;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer              pointer;
			typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference            reference;
            
			T          *_node;
			Compare     _comp;

            ConstMapIterator(const Compare& comp = Compare()) : _node(), _comp(comp){}

            ConstMapIterator(T * node_p, const Compare& comp = Compare()): _node(node_p), _comp(comp){}
            
            ConstMapIterator(const ConstMapIterator& other) : _node(other._node), _comp(){}

            ConstMapIterator(const MapIterator<T, Compare >& bst_it)
			:
				_node(bst_it._node),
				_comp()
			{}

            ~ConstMapIterator(){}

            ConstMapIterator &operator=(const ConstMapIterator &other){
                if (this == &other)
                    return *this;
                _node = other._node;
                return *this;
            }

            ConstMapIterator& operator++(){
                T *tmp_p = NULL;
                T *tmp_r = _node;
                T *check = _node;
                if (check->right && check->right->is_end == true)
                {
                    _node = _node->right;
                    return *this;
                }
                while (1)
                {
                    if (tmp_r->right)
                    {
                        tmp_r = tmp_r->right;
                        while (tmp_r->left)
                            tmp_r = tmp_r->left;
                        if (tmp_p && _comp(tmp_p->value.first,tmp_r->value.first))
                            _node = tmp_p;
                        else
                            _node = tmp_r;
                        return *this;
                    }
                    else
                    {
                        tmp_p = _node;
                        while (_comp(tmp_p->parent->value.first,_node->value.first))
                            tmp_p = tmp_p->parent;
                        tmp_p = tmp_p->parent;
                        if (tmp_p->right == NULL || tmp_p->right->is_end == true)
                        {
                            _node = tmp_p;
                            return *this;
                        }
                        tmp_r = tmp_p;
                    }
                }
            }

            ConstMapIterator operator++(int){
                ConstMapIterator tmp(*this);
				operator++();
				return (tmp);
            }

            ConstMapIterator& operator--() {
                if (_node->is_end == true){
                    _node = _node->right;
                    return *this;
                }
                T *tmp_p = NULL;
                T *tmp_l = _node;
                T *check = _node;
                if (check->left == NULL)
                {
                    while (check){
                        if (_comp(_node->value.first,check->value.first) || check->value.first == _node->value.first)
                            check = check->parent;
                        else
                            break;
                        if (check == NULL){
                            _node = _node->left;
                            return *this;
                        }
                    }
                }
                while (1)
                {
                    if (tmp_l->left)
                    {
                        tmp_l = tmp_l->left;
                        while (tmp_l->right)
                            tmp_l = tmp_l->right;
                        if (tmp_p && _comp(tmp_l->value.first,tmp_p->value.first))
                            _node = tmp_p;
                        else
                            _node = tmp_l;
                        return *this;
                    }
                    else
                    {
                        tmp_p = _node;
                        while (_comp(_node->value.first,tmp_p->parent->value.first))
                            tmp_p = tmp_p->parent;
                        tmp_p = tmp_p->parent;
                        if (tmp_p->left == NULL)
                        {
                            _node = tmp_p;
                            return *this;
                        }
                        tmp_l = tmp_p;
                    }
                }
                return *this;
            }

            ConstMapIterator operator--(int) {
                ConstMapIterator tmp(*this);
				operator--();
				return (tmp);
            }
            
            bool operator == (const ConstMapIterator &other) const {return (_node == other._node);}

            bool operator == (const MapIterator<T, Compare> &other) const {return (_node == other._node);}

            bool operator != (const ConstMapIterator &other) const {return (_node != other._node);}

            bool operator>(const ConstMapIterator &other) const {return _node > other._node;}

            bool operator>=(const ConstMapIterator &other) const {return _node >= other._node;}

            bool operator<(const ConstMapIterator &other) const {return _node < other._node;}

            bool operator<=(const ConstMapIterator &other) const {return _node <= other._node;}

            reference operator*() const {return _node->value;}

            pointer operator->() const {return &_node->value;}
    };
    template<class T, class U>

    std::ostream& operator<<( std::ostream & o, ConstMapIterator<T, U> const & i ){o << i._node;return o;}
}

#endif 