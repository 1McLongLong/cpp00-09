#include "Serializer.hpp"

int	main() {
	Data *ptr_data = new Data;

	ptr_data->value = 55;
	uintptr_t un_ptr = Serializer::serialize(ptr_data);
	Data *ptr_data2 = Serializer::deserialize(un_ptr);
	std::cout << ptr_data2->value << std::endl;
}
