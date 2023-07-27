/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alida-si <alida-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:53:12 by alida-si          #+#    #+#             */
/*   Updated: 2023/07/07 19:48:36 by alida-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <cstdlib>

void	checkEof(void);
void	printMessage(std::string msg);
void	requestInput(std::string request, std::string &str);

#endif
