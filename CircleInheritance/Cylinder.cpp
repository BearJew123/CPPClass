//
//  Cylinder.cpp
//  CircleInheritance
//
//  Created by Jacob on 7/16/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#include "Cylinder.h"

using namespace std;

Cylinder::Cylinder(double _radius, double _height) : Circle(_radius){
    
    SetHeight(_height);
    
}

void Cylinder::SetHeight(double _height){
    
    if(_height >= 0)
        height = _height;
    else
        height = 0.0;
    
}

double Cylinder::GetHeight(){
    
    return height;
    
}

double Cylinder::SurfArea(){
    
    return Circumference() * height;
    
}

double Cylinder::Volume(){
    
    return Area() * height;
    
}

void Cylinder::Print(){
    
    Circle::Print();
    
    cout << "Height: " << height << endl;
    cout << "Surface Area: " << SurfArea() << endl;
    cout << "Volume: " << Volume() << endl;
    
}
