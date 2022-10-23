#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "../utils/utils.hpp"

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

        private:
            iterator_type _rit;
        
        public:
            reverse_iterator(): _rit(){}
            explicit reverse_iterator( iterator_type x ): _rit(x){}
            template< class U >
            reverse_iterator( const reverse_iterator<U>& other ): _rit(other.base()){}

            iterator_type base() const{return _rit;}

            reverse_iterator &operator ++ (){--_rit;return *this;}

            reverse_iterator  operator ++ (int){reverse_iterator tmp = *this;++(*this);return tmp;}

            reverse_iterator &operator -- (){++_rit;return *this;}

            reverse_iterator  operator -- (int){reverse_iterator tmp = *this;--(*this);return tmp;}

            reference operator * () const {iterator_type tmp = _rit; return (*(--tmp));}

            pointer operator -> () const{return &(operator*());}

            reverse_iterator operator + (difference_type n) const{return reverse_iterator(_rit - n);}

            reverse_iterator operator - (difference_type n) const{return reverse_iterator(_rit + n);}

			difference_type	 operator -	(const reverse_iterator & x) const		{ return (x.base() - _rit); }

            reverse_iterator &operator += (difference_type n){_rit -= n;return *this;}

            reverse_iterator &operator -= (difference_type n){_rit += n;return *this;}

            reference operator [] (difference_type n) const{return _rit[-n - 1];}

    };

    template <class iterator>
	reverse_iterator<iterator> operator + (
            typename reverse_iterator<iterator>::difference_type n,
            const reverse_iterator<iterator> &rev_it)
	{
		return reverse_iterator<iterator>(rev_it + n);
	}

	template <class iterator>
	typename reverse_iterator<iterator>::difference_type operator - (const reverse_iterator<iterator> &lhs, const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() - rhs.base();
	}

	template <class iterator>
	bool operator == (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator == (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() == rhs.base();
	}

	template <class iterator>
	bool operator != (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator != (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() != rhs.base();
	}

	template <class iterator>
	bool operator < (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator < (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <class iterator>
	bool operator <= (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator <= (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <class iterator>
	bool operator > (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator > (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <class iterator>
	bool operator >= (const reverse_iterator<iterator> &lhs,
			const reverse_iterator<iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <class iteratorL, class iteratorR>
	bool operator >= (const reverse_iterator<iteratorL> &lhs,
			const reverse_iterator<iteratorR> &rhs)
	{
		return lhs.base() <= rhs.base();
	}
}

#endif