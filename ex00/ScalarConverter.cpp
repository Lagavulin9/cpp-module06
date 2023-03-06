/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:25:17 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 03:25:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter():
	_isNaNf(false),
	_isPosInff(false),
	_isNegInff(false),
	_isNaN(false),
	_isPosInf(false),
	_isNegInf(false)
{
}

ScalarConverter::ScalarConverter(const std::string& str):
	_isNaNf(false),
	_isPosInff(false),
	_isNegInff(false),
	_isNaN(false),
	_isPosInf(false),
	_isNegInf(false)
{
	this->convert(str);
}

ScalarConverter::ScalarConverter(const ScalarConverter& ref):
	_string(ref._string),
	_int(ref._int),
	_float(ref._float),
	_double(ref._double),
	_isNaNf(ref._isNaNf),
	_isPosInff(ref._isPosInff),
	_isNegInff(ref._isNegInff),
	_isNaN(ref._isNaNf),
	_isPosInf(ref._isPosInf),
	_isNegInf(ref._isNegInf)
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ref)
{
	this->_string = ref._string;
	this->_int = ref._int;
	this->_float = ref._float;
	this->_double = ref._double;
	this->_isNaNf = ref._isNaNf;
	this->_isPosInff = ref._isPosInff;
	this->_isNegInff = ref._isNegInff;
	this->_isNaN = ref._isNaNf;
	this->_isPosInf = ref._isPosInf;
	this->_isNegInf = ref._isNegInf;
	return (*this);
}

bool	ScalarConverter::isChar(const std::string& str)
{
	if (str.length() == 1)
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(const std::string& str)
{
	const char	*s = str.data();
	int			i = 0;

	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (!std::isdigit(s[i++]))
			return (false);
	}
	return (true);
}

bool	ScalarConverter::isFloat(const std::string& str)
{
	const char	*s = str.data();
	int			i = 0;
	int			len = str.length() - 1;
	bool		dot_flag = false;

	if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff") 
		return (true);
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i] && i < len)
	{
		if (s[i] == '.')
		{
			if (dot_flag)
				return (false);
			else
				dot_flag = true;
			i++;
			continue;
		}
		if (!std::isdigit(s[i++]))
			return (false);
	}
	return (s[len] == 'f');
}

bool	ScalarConverter::isDouble(const std::string& str)
{
	const char	*s = str.data();
	int			i = 0;
	bool		dot_flag = false;

	if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
		return (true);
	if (s[0] == '-' || s[0] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot_flag)
				return (false);
			else
				dot_flag = true;
			i++;
			continue;
		}
		if (!std::isdigit(s[i++]))
			return (false);
	}
	return (true);
}

void	ScalarConverter::convert(const std::string& str)
{
	this->_string = str;
	
	
	if (this->isInt(str))
	{
		this->_int = atoi(str.data());
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
	}
	else if (this->isChar(str))
	{
		this->_char = str.data()[0];
		this->_int = static_cast<int>(this->_char);
		this->_char = static_cast<char>(this->_char);
		this->_float = static_cast<float>(this->_char);
	}
	else if (this->isFloat(str))
	{
		this->_float = (float)atof(str.c_str());
		if (str == "nanf")
			this->_isNaNf = true;
		else if (str == "inff" || str == "+inff")
				this->_isPosInff = true;
		else if (str == "-inff")
				this->_isNegInff = true;
		else
		{
			this->_int = static_cast<int>(this->_float);
			this->_char = static_cast<char>(this->_float);
			this->_double = static_cast<double>(this->_float);
		}
	}
	else if (this->isDouble(str))
	{
		this->_double = atof(str.c_str());
		if (str == "nan")
			this->_isNaN = true;
		else if (str == "inf" || str == "+inf")
				this->_isPosInf = true;
		else if (str == "-inf")
				this->_isNegInf = true;
		else
		{
			this->_int = static_cast<int>(this->_double);
			this->_char = static_cast<char>(this->_double);
			this->_float = static_cast<float>(this->_double);
		}
	}
	else
	{
		std::cerr << "Invalid argument" << std::endl;
		exit(1);
	}
}

void	ScalarConverter::print(void)
{
	std::cout << "char : ";
	if (this->_isNaN || this->_isNaNf\
		|| this->_isPosInf || this->_isPosInff \
		|| this->_isNegInf || this->_isNegInff \
		|| this->_int < 32 || 127 < this->_int)
		std::cout << "non printable" << std::endl;
	else
		std::cout << "'" << this->_char << "'" << std::endl;

	std::cout << "int : ";
	if (this->_isNaN || this->_isNaNf)
		std::cout << "NaN" << std::endl;
	else if (this->_isPosInf || this->_isPosInff)
		std::cout << "+INF" << std::endl;
	else if (this->_isNegInf || this->_isNegInff)
		std::cout << "-INF" << std::endl;
	else
		std::cout << this->_int << std::endl;

	std::cout << "float : ";
	if (this->_isNaN || this->_isNaNf)
		std::cout << "NaN" << std::endl;
	else if (this->_isPosInf || this->_isPosInff)
		std::cout << "+INF" << std::endl;
	else if (this->_isNegInf || this->_isNegInff)
		std::cout << "-INF" << std::endl;
	else
		std::cout << this->_float << std::endl;

	std::cout << "double : ";
	if (this->_isNaN || this->_isNaNf)
		std::cout << "NaN" << std::endl;
	else if (this->_isPosInf || this->_isPosInff)
		std::cout << "+INF" << std::endl;
	else if (this->_isNegInf || this->_isNegInff)
		std::cout << "-INF" << std::endl;
	else
		std::cout << this->_double << std::endl;
}
