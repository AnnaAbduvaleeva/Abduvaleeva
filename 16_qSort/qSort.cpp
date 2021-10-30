#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void swap_var(int *var1, int *var2)
{
	if (var1 != var2)
	{
		*var1 = *var1 + *var2;
		*var2 = *var1 - *var2;
		*var1 = *var1 - *var2;
	}
}

void quicksort(int *str, int first, int last)
{
	int pivot, var;
	int f = first, l = last;
	pivot = str[(f + l) / 2]; //опорный элемент, относительно которого разбиваю массив на 2 части
	do
	{
		while (str[f] < pivot) 
			f++;
		while (str[l] > pivot)
			l--;
		if (f <= l)
		{
			/*var = str[f];   // 1-й способ обмена значениями
			str[f] = str[l];
			str[l] = var;*/

			//swap(str[l], str[f]);  // 2-й способ обмена значениями

			swap_var(&str[l], &str[f]); // 3-й способ обмена значениями

			f++;
			l--;
		}
	} while (f < l);
	if (first < l) quicksort(str, first, l); 
	if (f < last) quicksort(str, f, last);
}


int main ()
{
	string number;
	float NN;
	const int k = 1000;
	int n = 0, N;
	cout << "Enter a natural number from 1 to 100: ";
	cin >> number;
	for (int i = 0; i < number.length(); i++)
	{
		if (isdigit(number[i]) || number[i] == '.' || number[i] == '-' || number[i] == ',') //Проверка строки на символы
			n++;
		else 
		{
			cout << "Incorrect input. Please, try again.\n";
			system("pause");
			exit(0);
		}
	}	

	if (number.length() == n)
		{
			NN = stof(number); 
			N = stoi(number); 


			if (NN < 1)
			{
				cout << "You entered a number less than 1. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (NN > 100)
			{
				cout << "You entered a number more than 100. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (N != NN)
			{
				cout << "You entered a non-integer number. Please, try again.\n";
				system("pause");
				exit(0);
			}

			if (N == 1)
			{
				cout << "The length of your array is 1. It's already sorted. It's not neccessary to replace any element of the array.\n";
			}
		}
	cout << "Source array:\n"; 
	int randomDigits[k];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	 {
		randomDigits[i] = rand() % 401 - 200; //генерация чисел от -200 до 200
		cout << randomDigits[i] << ' ';
	 }
	cout << '\n';

	int first = 0, last = N - 1;
	quicksort(randomDigits, first, last); //вызов функции
	cout << "Sorted array:\n";
	for (int j = 0; j < N; j++)
		cout << randomDigits[j] << ' ';
	cout << '\n';

	system ("pause");
	return 0;
}