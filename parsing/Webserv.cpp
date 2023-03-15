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
}

Pars::Pars(const Pars &ws)
{
	*this = ws;
	std::cout << "Pars copy constructor called" << std::endl;
}

Pars	Pars::operator = (const Pars &ws)
{
	this->file_name = ws.file_name;
	std::cout << "Pars copy assignement constructor called" << std::endl;
	return (*this);
}

const char	*Pars::NotOpen::what() const throw()
{
	return ("file not found");
}

const char	*Pars::EndNotReached::what() const throw()
{
	return ("you must set end of confige file");
}

const char	*Pars::Nofile::what() const throw()
{
	return ("server rquire config file");
}

const char	*Pars::YmlFileError::what() const throw()
{
	return ("configuration file must be .yml");
}

void	ft_getserver(std::ifstream &rf)
{
	std::string line;

	while (!rf.eof())
	{
		getline(rf, line);
		if (line.compare(0, 10, "\tlocation") == 0)
			std::cout << "----->" << line << std::endl;
		std::cout << line << std::endl;
	}
}

void	Pars::check_serverfile(std::ifstream &rf)
{
	std::string line;
	
	while (!rf.eof())
	{
		getline(rf, line);
			if (line == "server:")
				ft_getserver(rf);
		std::cout << line << std::endl;
	}
}

void	Pars::check_yml()
{
	size_t i;
	std::string	yml;
	yml = ".yml";
	i = this->file_name.find(yml, 0);
	if (i == std::string::npos)
		throw(YmlFileError());
}

void	Pars::setNginixFile(char **argv)
{
	if (argv[1] == NULL)
		throw(Nofile());
	this->file_name = argv[1];
	std::ifstream rf(this->file_name.c_str(), std::ios::in);
	if (rf.is_open() == false)
		throw(NotOpen());
	this->check_yml();
	this->check_serverfile(rf);
}

std::string		Pars::getData(void) const
{
	return (this->file_name);
}

Pars::~Pars(){}
