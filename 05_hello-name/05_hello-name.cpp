#include <iostream>
#include <cstdlib>

int main()
{
	char name[10];
	std::cout << "What's your name?\n";
	std::cin >> name;
	std::cout << "Hello, " << name <<'!' << '\n';
	system("pause");
	return 0;
}