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

Server::Server(){}

void	Server::set_number_of_location(std::ifstream &file)
{
	std::string line;

	this->n_location = 0;
	while (!file.eof())
	{
		getline(file, line);
		if (line.compare(0, 9, "\tlocation") == 0)
			this->n_location++;
	}
}

int	Server::GET_LOCATION_NUMBER(void) const
{
	return (this->n_location);
}

Server::~Server(){}