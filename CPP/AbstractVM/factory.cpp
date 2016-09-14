/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:18:35 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/07 15:02:34 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operand.hpp"
#include "factory.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value) const
{
	switch(type){
		case(INT8):
			return createInt8(value);
		case(INT16):
			return createInt16(value);
		case(INT32):
			return createInt32(value);
		case(FLOAT):
			return createFloat(value);
		case(DOUBLE):
			return createDouble(value);
		case(NONE):
			return createNone(value);
		break;
	}
	return (0);
}

IOperand const * Factory::createInt8( std::string const & value) const
{
	return (new Operand<char>(value, INT8, 0, this));
}
IOperand const * Factory::createInt16( std::string const & value) const
{
	return (new Operand<int>(value, INT16, 0, this));
}
IOperand const * Factory::createInt32( std::string const & value) const
{
	return (new Operand<long int>(value, INT32, 0, this));
}
IOperand const * Factory::createFloat( std::string const & value) const
{
	return (new Operand<float>(value, FLOAT, 7, this));
}
IOperand const * Factory::createDouble( std::string const & value) const
{
	return (new Operand<double>(value, DOUBLE, 14, this));
}

IOperand const * Factory::createNone( std::string const & value) const
{
	return (new Operand<int>(value, NONE, 0, this));
}
