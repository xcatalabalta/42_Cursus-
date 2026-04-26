#include <iostream>
#include <string>

void PutStr(std::string str)
{
	for (int i = 0; str[i]; i++)
		std::cout << str[i];
}

int main ()
{
	std::string greet = "Hello!";
	std::string entra;

	for (int i = 0; greet[i]; i++)
		std::cout << greet[i];
	std::cout << std::endl;
	std::cout <<"Enter a string: ";
	std::getline(std::cin, entra);
	PutStr(entra);
	std::cout << std:: endl << greet << " " << entra;
	return (0);
}
