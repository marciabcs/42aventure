/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 10:15:05 by mcostaes          #+#    #+#             */
/*   Updated: 2016/09/08 09:36:20 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.hpp"
#include "abstractvm.hpp"

Parser::Parser()
{
}
Parser::Parser(std::list<token> inst):_instructions(inst)
{
}
Parser::Parser(Parser const & l)
{
	*this = l;
}

Parser::~Parser()
{
}

Parser & Parser::operator=(Parser const &f)
{
	_instructions = f._instructions;
	return *this;
}

void Parser::action()
{
	_instructions=this->corr_instructions(_instructions);
	try{ 
		if(Exception::_errors.find("ERROR") == std::string::npos)
		 {
			AbstractVM AVM(_instructions);
			AVM.calc();
		 }
		 else
		 	throw (Exception());
	}
	catch(Exception const & e)
	{
		std::string msgm = e.what();
		msgm.erase(msgm.size()-1);
		std::cout<<msgm<<std::endl;
	}
}

int Parser::match_begin(std::string test, std::string const patern[])
{
	int i = 0;
	while (!patern[i].empty())
	{
		std::size_t found = test.find(patern[i]);
		if (found == 0)
			return i;
		i++;
	}
	return -1;
}

std::list<token> Parser::corr_instructions(std::list<token> inst)
{
	std::list<token> test = inst;
	std::list<token>::iterator it = test.begin();
	std::vector<int> v;
	while (it != test.end())
	{
		int line = (*it).line;
		std::string frase = (*it).comand;
		int a = this->match_begin(frase, Parser::instr);
		if (a >= 0)
		{
			(*it).intcomand = a;
			if ( (std::distance(it, test.end()) == 1) && (frase != "exit" ))
			{
				Exception::_errors += "Ligne ";
				Exception::_errors += std::to_string(line);
				Exception::_errors += ": ERROR PARSER: Program does not have a EXIT instruction\n";
			}
			if (frase == "exit")
				break;
			if((frase.size()!=instr[a].size())&&(a == 0 || a == 1))
			{
				std::string frase1 = frase.substr(instr[a].size() + 1);
				int b = this->match_begin(frase1, Parser::value);
				if (b >= 0)
				{
					if (a == 0 || a == 1)
						(*it).type = static_cast<eOperandType>(b);
					std::string frase2 = frase1.substr(value[b].size());
					std::regex Nr(Parser::N);
					std::regex Zr(Parser::Z);
					if (((b >= 0 && b <= 2 ) && (std::regex_match(frase2, Nr)== false)) 
							|| ((b > 2) && std::regex_match(frase2, Zr)==false))
					{
						v.push_back(line);
						Exception::_errors += "Ligne ";
						Exception::_errors += std::to_string(line);
						Exception::_errors += ": ERROR PARSER: Invalid number\n";
					}
				}
				else
				{
					v.push_back(line);
					Exception::_errors += "Ligne ";
					Exception::_errors += std::to_string(line);
					Exception::_errors += ": ERROR PARSER: Not a valid operator\n";
				}
			}
			else if(frase.size()!=instr[a].size() && a > 1)
			{
				v.push_back(line);
				Exception::_errors += "Ligne ";
				Exception::_errors += std::to_string(line);
				Exception::_errors += ": ERROR PARSER: Not a valid command\n";
			}
			else if (a == 0 || a == 1)
			{
				v.push_back(line);
				Exception::_errors += "Ligne ";
				Exception::_errors += std::to_string(line);
				Exception::_errors += ": ERROR PARSER: Command without value\n";
			}
		}
		else
		{
			v.push_back(line);
			Exception::_errors += "Ligne ";
			Exception::_errors += std::to_string(line);
			Exception::_errors += ": ERROR PARSER: Not a valid command\n";
		}
		(*it).comand = this->_removespaces(frase);
		it++;
	}
	if ( (std::distance(it, test.end()) > 1) )
		test.erase(++it, test.end());
	while (v.size() > 0)
	{
		std::list<token>::iterator i = test.begin(); 
		while(i != test.end())
		{
			if ((*i).line == v.back())
			{
				test.erase(i);
				i = test.end();
			}
			else
				++i;
		}
		v.pop_back();
	}
	return test;
}
std::string Parser::_removespaces(std::string str)
{
	std::string::iterator it;
	it = std::remove(str.begin(), str.end(),' ');
	str.erase(it, str.end());
	return str;
}

const std::string Parser::instr[] = {"push","assert", "pop", "dump", "add", "sub", "mul", "div", "mod", "print", "exit"};
const std::string Parser::value[] = {"int8", "int16", "int32", "float", "double"};
const std::string Parser::N = "\\([-]?[0-9]+\\)";
const std::string Parser::Z = "\\([-]?[0-9]+(\\.[0-9]+)?\\)";
