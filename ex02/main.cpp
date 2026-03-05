/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhabin- <muhabin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:24:02 by muhabin-          #+#    #+#             */
/*   Updated: 2026/03/05 23:28:21 by muhabin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	// Seed random number generator
	srand(time(NULL));

	std::cout << "=== Dynamic Type Identification Test ===" << std::endl << std::endl;

	// Test 1: Generate and identify multiple random objects
	std::cout << "--- Test 1: Random Generation ---" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* obj = generate();

		std::cout << "Object " << i + 1 << ": ";
		std::cout << "Pointer version: ";
		identify(obj);

		std::cout << "Reference version: ";
		identify(*obj);

		delete obj;
		std::cout << std::endl;
	}

	std::cout << std::string(50, '-') << std::endl << std::endl;

	// Test 2: Specific type testing
	std::cout << "--- Test 2: Specific Types ---" << std::endl;

	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "Known A object - Pointer: ";
	identify(a);
	std::cout << "Known A object - Reference: ";
	identify(*a);
	std::cout << std::endl;

	std::cout << "Known B object - Pointer: ";
	identify(b);
	std::cout << "Known B object - Reference: ";
	identify(*b);
	std::cout << std::endl;

	std::cout << "Known C object - Pointer: ";
	identify(c);
	std::cout << "Known C object - Reference: ";
	identify(*c);
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;

	std::cout << std::string(50, '-') << std::endl << std::endl;

	return 0;
}
