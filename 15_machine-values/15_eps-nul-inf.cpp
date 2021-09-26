#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
	int n = 0, k = 0, m = 0;
	float eps_float = 1.0f, nul_checkf = 1.0f, nul_float,inf_positiv_float, inf_negativ_float;
	double eps_double = 1.0, nul_checkd = 1.0, nul_double,inf_positiv_double, inf_negativ_double;
	long double eps_ldouble = 1.0, nul_checkld = 1.0, nul_ldouble, inf_positiv_ldouble, inf_negativ_ldouble;


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

	inf_positiv_float = FLT_MAX;
	inf_negativ_float = - FLT_MAX;
	inf_positiv_double = DBL_MAX;
	inf_negativ_double = - DBL_MAX;
	inf_positiv_ldouble = LDBL_MAX;
	inf_negativ_ldouble = - LDBL_MAX;

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
