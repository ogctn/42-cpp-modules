#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <sstream>

class RPN {
	private:
		std::stack<float> _stack;
		std::string _str;
		RPN();

	public:
		RPN(std::string const & str);
		~RPN();
		RPN(RPN const & src);
		RPN & operator=(RPN const & src);

		void calculate();
		void printResult() const;
		void doOp(char op);
};

# endif
