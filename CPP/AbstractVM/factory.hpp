/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:18:26 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/07 15:02:37 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include "ioperand.hpp"

class Factory{

	public:
		Factory();
		//Factory(const Factory&);
		~Factory();
		IOperand const * createOperand( eOperandType type, std::string const & value ) const;
	private: 
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;
		IOperand const * createNone( std::string const & value ) const;
};


#endif
