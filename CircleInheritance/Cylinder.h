#include <iostream>

#include "Circle.h"

//Set to protected inheritance since area and circumference do not make sense
class Cylinder : public Circle{
    
private:
    
    double height;
    
public:
    
    void SetHeight(double h);
    
    double GetHeight();
    
    void Print();
    
    //returns the surface area of cylinder
    //Circumference * height
    double SurfArea();
    
    //returns the volume of cylinder
    //area * height
    double Volume();
    
    Cylinder (double radius, double height);
    
};
