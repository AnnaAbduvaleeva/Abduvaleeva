#include <iostream>
#include <cstdlib>

using namespace std;

class Container
{
protected: 
	int *array;
	int lenght;
	int element;

public:
	Container(int lenght_a)
	{
		lenght = lenght_a;
		array = new int[lenght];
		element = 0;
	}
	virtual void push(int q) = 0;
	virtual void pop(int &i) = 0;

	~Container()
	{
		delete[] array;
	};

};

class FIFO: public Container
{
public:
	FIFO(int lenght_a): Container(lenght_a) {}

	virtual void push(int q)
	{
		array[element] = q;
		element ++;
	}
	virtual void pop(int &i)
	{
		int j = 0;
		if (element - 1 < lenght)
		{
			cout << i + 1 << " will be retrieved "<< array[0] << endl; 
		
			for(j = 0; j < lenght - 1; j++)
				array[j] = array[j+1];
		}
		else cout << i + 1 << " will be retrieved "<< array[element - 1] << endl;
	}
};


int main()
{
	cout << "Enter the starting lenght of the queue: ";
	int N, q;
	cin >> N;

	FIFO Queue(N);

	cout << "Enter integer elements of the queue: ";
	int i = 0;
	while (i < N)
	{
		cin >> q;
		Queue.push(q);
		i++;
	}

	for (i = 0; i < N; i++)
		Queue.pop(i);
	Queue.push(10);
	Queue.pop(i);

	system("pause");
	return 0;
}