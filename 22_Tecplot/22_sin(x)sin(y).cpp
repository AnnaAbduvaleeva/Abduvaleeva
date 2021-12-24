#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int main()
{
	ofstream outfile("sin(x)sin(y).dat");

    outfile << "TITLE = \"Z = sin(X) * sin(Y)\"" << endl;
	outfile << "VARIABLES = \"X\", \"Y\", \"Z\"" << endl;
	outfile << "ZONE T = \"ZONE1\", I = 100 J = 100, F = POINT" << endl;

    double h, x, y;
    x = 0.0;
	y = 0.0;
	h = (2.0 * acos(-1)) / 100.0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            outfile << x << ", " << y << ", " << sin(x) * sin(y) << endl;
            y += h;
        }
        y = 0.0;
        x += h;
    }

    outfile.close();
	return 0;
}