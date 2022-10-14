#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
#include "deque.hpp"

namespace ft
{

	template <class T, class Container = ft::deque<T> >


    class stack{

        public:

            typedef	T				                        value_type;
            typedef	Container		                        container_type;
            typedef	size_t		                            size_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;

        protected:

            container_type _c;

        public:

            explicit stack( const Container& cont = Container() ) : _c(cont){}

            ~stack(){}

            stack& operator=( const stack& other ){
                _c = other._c;
            }

        //////////////////////////// ELEMENT ACCESS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

        reference top(){return _c.back();}

        const_reference top() const{ return _c.back();}

        /////////////////////////////// CAPACITY \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

        bool empty() const{return _c.empty();}

        size_type size() const{return _c.size();}

        ////////////////////////////// MODIFIERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\/

        void push( const value_type& value ){_c.push_back(value);}

        void pop(){_c.pop_back();}

        ////////////////////////// NON-MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\/

        friend bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c == rhs._c);
        }

        friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c != rhs._c);
        }

        friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c < rhs._c);
        }

        friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c <= rhs._c);
        }

        friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c > rhs._c);
        }

        friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){
            return (lhs._c >= rhs._c);
        }
    };

}

#endif