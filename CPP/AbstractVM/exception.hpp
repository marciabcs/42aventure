/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 10:59:02 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 10:33:21 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <exception>

class Exception: public std::exception
{
	std::string _msgm;
	public:
		Exception() throw();
		Exception(std::string const &msg) throw();
		Exception(std::string const &msg, int line) throw();
		Exception(Exception const & f) throw();
		virtual ~Exception() throw();
		Exception & operator=(Exception const & c);
		virtual const char* what() const throw();
		static std::string _errors;
};


#endif
