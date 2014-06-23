//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double increaseRate(double current, double rate);

int main(){

    //Input stream for text.txt
    ifstream in;
    //output stream for output.out
    ofstream out;
    
    //Work around for mac due to the way xCode handles project building
    //Should be ignored for windows and linux
    string macWorkAroundPath = "../../../../../../../../Desktop/CLC_CPP/P.183_EX.6/P.183_EX.6/";
    
    //Output directory, needs a '/' at end, defaults to test.txt location
    string outputDest = macWorkAroundPath;
    
    //Opens both in and out files
    in.open(macWorkAroundPath + "test.txt");
    cout << in.is_open() << endl;
    out.open(outputDest + "output.out");
   
    //This would be way easier with a class
    
    //Worker 1
    string lastName1;
    string firstName1;
    
    //Current salary
    double current1 = 0.0;
    //Salary rate increase
    double rateIncrease1 = 0.0;
    //Updated salary
    double updated1 = 0.0;
    
    in >> lastName1 >> firstName1 >> current1 >> rateIncrease1;
    
    updated1 = increaseRate(current1, rateIncrease1);
    
    //Worker 2
    string lastName2;
    string firstName2;
    
    //Current salary
    double current2 = 0.0;
    //Salary rate increase
    double rate2 = 0.0;
    //Updated salary
    double updated2 = 0.0;
    
    in >> lastName2 >> firstName2 >> current2 >> rate2;

    updated2 = increaseRate(current2, rate2);
    
    //Worker 3
    string lastName3;
    string firstName3;
    
    //Current salary
    double current3 = 0.0;
    //Salary rate increase
    double rate3 = 0.0;
    //Updated salary
    double updated3 = 0.0;
    
    in >> lastName3 >> firstName3 >> current3 >> rate3;
    
    updated3 = increaseRate(current3, rate3);
    
    //Output formatting
    out << fixed << showpoint;
    out <<setprecision(2);
    
    out << "Employee List:" << endl;
    
    //Write
    out << firstName1 << ' ' << lastName1 << ' ' << updated1 << endl;
    out << firstName2 << ' ' << lastName2 << ' ' << updated2 << endl;
    out << firstName3 << ' ' << lastName3 << ' ' << updated3 << endl;
    
    //closes in and out files
    in.close();
    out.close();
    
    return 0;
    
}

//Increases the salary by rate%
double increaseRate(double current, double rate){
    
    double val;
    
    val = current * (1.0+(rate/100));
    
    return val;
    
}