/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:57:32 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/06 11:10:41 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Functions.hpp"
#include <cstdlib>
#include <iostream>
#include <exception>

Base* generate(void)
{
	int random = rand() % 3;

	// Creating new Class
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p) != NULL)
		std::cout<< "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout<< "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout<< "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout<< "A"<< std::endl;
		return;
	}
	catch(const std::exception&){}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout<< "B"<< std::endl;
		return;
	}
	catch(const std::exception&){}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout<<"C"<<std::endl;
	}
	catch(const std::exception&){}


}
