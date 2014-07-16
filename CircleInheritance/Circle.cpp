#include <cmath>

#include "Circle.h"

using namespace std;

Circle::Circle(double _radius){
    
    SetRadius(_radius);
    
}

void Circle::SetRadius(double _radius){
    
    if(_radius >= 0)
        radius = _radius;
    else
        radius = 0.0;
    
}

double Circle::GetRadius(){
    
    return radius;
    
}

double Circle::Area(){

    return M_PI * pow(radius, 2.0);
    
}

double Circle::Circumference(){
    
    return 2 * M_PI * radius;
    
}

void Circle::Print(){
    
    cout << "Radius: " << radius << endl;
    cout << "Circumference: " << Circumference() << endl;
    cout << "Area: " << Area() << endl;
    
}