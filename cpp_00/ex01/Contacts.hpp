/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:33 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/07 20:14:55 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include "utils.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class Contacts
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
	char		_id;

	void		_requestInfo(std::string request, std::string &contactField);
	char		_intToChar(int number);

public:
	Contacts(void);
	~Contacts(void);

	void		setFirstName(void);
	void		setLastName(void);
	void		setNickname(void);
	void		setPhoneNumber(void);
	void		setDarkestSecret(void);
	void		setId(int i);
	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickname(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
	char		getId(void);
	bool		contactIsEmpty(void);
};

#endif
