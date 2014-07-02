
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//The Super overcomplicated build
enum Operation{
    
    ADD,
    SUB,
    MULT,
    DIV
    
};

enum Mode{
    
    DEC,
    FRA,
    SCI
    
};

//Drawing
void DrawMenu(); // Passes to ModeSelect
void ModeSelect(); // Passes to OperatorSelect
void OperatorSelect(); // Passes to OperatorSelect
void NumberInput(); // Passes to Ouput
void Output(string num1, string num2); // Prints final outputs determines whether to go back to ModeSelect or quit

//Math to convert strings
string Add(string x, string y);
string Sub(string x, string y);
string Mult(string x, string y);
string Div(string x, string y);

//Math to calculate decimals
double Add(double x, double y);
double Sub(double x, double y);
double Mult(double x, double y);
double Div(double x, double y);

//Math to calculate fractions and scientifics
double Add(double x1, double x2, double y1, double y2);
double Sub(double x1, double x2, double y1, double y2);
double Mult(double x1, double x2, double y1, double y2);
double Div(double x1, double x2, double y1, double y2);

//Parsers
void ParseString(string num, double& x1, double& x2);

//Utils
void PseudoClear();
int ProcessInput(char in);
double StringToNumber(const string&);

string title = "Super Calculator";

string intro = "Welcome! To get started please enter the symbol (within the parenthesis)\nfor you desired mode and press enter. You will then be asked to input the\ndesired command and press enter. Finally you will enter the two number/\noperands with a space or enter inbetween them. You may go back at anytime\nby inputing 'B' or 'b'. You may also quit at anytime by inputing 'Q' or 'q'.";
           
Mode currentMode;
Operation currentOperator;

int main1(int argc, const char * argv[])
{

    DrawMenu();
    
    cout << "\n\nThank you for using " + title + "!" << endl;
    
    return 0;
}

/* Menu Layout
 
 Super Calculator
 ================
 
 Welcome! To get started please enter the symbol (within the parenthesis)
 for you desired mode and press enter. You will then be asked to input the 
 desired command and press enter. Finally you will enter the two number
 operands with a space or enter inbetween them. You may go back at anytime
 by inputing 'B' or 'b'. You may also quit at anytime by inputing 'Q' or 'q'.
 
 Please select mode:
 
 Decimal (D or d) :: Fractions (F or f) :: Scientific (S or s)
 
 input
 
 Please select operation:
 
 Add (A or a or +) :: Subtract (S or s or -) :: Multiply (M or m or *) :: Divide (D or d or /)
 
 input
 
 Please input two numbers (can be decimals) with a space inbetween:
 
 eg. 23 34 OR 23/12 45/96 OR 2e23 4e-20
 
 intput
 
 output 
 
 Would you like to do another calculation? (y or n)
 
 input
 
 if n
 exit
 if y
 pseudoClear()
 
 'B' or 'b' to go Back. 'Q' or 'q' to quit
 
 goto mode
 */
void DrawMenu(){
    
    //Begin Title
    int titleLen = title.length();
    cout << title << endl;
    
    for(int i = 0; i < titleLen; i++)
        cout << '=';
    
    cout << "\n\n";
    //End title
    
    cout << intro << endl << endl;
    
    ModeSelect();
    
}

//Selects the mode to use
void ModeSelect(){
    
    cout << "Please select mode:\n\nDecimal (D or d) :: Fractions (F or f) :: Scientific (S or s)\n\n";
    
    char control;
    
    cin >> control;
    
    int c = ProcessInput(control);
    
    if(c == 1)
        ModeSelect(); //Special because there is no back sequence to ModeSelect
    else if(c == 0){
        switch (control) {
                
            case 'D':
            case 'd':
                ::currentMode = DEC;
                break;
                
            case 'F':
            case 'f':
                ::currentMode = FRA;
                break;
                
            case 'S':
            case 's':
                ::currentMode = SCI;
                break;
                
            default:
                ModeSelect();
        }
    }else
        return;
    
    cout << "\n\n";
    OperatorSelect();
    
}

