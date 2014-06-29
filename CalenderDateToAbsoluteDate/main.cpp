//
//  main.cpp
//  CalenderDateToAbsoluteDate
//
//  Created by Jacob on 6/29/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#include <iostream>

using namespace std;

bool Even(int num);
bool Divisible(int number, int divisor);
int DaysInMonth(int month);
int GregorianToJulian(int month, int day);

bool leapYear;

int main(){
    
    int month;
    int day;
    int year;
    

    cout << "Please enter the date (MM DD YYYY):" << endl;
    cin >> month >> day >> year;
    
    //Checks for leap year
    if(Divisible(year, 4) && !Divisible(year, 100)){
        leapYear = true;
    }else if(Divisible(year, 100) && Divisible(year, 400)){
        leapYear = true;
    }else{
        leapYear = false;
    }
    
    if(DaysInMonth(month) < day){
        cout << "INVALID Date please enter again" << endl;
        main();
    }
    
    cout << "Absolute day of the year is: " << GregorianToJulian(month, day) << endl;
    
    return 0;
}

//Converts the gregorian date to the 'absolute' date
int GregorianToJulian(int month, int day){
    
    int total = 0;
    
    //will iterate until month-1
    for(int i=1; i < month; i++){
        total += DaysInMonth(i);
    }
    
    total += day;
    return total;
}

//Tells the total number of days in the month
int DaysInMonth(int month){
    
    if(month > 12){
        //FAIL
        return 32;
    }
    
    if(month <= 7 && month != 2){
        //Odd 31 even 30
        
        if(Even(month))
            return 30;
        else
            return 31;
        
    }else if(month > 7){
        //Odd 30 even 31
        if(Even(month))
            return 31;
        else
            return 30;
        
    }else{
        //Month is 2
        if(leapYear){
            return 29;
        }else {
            return 28;
        }
    }
}

//checks if a number is divisible by the divisor
bool Divisible(int number, int divisor){
    
    if(number%divisor == 0){
        return true;
    }else{
        return false;
    }
}

// checks if number is even
bool Even(int num){
    
    if(num % 2 == 0){
        return true;
    }else{
        return false;
    }
}