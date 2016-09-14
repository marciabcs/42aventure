/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractvm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:37:10 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 14:09:28 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "abstractvm.hpp"
#include <utility>
#include <iostream>
#include <typeinfo>
#include <cinttypes>
#include <limits>

AbstractVM::AbstractVM()
{
}

AbstractVM::AbstractVM(std::list<token> inst):_operations(inst)
{
}
AbstractVM::AbstractVM(AbstractVM const &copy)
{
	*this = copy;
}

AbstractVM & AbstractVM::operator=(AbstractVM const &rhs)
{
	_operations = rhs._operations;
	return *this;
}

AbstractVM::~AbstractVM()
{
}

void AbstractVM::calc()
{

	for (std::list<token>::iterator it=_operations.begin(); it != _operations.end(); ++it)
	{
		switch((*it).intcomand)
		{
			case(0): push(*it); break;
			case(1): assert(*it); break;
			case(2): pop(*it); break;
			case(3): dump(*it); break;
			case(4): add(*it); break;
			case(5): sub(*it); break;
			case(6): mul(*it); break;
			case(7): div(*it); break;
			case(8): mod(*it); break;
			case(9): print(*it); break;
			case(10): exit(); break;
		}
	}
}

void AbstractVM::push(token calc)
{
		std::string value = calc.comand;
		std::size_t pos = value.find("(");
		std::size_t pos2 = value.find(")");
		value = value.substr(pos+1, pos2-pos);
		value.erase(value.end()-1);
		if (calc.type < FLOAT && value > "9223372036854775807")
			throw (Exception(": ERROR CALCULATOR : PUSH Operator overflow or underflow\n", calc.line));
		if (calc.type >= FLOAT && !AbstractVM::hasOverflow(std::stold(value), calc.type))
			_stack.push_front(_factory.createOperand(calc.type,value));
		else if (calc.type < FLOAT && !AbstractVM::hasOverflow_int(std::stoll(value), calc.type))
			_stack.push_front(_factory.createOperand(calc.type,value));
		else
			throw (Exception( ": ERROR CALCULATOR : PUSH Operator overflow or underflow\n", calc.line));
}

