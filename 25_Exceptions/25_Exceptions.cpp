#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class CRational {
private:
	int numerator, denominator;

public:
	CRational()  
	{
        numerator = 1;
        denominator = 1;
    }

	CRational (int num, int den)
	{
        numerator = num;
		try{
		  if (den == 0) 
		        throw 3;
		  denominator = den;
		}
        catch (int except)
        {
          cout << "Error! Denominator can't be 0\n";
		  system("pause");
		  exit(except);
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
        int num, den;
		try{
		    if (INT_MAX / numerator < otherCRational.denominator || INT_MAX / otherCRational.numerator < denominator ||
				INT_MAX / denominator < otherCRational.denominator)
		        throw 4;
		    den = denominator * otherCRational.denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}

		try{
		    if (INT_MAX - numerator * otherCRational.denominator < otherCRational.numerator * denominator)
		        throw 4;
		    num = numerator * otherCRational.denominator + otherCRational.numerator * denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}
		return CRational(num, den).Reduce();
	}

	CRational Product(CRational otherCRational)
	{
        int num, den;
		try{
		    if (INT_MAX / numerator < otherCRational.numerator || INT_MAX / otherCRational.denominator < denominator)
		        throw 5;
		    num = numerator * otherCRational.numerator;
			den = denominator * otherCRational.denominator;
		}
		catch(int except)
		{
			cout << "Overflow error\n";
			system("pause");
            exit(except);
		}
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
		try{
		    if (numerator * denominator <= 0)
		        throw 6;
		     sign = 1; 
		}
		catch(int except)
		{
			sign = -1;
		}

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
	try{
          if (num1 == 0xcccccccc || den1 == 0xcccccccc) //not numbers
              throw 1;
    }
    catch (int except)
    {
          cout << "Error! You should enter numbers\n";
		  system("pause");
          exit(except);
    }

	try{
          if ((num1 - int(num1)) != 0 || (den1 - int(den1)) != 0) 
              throw 2;
    }
    catch (int except)
    {
          cout << "Error! You should enter integer numbers\n";
		  system("pause");
          exit(except);
    }
	CRational drob1(num1, den1);

	cout << "Enter the numeratorand denominator of the second fraction separated by a space\n";
	cin >> num2 >> den2;
	try{
          if (num2 == 0xcccccccc || den2 == 0xcccccccc) //not numbers
               throw 1;
    }
    catch (int except)
    {
          cout << "Error! You should enter numbers\n";
		  system("pause");
          exit(except);
    }

	try{
          if ((num2 - int(num2)) != 0 || (den2 - int(den2)) != 0) 
              throw 2;
    }
    catch (int except)
    {
          cout << "Error! You should enter integer numbers\n";
		  system("pause");
          exit(except);
    }

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