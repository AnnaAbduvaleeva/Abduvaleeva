#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile("sin(x).dat");

    outfile << "TITLE = \"Y = sin(X)\"" << endl;
	outfile << "VARIABLES = \"X\", \"Y\"" << endl;

    double h, x, y;
    x = 0.0;
	h = (2.0 * acos(-1.0)) / 100.0;

    for (int i = 0; i < 100; i++) 
	{
        x = x + i * h;
        outfile << x << ", " << sin(x) << endl;
        x = 0;
    }

    outfile.close();
	return 0;
}