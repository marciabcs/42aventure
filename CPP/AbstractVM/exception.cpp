/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:58:44 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 10:36:08 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exception.hpp"

Exception::Exception() throw()
{
	_msgm = Exception::_errors;
}
Exception::Exception(std::string const &msg) throw()
{
	_msgm = Exception::_errors + msg;
}

Exception::Exception(std::string const &msg, int line) throw()
{
	_msgm = Exception::_errors;
	_msgm += "Line ";
	_msgm += std::to_string(line);
	_msgm += msg;
}
Exception::Exception(Exception const &f) throw()
{
	_msgm = f._msgm; 
}
Exception::~Exception() throw()
{
}

const char* Exception::what() const throw()
{
	return (_msgm.c_str());
}

std::string Exception::_errors = "";
