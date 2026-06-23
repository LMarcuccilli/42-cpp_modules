#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;

	data.id = 42;
	data.name = "hello";

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Serialized:       " << raw << std::endl;
	std::cout << "Deserialized ptr: " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "success: pointers match" << std::endl;
	else
		std::cout << "failure" << std::endl;

	std::cout << ptr->id << ", " << ptr->name << std::endl;
	return 0;
}
