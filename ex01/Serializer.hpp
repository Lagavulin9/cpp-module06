/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:47:36 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 18:47:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

# include <iostream>
# include <string>

typedef struct s_data
{
	std::string	_data;
}	Data;

uintptr_t	serialize(Data* ptr);
Data		*deserialize(uintptr_t raw);

#endif
