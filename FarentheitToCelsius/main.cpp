//
//  main.cpp
//  FarentheitToCelsius
//
//  Jacob Loss
//
//  Converts an inputed temperature in farentheit to celsius
//

#include <iostream>

using namespace std;

int main(){
    
    double fahrenheit;
    double celsius;
    
    cout << "Input temperature in fahrenhiet here (Can be a decimal):" << endl;
    cin >> fahrenheit;
    
    celsius = (fahrenheit - 32) * 5.0/9.0;
    
    cout << "Temperature in celcius is " << celsius << endl;
    
    //System("pause");
    //Does not need to be used in xCode
    return 0;
}

