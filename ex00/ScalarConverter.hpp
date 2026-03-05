/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:33:13 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/04 16:01:44 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#define GREEN	"\033[32m"
#define RED		"\033[31m"
#define BLUE	"\033[0;34m"
#define YELLOW  "\033[33m"
#define WHITE	"\033[0;37m"
#define RESET	"\033[0m"

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <iomanip>
#include <limits>


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter &copy);

	public:

	// Main static function
		static void convert(std::string const &literal);

	// bool for checking the input
		static bool isChar(std::string const &str);
		static bool isSpecial(std::string const &str);
		static bool isFloat(std::string const &str);
		static bool isDouble(std::string const &str);
		static bool isInt(std::string const &str);

	// need function to convert str into what it wants
		static void convertFromChar(std::string const &str);
		static void convertFromSpecial(std::string const &str);
		static void convertFromFloat(std::string const &str);
		static void convertFromDouble(std::string const &str);
		static void convertFromInt(std::string const &str);

};
#endif
