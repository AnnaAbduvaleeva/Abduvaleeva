#include <iostream>
#include <cstdlib>

using namespace std;

class LIFO {
private:
	int *array;
	int lenght;

public: 
	LIFO(int N)
	{
		if (N <= 0)
		{
			cout << "Error\n";
			system ("pause");
			exit(0);
		}

		lenght = N;
		array = new int[lenght];
	}

	~LIFO()
	{
		delete[] array;
	}

	void push(int index, int number)
	{
		array[lenght - index - 1] = number;
	}

	void pop(int a)
	{
		int j = 0;
		cout << a + 1 << " will be retrieved " << array[0] << "\n";
			
		while (j < lenght - 1)
		{
			array[j] = array[j + 1];
			j++;
		}
	}

};

int main()
{
	cout << "Enter the starting lenght of the array\n";
	int N, q;
	cin >> N;

	LIFO array(N);

	cout << "Enter integers via ENTER: \n";
	int i = 0;
	while (i < N)
	{
		cin >> q;
		array.push(i, q);
		i++;
	}

	for (i = 0; i < N; i++)
		array.pop(i);

	system("pause");
	return 0;
}