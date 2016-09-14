/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:15:41 by mcostaes          #+#    #+#             */
/*   Updated: 2016/08/16 12:35:06 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "exception.hpp"
#include "ioperand.hpp"

class Lexer
{
	std::list<token> _instructions;
	int countwords(std::string phrase);
	void save_instructions(int line, std::string instructions);
	std::string _trim(std::string str);
	public:
		Lexer();
		Lexer(Lexer const & l);
		~Lexer();
		Lexer & operator=(Lexer const & f);

		void read(std::string in);
};


#endif 
