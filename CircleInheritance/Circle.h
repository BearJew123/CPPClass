#include <iostream>

class Circle{
    
private:
    
    double radius;
    
public:
    
    //Sets the radius of the circle
    void SetRadius(double r);
    
    //returns the radius
    double GetRadius();
    
    //returns the calculated area of the circle
    //PI*radius^2
    double Area();
    
    //returns the calculated circumference
    //2 * Pi * radius
    double Circumference();
    
    void Print();
    
    Circle (double _radius = 0.0);
    
};
