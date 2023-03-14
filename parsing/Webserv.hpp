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

class Pars
{
	private : 
		std::string file_name;
	public : 
		Pars();
		Pars(const Pars &ws);
		Pars operator = (const Pars &ws);
		void	setNginixFile(char **argv);
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
		void	check_yml();
		void	check_serverfile(std::ifstream &rf);
		virtual ~Pars();
};
#endif