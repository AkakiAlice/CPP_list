/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:53:36 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/07 19:47:23 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	checkEof(void)
{
	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(0);
	}
}

void	printMessage(std::string msg)
{
	std::cout << msg << std::endl;
	std::cout << std::endl;
}

void	requestInput(std::string request, std::string &str)
{
	std::cout << request;
	std::getline(std::cin, str);
}
