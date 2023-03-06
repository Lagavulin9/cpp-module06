/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:56:47 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 22:56:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	Base	*ret = 0;
	int		random;

	srand(time(0));
	random = std::rand() % 3;
	if (random == 0)
		ret = new A;
	else if (random == 1)
		ret = new B;
	else
		ret = new C;
	return (ret);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p is A address" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p is B address" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p is C address" << std::endl;
	else
	{
		std::cerr << "Error\n";
		exit(1);
	}
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "p is A reference" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "p is B reference" << std::endl;
	}
	catch (std::exception& e){}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "p is C reference" << std::endl;
	}
	catch (std::exception& e){}
}
