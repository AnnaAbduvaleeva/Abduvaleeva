#include <iostream>
#include <cstdlib>

using namespace std;

void hanoi_towers(int quantity, int from, int to, int buf_peg)	//quantity-число колец
																//from-начальное положение колец(1-3)
																//to-конечное положение колец(1-3)
{																//buf_peg - промежуточный колышек(1-3)
	if (quantity != 0)
	{
		hanoi_towers(quantity-1, from, buf_peg, to);   // (N-1) дисков передвигаем с начального положения в промежуточное

		cout << from << " -> " << to << endl; // N диск передвигаем с начального положения в конечный

		hanoi_towers(quantity-1, buf_peg, to, from); // (N-1) дисков передвигаем из промежуточного положения в конечное
	}
}

int main()
{
    setlocale(LC_ALL,"rus");
	int start_peg = 1, destination_peg = 3, buffer_peg = 2, plate_quantity;

	/*cout << "Номер первого столбика:" << endl;
	cin >> start_peg;
	cout << "Номер конечного столбика:" << endl;
	cin >> destination_peg;
	cout << "Номер промежуточного столбика:" << endl;
	cin >> buffer_peg;*/

	cout << "Количество дисков:" << endl;
	cin >> plate_quantity;

	hanoi_towers(plate_quantity, start_peg, destination_peg, buffer_peg);
	system("pause");
return 0;
}