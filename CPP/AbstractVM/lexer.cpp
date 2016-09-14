/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcostaes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 15:15:32 by mcostaes          #+#    #+#             */
/*   Updated: 2016/08/25 17:02:01 by mcostaes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.hpp"
#include "parser.hpp"
#include <fstream>

Lexer::Lexer()
{
}

Lexer::Lexer(Lexer const & l)
{
	*this = l;
}

Lexer::~Lexer()
{
}

Lexer & Lexer::operator=(Lexer const &f)
{
	_instructions = f._instructions;
	return *this;
}

void Lexer::read(std::string in)
{
	std::ifstream infile(in);
	std::string commands;
	int line = 1;
	try
	{
		if (infile)
		{
			while (getline(infile, commands))
			{
				if (commands.size() > 0)
					this->save_instructions(line, _trim(commands));
				else
				{
					Exception::_errors += "Ligne ";
					Exception::_errors += std::to_string(line);
					Exception::_errors += ": WARNING LEXER: Command line empty\n";
				}
				line++;
			}

		}
		else if (in.compare("cin") == 0)
		{

			while (getline(std::cin, commands) && commands.find(";;") != 0)
			{
				if (commands.size() > 0)
						this->save_instructions(line,_trim(commands));
				else
				{
					Exception::_errors += "Ligne ";
					Exception::_errors += std::to_string(line);
					Exception::_errors += ": WARNING LEXER: Command line empty\n";
				}
				line++;
			}
		}
		else
			throw (Exception("ERROR LEXER: Invalid file name"));
	}
	catch(Exception const & e)
	{
		std::cout<<"ERROR : "<<e.what()<<std::endl;
	}
	
	Parser p(_instructions);
	p.action();
}

int Lexer::countwords(std::string phrase)
{
	std::size_t mark = phrase.find_first_not_of(" /t");
	if (mark!=std::string::npos)
	{
		if (mark != 0)
			phrase.erase(0, mark);
	}
	else
		return 5;
	mark = phrase.find_last_not_of(" /t");
	if (mark!=std::string::npos)
	{
		if (mark != phrase.size())
		phrase.erase(mark + 1);
	}
	else
		return 5;
	std::string::iterator it;
	it = std::remove(phrase.begin(), phrase.end(),' ');
	int res = std::distance(it, phrase.end()) + 1;
	return res;
}

void Lexer::save_instructions(int line, std::string instructions)
{
	std::string inst;
	std::size_t found = instructions.find(";");
	if (found != std::string::npos)
	{
		if (found == 0)
		{
			Exception::_errors += "Ligne ";
			Exception::_errors += std::to_string(line);
			Exception::_errors += ": WARNING LEXER: Commentary line\n";
			return;
		}
		inst = instructions.substr(0, found);
	}
	else
		inst = instructions;
	inst = _trim(inst);
	if (this->countwords(inst) > 0 && this->countwords(inst) <= 2)
	{
		token tok = {line, inst,-1, NONE};
		this->_instructions.push_back(tok);
	}
	else
	{
		Exception::_errors += "Ligne ";
		Exception::_errors += std::to_string(line);
		Exception::_errors += 
			": ERROR LEXER: Incorrect number of words or spaces in command line\n";
	}
}

std::string Lexer::_trim(std::string str)
{
	std::string phrase = str;
	std::size_t mark = phrase.find_first_not_of(" ");
	if (mark != 0)
		phrase.erase(0, mark);
	mark = phrase.find_last_not_of(" ");
	if (mark != phrase.size())
		phrase.erase(mark + 1);
	return phrase;
}

