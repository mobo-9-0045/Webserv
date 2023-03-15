/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:55:20 by aomman            #+#    #+#             */
/*   Updated: 2023/03/11 14:55:21 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
# define WEBSERV_HPP
# include<iostream>
# include<fstream>
# include<exception>
# include<algorithm>
# include<map>

class Pars
{
	private : 
		std::string file_name;
		std::string	root;
		std::string	index;
		std::string	upload;
	public : 
		Pars();
		Pars(const Pars &ws);
		Pars operator = (const Pars &ws);
		void	setNginixFile(std::ifstream &rf, char *str);
		std::string		getData(void) const;
		class	NotOpen : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class	EndNotReached : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class	Nofile : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		class	YmlFileError : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
		void	check_yml(char *str);
		void	check_serverfile(std::ifstream &rf);
		void	ft_getserver(std::ifstream &rf);

		void	set_root(std::ifstream &rf);
		std::string	get_root(void) const;

		void	set_index(std::ifstream &rf);
		std::string	get_index(void) const;

		void	set_upload(std::ifstream &rf);
		std::string	get_upload(void) const;
		virtual ~Pars();
};
#endif