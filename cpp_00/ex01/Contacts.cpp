/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:37:41 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/07 20:14:46 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

Contacts::Contacts(void)
{
	return ;
}

Contacts::~Contacts(void)
{
	return ;
}

void	Contacts::_requestInfo(std::string request, std::string &contactField)
{
	while (1)
	{
		requestInput(request, contactField);
		checkEof();
		if (!contactField.empty())
			break ;
		printMessage("No field must be empty!");
	}
}

void	Contacts::setFirstName(void)
{
	_requestInfo("FIRST NAME: ", this->_firstName);
}

void	Contacts::setLastName(void)
{
	_requestInfo("LAST NAME: ", this->_lastName);
}

void	Contacts::setNickname(void)
{
	_requestInfo("NICKNAME: ", this->_nickname);
}

void	Contacts::setPhoneNumber(void)
{
	_requestInfo("PHONE NUMBER: ", this->_phoneNumber);
}

void	Contacts::setDarkestSecret(void)
{
	_requestInfo("DARKEST SECRET: ", this->_darkestSecret);
}

char	Contacts::_intToChar(int number)
{
	return static_cast<char>('0' + number);
}

void	Contacts::setId(int i)
{
	this->_id = _intToChar(i);
}

std::string	Contacts::getFirstName(void)
{
	return (this->_firstName);
}

std::string	Contacts::getLastName(void)
{
	return (this->_lastName);
}

std::string	Contacts::getNickname(void)
{
	return (this->_nickname);
}

std::string	Contacts::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string	Contacts::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

char	Contacts::getId(void)
{
	return (this->_id);
}
