/* ************************************************************************** */
/*																		    */
/*														:::      ::::::::   */
/*   ScalarConverter.cpp								:+:      :+:    :+:   */
/*												    +:+ +:+		 +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>		  +#+  +:+       +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/03/04 16:03:04 by muhabin-		  #+#    #+#		     */
/*   Updated: 2026/03/06 19:09:12 by muhabin-		 ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}
ScalarConverter::~ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void)copy;
	return *this;
}

// Main static Function
void ScalarConverter::convert(std::string const &literal)
{
	if (isChar(literal))
		convertFromChar(literal);
	else if (isSpecial(literal))
		convertFromSpecial(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cout << "Error: Invalid Input" << std::endl;
}

// Detection Function
bool ScalarConverter::isChar(std::string const &str)
{
	// IF the length of string is equal to 3 and the index of 0 and 2 is ' then its true
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return true;
	if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
		return true;
	return false;
}

bool ScalarConverter::isSpecial(std::string const &str)
{
	if (str == "nan" || str == "nanf")
		return true;
	if (str == "inf" || str == "inff")
		return true;
	if (str == "+inf" || str == "+inff")
		return true;
	if (str == "-inf" || str == "-inff")
		return true;
	else
		return false;
}
bool ScalarConverter::isFloat(std::string const &str)
{
	if (str.empty() || (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F'))
		return false;
	if (str.find('.') == std::string::npos)
		return false;
	return true;
}
bool ScalarConverter::isInt(std::string const &str)
{
	if (str.empty())
		return false;
	if (str.find('.') !=  std::string::npos)
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		if(!std::isdigit(str[i]))
			return false;
	}
	return true;
}
bool ScalarConverter::isDouble(std::string const &str)
{
	if (str.find('.') == std::string::npos)
		return false;
	if (str.empty() || (str[str.length() -1] == 'f' || str[str.length() -1] == 'F'))
		return false;
	return true;
}

// Convertion Function
/*
	The string needs to be parse to get the value
	then convert to all 4types
	print the results with proper formatting
*/

void ScalarConverter::convertFromInt(std::string const &str)
{
	// parse string as double first to avoid overflow
	double temp = std::strtod(str.c_str(), NULL);

	// Check if it fits in int range
	if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
	{
		// Number too big/small for int!
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
		std::cout << "double: " << temp << std::endl;
		return;
	}

	// IF EVERYTING IS FINE SAFE TO CONVERT LIKE NORMAL

	int value = static_cast<int>(temp);
	// Convert the int into all 4 types
	char c = static_cast<char>(value);
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	// Print the result
	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout<< "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout<< "Non displayable" << std::endl;
	else
		std::cout<< "'" << c << "'" << std::endl;
	std::cout << "int: " << value << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromChar(std::string const &str)
{
	char c;
	if (str.length() == 3)
		c = str[1]; //From 'c'
	else
		c = str[0]; // from c
	int value = static_cast<int>(c); // why like this because need to convert the char into int first then use the int to convert with f & d
	int i = value;
	float f = static_cast<float>(value);
	double d = static_cast<double>(value);

	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout<< "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout<< "Non displayable" << std::endl;
	else
		std::cout<< "'" << c << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromFloat(std::string const &str)
{
	// convert string to float
	float f = std::strtof(str.c_str(), NULL);
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	// Special case for Char
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f))
		std::cout << "impossible" << std::endl;
	else if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	// Special Case for Int
	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f))
		std::cout << "impossible" << std::endl;
	else if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout<< "impossible"<<std::endl;
	else
		std::cout << i << std::endl;

	// Normal
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}
void ScalarConverter::convertFromDouble(std::string const &str)
{
	double d = std::strtod(str.c_str(),NULL);
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible" << std::endl;
	else if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	// Special Case for Int
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible" << std::endl;
	else if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout<< "impossible"<<std::endl;
	else
		std::cout << i << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromSpecial(std::string const &str)
{
	// For char is always impossible
	std::cout << "char: impossible" << std::endl;
	// Same for int
	std::cout << "int: impossible" << std::endl;

	// Float and double is depends on the input
	std::cout <<"float: ";
	if (str == "nan" || str == "nanf")
		std::cout << "nanf" << std::endl;
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
		std::cout << "+inff" << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "-inff" << std ::endl;

	std::cout << "double: ";
	if (str == "nan" || str == "nanf")
		std::cout << "nan" << std::endl;
	else if (str == "inf" || str == "inff" || str == "+inf" || str == "+inff")
		std::cout << "+inf" << std::endl;
	else if (str == "-inf" || str == "-inff")
		std::cout << "-inf" << std ::endl;

}
