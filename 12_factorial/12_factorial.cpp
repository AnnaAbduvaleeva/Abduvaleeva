#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>

using namespace std;

int main()
{
	float AA;
	int n = 0, f = 1, a;
	string A;
	cout << "Enter number: " << '\n';
	cin >> A;

	for (int i = 0; i < A.length(); i++)
	{
		if (isdigit(A[i]) || A[i] == '.' || A[i] == '-' || A[i] == ',') //�������� �� �������: ����������� �����, �����, ������� � �����
			n++;
		else 
		{
			cout << "Incorrect input. Please, try again.\n";
			system("pause");
			exit(0);
		}
	}	

	if (A.length() == n)
		{
			AA = stof(A); //����������� ������ � ����� � ��������� ������
			a = stoi(A); //����������� ������ � ����� �����

			if (AA == 0)
			{
				cout << AA << "! = 1\n";
				system("pause");
				exit(0);
			}

			if (AA < 0)
			{
				cout << "You entered a negative number. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (a != AA)
			{
				cout << "You entered a non-integer number. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (a > 100000)
			{
				cout << "You entered a number more than 100000. Please, try again.\n";
				system("pause");
				exit(0);
			}
		}
		
	for (int j = 1; j <= a; j++)
		f = f * j;
	cout << A << "! = " << f << '\n';
	system("pause");
	return 0;
} 
