#include <iostream>
#include <cstdlib>

int main()
{
	std::cout<<"Think of a namber from 1 to 100\n";
	int a=1, b=100, c, answer, i=1, k=0;
	while (i>0)
	{
		if ((a+b)%2==0)
		{
			c=(a+b)/2;
		}
		else c=(a+b-1)/2;
		std::cout<<"Is your nomber more than "<<c<<'?'<<'\n'<<"1. Yes\n"<<"2. No\n"<<"3. Equals\n";
		std::cin>>answer;
		if (answer==1)
		{
			a=c;
			i=1;
			k++;
		}
		else if (answer==2)
		{
			b=c;
			i=1;
			k++;
		}
		else if (answer==3)
		{
			std::cout<<"Your nomber "<<c<<'\n';
			i=0;
			k++;
		}
	}
	std::cout<<"Nomber of attempts: "<<k<<'\n';
	system("pause");
	return 0;
} 