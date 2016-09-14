/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstractvm.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:37:22 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 10:33:28 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_HPP
#define ABSTRACTVM_HPP

#include "lexer.hpp"
#include "ioperand.hpp"
#include "factory.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <climits>
#include <cfloat>


class AbstractVM
{
	std::list<token> 		_operations;
	std::list<const IOperand*> 	_stack;
	Factory 				_factory;

	void push(token calc);
	void pop(token calc);
	void dump(token calc);
	void assert(token calc);
	void add(token calc);
	void sub(token calc);
	void mul(token calc);
	void div(token calc);
	void mod(token calc);
	void print(token calc);
	void exit(void);
	public:
		AbstractVM();
		AbstractVM(std::list<token> inst);
		AbstractVM(AbstractVM const &copy);
		AbstractVM & operator=(AbstractVM const &rhs);
		~AbstractVM();
		void calc();

		static bool hasOverflow(long double r, eOperandType type);
		static bool hasOverflow_int(long long r, eOperandType type);
};


#endif
