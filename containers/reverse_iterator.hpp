#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <stdlib.h>

namespace ft
{

    template <class iterator>

    class reverse_iterator
    {
        public:
            typedef iterator                                                    iterator_type;
            typedef typename ft::iterator_traits<iterator>::iterator_category	iterator_category;
            typedef typename ft::iterator_traits<iterator>::value_type			value_type;
            typedef typename ft::iterator_traits<iterator>::reference 			reference;
            typedef typename ft::iterator_traits<iterator>::pointer				pointer;
            typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;

        protected:
            iterator_type _rit;
        
        public:
            pointer get_ptr() const{return _rit;}
            reverse_iterator(): _rit(NULL){}
            explicit reverse_iterator( iterator_type x ): _rit(x){}
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other ): _rit(other.base()){}
    };

}

#endif