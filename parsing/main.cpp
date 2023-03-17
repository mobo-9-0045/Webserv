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
			std::string	server;
			int			n_servr;

			std::ifstream rf(argv[1], std::ios::in);
			if (rf.is_open() == false)
				throw ("not opened");
			std::ifstream file(argv[1], std::ios::in);
			if (file.is_open() == false)
				throw ("not opened");
			n_servr = 0;
			while (!file.eof())
			{
				getline(file, server);
				if (server == "server:")
					n_servr++;
			}
			Server s[n_servr];
			s[0].l[0].set_location(rf);
			std::cout << "server 0 location 0" << std::endl;
			std::cout << "---->" << s[0].l[0].get_location() << std::endl;
			std::cout << "---->" << s[0].l[0].get_root() << std::endl;
			std::cout << "---->" << s[0].l[0].get_index() << std::endl;
			std::cout << "---->" << s[0].l[0].get_upload() << std::endl;
			s[0].l[1].set_location(rf);
			std::cout << "server 0 location 1" << std::endl;
			std::cout << "---->" << s[0].l[1].get_location() << std::endl;
			std::cout << "---->" << s[0].l[1].get_root() << std::endl;
			std::cout << "---->" << s[0].l[1].get_index() << std::endl;
			std::cout << "---->" << s[0].l[1].get_upload() << std::endl;
			s[0].l[2].set_location(rf);
			std::cout << "server 0 location 2" << std::endl;
			std::cout << "---->" << s[0].l[2].get_location() << std::endl;
			std::cout << "---->" << s[0].l[2].get_root() << std::endl;
			std::cout << "---->" << s[0].l[2].get_index() << std::endl;
			std::cout << "---->" << s[0].l[2].get_upload() << std::endl;
			s[1].l[0].set_location(rf);
			std::cout << "server 1 location 0" << std::endl;
			std::cout << "---->" << s[1].l[0].get_location() << std::endl;
			std::cout << "---->" << s[1].l[0].get_root() << std::endl;
			std::cout << "---->" << s[1].l[0].get_index() << std::endl;
			std::cout << "---->" << s[1].l[0].get_upload() << std::endl;
			s[1].l[1].set_location(rf);
			std::cout << "server 1 location 1" << std::endl;
			std::cout << "---->" << s[1].l[1].get_location() << std::endl;
			std::cout << "---->" << s[1].l[1].get_root() << std::endl;
			std::cout << "---->" << s[1].l[1].get_index() << std::endl;
			std::cout << "---->" << s[1].l[1].get_upload() << std::endl;
			s[1].l[2].set_location(rf);
			std::cout << "server 1 location 2" << std::endl;
			std::cout << "---->" << s[1].l[2].get_location() << std::endl;
			std::cout << "---->" << s[1].l[2].get_root() << std::endl;
			std::cout << "---->" << s[1].l[2].get_index() << std::endl;
			std::cout << "---->" << s[1].l[2].get_upload() << std::endl;
			s[1].l[3].set_location(rf);
			std::cout << "server 1 location 3" << std::endl;
			std::cout << "---->" << s[1].l[3].get_location() << std::endl;
			std::cout << "---->" << s[1].l[3].get_root() << std::endl;
			std::cout << "---->" << s[1].l[3].get_index() << std::endl;
			std::cout << "---->" << s[1].l[3].get_upload() << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
		}
	}
	return (0);
}