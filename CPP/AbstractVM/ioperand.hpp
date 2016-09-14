/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ioperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:08:26 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/07 11:44:14 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <iostream>
#include <string>
#include <list>
#include <regex>

enum eOperandType
{ INT8, INT16, INT32, FLOAT, DOUBLE, NONE};

struct token{
	int				line;
	std::string		comand;
	int				intcomand;
	eOperandType	type;
};

class IOperand{

	public:
		virtual int getPrecision(void) const = 0;
		virtual eOperandType getType(void) const = 0;

		virtual IOperand const * operator+(IOperand const &rhs) const = 0;
		virtual IOperand const * operator-(IOperand const &rhs) const = 0;
		virtual IOperand const * operator*(IOperand const &rhs) const = 0;
		virtual IOperand const * operator/(IOperand const &rhs) const = 0;
		virtual IOperand const * operator%(IOperand const &rhs) const = 0;

		virtual std::string const & toString(void) const =0;

		virtual ~IOperand(void){}
};


#endif
