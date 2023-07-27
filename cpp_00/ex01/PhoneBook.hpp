/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:45 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/07 20:15:29 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_CLASS_HPP
# define PHONE_BOOK_CLASS_HPP

#include "Contacts.hpp"
#include "utils.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cctype>

class PhoneBook
{
private:
	Contacts	_contacts[8];
	int			_totalContacts;
	int			_searchIndex;

	int			_setIndex(void);
	bool		_hasContacts(void);
	void		_printSearchTable(void);
	void		_printSearchTableInfo(void);
	void		_printContactInfo(void);
	void		_countContacts(void);
	bool		_isValidIndex(void);
	void		_requestSearchIndex(void);
	void		_setSearchIndex(std::string indexStr);
	bool		_isStringDigit(std::string str);
	std::string	_truncateString(std::string str);

public:
	PhoneBook(void);
	~PhoneBook(void);

	void		addContact(void);
	void		searchContact(void);
};

#endif
