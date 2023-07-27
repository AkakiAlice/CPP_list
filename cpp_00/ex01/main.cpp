/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:25 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/08 12:44:36 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	initMsg(void)
{
	std::cout << "You can use the following commands "
		<< "to navigate through your phonebook:" << std::endl;
	std::cout << "ADD - add a new contact" << std::endl;
	std::cout << "SEARCH - search for a contact" << std::endl;
	std::cout << "EXIT - exit the program" << std::endl;
	std::cout << std::endl;
}

void	getCommand(void)
{
	std::string command;
	PhoneBook phonebook;

	requestInput("Insert a command: ", command);
	while (command != "EXIT" && !std::cin.eof())
	{
		//checkEof();
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Please, insert a valid command." << std::endl;
		std::cout << std::endl;
		requestInput("Insert a command: ", command);
	}
}

int	main(void)
{
	initMsg();
	getCommand();
	return (0);
}
