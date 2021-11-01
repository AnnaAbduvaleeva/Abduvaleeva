#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class CRational {
private:
	int numerator, denominator;

public:
	CRational()  //конструктор по умолчанию
	{
        numerator = 1;
        denominator = 1;
    }

	CRational (int num, int den)
	{
		numerator = num;
		if (den != 0)
			denominator = den;
		else 
		{
			cout << "Error! Denominator can't be 0\n";
			system("pause");
			exit(0);
		}
	}

	int GreatestCommonDivisor (int n, int d)
	{
		if (d == 0)
			return n;
		else
			return GreatestCommonDivisor (d, n % d);
	}

	CRational Sum(CRational otherCRational)
	{
        int num = numerator * otherCRational.denominator + otherCRational.numerator * denominator;
        int den = denominator * otherCRational.denominator;

		return CRational(num, den).Reduce();
	}

	CRational Product(CRational otherCRational)
	{
        int num = numerator * otherCRational.numerator;
        int den = denominator * otherCRational.denominator;

		return CRational(num, den).Reduce();
    }

	CRational Reduce()
	{
		int num = numerator / GreatestCommonDivisor (abs (numerator), denominator);
		int den = denominator / GreatestCommonDivisor (abs(numerator), denominator);

		return CRational(num, den);
	}

	void Print()
	{
		int sign;
		if (numerator * denominator >= 0)
			 sign = 1;
		else  sign = -1;

		numerator = abs(numerator);
		denominator = abs(denominator);

		if (denominator == 1)
			cout << sign * numerator << "\n";
		else if (numerator < denominator)
            cout << sign * numerator << "/" << denominator << "\n";
		else if (numerator > denominator)
			cout << sign * numerator / denominator << " " << numerator % denominator << "/" << denominator << "\n";
	}
};

	
int main()
{
	int num1, den1, num2, den2;
	cout << "Enter the numeratorand denominator of the first fraction separated by a space\n";
	cin >> num1 >> den1;
	cout << "Enter the numeratorand denominator of the second fraction separated by a space\n";
	cin >> num2 >> den2;

	CRational drob1(num1, den1);
	CRational drob2(num2, den2);
	CRational drob3;

	cout << '\n';

	drob3 = drob1.Sum(drob2);
	cout << "The sum is ";
	drob3.Print();
	
	drob3 = drob1.Product(drob2);
	cout << "The product is ";
	drob3.Print();

	system("pause");
	return 0;
}