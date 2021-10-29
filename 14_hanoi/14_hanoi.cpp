#include <iostream>
#include <cstdlib>

using namespace std;

void hanoi_towers(int quantity, int from, int to, int buf_peg)	//quantity-����� �����
																//from-��������� ��������� �����(1-3)
																//to-�������� ��������� �����(1-3)
{																//buf_peg - ������������� �������(1-3)
	if (quantity != 0)
	{
		hanoi_towers(quantity-1, from, buf_peg, to);   // (N-1) ������ ����������� � ���������� ��������� � �������������

		cout << from << " -> " << to << endl; // N ���� ����������� � ���������� ��������� � ��������

		hanoi_towers(quantity-1, buf_peg, to, from); // (N-1) ������ ����������� �� �������������� ��������� � ��������
	}
}

int main()
{
    setlocale(LC_ALL,"rus");
	int start_peg = 1, destination_peg = 3, buffer_peg = 2, plate_quantity;

	/*cout << "����� ������� ��������:" << endl;
	cin >> start_peg;
	cout << "����� ��������� ��������:" << endl;
	cin >> destination_peg;
	cout << "����� �������������� ��������:" << endl;
	cin >> buffer_peg;*/

	cout << "���������� ������:" << endl;
	cin >> plate_quantity;

	hanoi_towers(plate_quantity, start_peg, destination_peg, buffer_peg);
	system("pause");
return 0;
}