#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(void) {
	Data		originalData("Julia", 25);
	Data		*returnedData;
	uintptr_t	intPtr;

	std::cout << std::endl;
	std::cout << "Original Data: " << originalData << std::endl;
	intPtr = Serializer::serialize(&originalData);
	std::cout << "uintptr_t: " << intPtr << std::endl;
	returnedData = Serializer::deserialize(intPtr);
	std::cout << "Returned Data: " << *returnedData << std::endl;
	std::cout << std::endl;

	return 0;
}
