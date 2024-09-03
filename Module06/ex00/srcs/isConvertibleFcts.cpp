/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isConvertibleFcts.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaquatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:14:56 by lpaquatt          #+#    #+#             */
/*   Updated: 2024/09/03 18:22:08 by lpaquatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	return (false);
}

bool	isInt(std::string input)
{
	if (input.length() == 1 && isdigit(input[0]))
		return (true);
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-' || input[0] == '+'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				return (false);
		}
		if (input.length() > 11 
			|| atoll(input.c_str()) > std::numeric_limits<int>::max()
			|| atoll(input.c_str()) <  std::numeric_limits<int>::min())
			return (false);
		return (true);
	}
	return (false);
}

static bool	isDecimal(std::string input)
{
	if (input.length() < 2)
		return (false);
	size_t nbDot = 0;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '.')
		{
			if ((input[i] == '-' || input[i] == '+') && i == 0)
				continue;
			return (false);
		}
		if (input[i] == '.' && nbDot++ > 0)
			return (false);
	}
	if (nbDot == 0)
		return (false);
	return (true);
}


bool isDouble(std::string input)
{
	std::string decimalPart = input;
	size_t posE = input.find('e');
	if (posE == std::string::npos)
		posE = input.find('E');
	if (posE != std::string::npos)
	{
		std::string exponentPart = input.substr(posE + 1, input.length() - posE - 2);
		if (isInt(exponentPart) == false)
			return (false);
		decimalPart = input.substr(0, posE);
	}
	if (isDecimal(decimalPart) == false)
		return (false);
	return (true);
}

bool	isFloat(std::string input)
{
	if (input.length() < 3)
		return (false);
	if (input[input.length() - 1] != 'F' && input[input.length() - 1] != 'f')
		return (false);
	std::string withoutF = input.substr(0, input.length() - 1);
	if (isDouble(withoutF) == false)
		return (false);
	//no overflow check for float ? put it as +/-inff
	return (true);
}
