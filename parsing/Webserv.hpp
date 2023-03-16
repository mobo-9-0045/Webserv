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

#ifndef WEBSERVER_HPP
# define WEBSERVER_HPP
#include"location.hpp"
# include <new>

class Server
{
	private :
		int	n_location;
	public :
		void	set_number_of_location(std::ifstream &file);
		int		GET_LOCATION_NUMBER(void) const;
		Location l[GET_LOCATION_NUMBER()];
		Server();
		~Server();
};

#endif
