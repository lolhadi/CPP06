/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:51:37 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/05 15:53:50 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout<< RED << "Usage: ./convert <literal> " << RESET <<std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
