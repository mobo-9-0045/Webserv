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

#include"location.hpp"
#include"Webserv.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		(void)argv;
		//Location *l = new Location();
		try
		{
			std::string	line;
			std::ifstream rf(argv[1], std::ios::in);
			if (rf.is_open() == false)
				throw ("not opened");
			Server s;
			s.l[0].set_location(rf);
			std::cout << "---->" << s.l[0].get_location() << std::endl;
			std::cout << "---->" << s.l[0].get_root() << std::endl;
			std::cout << "---->" << s.l[0].get_index() << std::endl;
			std::cout << "---->" << s.l[0].get_upload() << std::endl;
			s.l[1].set_location(rf);
			std::cout << "---->" << s.l[1].get_location() << std::endl;
			std::cout << "---->" << s.l[1].get_root() << std::endl;
			std::cout << "---->" << s.l[1].get_index() << std::endl;
			std::cout << "---->" << s.l[1].get_upload() << std::endl;
			s.l[2].set_location(rf);
			std::cout << "---->" << s.l[2].get_location() << std::endl;
			std::cout << "---->" << s.l[2].get_root() << std::endl;
			std::cout << "---->" << s.l[2].get_index() << std::endl;
			std::cout << "---->" << s.l[2].get_upload() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	return (0);
}