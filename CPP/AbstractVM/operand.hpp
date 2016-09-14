/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:32:35 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 14:18:12 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include "ioperand.hpp"
#include "abstractvm.hpp"
#include "factory.hpp"

template <class T>
class Operand: public IOperand{

	T 					_value;
	eOperandType		_type;
	int					_precision;
	const Factory*			_factory;
	std::string			_str;

	public:
		Operand(void){}

		Operand (std::string const & value, eOperandType type, int precision, const Factory* factory)
		: _type(type)
		, _precision(precision)
		, _factory(factory)
		{
			
			if (_type >INT32)
			{
				long double v = std::stold(value);
				_value = static_cast<T>(v);
				std::stringstream ss;
				ss << std::setprecision(precision) << v;
				_str = ss.str();
			}
			else 
			{
				long long v = std::stoll(value);
				_value = static_cast<T>(v);
				std::stringstream ss;
				ss  << v;
				_str = ss.str();
			}
		}
		
		Operand (Operand const & f)
		{
			*this = f;
		}
		virtual ~Operand(void){}

		Operand & operator=(Operand const & c)
		{
			_value = c._value;
			_type = c._type;
			_precision = c._precision;
			_factory = c._factory;
			_str = c._str;
			return *this;
		}
		int getPrecision( void ) const 
		{
			return _precision;
		}

		eOperandType getType( void ) const
		{
			return _type;
		}

		IOperand const * operator+( IOperand const & rhs ) const
		{
			eOperandType t = ( _type >= rhs.getType() ) ? _type : rhs.getType();
			int p = ( _precision >= rhs.getPrecision() ) ? _precision: rhs.getPrecision();
			std::stringstream ss (std::stringstream::out);
			if (t < FLOAT)
			{
				long long r = std::stoll(_str) + std::stoll(rhs.toString());
				ss << r;
				if (AbstractVM::hasOverflow_int(r, t))
					t = NONE;
			}
			else
			{
				long double r = std::stold(_str) + std::stold(rhs.toString());
				ss << std::setprecision(p) << r;
				if (AbstractVM::hasOverflow(r, t))
					t = NONE;
			}
			return (_factory->createOperand(t, ss.str()));
		}
		IOperand const * operator-(IOperand const &rhs) const
		{
			eOperandType t = ( _type >= rhs.getType() ) ? _type : rhs.getType();
			int p = ( _precision >= rhs.getPrecision() ) ? _precision: rhs.getPrecision();
			std::stringstream ss (std::stringstream::out);
			if (t < FLOAT)
			{
				long long r = std::stoll(_str) - std::stoll(rhs.toString());
				ss << r;
				if (AbstractVM::hasOverflow_int(r, t))
					t = NONE;
			}
			else
			{
				long double r = std::stold(_str) - std::stold(rhs.toString());
				ss << std::setprecision(p) << r;
				if (AbstractVM::hasOverflow(r, t))
					t = NONE;
			}
			return (_factory->createOperand(t, ss.str()));
		}
		IOperand const * operator*(IOperand const &rhs) const

		{
			eOperandType t = ( _type >= rhs.getType() ) ? _type : rhs.getType();
			int p = ( _precision >= rhs.getPrecision() ) ? _precision: rhs.getPrecision();
			std::stringstream ss (std::stringstream::out);
			if (t < FLOAT)
			{
				long long r = std::stoll(_str) * std::stoll(rhs.toString());
				ss << r;
				if (AbstractVM::hasOverflow_int(r, t))
					t = NONE;
			}
			else
			{
				long double r = std::stold(_str) * std::stold(rhs.toString());
				ss << std::setprecision(p) << r;
				if (AbstractVM::hasOverflow(r, t))
					t = NONE;
			}
			return (_factory->createOperand(t, ss.str()));
		}
		IOperand const * operator/(IOperand const &rhs) const
		{
			eOperandType t = ( _type >= rhs.getType() ) ? _type : rhs.getType();
			int p = ( _precision >= rhs.getPrecision() ) ? _precision: rhs.getPrecision();
			std::stringstream ss (std::stringstream::out);
			if (t < FLOAT)
			{
				long long r = std::stoll(_str) / std::stoll(rhs.toString());
				ss << r;
				if (AbstractVM::hasOverflow_int(r, t))
					t = NONE;
			}
			else
			{
				long double r = std::stold(_str) / std::stold(rhs.toString());
				ss << std::setprecision(p) << r;
				if (AbstractVM::hasOverflow(r, t))
					t = NONE;
			}
			return (_factory->createOperand(t, ss.str()));
		}
		IOperand const * operator%(IOperand const &rhs) const
		{
			eOperandType t = ( _type >= rhs.getType() ) ? _type : rhs.getType();
			int p = ( _precision >= rhs.getPrecision() ) ? _precision: rhs.getPrecision();
			std::stringstream ss (std::stringstream::out);
			if (t < FLOAT)
			{
				long long r = std::stoll(_str) % std::stoll(rhs.toString());
				ss << r;
				if (AbstractVM::hasOverflow_int(r, t))
					t = NONE;
			}
			else
			{
				long double r = fmod(std::stold(_str), std::stold(rhs.toString()));
				ss << std::setprecision(p) << r;
				if (AbstractVM::hasOverflow(r, t))
					t = NONE;
			}
			return (_factory->createOperand(t, ss.str()));
		}

		std::string const & toString(void) const
		{
			return (_str);
		}

};

#endif
