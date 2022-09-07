#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>

namespace ft
{
    //////// ENABLE_IF \\\\\\\/
    template< bool B, class T = void >

    struct enable_if
    {
    };


    template< class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    //////// IS_INTEGRAL \\\\\\\/
    template <bool is_integral, typename T>
        struct integral_res
		{
            typedef T type;
            static const bool value = is_integral;
        };


	template <typename>
        struct integral_type : public integral_res<false, bool> {};

    template <>
        struct integral_type<bool> : public integral_res<true, bool> {};

    template <>
        struct integral_type<char> : public integral_res<true, char> {};

    template <>
        struct integral_type<signed char> : public integral_res<true, signed char> {};

    template <>
        struct integral_type<short int> : public integral_res<true, short int> {};
    
    template <>
        struct integral_type<int> : public integral_res<true, int> {};

    template <>
        struct integral_type<long int> : public integral_res<true, long int> {};

    template <>
        struct integral_type<long long int> : public integral_res<true, long long int> {};

    template <>
        struct integral_type<unsigned char> : public integral_res<true, unsigned char> {};

    template <>
        struct integral_type<unsigned short int> : public integral_res<true, unsigned short int> {};

    template <>
        struct integral_type<unsigned int> : public integral_res<true, unsigned int> {};

    template <>
        struct integral_type<unsigned long int> : public integral_res<true, unsigned long int> {};
    
    template <>
        struct integral_type<unsigned long long int> : public integral_res<true, unsigned long long int> {};

	template< typename T >
	struct is_integral : public integral_type<T>
	{};
    //////// LEXICOGRAPHICAL_COMPARE \\\\\\\/
    template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 ){
		for (; first1!=last1 && first2!=last2; first1++, first2++){
			if (*first1 < *first2)
				return true;
			else if (*first1 > *first2)
				return false;
		}
		if (first1 == last1 && first2 != last2)
			return true;
		else
			return false;
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp ){
		for (; first1!=last1 && first2!=last2; first1++, first2++){
			if (comp(first1, first2))
				return true;
			else if (comp(*first2, *first1))
				return false;
		}
		if (first1 == last1 && first2 != last2)
			return true;
		else
			return false;
	}
    //////// Pair \\\\\\\/
    template<class T1, class T2>

	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair(): first(), second(){}

		pair( const T1& x, const T2& y ): first(x), second(y){}

		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ): first(p.first), second(p.second){}

		pair& operator=( const pair& other ){if (*this == other)return *this;first = other.first;second = other.second; return *this;}
	};

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 t, T2 u ){
		return (pair<T1, T2>(t, u));
	}

	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	}

	template< class T1, class T2 >
	bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template< class T1, class T2 >
	bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs > rhs);
	}

	template< class T1, class T2 >
	bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
		return !(rhs > lhs);
	}
    //////// ITERATOR_TAG \\\\\\\/

    class random_access_iterator_tag { };

    class bidirectional_iterator_tag { };

    class forward_iterator_tag { };

    class input_iterator_tag { };

    class output_iterator_tag { };

    //////// ITERATOR \\\\\\\/
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
        class iterator
        {
            public:
                typedef T           value_type;
                typedef Distance    difference_type;
                typedef Pointer     pointer;
                typedef Reference   reference;
                typedef Category    iterator_category;
        };

    template <class T>
        class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
        {  
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category     iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type            value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type       difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer               pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference             reference;
            
            private:
                pointer _elem;
        };
    
    template <class Arg1, class Arg2, class Result>
    struct binary_function
    {
        typedef Arg1 first_argument_type;

        typedef Arg2 second_argument_type;

        typedef Result result_type;
    };

    template <class T>
    struct less : binary_function<T, T, bool>
    {
        bool operator() (const T& x, const T& y) const { return (x < y); }
    };
}

#endif