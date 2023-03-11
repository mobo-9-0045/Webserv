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

Webserv::Webserv()
{
	this->data = 0;
	std::cout << "Webserv default constructor called" << std::endl;
}

Webserv::Webserv(const Webserv &ws)
{
	*this = ws;
	std::cout << "Webserv copy constructor called" << std::endl;
}

Webserv	Webserv::operator = (const Webserv &ws)
{
	this->data = ws.data;
	std::cout << "Webserv copy assignement constructor called" << std::endl;
	return (*this);
}

void	Webserv::setData(int data)
{
	this->data = data;
}

int		Webserv::getData(void) const
{
	return (this->data);
}

Webserv::~Webserv()
{
	std::cout << "Webserv destructor called" << std::endl;
}
