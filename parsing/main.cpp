/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aomman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:40:01 by aomman            #+#    #+#             */
/*   Updated: 2023/03/11 18:21:10 by aomman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Webserv.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		Pars p;
		try
		{
			std::ifstream rf(argv[1], std::ios::in);
			if (rf.is_open() == false)
				throw ("not opened");
			p.setNginixFile (rf, argv[1]);
			p.ft_getserver(rf);
			p.set_root(rf);
			p.set_index(rf);
			p.set_upload(rf);
			std::cout << "---->" << p.get_index() << std::endl;
			std::cout << "---->" << p.get_root() << std::endl;
			std::cout << "---->" << p.get_upload() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	return (0);
}