//
//  Fraction.cpp
//  Fractions
//
//  Created by Jacob on 7/27/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#include "Fraction.h"

//Default constructor
//only used internally
Fraction::Fraction(){
    
    num = 0;
    den = 1;
    
}

Fraction::Fraction( int _num, int _den){
    
    num = _num;
    den = _den != 0 ? _den : 1;
    
    Simplify();
    
}

//Private Methods

int Fraction::GCF(int a, int b){
    
    if( b == 0 ){
        return a;
    }else{
        return GCF(b, a % b);
    }
    
}

//Public Methods
void Fraction::Simplify(){
    
    int factor = GCF(num, den);
    
    num /= factor;
    den /= factor;
    
}

double Fraction::Value() const{
    
    return (double)num/(double)den;
    
}

void Fraction::SetNum(int _num) {
 
    num = _num;
    
    Simplify();
    
}

void Fraction::SetDen(int _den){
    
    den = _den;
    
    Simplify();
    
}

//Static function
Fraction Fraction::GetBlank(){
    
    return Fraction();
    
}

//Operators

void Fraction::operator= (const Fraction& ref){
    
    if(this != &ref){
        num = ref.num;
        den = ref.den;
        
        Simplify();
        
    }
    
}

Fraction Fraction::operator+ (const Fraction& adder) const{
    
    int common = den * adder.den;
    
    int num1 = num * adder.den;
    int num2 = adder.num * den;
    
    return Fraction(num1+num2, common);
    
}

Fraction Fraction::operator+ (const int &adder) const{
    
    return *this + Fraction(adder, 1);
    
}

Fraction Fraction::operator- (const Fraction &subAdder) const{
    
    return *this + (subAdder * -1);
    
}

Fraction Fraction::operator- (const int &subAdder) const{
    
    return *this + (Fraction(subAdder, 1) * -1);
    
}

Fraction Fraction::operator* (const Fraction &multi) const{
    
    int num = this->num * multi.num;
    int den = this->den * multi.den;
    
    return Fraction(num, den);
    
}

Fraction Fraction::operator* (const int &multi) const{
    
    return *this * Fraction(multi, 1);
    
}

Fraction Fraction::operator/ (const Fraction& divi) const{
    
    return *this * !divi;
    
}

Fraction Fraction::operator/ (const int &divi) const{
    
    return *this / Fraction(divi, 1);
    
}

//returns den/num
Fraction Fraction::operator! () const{
    
    return Fraction(den, num);
    
}

bool Fraction::operator== (const Fraction& test) const{
    
    return Value() == test.Value();
    
}

bool Fraction::operator!= (const Fraction& test) const{
    
    return !(*this == test);
    
}

bool Fraction::operator< (const Fraction& test) const{
    
    return Value() < test.Value();
    
}

bool Fraction::operator<= (const Fraction& test) const{
    
    return !(*this > test);
    
}

bool Fraction::operator> (const Fraction& test) const{
    
    return Value() > test.Value();
    
}

bool Fraction::operator>= (const Fraction& test) const{
    
    return !(*this < test);
    
}

//Friend Operators

ostream& operator<< (ostream& os, const Fraction& target){
    
    if(target.den == 1){
        os << target.num;
        return os;
    }
    
    os << target.num << '/' << target.den;
    
    return os;
    
}

istream& operator>> (istream& is, Fraction& target){
    
    int _num, _den;
    
    cin >> _num;
    target.num = _num;
    
    char test;
    
    cin >> test;
    
    if(!(test == '/')){
        
        _den = 1;
        
        
    }else{
        
        cin >> _den;
        
    }
    
    target.den = _den;
    
    target.Simplify();
    
    return is;
    
}