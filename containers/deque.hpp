#ifndef DEQUE_HPP
# define DEQUE_HPP

# include "iterators/VectorIterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include <stdexcept>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >

    class deque{
        public:

            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t size_type;
		    typedef ft::VectorIterator<value_type>				iterator;
            typedef ft::VectorIterator<const value_type>        const_iterator;
            typedef ft::reverse_iterator<iterator>         reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;


        public:
            
            explicit deque (const allocator_type& alloc = allocator_type()) : 
                _alloc(alloc),
                _start(0),
                _size(0),
                _capacity(0){}
            
            explicit deque (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
                _alloc(alloc),
                _start(0),
                _size(n),
                _capacity(n)
            {
                assign(n, val);
            }
            template <class InputIterator>
            deque (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
                _alloc(alloc),
                _start(0),
                _size(0),
                _capacity(0)
            {
                assign(first, last);
            }
            deque (const deque& x) :
                _alloc(x._alloc),
                _start(0),
                _size(x._size),
                _capacity(x._capacity)
            {
                _start = _alloc.allocate(x._size);
                for (size_type i = 0; i < x._size;i++)
                    _alloc.construct(&_start[i], x._start[i]);
            }
            ~deque()
            {
                clear();
                _alloc.deallocate(_start, _capacity);
            }

            deque& operator= (const deque& x){
                if (*this == x)
                    return (*this);
                clear();
                _alloc.deallocate(_start, _capacity);
                _capacity = x._capacity;
                _size = x._size;
                _start = _alloc.allocate(_size);
                for (size_type i = 0;i < _size;i++)
                    _alloc.construct(&_start[i],x._start[i]);
                return (*this);
            }
    /////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            iterator begin(){
                return iterator(_start);
            }

            const_iterator begin() const{
                return const_iterator(_start);
            }

            iterator end(){
                return iterator(_start + _size);
            }

            const_iterator end() const{
                return const_iterator(_start + _size);
            }

            reverse_iterator rbegin(){
                return reverse_iterator(_start + _size);
            }

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(_start + _size);
            }

            reverse_iterator rend(){
                return reverse_iterator(_start);

            }

            const_reverse_iterator rend() const{
                return const_reverse_iterator(_start);
            }

    /////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            size_type size() const {
                return _size;
            }

            size_type max_size() const{
                return _alloc.max_size();
            }

            bool empty() const{
                if (_size == 0)
                    return true;
                else
                    return false;
            }

    //////////////////////////// ELEMENT ACCESS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            reference operator[] (size_type n){
                return _start[n];
            }

            const_reference operator[] (size_type n) const{
                return _start[n];
            }

            reference at (size_type n){
                if (n < _size)
                    return _start[n];
                else
                    throw std::out_of_range("deque");
            }

            const_reference at (size_type n) const{
                if (n < _size)
                    return _start[n];
                else
                    throw std::out_of_range("deque");
            }

            reference front(){
                return (*_start);
            }

            const_reference front() const{
                return (*_start);
            }

            reference back(){
                return (_start[_size - 1]);
            }

            const_reference back() const{
                return (_start[_size - 1]);
            }

    /////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            template <class InputIterator>
            void assign (InputIterator first, InputIterator last){
                InputIterator tmp = first;
                int range;
                while (tmp != last){
                    tmp++;
                    range++;
                }
                clear();
                if (range > _capacity){
                    _alloc.deallocate(_start, _capacity);
                    _start = _alloc.allocate(range);
                }
                _capacity = range;
                for (size_type i = 0;i < ft::distance(first, last) + i;i++){
                    _alloc.construct(&_start[i], *first);
                    first++;
                    _size = i;
                }
            }

            void assign (size_type n, const value_type& val){
                clear();
                if (_capacity == 0 && n > 0)
                    _start = _alloc.allocate(n);
                else if (n > _capacity){
                    _alloc.deallocate(_start, _capacity);
                    _start = _alloc.allocate(n);
                }
                _capacity = n;
                for (size_type i = 0;i < n;i++){
                    _alloc.construct(&_start[i], val[i]);
                    _size = i;
                }
            }

            void push_back (const value_type& val){
                if (_size >= _capacity){
                    if (_size == 0){
                        if (1 > _capacity){
                            size_type tmp_size;
                            value_type *tmp = _alloc.allocate(1);
                            for (size_type i = 0;i<_size;i++)
                                _alloc.construct(&tmp[i], _start[i]);
                            tmp_size = _size;
                            clear();
                            _alloc.deallocate(_start, _capacity);
                            _capacity = 1;
                            _start = tmp;
                            _size = tmp_size;
                        }
                    }
                    else{
                        if (_size * 2 > _capacity){
                            size_type tmp_size;
                            value_type *tmp = _alloc.allocate(_size * 2);
                            for (size_type i = 0;i<_size;i++)
                                _alloc.construct(&tmp[i], _start[i]);
                            tmp_size = _size;
                            clear();
                            _alloc.deallocate(_start, _capacity);
                            _capacity = tmp_size * 2;
                            _start = tmp;
                            _size = tmp_size;
                        }
                    }
                }
                _alloc.construct(&_start[_size], val);
                _size++;
            }

            void pop_back(){
                if (_size > 0)
                    _alloc.destroy(&_start[_size - 1]);
                _size--;
            }

            void push_front( const T& value ){
                if (_size >= _capacity){
                    if (_size == 0){
                        if (1 > _capacity){
                            size_type tmp_size;
                            value_type *tmp = _alloc.allocate(1);
                            for (size_type i = 0;i<_size;i++)
                                _alloc.construct(&tmp[i], _start[i]);
                            tmp_size = _size;
                            clear();
                            _alloc.deallocate(_start, _capacity);
                            _capacity = 1;
                            _start = tmp;
                            _size = tmp_size;
                        }
                    }
                    else{
                        if (_size * 2 > _capacity){
                            size_type tmp_size;
                            value_type *tmp = _alloc.allocate(_size * 2);
                            for (size_type i = 0;i<_size;i++)
                                _alloc.construct(&tmp[i], _start[i]);
                            tmp_size = _size;
                            clear();
                            _alloc.deallocate(_start, _capacity);
                            _capacity = tmp_size * 2;
                            _start = tmp;
                            _size = tmp_size;
                        }
                    }
                }
                value_type *tmp = _alloc.allocate(_capacity);
                size_type tmp_size = _size;
                _alloc.construct(&tmp[0], value);
                for (size_type j = 0;j<_size;j++)
                    _alloc.construct(&tmp[j + 1], _start[j]);
                clear();
                _alloc.deallocate(_start, _capacity);
                _start = tmp;
                _size = tmp_size + 1;
            }

            void pop_front(){
                if (_size == 0)
                    return;
                else if (_size == 1)
                    clear();
                else{
                    value_type *tmp = _alloc.allocate(_capacity);
                    size_type tmp_size = _size;
                    for (size_type j = 1;j<_size;j++)
                        _alloc.construct(&tmp[j - 1], _start[j]);
                    clear();
                    _alloc.deallocate(_start, _capacity);
                    _start = tmp;
                    _size = tmp_size - 1;
                }
            }

            iterator insert (iterator position, const value_type& val){
                size_type pos;

                pos = position - this->begin();
                insert(position, 1, val);
                return iterator(position + pos);
            }

            void insert (iterator position, size_type n, const value_type& val){
                if (!(n > 0))
                    return;
                size_type pos = 0;
                pos = this->begin() - position;
                if (pos <= _size){
                    if (_size + n > _capacity){
                        size_type tmp_size;
                        value_type *tmp = _alloc.allocate(n);
                        for (size_type i = 0;i<_size;i++)
                            _alloc.construct(&tmp[i], _start[i]);
                        tmp_size = _size;
                        clear();
                        _alloc.deallocate(_start, _capacity);
                        _capacity = _size + n;
                        _start = tmp;
                        _size = tmp_size;
                    }
                    size_type tmp_size = 0;
                    value_type *tmp = _alloc.allocate(pos + _size);
                    for (size_type i = 0;i<_size - pos;i++){
                        _alloc.construct(&tmp[i], _start[pos + i]);
                        tmp_size++;
                    }
                    for (size_type i = 0;i < tmp_size ;i++)
                        this->pop_back();
                    for (size_type i = 0;i < n;i++)
                        push_back(val);
                    for (size_type i = 0; i < tmp_size; i++)
                        push_back(tmp[i]);
                    for (size_type i = 0;i<tmp_size;i++)
                        _alloc.destroy(&tmp[i]);
                    _alloc.deallocate(tmp, tmp_size);
                }
                return ;
            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last){
                if (!(ft::distance(first, last) > 0))
                    return;
                size_type n = ft::distance(first, last);
                size_type pos = ft::distance(begin(), position);
                if (pos <= _size){
                    if (_size + n > _capacity){
                        size_type tmp_size;
                        value_type *tmp = _alloc.allocate(_size + n);
                        for (size_type i = 0;i<_size;i++)
                            _alloc.construct(&tmp[i], _start[i]);
                        tmp_size = _size;
                        clear();
                        _alloc.deallocate(_start, _capacity);
                        _capacity = _size + n;
                        _start = tmp;
                        _size = tmp_size;
                    }
                    int tmp_size = 0;
                    value_type *tmp = _alloc.allocate(pos + _size);
                    for (size_type i = 0;i<_size - pos;i++){
                        _alloc.construct(&tmp[i], _start[pos + i]);
                        tmp_size++;
                    }
                    for (int i = 0;i < tmp_size ;i++)
                        this->pop_back();
                    for (;first != last;first++)
                        push_back(*first);
                    for (int i = 0; i < tmp_size; i++)
                        push_back(tmp[i]);
                    for (int i = 0;i<tmp_size;i++)
                        _alloc.destroy(&tmp[i]);
                    _alloc.deallocate(tmp, tmp_size);
                }
                return ;
            }

            iterator erase (iterator position){
                return (this->erase(position, position + 1));
            }

            iterator erase (iterator first, iterator last){
                if (!(ft::distance(first, last) > 0))
                    return first;
                size_type n = ft::distance(first, last);
                int tmp_size = 0;
                value_type *tmp = _alloc.allocate(ft::distance(last - end()));
                for (int i = 0;i<ft::distance(last, end());i++){
                    _alloc.construct(&tmp[i], _start[_size - 1 - i]);
                    tmp_size++;
                }
                for (size_type i = 0;i<tmp_size + n;i++)
                    pop_back();
                for (int i = tmp_size - 1;i >= 0;i--)
                    push_back(tmp[i]);
                for (int i = 0;i<tmp_size;i++)
                    _alloc.destroy(&tmp[i]);
                _alloc.deallocate(tmp, tmp_size);
                return first;
            }

            void swap (deque& x){
                allocator_type	tmp_alloc;
                pointer			tmp_start;
                size_type		tmp_size;
                size_type		tmp_capacity;

                tmp_alloc = _alloc;
                tmp_start = _start;
                tmp_size = _size;
                tmp_capacity = _capacity;

                _alloc = x._alloc;
                _start = x._start;
                _size = x._size;
                _capacity = x._capacity;
                
                x._alloc = tmp_alloc;
                x._start = tmp_start;
                x._size = tmp_size;
                x._capacity = tmp_capacity;

            }

            void clear(){
                for (size_type i = 0;i<_size;i++)
                    _alloc.destroy(&_start[i]);
                _size = 0;
            }

    /////////////////////////////// ALLOCATOR \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            allocator_type get_allocator() const{
                return this->_alloc;
            }
        private:

            allocator_type	_alloc;
            pointer			_start;
            size_type		_size;
            size_type		_capacity;
    };

    ///////////////////// NON-MEMBER FUNCTION OVERLOADS \\\\\\\\\\\\\\\\\\\\\\/
        
        template <class T, class Alloc>
        bool operator== (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){

            if (lhs.size() != rhs.size())
                return false;
            typename ft::deque<T>::const_iterator first;
            typename ft::deque<T>::const_iterator second;

            first = lhs.begin();
            second = rhs.begin();

            for (size_t i = 0;i < lhs.size();i++){
                if (*first != *second)
                    return false;
                first++;
                second++;
            }
            return true;
        }

        template <class T, class Alloc>
        bool operator!= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){
            return !(lhs == rhs);
        }

        template <class T, class Alloc>
        bool operator<  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){
            typename ft::deque<T>::const_iterator first1;
            typename ft::deque<T>::const_iterator first2;

            first1 = lhs.begin();
            first2 = rhs.begin();

            while (first1!=lhs.end())
            {
                if (first2==rhs.end() || *first2<*first1)
                    return false;
                else if (*first1<*first2)
                    return true;
                ++first1;
                ++first2;
            }
            return (first2!=rhs.end());
        }

        template <class T, class Alloc>
        bool operator<= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){
            return !(rhs<lhs);
        }

        template <class T, class Alloc>
        bool operator>  (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){
            return (rhs<lhs);
        }

        template <class T, class Alloc>
        bool operator>= (const deque<T,Alloc>& lhs, const deque<T,Alloc>& rhs){
            return !(lhs<rhs);
        }

        template <class T, class Alloc>
        void swap (deque<T,Alloc>& x, deque<T,Alloc>& y){
            x.swap(y);
        }
}

#endif