

#include <iostream>
#include <string>

#include "Person.h"

using namespace std;

int main(int argc, const char * argv[]){
    
    string tempFirst;
    string tempLast;
    string tempMiddle;
    
    cout << "Please enter a persons first name:" << endl;
    
    cin >> tempFirst;
    
    cout << "Please enter a persons last name:" << endl;
    
    cin >> tempLast;
    
    cout << "Please enter a persons middle name\nIf this person does not have one type a \" instead:" << endl;
    
    cin >> tempMiddle;
    
    Person p1(tempFirst, tempMiddle, tempLast);
    
    cout << "You persons full name is: ";
    p1.printName();
    
    cout << "\nPlease type a first name to test against the person you already created (this is case sensitive):" << endl;
    
    string testVal;
    
    cin >> testVal;
    
    if(p1.FirstNameEqual(testVal))
        cout << "These two people have the same first name!" << endl;
    else
        cout << "These people do not have the same first name" << endl;
    
    
    return 0;
}

