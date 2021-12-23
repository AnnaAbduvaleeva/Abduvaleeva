#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

class Object_2D 
{
public:
    virtual void Move(double, double) = 0; //чисто виртуальные функции
    virtual void Rotate(double) = 0;
    virtual void Scale(double) = 0;
    virtual void Show() = 0;
};

class Circle:public Object_2D
{
private:
    double x_center;
    double y_center;
    double radius;
    
public:
    Circle(double c_x, double c_y, double r)
    {
        x_center = c_x;
        y_center = c_y;
        radius = r;
    }
    
    void Move(double h, double alpha) override
    {
        x_center = x_center + h * cos(alpha * acos(-1.0) / 180.0);
        y_center = y_center + h * sin(alpha * acos(-1.0) / 180.0);
    }
    
    void Rotate(double alpha) override//при вращении ничего не изменится
    {
        x_center = x_center * 1;
        y_center = y_center * 1;
        radius = radius * 1;
    }
    
    void Scale(double k) override
    {
        radius = radius * k;
    }
    
    void Show() override
    {
       cout << "Circle, center (" << x_center << ',' << y_center << "), r = " << radius << endl; 
    }

	//~Circle();
};

class Square:public Object_2D 
{
private:
    double x_center;
    double y_center;
    double angle;
    double width;
    double diagonal;
    double vertex[8];
    
public:
    Square(double c_x, double c_y, double a, double w): Object_2D()
    {
       x_center = c_x;
       y_center = c_y;
       angle = a;
       width = w;
       diagonal = width * sqrt(2.0);
       vertex[0] = x_center + diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
       vertex[1] = y_center + diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
       vertex[2] = x_center - diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
       vertex[3] = y_center + diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
       vertex[4] = x_center - diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
       vertex[5] = y_center - diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
       vertex[6] = x_center + diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
       vertex[7] = y_center - diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
    }
    
    void Move(double h, double alpha) override
    {
        int i;
        for (i = 0; i < 8; i += 2) 
        {
            vertex[i] = vertex[i] + h * cos(alpha * acos(-1.0) / 180.0);
            vertex[i + 1] = vertex[i + 1] + h * sin(alpha * acos(-1.0) / 180.0);
        }
        x_center = x_center + h * cos(alpha * acos(-1.0) / 180.0);
        y_center = y_center + h * sin(alpha * acos(-1.0) / 180.0);
    }
    
    void Rotate(double alpha) override
    {
        for (int i = 0; i < 8; i += 2) 
        {
            double old_x, old_y;
            old_x = vertex[i];
            old_y = vertex[i + 1];
            vertex[i] = (old_x - x_center) * cos(alpha * acos(-1.0) / 180.0) - (old_y - y_center) * sin(alpha * acos(-1.0) / 180.0);
            vertex[i + 1] = (old_x - x_center) * sin(alpha * acos(-1.0) / 180.0) + (old_y - y_center) * cos(alpha * acos(-1.0) / 180.0); 
        }
		angle = angle + alpha;
    }
    
    void Scale(double k) override
    {
        double new_diagonal;
        new_diagonal = width * k * sqrt(2.0);
        vertex[0] = x_center + new_diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
        vertex[1] = y_center + new_diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
        vertex[2] = x_center - new_diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
        vertex[3] = y_center + new_diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
        vertex[4] = x_center - new_diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
        vertex[5] = y_center - new_diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
        vertex[6] = x_center + new_diagonal / 2.0 * sin(angle * acos(-1.0) / 180.0);
        vertex[7] = y_center - new_diagonal / 2.0 * cos(angle * acos(-1.0) / 180.0);
    }
    
    void Show() override
    {
        std::cout << "Square, vertex coordinates: " << endl;
        std::cout << "1. (" << vertex[0] << "," << vertex[1] << ");" << endl;
        std::cout << "2. (" << vertex[2] << "," << vertex[3] << ");" << endl;
        std::cout << "3. (" << vertex[4] << "," << vertex[5] << ");" << endl;
        std::cout << "4. (" << vertex[6] << "," << vertex[7] << ");" << endl;
    }

	//~Square();
};

int main()
{
    Circle cir1(0,0,5);
    Circle cir2(2,2,2);
    Square sq1(2,2,45,4);
    Square sq2(-1,-1,60,2);
    
	Object_2D* obj[] = {&cir1, &cir2, &sq1, &sq2};

    cout << "Initial data for the first circle: " << endl;
    cir1.Show();
    
    cir1.Move(5, 0); //передвигаю на вектор длины 4, угол которого 60
    cout << "Data after movement: " << endl;
    cir1.Show();
    
    cir1.Rotate(45);
    cout << "Data after rotation: " << endl;
    cir1.Show();
    
    cir1.Scale(2.0);
    cout << "Data after rescaling: " << endl;
    cir1.Show();
    
    cout << endl;
 
    cout << "Initial data for the second circle: " << endl;
    cir2.Show();
    
    cir2.Move(sqrt(2), 45);
    cout << "Data after movement: " << endl;
    cir2.Show();
    
    cir2.Rotate(80);
    cout << "Data after rotation: " << endl;
    cir2.Show();
    
    cir2.Scale(0.5);
    cout << "Data after rescaling: " << endl;
    cir2.Show();
    
    cout << endl << endl;
    
    cout << "Initial data for the first square: " << endl;
    sq1.Show();
    
    sq1.Move(2*sqrt(2), 225);
    cout << "Data after movement: " << endl;
    sq1.Show();
    
    sq1.Rotate(45);
    cout << "Data after rotation: " << endl;
    sq1.Show();

    sq1.Scale(2.0);
    cout << "Data after rescaling: " << endl;
    sq1.Show();
    
    cout << endl;

    cout << "Initial data for the second square: " << endl;
    sq2.Show();
    
    sq2.Move(1, 45);
    cout << "Data after movement: " << endl;
    sq2.Show();
    
    sq2.Rotate(45);
    cout << "Data after rotation: " << endl;
    sq2.Show();

    sq2.Scale(2.0);
    cout << "Data after rescaling: " << endl;
    sq2.Show();
    
    system("pause");
    return 0;
}