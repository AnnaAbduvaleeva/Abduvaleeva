#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
	//setlocale(LC_ALL, "Russian");
    
    char a[100], b[100], c[100], d[100];
    
    cout << "Введите слово\n";
    gets(a);
    
    int i = strlen(a);
	for (int g = 0; g < i; g++)
		d[g] = a[g];
    for (int k = 0; k < i; k++)
        b[k] = '-';
    b[i]='\0';
	d[i]='\0';
    cout << b << '\n';
    
    int s = 0, p = 0;
    while (s < i)
    {
        cout << "Введите букву\n";
        gets(c);
		if (strlen(c) > 1)
		{
			for (int j = 0; j < strlen(a); j++)
			{
				if 	(c[j] != d[j])
				{
					cout << "К сожалению, Вы не угадали слово. Вы проиграли.\n";
					system("pause");
					exit(0);
				}
			}
			cout << "Вы угадали!\n"; 
			system("pause");
			exit(0);
		}
		
		else 
		{
			char m = c[0];
			for (int q = 0; q < i; q++)
			{
				if (b[q] == m)
				{
					cout << "Эта буква уже была, попробуйте ещё раз\n";
					p = 1;
					break;
				}
			}
			
					for (int q = 0; q < i; q++)
					 {
						if (a[q] == m)
						 {
							for (int f = q; f < i; f++)   //проверка на повторяющиеся буквы
							{
								if (a[f] == m)
								{
									b[f] = m;
									a[f] = '*';
									s++;
								}
							}
						  cout << "Есть такая буква " << '\n' << b << '\n';
						  p = 1;
						}
					}
        
		if (p == 0) cout << "Нет такой буквы\n";
		p = 0;
		}
	}
    cout << "Вы угадали!\n";

    system("pause");
    return 0;
}