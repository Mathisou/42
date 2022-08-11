#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <iterator>

namespace ft
{

	template <class T, class Alloc = std::allocator<T> >

    class vector{
        public:

            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
		    // typedef ft::VectorIterator<value_type>				iterator;
            // typedef ft::VectorIterator<const value_type> const_iterator;
            // typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
            // typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
            // typedef typename std::stack<T>::container_type::difference_type difference_type;


        public:

            explicit vector (const allocator_type& alloc = allocator_type()) : 
                _alloc(alloc),
                _start(0),
                _size(0),
                _capacity(0){}
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
                _alloc(alloc),
                _start(0),
                _size(n),
                _capacity(n)
            {
                // _start = _alloc.allocate(n);
                // for (size_type i = 0;i<n;i++)
                //     _alloc.construct(&_start[i], val);
                assign(n, val);
            }
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
                _alloc(alloc),
                _start(0),
                _size(0),
                _capacity(0)
            {
                // alloc.allocate(last - first);
                // for (size_type i = 0;i < last - first + i;i++){
                //     alloc.construct(&_start[i], *first);                //Tres probablement faux
                //     first++;
                // }
                // appeler directement assign().
                assign(first, last);
            }
            vector (const vector& x) :
                _alloc(x._alloc),
                _start(0),
                _size(x._size),
                _capacity(x._capacity)
            {
                _start = _alloc.allocate(x._size);
                for (size_type i = 0; i < x._size;i++)
                    _alloc.construct(&_start[i], x._start[i]);
            }
            ~vector()
            {
                clear(); // destroy all objects
                _alloc.deallocate(_start, _capacity);
            }

            vector& operator= (const vector& x){
                if (*this == x)
                    return (*this);
                _capacity = x._capacity;
                _size = x._size;
                clear();
                _alloc.deallocate(_start, _capacity);
                _start = _alloc.allocate(_size);
                for (size_type i = 0;i < _size;i++)
                    _alloc.construct(&_start[i],x._start[i]);
                return (*this);
            }
    /////////////////////////////// ITERATORS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/
            // iterator begin(){
            //     return c.begin();
            // }
            // iterator end(){
            //     return c.end();
            // }
            // iterator rbegin(){
            //     return c.rbegin();
            // }
            // iterator rend(){
            //     return c.rend();
            // }
            // iterator cbegin(){
            //     return c.cbegin();
            // }
            // iterator cend(){
            //     return c.cend();
            // }
            // iterator crbegin(){
            //     return c.crbegin();
            // }
            // iterator crend(){
            //     return c.crend();
            // }

    /////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            size_type size() const {
                return _size;
            }

            size_type max_size() const{
                return _alloc.max_size();
            }

            void resize (size_type n, value_type val = value_type()){
                if (n < _size){
                    while (_size > n)
                        pop_back();
                }
                else if (n > _size){
                    for (int i = 0;_size < n;i++) // dans le cas ou val contient toujours assez d'element pour completer jusqua n
                        push_back(val[i]);
                }
            }

            size_type capacity() const{
                return (_capacity);
            }

            bool empty() const{
                if (_size == 0)
                    return true;
                else
                    return false;
            }

            void reserve (size_type n){
                if (n > _capacity){
                    value_type *tmp = _alloc.allocate(n);
                    for (int i = 0;i<_size;i++)
                        _alloc.construct(&tmp[i], _start[i]);
                    clear();
                    _alloc.deallocate(_start, _capacity);
                    _capacity = n;
                    _start = tmp;
                    // _start = _alloc.allocate(n);
                    // for (int i = 0;i<_size;i++)
                    //     _alloc.construct(&_start[i], tmp[i]);
                    // for (int i = 0;i<_size,i++){
                    //     _alloc.destroy(tmp[i]);
                    // }
                    // _alloc.deallocate(tmp, _capacity);
                }
            }

    //////////////////////////// ELEMENT ACCESS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            reference operator[] (size_type n){
                return _start[n];
            }

            const_reference operator[] (size_type n) const{
                return _start[n];
            }

            reference at (size_type n){
                if (n <= _size)
                    return _start[n];
                else
                    throw std::out_of_range("vector");
            }

            const_reference at (size_type n) const{
                if (n <= _size)
                    return _start[n];
                else
                    throw std::out_of_range("vector");
            }

            reference front(){
                if (_size > 0)
                    return (*_start);
            }

            const_reference front() const{
                if (_size > 0)
                    return (*_start);
            }

            reference back(){
                if (_size > 0)
                    return (_start[_size - 1]);
            }

            const_reference back() const{
                if (_size > 0)
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
                for (size_type i = 0;i < last - first + i;i++){
                    _alloc.construct(&_start[i], *first);   //Tres probablement faux
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
                    _alloc.construct(&_start[i], val[i]);   //Tres probablement faux
                    _size = i;
                }
            }

            void push_back (const value_type& val){
                if (_size >= _capacity){
                    reserve(_capacity + 1);
                }
                _alloc.construct(&_start[_size], val);
                _size++;
            }

            void pop_back(){
                if (_size > 0)
                    _alloc.destroy(_start[_size - 1]);
                _size--;
            }

            iterator insert (iterator position, const value_type& val){

            }

            void insert (iterator position, size_type n, const value_type& val){

            }

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last){

            }

            iterator erase (iterator position){

            }

            iterator erase (iterator first, iterator last){

            }

            void swap (vector& x){
                allocator_type	tmp_alloc;
                pointer			tmp_start;
                size_type		tmp_size;
                size_type		tmp_capacity;

                tmp_alloc = _alloc;
                tmp_start = _start;
                tmp_size = _size;
                tmp_capacity = _capacity

                _alloc = x.alloc;
                _start = x.start;
                _size = x.size;
                _capacity = x.capacity;
                
                x._alloc = tmp_alloc;
                x._start = tmp_start;
                x._size = _size;
                x._capacity = tmp_capacity

            }

            void clear(){
                for (size_type i = 0;i<_size;i++)
                    _alloc.destroy(_start[i]);
                _size = 0;
            }

    /////////////////////////////// ALLOCATOR \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

            allocator_type get_allocator() const{
                return this->_alloc;
            }

    ///////////////////// NON-MEMBER FUNCTION OVERLOADS \\\\\\\\\\\\\\\\\\\\\\/


            template <class T, class Alloc>
            bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){

            }

            template <class T, class Alloc>
            void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){

            }

        private:

            allocator_type	_alloc;
            pointer			_start;
            size_type		_size;
            size_type		_capacity;
    };
}

#endif
