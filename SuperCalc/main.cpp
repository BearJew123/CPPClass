
/*
 
 fraction calculator
 
 calculates and outputs fraction or integer values 
 
 back and quit funcionallity disabled due to major bugs
 
 */

#include <iostream>
#include <string>

using namespace std;

struct fraction{
    
    int num;
    int den;
    
};

void DoMenu();

fraction ParseFraction();

fraction AddFractions(fraction f1, fraction f2);
fraction SubFractions(fraction f1, fraction f2);
fraction MultFractions(fraction f1, fraction f2);
fraction DivFractions(fraction f1, fraction f2);

void Simplify(fraction& f1);

int GCF(int a, int b);
bool IsPrime(int number);

bool ProcessInput();

bool isRunning = true;
enum { ADD, SUB, MULT, DIV } mode;

string title = "Super Calculator";
string author = "Jacob Loss";

int menuState = 0;

int main(){
    
    while (isRunning){
        
        DoMenu();
        
    }
    
    return 0;
    
}

//Menu Stuff
//Ask for Operation type and input values
//output results
void DoMenu(){
    
    fraction f1;
    fraction f2;
    
    switch(menuState){
            
        //Intro
        case 0:
            cout << title << endl;
            
            
            for(int i = 0; i < title.length() ; i++)
                cout << '=';
            
            cout << "\n\nDeveloped by " + author + "\n\n";
            
            cout << "This program will ask you to input both an operation and two integer or fraction numbers\nand will calculate the result printing it as either a fraction or integer accordingly." << endl << endl;
            
            menuState++;
            break;
        
        //Operator control
        case 1:
            cout << "Please enter desired Operation:\nAddition (A or a or +) :: Subtraction (S or s or -) :: Multiplication (M or m or *) :: Division  (D or d or /)\n\n";
            
            if(ProcessInput()){
                
                char control;
                
                cin >> control;
                
                switch(control){
                        
                    case 'A':
                    case 'a':
                    case '+':
                        mode = ADD;
                        break;
                    
                    case 'S':
                    case 's':
                    case '-':
                        mode = SUB;
                        break;
                        
                    case 'M':
                    case 'm':
                    case '*':
                        mode = MULT;
                        break;
                        
                    case 'D':
                    case 'd':
                    case '/':
                        mode = DIV;
                        break;
                        
                    default:
                        cout << "Invalid Input please try again." << endl;
                        menuState--;
                        break;
                }
            }else{
                    break;
            }
            menuState++;
                break;
            
        //Fractions
        case 2:
            
            cout << "\nPlease input two numbers as either integers or fractions with a space between them Eg. 2/3 3/4 or 2 4" << endl;
            
            f1 = ParseFraction();
            f2 = ParseFraction();
            
            menuState++;
            
        case 3:
            
            fraction resultFrac;
            
            switch(mode){
                    
                case ADD:
                    resultFrac = AddFractions(f1, f2);
                    break;
                    
                case SUB:
                    resultFrac = SubFractions(f1, f2);
                    break;
                    
                case MULT:
                    resultFrac = MultFractions(f1, f2);
                    break;
                    
                case DIV:
                    resultFrac = DivFractions(f1, f2);
                    break;
            }
            
            Simplify(resultFrac);
            
            cout << "\nResults: "<< resultFrac.num;
            
            if(resultFrac.den != 1)
                cout << '/' <<resultFrac.den << endl;
            
            cout << "\nWould you like to do another calculation? (y or n)" << endl;
            
            char control;
            
            cin >> control;
            
            if(control == 'y')
                menuState = 1;
            else
                isRunning = false;
            
    }
}

void Simplify(fraction& frac){
    
   // if( IsPrime(frac.num) || IsPrime(frac.den))
    //  return;
       
    int Factor = GCF(frac.num, frac.den);
    
    frac.num /= Factor;
    frac.den /= Factor;
    
}

//Primes test
bool IsPrime(int number){
    
    if(number < 2)
        return false;
    
    if(number == 2)
        return true;
    
    if(number % 2 == 0)
        return false;
    
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    
    return true;
    
}

int GCF(int a, int b){
    
    if( b == 0)
        return a;
    else
        return GCF(b, a % b);
    
}

fraction AddFractions(fraction f1, fraction f2){
    
    fraction result;
    
    f1.num *= f2.den;
    f2.num *= f1.den;
    
    //Common Denominator
    f1.den *= f2.den;
    
    cout << f1.num << " " << f2.num << endl;
    
    result.num = f1.num + f2.num;
    result.den = f1.den;
    
    return result;
}

fraction SubFractions(fraction f1, fraction f2){
    
    fraction result;
    
    f1.num *= f2.den;
    f2.num *= f1.den;

    //Common Denominator
    f1.den *= f2.den;
    
    result.num = f1.num - f2.num;
    result.den = f1.den;
    
    return result;
}

fraction MultFractions(fraction f1, fraction f2){
    
    fraction result;
    
    result.num = f1.num * f2.num;
    result.den = f1.den * f2.den;
    
    return result;
    
}

fraction DivFractions(fraction f1, fraction f2){
    
    int num = f2.num;
    f2.num = f2.den;
    f2.den = num;
    
    return MultFractions(f1, f2);
    
}

//Parses a fraction using cin
fraction ParseFraction(){
    
    fraction result;
    cin >> result.num;
    
    if(cin.peek() == '/'){
        cin.ignore();
        cin >> result.den;
        if( result.den == 0)
            result.den = 1;
    }else if(cin.peek() == '.'){
        cout << "ERROR: Only integers are allowed\nPlease try again" << endl;
        ParseFraction();
    }else
        result.den = 1;
    
    return result;
}

//Will either quit, go back or allow to continue
//quiting sets running to false
//back decrements state and returns false(to continue)
//other will return true for further processing
//Not using due to bugs
bool ProcessInput(){
    
    //Disabling function
    return true;
    
    char control = cin.peek();
    
    switch(control){
        
        //Quit
        case 'Q':
        case 'q':
            isRunning = false;
            return false;
        
        //Back
        case 'B':
        case 'b':
            cout << "back detected" << endl;
            menuState--;
            //cin.ignore();
            return false;
            
        //Continue
        default:
            return true;
            
    }
    
}
