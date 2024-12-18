#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(std::string const & str) : _str(str)
{
}

RPN::~RPN() {}

RPN::RPN(RPN const & src) {
	this->_stack = src._stack;
	this->_str = src._str;
}

RPN &RPN::operator=(RPN const & src) {
	if (this != &src) {
		this->_stack = src._stack;
		this->_str = src._str;
	}
	return (*this);
}

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::calculate()
{
	while (!_str.empty())
	{
		if (_str[0]	== ' ')
			_str.erase(0, 1);
		else if (_str[0] >= '0' && _str[0] <= '9')
		{
			_stack.push(_str[0] - '0');
			_str.erase(0, 1);
		}
		else if (isOperator(_str[0]))
		{
			doOp(_str[0]);
			_str.erase(0, 1);
		}
		else
			throw std::invalid_argument("Invalid argument");
	}
}

void RPN::doOp(char op)
{
	if (_stack.size() < 2)
		throw std::invalid_argument("Invalid argument");
	int a = _stack.top();
	_stack.pop();
	int b = _stack.top();
	_stack.pop();
	switch (op)
	{
		case '+':
			_stack.push(b + a);
			break;
		case '-':
			_stack.push(b - a);
			break;
		case '*':
			_stack.push(b * a);
			break;
		case '/':
			if (a == 0)
				throw std::invalid_argument("Division by zero");
			_stack.push(b / a);
		break;
	}
}

void RPN::printResult() const
{
	if (_stack.size() != 1)
		throw std::invalid_argument("Invalid argument");
	std::cout << _stack.top() << std::endl;
}
