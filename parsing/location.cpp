/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:20:30 by aomman            #+#    #+#             */
/*   Updated: 2023/03/16 17:20:32 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"location.hpp"

Location::Location()
{
}

Location::Location(const Location &ws)
{
	*this = ws;
	std::cout << "Location copy constructor called" << std::endl;
}

Location	Location::operator = (const Location &ws)
{
	this->file_name = ws.file_name;
	std::cout << "Location copy assignement constructor called" << std::endl;
	return (*this);
}

const char	*Location::NotOpen::what() const throw()
{
	return ("file not found");
}

const char	*Location::EndNotReached::what() const throw()
{
	return ("you must set end of confige file");
}

const char	*Location::Nofile::what() const throw()
{
	return ("server rquire config file");
}

const char	*Location::YmlFileError::what() const throw()
{
	return ("configuration file must be .yml");
}

const char *Location::PathError::what() const throw()
{
	return ("invalid path");
}

void	Location::check_serverfile(std::ifstream &rf)
{
	std::string line;
	
	while (!rf.eof())
	{
		getline(rf, line);
		if (line == "server:")
		{
			std::cout << "server start " << line << std::endl;
			this->set_location(rf);
		}
	}
}

void	Location::check_yml(char *str)
{
	size_t i;
	this->file_name = (std::string)str;
	std::string	yml;
	yml = ".yml";
	i = this->file_name.find(yml, 0);
	if (i == std::string::npos)
		throw(YmlFileError());
}

void	Location::setNginixFile(std::ifstream &rf, char *str)
{
	this->check_serverfile(rf);
	this->check_yml(str);
}

std::string		Location::getData(void) const
{
	return (this->file_name);
}

Location::~Location(){}
