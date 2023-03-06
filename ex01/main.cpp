/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:52:25 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 21:52:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		*data = new Data;
	uintptr_t	serialized;
	Data		*deserialized;

	data->_data = "some string data";
	serialized = serialize(data);
	deserialized = deserialize(serialized);
	std::cout << data << std::endl;
	std::cout << "0x" << std::hex << serialized << std::endl;
	std::cout << deserialized << std::endl;
	std::cout << deserialized->_data << std::endl;
	delete data;
	return (0);
}
