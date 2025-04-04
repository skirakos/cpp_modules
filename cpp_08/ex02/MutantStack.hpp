#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include <stack>
#include <deque>


template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& original);
		MutantStack& operator=(const MutantStack& original);
		~MutantStack();
		
        typedef std::deque<T>                       container_type;
        typedef typename container_type::iterator   iterator;
        typedef typename container_type::iterator   const_iterator;
        typedef typename container_type::iterator   reverse_iterator;
        typedef typename container_type::iterator   const_reverse_iterator;

        iterator                  begin()        {return this->c.begin();}
        iterator                  end()          {return this->c.end();}
        const_iterator            begin() const  {return this->c.begin();}
        const_iterator            end() const    {return this->c.end();}
        reverse_iterator          rbegin()       {return this->c.rbegin();}
        reverse_iterator          rend()         {return this->c.rend();}
        const_reverse_iterator    rbegin() const {return this->c.rbegin();}
        const_reverse_iterator    rend()   const {return this->c.rend();}
};

#endif