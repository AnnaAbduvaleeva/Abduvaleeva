#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Rectangle
{
public:
	double x_left_lower, y_left_lower, x_right_upper, y_right_upper;
	Rectangle(double x_left_lower, double  y_left_lower, double x_right_upper,  double y_right_upper) : x_left_lower(x_left_lower), y_left_lower(y_left_lower), x_right_upper(x_right_upper), y_right_upper(y_right_upper) {}
};

void Cross(Rectangle rectangle1, Rectangle rectangle2)
{
	bool check = false;

	if (rectangle1.x_right_upper < rectangle2.x_left_lower || rectangle1.x_left_lower > rectangle2.x_right_upper)
		check = false;
	if (rectangle1.x_left_lower <= rectangle2.x_left_lower && rectangle1.x_right_upper >= rectangle2.x_left_lower && 
		rectangle1.y_left_lower <= rectangle2.y_left_lower && rectangle2.y_left_lower <= rectangle1.y_right_upper)
		check = true;
	if (rectangle2.x_right_upper >= rectangle1.x_left_lower && rectangle2.x_left_lower <= rectangle1.x_right_upper && 
		rectangle2.y_left_lower >= rectangle1.y_left_lower && rectangle2.y_left_lower <= rectangle1.y_right_upper)
		check = true;
	if (rectangle1.x_left_lower <= rectangle2.x_left_lower && rectangle1.x_right_upper >= rectangle2.x_left_lower && 
		rectangle2.y_left_lower <= rectangle1.y_left_lower && rectangle2.y_right_upper >= rectangle1.y_left_lower)
		check = true;

	if (check)
		cout << "Rectangles intersect\n";
	else 
		cout << "Rectangles don't intersect\n";
}

int main ()
{
	double x1_left_lower, y1_left_lower, x1_right_upper, y1_right_upper;
	double x2_left_lower, y2_left_lower, x2_right_upper, y2_right_upper;
	
	ifstream outfile ("Coordinates.txt");
	
	outfile >> x1_left_lower >> y1_left_lower >> x1_right_upper >> y1_right_upper >> x2_left_lower >> y2_left_lower >> x2_right_upper >> y2_right_upper;
	
	outfile.close();
	Rectangle rect1(x1_left_lower, y1_left_lower, x1_right_upper, y1_right_upper);
	Rectangle rect2(x2_left_lower, y2_left_lower, x2_right_upper, y2_right_upper);
	
	Cross(rect1, rect2);
	
	system ("pause");
	return 0;
}