#include "Base.hpp"

int	main(void) {

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		Base*	meta = generate();

		identify(meta);
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
	}	

	{
		std::cout << std::endl;
		std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		std::cout << std::endl;
		Base	meta;
		A		gama;
		B		ama;
		C		ma;
		identify(meta);
		identify(gama);
		identify(ama);
		identify(ma);
	}
	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	return (0);
}



// #include "Data.hpp"
// #include "Serializer.hpp"

// int main() {
//     Data myData = {42, "John Doe"};  // Create a Data object

//     // Serialize
//     uintptr_t raw = Serializer::serialize(&myData);
//     std::cout << "Serialized: " << raw << std::endl;

//     // Deserialize
//     Data* deserializedPtr = Serializer::deserialize(raw);
//     std::cout << "Deserialized ID: " << deserializedPtr->id << std::endl;
//     std::cout << "Deserialized Name: " << deserializedPtr->name << std::endl;

//     // Verify that the original pointer and deserialized pointer are the same
//     if (deserializedPtr == &myData) {
//         std::cout << "Success: Pointers match!" << std::endl;
//     } else {
//         std::cout << "Error: Pointers do not match!" << std::endl;
//     }

//     return 0;
// }