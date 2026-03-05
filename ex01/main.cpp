/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: muhabin- <muhabin-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/03/05 21:59:50 by muhabin-		  #+#	#+#			 */
/*   Updated: 2026/03/05 21:59:50 by muhabin-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== Serialization Test ===" << std::endl << std::endl;

	// Create a Data object
	Data original;
	original.value = 42;
	original.str = "Hello, World!";

	std::cout << "Original Data:" << std::endl;
	std::cout << "  Address: " << &original << std::endl;
	std::cout << "  value:   " << original.value << std::endl;
	std::cout << "  str:	 " << original.str << std::endl;
	std::cout << std::endl;

	// Get pointer to the object
	Data* originalPtr = &original;

	// Serialize: Pointer → Number
	uintptr_t serialized = Serializer::serialize(originalPtr);
	std::cout << "Serialized (as number): " << serialized << std::endl;
	std::cout << std::endl;

	// Deserialize: Number → Pointer
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "  Address: " << deserialized << std::endl;
	std::cout << "  value:   " << deserialized->value << std::endl;
	std::cout << "  str:	 " << deserialized->str << std::endl;
	std::cout << std::endl;

	// Verify pointers match
	std::cout << "=== Verification ===" << std::endl;
	if (originalPtr == deserialized)
		std::cout << "✓ SUCCESS: Pointers match!" << std::endl;
	else
		std::cout << "✗ FAILURE: Pointers don't match!" << std::endl;

	// Verify data is intact
	if (original.value == deserialized->value && original.str == deserialized->str)
		std::cout << "✓ SUCCESS: Data is intact!" << std::endl;
	else
		std::cout << "✗ FAILURE: Data corrupted!" << std::endl;

	return 0;
}
