/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:24:45 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 03:24:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

# include <iostream>
# include <string>
# include <math.h>

class ScalarConverter
{
private:
	std::string	_string;
	char		_char;
	int			_int;
	float		_float;
	double		_double;
	bool		_isNaNf;
	bool		_isPosInff;
	bool		_isNegInff;
	bool		_isNaN;
	bool		_isPosInf;
	bool		_isNegInf;
	bool		isChar(const std::string&);
	bool		isInt(const std::string&);
	bool		isFloat(const std::string&);
	bool		isDouble(const std::string&);
public:
	ScalarConverter();
	ScalarConverter(const std::string& str);
	ScalarConverter(const ScalarConverter& ref);
	~ScalarConverter();

	ScalarConverter&	operator=(const ScalarConverter& ref);

	void	convert(const std::string& str);
	void	print(void);
};

#endif
