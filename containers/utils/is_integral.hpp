#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP


namespace ft
{

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
}

#endif