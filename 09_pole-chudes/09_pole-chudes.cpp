#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
	//setlocale(LC_ALL, "Rus");
    
    char a[100], b[100], c;
    
    cout << "Введите слово\n";
    gets(a);
    
    int i = strlen(a);
	//cout << i;
    for (int k = 0; k < i; k++)
        b[k] = '-';
    b[i]='\0';
    cout << b << '\n';
    
    int s = 0, p = 0;
    while (s < i)
    {
        cout << "Введите букву\n";
        cin >> c;
        for (int q = 0; q < i; q++)
        {
            if (a[q] == c)
            {
				for (int f = q; f < i; f++)   
				{
					if (a[f] == c)
					{
						b[f] = c;
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
    cout << "Вы угадали!\n";

    system("pause");
    return 0;
}
