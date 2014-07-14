
#include "Person.h"

//Constructors
Person::Person(string first, string middle, string last){
    
    firstName = first;
    middleName = middle;
    lastName = last;
    
}

Person::Person(string first, string last){
    
    firstName = first;
    lastName = last;
    
}

//print functions
void Person::printName() const{
    
    printFirstName();
    cout << " ";
    
    if(!(middleName.empty() || middleName == "\"")){
        printMiddleName();
        cout << " ";
    }
    
    printLastName();
    cout << endl;
    
}

void Person::printFirstName() const{
    
    cout << firstName;
    
}

void Person::printMiddleName() const{
    
    cout << middleName;
    
}

void Person::printLastName() const{
    
    cout << lastName;
    
}

//Setter Functions
void Person::setFirstName(string name){
    
    firstName = name;
    
}

void Person::setMiddleName(string name){
    
    middleName = name;
    
}

void Person::setLastName(string name){
    
    lastName = name;
    
}

//Getter Functions
string Person::getFirstName() const{
    
    return firstName;
    
}

string Person::getMiddleName() const{
    
    return middleName;
    
}

string Person::getLastName() const{
    
    return lastName;
    
}

//Testing functions
bool Person::FirstNameEqual(string name) const{
    
    return name == firstName;
    
}

bool Person::LastNameEqual(string name) const{
    
    return name == lastName;
    
}