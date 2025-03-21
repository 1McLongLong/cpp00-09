#include "Serializer.hpp"

int main()
{
  Data *data = new Data;
  data->value = 42;

  std::cout << "Original data - Address: " << data << ", Value: " << data->value << std::endl;

  uintptr_t serialized = Serializer::serialize(data);
  std::cout << "Serialized: " << serialized << std::endl;

  Data *deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized data - Address: " << deserialized << ", Value: " << deserialized->value << std::endl;

  std::cout << "Pointers are equal: " << (data == deserialized ? "true" : "false") << std::endl;

  delete data;
  return 0;
}
