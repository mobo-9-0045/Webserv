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
		std::string str;
	public : 
		Pars();
		Pars(const Pars &ws);
		Pars operator = (const Pars &ws);
		void	setNginixFile(void);
		void	checkBrackets(void) const;
		std::string		getData(void) const;
		class	BracketsException : public std::exception
		{
			public : 
				virtual const char *what() const throw();
		};
		virtual ~Pars();
};
#endif