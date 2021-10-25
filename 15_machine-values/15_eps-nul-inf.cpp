#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main ()
{
	int n = 0, k = 0, m = 0;
	float eps_float = 1.0f, nul_checkf = 1.0f, nul_float, inf_positiv_float = 1, inf_negativ_float = 1;
	double eps_double = 1.0, nul_checkd = 1.0, nul_double, inf_positiv_double = 1, inf_negativ_double = 1;
	long double eps_ldouble = 1.0, nul_checkld = 1.0, nul_ldouble, inf_positiv_ldouble = 1, inf_negativ_ldouble = 1;


	while (1.0f + eps_float != 1.0f)
		eps_float = eps_float / 2.0f;

	while (1.0 + eps_double != 1.0)
		eps_double = eps_double / 2.0;

	while (1.0 + eps_ldouble != 1.0)
		eps_ldouble = eps_ldouble / 2.0;
	
	cout << "Machine epsilon: \n" ;
	cout << "float -> " << eps_float << '\n';
	cout << "double -> " << eps_double << '\n';
	cout << "long double -> " << eps_ldouble << '\n';
	cout << '\n';


	while (nul_checkf != 0)
	{
		nul_checkf = nul_checkf / 2.0f;
		n++;
	}
	nul_float = pow (2, -(n-1));

	while (nul_checkd != 0)
	{
		nul_checkd = nul_checkd / 2.0;
		m++;
	}
	nul_double = pow (2, -(m-1));

	while (nul_checkld != 0)
	{
		nul_checkld = nul_checkld / 2.0;
		k++;
	}
	nul_ldouble = pow (2, -(k-1));

	cout << "Machine zero:\n";
	cout << "float -> " << nul_float << '\n';
	cout << "double -> " << nul_double << '\n';
	cout << "long double -> " << nul_ldouble << '\n';
	cout << '\n';

	cout << "Sum and difference of machine zero and machine epsilon:\n";
	cout << "float ->" << nul_float + eps_float << '\n';
	cout << '\t' << nul_float - eps_float << '\n'; 

	cout << "double -> " << nul_double + eps_double << '\n';
	cout << '\t' << nul_double - eps_double << '\n';

	cout << "long double -> " << nul_ldouble + eps_ldouble << '\n';
	cout << '\t' << nul_ldouble - eps_ldouble << '\n'; 
	cout << '\n';

	int counter_inf_pos_float = 0;
	while(inf_positiv_float < pow(10, 10000))
	{
		counter_inf_pos_float = counter_inf_pos_float + 1;
		inf_positiv_float = inf_positiv_float * 2.0f;
	}
	inf_positiv_float = pow(2, counter_inf_pos_float - 1);

	int counter_inf_neg_float = 0;
	while(inf_negativ_float > -pow(10, 10000))
	{
		inf_negativ_float = abs(inf_negativ_float);
		counter_inf_neg_float = counter_inf_neg_float + 1;
		inf_negativ_float = inf_negativ_float * (-2.0f);
	}
	inf_negativ_float = -pow(2, counter_inf_neg_float - 1);


	int counter_inf_pos_double = 0;
	while(inf_positiv_double < pow(10, 10000))
	{
		counter_inf_pos_double = counter_inf_pos_double + 1;
		inf_positiv_double = inf_positiv_double * 2.0;
	}
	inf_positiv_double = pow(2, counter_inf_pos_double - 1);

	int counter_inf_neg_double = 0;
	while(inf_negativ_double > - pow(10, 10000))
	{
		inf_negativ_double = abs(inf_negativ_double);
		counter_inf_neg_double = counter_inf_neg_double + 1;
		inf_negativ_double = inf_negativ_double * (-2.0);
	}
	inf_negativ_double = - pow(2, counter_inf_neg_double - 1);


	int counter_inf_pos_ldouble = 0;
	while(inf_positiv_ldouble < pow(10, 10000))
	{
		counter_inf_pos_ldouble = counter_inf_pos_ldouble + 1;
		inf_positiv_ldouble = inf_positiv_ldouble * 2.0;
	}
	inf_positiv_ldouble = pow(2, counter_inf_pos_ldouble - 1);

	int counter_inf_neg_ldouble = 0;
	while(inf_negativ_ldouble > - pow(10, 100000))
	{
		inf_negativ_ldouble = abs(inf_negativ_ldouble);
		counter_inf_neg_ldouble = counter_inf_neg_ldouble + 1;
		inf_negativ_ldouble = inf_negativ_ldouble * (-2.0);
	}
	inf_negativ_ldouble = - pow(2, counter_inf_neg_ldouble - 1);
	

	cout << "Machine infinity: \n";
	cout << "float -> " << inf_positiv_float << '\n';
	cout << '\t' << inf_negativ_float << '\n';
	cout << "double -> " << inf_positiv_double << '\n';
	cout << '\t' << inf_negativ_double << '\n';
	cout << "long double -> " << inf_positiv_ldouble << '\n';
	cout << '\t' << inf_negativ_ldouble << '\n';


	system ("pause");
	return 0;
}
