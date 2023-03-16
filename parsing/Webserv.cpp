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

const char *Pars::PathError::what() const throw()
{
	return ("invalid path");
}

std::string	Pars::set_values(std::string line)
{
	size_t	start;
	start = line.find("/");
	if (start == std::string::npos)
		throw(PathError());
	this->line_val = line.substr(start, line.length());
	return (this->line_val);
}

void	Pars::set_config_items()
{
	this->config_items.insert(std::make_pair("root", this->root_val));
	this->config_items.insert(std::make_pair("index", this->index_val));
	this->config_items.insert(std::make_pair("upload", this->upload_val));
	std::map<std::string, std::string>::iterator	it;
	it = this->config_items.begin();
	std::cout << "here" << std::endl;
	while (it != this->config_items.end())
	{
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
		++it;
	}
}

std::map<std::string, std::string>	Pars::get_config_item(void) const
{
	return (this->config_items);
}

void	Pars::set_upload(std::ifstream &rf)
{
	std::string line;

	while (!rf.eof())
	{
		getline(rf, line);
		if (line.compare(0, 8, "\t\tupload") == 0)
		{
			this->upload_val = set_values(line);
		}
	}
}

std::string	Pars::get_upload(void) const
{
	return (this->upload_val);
}

void	Pars::set_index(std::ifstream &rf)
{
	std::string	line;

	while (!rf.eof())
	{
		getline(rf, line);
		if (line.compare(0, 7, "\t\tindex") == 0)
		{
			this->index_val = this->set_values(line);
			this->set_upload(rf);
		}
	}
}

std::string	Pars::get_index(void) const
{
	return (this->index_val);
}

void	Pars::set_root(std::ifstream &rf)
{
	std::string line;

	while (!rf.eof())
	{
		getline(rf, line);
		if (line.compare(0, 6, "\t\troot") == 0)
		{
			this->root_val = this->set_values(line);
			this->set_index(rf);
		}
	}
}

std::string	Pars::get_root(void) const
{
	return (this->root_val);
}

void	Pars::set_location(std::ifstream &rf)
{
	std::string line;

	while (!rf.eof())
	{
		getline(rf, line);
		if (line.compare(0, 9, "\tlocation") == 0)
		{
			this->location_val = this->set_values(line);
			this->set_root(rf);
			this->location_val = this->location_val.substr(0, this->location_val.length() - 1);
		}
	}
}

std::string	Pars::get_location(void)const
{
	return (this->location_val);
}

void	Pars::check_serverfile(std::ifstream &rf)
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

void	Pars::check_yml(char *str)
{
	size_t i;
	this->file_name = (std::string)str;
	std::string	yml;
	yml = ".yml";
	i = this->file_name.find(yml, 0);
	if (i == std::string::npos)
		throw(YmlFileError());
}

void	Pars::setNginixFile(std::ifstream &rf, char *str)
{
	this->check_serverfile(rf);
	this->check_yml(str);
}

std::string		Pars::getData(void) const
{
	return (this->file_name);
}

Pars::~Pars(){}
