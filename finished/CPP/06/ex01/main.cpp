#include <iostream>
#include <string>

typedef struct s_data {

	std::string content;
	int			content2;
}			Data;

uintptr_t serialize(Data *ptr) {

	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw) {

	return (reinterpret_cast<Data *>(raw));
}

int	main(void) {

	Data test;

	test.content = "Salut ca va ?";
	test.content2 = 42;

	std::cout << "Data struct contains string : '" << test.content << "' and int : '" << test.content2 << "'" << std::endl;

	uintptr_t raw = serialize(&test);

	std::cout << "Data has been serialized as a uintptr_t : " << raw << std::endl;

	Data *test2 = NULL;
	test2 = deserialize(raw);

	std::cout << "The raw uintptr_t has been deserialized in a new structure that should have the same content as the original one. " << std::endl;
	std::cout << "New struct contains string : '" << test2->content << "' and int : '" << test2->content2 << "'" << std::endl;
	return (0);
}