/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 14:41:44 by mcostaes          #+#    #+#             */
/*   Updated: 2016/08/16 16:50:40 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "lexer.hpp"
#include "exception.hpp"

int main(int argc, char **argv)
{
	std::string in;
	if (argc > 2)
	{
		std::cerr<<"ERROR: After ./avm please enter file name or press RETURN to enter command lines"<<std::endl;
		return 1;
	}
	Lexer A;
	if (argc == 1)
		in = "cin";
	else
		in = argv[1];
	A.read(in);
	return 0;
}