//Select Operation
void OperatorSelect(){
    cout <<
    "Please select operation:\n\nAdd (A or a or +) :: Subtract (S or s or -) :: Multiply (M or m or *) :: Divide (D or d or /)\n\n";
    
    char control;
    
    cin >> control;
    
    int c = ProcessInput(control);
    
    if(c == 1)
        ModeSelect();
    else if(c == 0){
        switch (control) {
                
            case 'A':
            case 'a':
            case '+':
                ::currentOperator = ADD;
                break;
                
            case 'S':
            case 's':
            case '-':
                ::currentOperator = SUB;
                break;
                
            case 'M':
            case 'm':
            case '*':
                ::currentOperator = MULT;
                break;
                
            case 'D':
            case 'd':
            case '/':
                ::currentOperator = DIV;
                
            default:
                ModeSelect();
        }
    }else
        return;

    cout << "\n\n";
    NumberInput();
    
}

void NumberInput(){
    cout << "Please Enter the first number (can be decimal, fraction or scientific)\n\n";
    
    //Parsed later in math funcs
    string str1;
    string str2;
    
    char control;
    
    control = cin.peek();
    
    int c = ProcessInput(control);
    
    if(c == 1)
        OperatorSelect();
    else if(c == 0){
        
        cin >> str1;
        
    }else
        return;

    cout << "\n\nPlease Enter the second number (can be decimal, fraction or scientific)\n\n";
    
    control = cin.peek();
    
    c = ProcessInput(control);
    
    if(c == 1)
        OperatorSelect();
    else if(c == 0){
        
        cin >> str2;
        
    }else
        return;
    
    Output(str1, str2);
    
}

void Output(string num1, string num2){
    
    string output;
    
    switch(currentOperator){
            
        case ADD:
            output = Add(num1, num2);
            break;
            
        case SUB:
            output = Sub(num1, num2);
            break;
            
        case MULT:
            output = Mult(num1, num2);
            break;
            
        case DIV:
            output = Div(num1, num2);
            break;
            
        default:
            output = "0";
    }
    
    cout << "Result is " + output + "\n\n";
    
    cout << "Would you like to make another calculation? (y or n)" << endl;
    
    char control;
    
    cin >> control;
    
    if(control == 'y'){
        PseudoClear();
        ModeSelect();
    }else{
        return;
    }
}

void PseudoClear(){
    for(int i=1; i <= 50; i++)
        cout << '\n';
}

int ProcessInput(char in){
    
    switch(in){
     
        //Go Back one step
        case 'B':
        case 'b':
            return 1;
            
        //Quit program
        case 'Q':
        case 'q':
            return -1;
            
        //passes operation
        default:
            return 0;
    }
}

//Methods only responsible for parsing and formatting strings
string Add(string num1, string num2){
    
    double x1;
    double x2;
    
    ParseString(num1, x1, x2);
    
    double y1;
    double y2;
    
    ParseString(num2, y1, y2);
    
    double raw = Add(x1, x2, y1, y2);
    
    double res1;
    double res2;
    
    string result = "";
    
    switch (currentMode){
            
        case DEC:
            result += raw;
            break;
            
        case FRA:;
            
            
    }
    
    return 0;
    
}

void ParseString(const string num, double& x1, double& y1){
    
    string x = "";
    
    string y = "";
    
    bool divisorFound = false;
    
    for(int i=0; i < num.length(); i++){
        
        if(num.c_str()[i] == '/' || num.c_str()[i] == 'e'){
            divisorFound = true;
            continue;
        }
        
        if(divisorFound){
            y += num.c_str()[i];
        }else{
            x += num.c_str()[i];
        }
    }
    
    x1 = StringToNumber(x);
    y1 = StringToNumber(y);
    
}

//Taken from internet converts a string to a number
//I dont think there is protection so must make sure that string is a number
double StringToNumber ( const string &Text ){
    stringstream ss(Text);
	double result;
	return ss >> result ? result : 0;
}