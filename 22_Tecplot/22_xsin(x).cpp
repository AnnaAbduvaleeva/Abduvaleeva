#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile("xsin(x).dat");

    outfile << "TITLE = \"Y = X * sin(X)\"" << endl;
	outfile << "VARIABLES = \"X\", \"Y\"" << endl;

    double h, x;
    x = -100;
	h = (100.0 - (-100.0)) / 200.0;

    for (int i = 0; i < 200; i++) {
        outfile << x << ", " << x * sin(x) << endl;
        x += h;
    }

    outfile.close();
	return 0;
}