void AbstractVM::pop(token calc)
{
	if (!_stack.empty())
		_stack.pop_front();
	else
		throw (Exception(": ERROR CALCULATOR: Instruction POP in a empty stack\n", calc.line));
}
void AbstractVM::dump(token calc)
{
	if (!_stack.empty())
	{
		std::list<const IOperand*>::iterator itr;
		for (itr=_stack.begin(); itr != _stack.end(); ++itr)
			std::cout << (*itr)->toString()<<std::endl;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction DUMP in a empty stack\n", calc.line));
	
}
void AbstractVM::assert(token calc)
{
	if (!_stack.empty())
	{
		std::string value = calc.comand;
		std::size_t pos = value.find("(");
		std::size_t pos2 = value.find(")");
		value = value.substr(pos+1, pos2-pos);
		value.erase(value.end()-1);
		const IOperand *ass = _factory.createOperand(calc.type,value);
		const IOperand * op1 = *(_stack.begin());
		if (ass->getType() != op1->getType() || 
			ass->getPrecision() != op1->getPrecision() || 
			ass->toString() != op1->toString()) 
			throw (Exception( ": ERROR CALCULATOR: Instruction ASSERT not true\n", calc.line));
		delete ass;
	}
	else
		throw (Exception( ": ERROR CALCULATOR: Instruction ASSERT in a empty stack\n", calc.line));
	
}
void AbstractVM::add(token calc)
{
	if (_stack.size() >= 2)
	{
		const IOperand * op1 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * op2 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * res = *op1 + *op2;
		if (res->getType() == NONE)
			throw (Exception( ": ERROR CALCULATOR : ADD overflow or underflow\n", calc.line ));
		else
			_stack.push_front(res);
		delete op1;
		delete op2;
	}
	else
			throw (Exception( ": ERROR CALCULATOR: Instruction ADD with less than 2 operands in stack\n", calc.line));
}

void AbstractVM::sub(token calc)
{
	if (_stack.size() >= 2)
	{
		const IOperand * op1 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * op2 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * res = *op2 - *op1;
		if (res->getType() == NONE)
			throw (Exception(": ERROR CALCULATOR : SUB overflow or underflow\n", calc.line));
		else
			_stack.push_front(res);
		delete op1;
		delete op2;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction SUB with less than 2 operands in stack\n", calc.line));
}
void AbstractVM::mul(token calc)
{
	if (_stack.size() >= 2)
	{
		const IOperand * op1 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * op2 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * res = *op1 * *op2;
		if (res->getType() == NONE)
			throw (Exception(": ERROR CALCULATOR : MUL overflow or underflow\n", calc.line));
		else
			_stack.push_front(res);
		delete op1;
		delete op2;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction MUL with less than 2 operands in stack\n", calc.line));
}
void AbstractVM::div(token calc)
{
	if (_stack.size() >= 2)
	{
		const IOperand * op1 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * op2 = *(_stack.begin());
		_stack.pop_front();
		if (op1->toString() == "0")
			throw (Exception(": ERROR CALCULATOR: Division by 0\n", calc.line));
		else
		{
			const IOperand *res = *op2 / *op1;

			if (res->getType() == NONE)
				throw (Exception(": ERROR CALCULATOR : DIV overflow or underflow\n", calc.line));
			else
				_stack.push_front(res);
		}
		delete op1;
		delete op2;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction DIV with less than 2 operands in stack\n", calc.line));
}
void AbstractVM::mod(token calc)
{
	if (_stack.size() >= 2)
	{
		const IOperand * op1 = *(_stack.begin());
		_stack.pop_front();
		const IOperand * op2 = *(_stack.begin());
		_stack.pop_front();
		if (op1->toString() == "0")
			throw (Exception(": ERROR CALCULATOR: Modulo by 0\n", calc.line));
		else
		{
			const IOperand * res = *op2 % *op1;
			if (res->getType() == NONE)
				throw (Exception(": ERROR CALCULATOR : MOD overflow or underflow\n", calc.line));
			else
				_stack.push_front(res);
		}
		delete op1;
		delete op2;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction MOD with less than 2 operands in stack\n", calc.line));
}
void AbstractVM::print(token calc)
{
	if (!_stack.empty())
	{
		const IOperand * op1 = *(_stack.begin());
		eOperandType type = op1->getType();
		if (type == INT8)
			std::cout << static_cast<char>(std::stoi(op1->toString()))<<std::endl;
		else
			throw (Exception(": ERROR CALCULATOR: Operator not a INT8 type to PRINT\n", calc.line));
		delete op1;
	}
	else
		throw (Exception(": ERROR CALCULATOR: Instruction DUMP in a empty stack\n", calc.line));
}
void AbstractVM::exit(){}

bool AbstractVM::hasOverflow_int(long long r, eOperandType type)
{
	switch (type)
	{
		case (INT8):
			return (r > SCHAR_MAX || r < SCHAR_MIN);
		case (INT16):
			return  (r > INT_MAX || r < INT_MIN);
		case (INT32):
			return (r > LONG_MAX || r < LONG_MIN);
		case (FLOAT):
			return false;
		case (DOUBLE):
			return false;
		case (NONE):
			return false;
			break;
	}
}

bool AbstractVM::hasOverflow(long double r, eOperandType type)
{
	switch (type)
	{
		case (INT8):
			return false;
		case (INT16):
			return  false;
		case (INT32):
			return false;
		case (FLOAT):
			return (r > FLT_MAX || r < -FLT_MAX);
		case (DOUBLE):
			return (r > DBL_MAX || r < -DBL_MAX);
		case (NONE):
			return false;
			break;
	}
}

