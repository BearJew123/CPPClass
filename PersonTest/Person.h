
#include <iostream>
#include <string>

using namespace std;

class Person{
    
private:
    
    string firstName;
    string middleName;
    string lastName;
    
public:
    
    //Constructors
    //First name is always required
    
    //Only rewuires first name
    Person(string first, string middle = " ", string last = " ");
    
    //requires
    //Middle name will default to " "
    Person(string first, string last);

    
    //Print funcs
    void printName() const; //Print full name will print middle if it is not "" or " "
    void printFirstName() const;
    void printMiddleName() const;
    void printLastName() const;
    
    //Set funcs, sets their coresponding variables to the parameter
    void setFirstName(string name);
    void setMiddleName(string name);
    void setLastName(string name);
    
    //Get funcs, returns their coresponding variables
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;

    //Test functions, tests whether given parameter is the same as the variable indicated
    bool FirstNameEqual(string name) const;
    bool LastNameEqual(string name) const;
    
};
