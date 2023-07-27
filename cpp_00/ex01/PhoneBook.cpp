/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:45:01 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/08 11:59:09 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_totalContacts = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

int	PhoneBook::_setIndex(void)
{
	static int	i = -1;

	++i;
	if (i == 8)
		i = 0;
	return(i);
}

void	PhoneBook::_countContacts(void)
{
	static int	i = 0;

	if (i < 8)
		_totalContacts = ++i;
}

bool	PhoneBook::_hasContacts(void)
{
	if (_totalContacts == 0)
		return (false);
	return (true);
}

bool	PhoneBook::_isStringDigit(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PhoneBook::addContact(void)
{
	int	i;

	i = _setIndex();
	_contacts[i].setId(i);
	_contacts[i].setFirstName();
	_contacts[i].setLastName();
	_contacts[i].setNickname();
	_contacts[i].setPhoneNumber();
	_contacts[i].setDarkestSecret();
	_countContacts();
}

void	PhoneBook::_printSearchTable(void)
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
}

std::string	PhoneBook::_truncateString(std::string str)
{
	std::string	truncated;

	if (str.length() <= 10)
		return (str);
	truncated = str.substr(0,9);
	truncated += '.';
	return (truncated);
}

void	PhoneBook::_printSearchTableInfo(void)
{
	for (int j = 0; j < _totalContacts; j++)
	{
		std::cout << std::setw(10) << _contacts[j].getId() << "|";
		std::cout << std::setw(10)
			<< _truncateString(_contacts[j].getFirstName()) << "|";
		std::cout << std::setw(10)
			<< _truncateString(_contacts[j].getLastName()) << "|";
		std::cout << std::setw(10)
			<< _truncateString(_contacts[j].getNickname()) << "|" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::_printContactInfo(void)
{
	std::cout << "First name: "
		<< _contacts[_searchIndex].getFirstName() << std::endl;
	std::cout << "Last name: "
		<< _contacts[_searchIndex].getLastName() << std::endl;
	std::cout << "Nickname: "
		<< _contacts[_searchIndex].getNickname() << std::endl;
	std::cout << "Phone number: "
		<< _contacts[_searchIndex].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: "
		<< _contacts[_searchIndex].getDarkestSecret() << std::endl;
}

bool	PhoneBook::_isValidIndex()
{
	if (_searchIndex > -1 && _searchIndex < _totalContacts)
		return (true);
	printMessage("Invalid index.");
	return (false);
}

void	PhoneBook::_setSearchIndex(std::string indexStr)
{
	if (_isStringDigit(indexStr) && !indexStr.empty())
		_searchIndex = std::atoi(indexStr.c_str());
	else
		_searchIndex = -1;
}

void	PhoneBook::_requestSearchIndex(void)
{
	std::string	buffer;

	while (1)
	{
		std::cout << "Enter an index to see more contact information: ";
		std::getline(std::cin, buffer);
		checkEof();
		_setSearchIndex(buffer);
		if (_isValidIndex())
			break ;
	}
}

void	PhoneBook::searchContact(void)
{
	if (_hasContacts())
	{
		_printSearchTable();
		_printSearchTableInfo();
		_requestSearchIndex();
		_printContactInfo();
	}
	else
		std::cout << "You have no contacts to search." << std::endl;
}
