/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:55:14 by aomman            #+#    #+#             */
/*   Updated: 2023/03/11 18:21:11 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Webserv.hpp"

Pars::Pars()
{
	this->str = "";
}

Pars::Pars(const Pars &ws)
{
	*this = ws;
	std::cout << "Pars copy constructor called" << std::endl;
}

Pars	Pars::operator = (const Pars &ws)
{
	this->str = ws.str;
	std::cout << "Pars copy assignement constructor called" << std::endl;
	return (*this);
}

void	Pars::setNginixFile(void)
{
	char	c;
	std::ifstream rf("nginix.conf", std::ios::in);
	while (!rf.eof() && rf >> std::noskipws >> c)
		this->str += c;
}

std::string		Pars::getData(void) const
{
	return (this->str);
}

Pars::~Pars(){}
