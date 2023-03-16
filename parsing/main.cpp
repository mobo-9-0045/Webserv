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
		Location *l = new Location();
		try
		{
			//std::string	line;
			std::ifstream rf(argv[1], std::ios::in);
			if (rf.is_open() == false)
				throw ("not opened");
			//getline(rf, line);
			//if (line == "server:")
			Server s;
			s.set_number_of_location(rf);
			std::cout << s.GET_LOCATION_NUMBER() << std::endl;
			//l->setNginixFile (rf, argv[1]);
			//std::cout << "---->" << l->get_root() << std::endl;
			//std::cout << "---->" << l->get_index() << std::endl;
			//std::cout << "---->" << l->get_upload() << std::endl;
			//std::cout << "---->" << l->get_location() << std::endl;
			//l->set_config_items();
			delete(l);
		}
		catch(std::exception &e)
		{
			std::cout << "Error : " << e.what() << std::endl;
			if (l)
				delete (l);
		}
	}
	return (0);
}