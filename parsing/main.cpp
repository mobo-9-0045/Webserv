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

int main(void)
{
	Pars p;

	try{
	p.setNginixFile ();
	std::cout << p.getData() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "Error : " << &e << std::endl;
	}
	return (0);
}