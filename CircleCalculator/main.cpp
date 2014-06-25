/*
 * Program which calculates the 
 * Radius
 * Diameter
 * Circumference
 * Area
 * of a circle with a point on the circle and the circles center
 */

//Learned from internet to obtain PI
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double distance(double x1, double y1, double x2, double y2);

double radius(double centerX, double centerY, double pointX, double pointY);
double diameter(double centerX, double centerY, double pointX, double pointY);

double circumference(double radius);

double area(double radius);

int main(int argc, const char * argv[]){

    double centerX;
    double centerY;
    
    double pointX;
    double pointY;
    
    cout << "Please input the center position as such: \"X Y\"" << endl;
    cin >> centerX >> centerY;
    
    cout << "Please input a point on the circle as such: \"X Y\"" << endl;
    cin >> pointX >> pointY;
    
    cout << fixed << setprecision(4);
    
    cout << "Circle information:" << endl;
    cout << "Radius: " << radius(centerX, centerY, pointX, pointY) << endl;
    cout << "Diameter: " << diameter(centerX, centerY, pointX, pointY) << endl;
    cout << "Circumference: " << circumference(radius(centerX, centerY, pointX, pointY)) << endl;
    cout << "Area: " << area(radius(centerX, centerY, pointX, pointY)) << endl;
    
    
    return 0;
    
}

double distance(double x1, double y1, double x2, double y2){
    
    return sqrt(pow(x1-x2, 2) + pow(y1-y1, 2));
    
}

double radius(double centerX, double centerY, double pointX, double pointY){
    
    return distance(centerX, centerY, pointX, pointY);
    
}

double diameter(double centerX, double centerY, double pointX, double pointY){
    
    return 2*radius(centerX, centerY, pointX, pointY);
    
}

double circumference(double radius){
    
    //M_PI learned from internet
    return M_PI * 2 * radius;
    
}

double area(double radius){
    
    return M_PI * pow(radius, 2);
    
}
