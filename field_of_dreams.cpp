#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    system("chcp 1251");
    system("cls");
	//setlocale(LC_ALL, "Russian");
    
    char a[100], b[100], c;
    
    cout << "������� �����\n";
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
        cout << "������� �����\n";
        cin >> c;
        for (int q = 0; q < i; q++)
        {
            if (a[q] == c)
            {
				for (int f = q; f < i; f++)   //�������� �� ������������� �����
				{
					if (a[f] == c)
					{
						b[f] = c;
						a[f] = '*';
						s++;
					}
				}
                cout << "���� ����� ����� " << '\n' << b << '\n';
                p = 1;
            }
        }
        if (p == 0) cout << "��� ����� �����\n";
        p = 0;
    }
    cout << "�� �������!\n";

    system("pause");
    return 0;
}