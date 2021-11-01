#include <iostream>
#include <cstdlib>

using namespace std;

class FIFO {
private:
	int *array;
	int lenght;

public: 
	FIFO(int N)
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

	~FIFO()
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
		while (j < lenght)
		{
			cout << a + 1 << " will be retrieved " << array[lenght - 1] << "\n";
			lenght--;
			a++;
		}
	}

};

int main()
{
	cout << "Enter the starting lenght of the array\n";
	int N, q;
	cin >> N;

	FIFO array(N);

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