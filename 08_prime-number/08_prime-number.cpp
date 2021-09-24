#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int a, b = 1, c, i, j;
	cout << "Enter a number\n";
	cin >> a;
	c = a;
	while ((c /= 10) > 0)
		b ++;
	for (j = 1; j <= b; j ++)
	{
		if(!cin)
		{
			cout << "Error\n"; //для чисел с запятой и строк, начинающихся с чисел, программа превращат их в int
			system("pause");
			exit(0);
		}
	}
	if (a == 1)
		cout << "You entered 1\n";
	else
	{
		for (i = 2; i < a; i ++)
		{
			if (a % i == 0)
			{
				cout << "The nomber " << a << " is composite\n";
				system("pause");
				exit(0);
			}
		}
		cout << "The nomber " << a << " is prime\n";
	}
	system("pause");
	return 0;
}