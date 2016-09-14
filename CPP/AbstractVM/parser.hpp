/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:15:17 by mcostaes          #+#    #+#             */
/*   Updated: 2016/08/25 10:30:02 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "ioperand.hpp"
#include "lexer.hpp"

class Parser
{
	std::list<token>	_instructions;
	std::string _removespaces(std::string str);
	int match_begin(std::string test, std::string const patern[]);
	std::list<token> corr_instructions(std::list<token> test);
//	eOperandType match_type(std::string test, std::string const patern[]);

	static const std::string instr[];
	static const std::string value[];
	static const std::string N;
	static const std::string Z;
	public:
		Parser();
		Parser(std::list<token> inst);
		Parser(Parser const & l);
		~Parser();
		Parser & operator=(Parser const & f);
		void action(void);
};


#endif
