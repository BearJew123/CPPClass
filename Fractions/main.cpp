//
//  main.cpp
//  Fractions
//
//  Created by Jacob on 7/27/14.
//  Copyright (c) 2014 Ragnarok. All rights reserved.
//

#include <iostream>
#include "Fraction.h"

void TryAgain();

int main(int argc, const char * argv[]){
    
    cout << "Welcome to Fraction Calculator Example!\nTo get started simply type in a problem using Fractions!" << endl;
    
    Fraction f1 = Fraction::GetBlank();
    Fraction f2 = Fraction::GetBlank();
    
    char test;
    
    Fraction result = Fraction::GetBlank();
    
    cin >> f1 >> test >> f2;
    
    switch (test){
            
        case '+':
            result = f1+f2;
            break;
            
        case '-':
            result = f1-f2;
            break;
            
        case '*':
            result = f1*f2;
            break;
            
        case '/':
            result = f1/f2;
            break;
        
        default:
            cout << "Invalid Operation please try again!" << endl;
            main(NULL, NULL);
            
    }
    
    cout << "\nResult is " << result << endl;
    
    TryAgain();
    
    return 0;
}

void TryAgain(){
    
    cout << "Would you like to go again? (y or n)" << endl;
    
    char test;
    
    cin >> test;
    
    if(test == 'y'){
        
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        main(NULL, NULL);
        
    }
    
}

