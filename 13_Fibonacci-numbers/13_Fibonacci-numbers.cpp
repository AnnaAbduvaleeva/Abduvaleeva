#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string N;
	int n = 0, Nn;
	float NN;
	cout << "Enter a number from 1 to 100\n";
	cin >> N;
	for (int i = 0; i < N.length(); i++)
	{
		if (isdigit(N[i]) || N[i] == '.' || N[i] == '-' || N[i] == ',') //проверка на символы: принимаются числа, точка, запятая и минус
			n++;
		else 
		{
			cout << "Incorrect input. Please, try again.\n";
			system("pause");
			exit(0);
		}
	}

	if (N.length() == n)
		{
			NN = stof(N); //преобразует строку в число с плавающей точкой
			Nn = stoi(N); //преобразует строку в целое число

			if (NN < 1)
			{
				cout << "You entered a number less than 1. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (Nn != NN)
			{
				cout << "You entered a non-integer number. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (Nn > 100)
			{
				cout << "You entered a number more than 100. Please, try again.\n";
				system("pause");
				exit(0);
			}
		}

	int fb1 = 0, fb2 = 1, fbN;
	cout << fb1 << ' ' << fb2 << ' ';
	for (int k = 3; k <= Nn; k++)
	{
		fbN = fb1 + fb2;
		cout << fbN << ' ';
		fb1 = fb2;
		fb2 = fbN;
	}
	cout << '\n';
	system("pause");
	return 0;
}

