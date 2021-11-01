#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	char a[100];
	char b[100];
	cout<<"Enter a string\n";
	gets(a);
	for (int i = 0; i < 100; i++)
	{
		b[i]=a[i];
	}
	cout<<b<<'\n';
	system("pause");
	return 0;
}