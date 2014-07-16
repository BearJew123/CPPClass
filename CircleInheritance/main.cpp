//
//  main.cpp
//  CircleInheritance
//
//  Created by Jacob on 7/16/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#include <iostream>

#include "Cylinder.h"

using namespace std;

int main(int argc, const char * argv[])
{

    cout << "Please enter a radius and height for a cylinder with a space or enter inbetween: " << endl;
    
    double r;
    double h;
    
    cin >> r >> h;
    
    Cylinder cy(r, h);
    
    cout << endl;
    
    cy.Print();
    
    return 0;
}

