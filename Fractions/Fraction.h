//
//  Fraction.h
//  Fractions
//
//  Created by Jacob on 7/27/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#ifndef __Fractions__Fraction__
#define __Fractions__Fraction__

#include <iostream>

using namespace std;

class Fraction{
    
private:
    
    //Numerator
    int num;
    
    //Denominator
    int den;
    
    //returns the Greatest Common Facor of the fraction
    //would be preferred to be placed as a utility method in a static enviroment
    int GCF(int a, int b);
    
    Fraction ();
    
public:
    
    Fraction (int num, int den);
    
    void Simplify();
    
    void SetNum(int _num);
    
    void SetDen(int _den);
    
    //returns the value of the fraction
    double Value() const;
    
    //returns blank fraction type using default constructor
    static Fraction GetBlank();
    
    //Member operators
    
    void operator= (const Fraction& ref);
    
    Fraction operator+ (const Fraction& adder) const;
    Fraction operator+ (const int& adder) const;
    
    Fraction operator- (const Fraction& subAdder) const;
    Fraction operator- (const int& subAdder) const;
    
    Fraction operator* (const Fraction& multi) const;
    Fraction operator* (const int& multi) const;
    
    Fraction operator/ (const Fraction& divi) const;
    Fraction operator/ (const int& divi) const;
    
    //Inverse of Fraction
    Fraction operator! () const;
    
    bool operator== (const Fraction& test) const;
    
    bool operator!= (const Fraction& test) const;
    
    bool operator < (const Fraction& test) const;
    
    // !(this > test)
    bool operator <= (const Fraction& test) const;
    
    
    bool operator > (const Fraction& test) const;
    
    // !(this < test)
    bool operator >= (const Fraction& test) const;
    
    //Friend operators
    friend ostream& operator<< (ostream& os, const Fraction& target);
    
    friend istream& operator>> (istream& is, Fraction& target);
    
};

#endif /* defined(__Fractions__Fraction__) */
