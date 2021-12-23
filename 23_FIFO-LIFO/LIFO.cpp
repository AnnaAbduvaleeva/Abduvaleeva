#include <iostream>
#include <cstdlib>

using namespace std;

class Container
{
protected: 
	int *array;
	int length;
	int element;

public:
	Container(int length_a)
	{
		length = length_a;
		array = new int[length];
		element = 0;
	}
	virtual void push(int q) = 0;
	virtual void pop(int &i) = 0;
	virtual void Deleting_Element(int *&array, int &length) = 0;

	~Container()
	{
		delete[] array;
	};

};

class LIFO: public Container
{
public:
	LIFO(int lenght_a): Container(lenght_a) {}

	~LIFO()
	{
		delete[] array;
	}

	virtual void push(int q)
	{
		array[length - element - 1] = q;
		element ++;
	}

	virtual void pop(int &a)
	{
		cout << a + 1 << ')' << " will be retrieved "<< array[0] << endl; 
		Deleting_Element(array, length);
	}
	virtual virtual void Deleting_Element(int *&array, int &length) 
	{
		int *new_array = new int[length-1];
		for(int i = 0; i < length-1; i++)
			new_array[i] = array[i+1];
		cout << endl << endl;
		length --;
		delete[] array;
		array = new_array;
	}

};

int main()
{
	cout << "Enter the lenght of the array: \n";
	int N, q;
	cin >> N;

	LIFO array(N);

	cout << "Enter integer numbers: \n";
	int i = 0;
	while (i < N)
	{
		cin >> q;
		array.push(q);
		i++;
	}

	for (i = 0; i < N; i++)
		array.pop(i);

	system("pause");
	return 0;
}