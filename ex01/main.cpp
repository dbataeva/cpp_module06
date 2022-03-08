// #include <cstdint>
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}

int main(void) {
	Data *ptr = new Data;
	ptr->i = 15;
	std::cout << "=== data before cast ===\nData->i = " << ptr->i << std::endl;
	uintptr_t ser = serialize(ptr);
	Data *des = deserialize(ser);
	std::cout << "=== data after cast ===\nData->i = " << des->i << std::endl;
	delete ptr;
	return (0);
}
