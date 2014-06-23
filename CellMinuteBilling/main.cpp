/*
 Program which takes user data:
   Account Number
   Account type(Regular and premium)
   Minutes used total
   Minutes used during day(6:00 AM to 6:00 PM)(premium only)
 and will calculate a bill for this user and output it along with
 account number
 Service type
 total minutes used
 time used at day and night for premium
 amount due
 */
 


#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//calculates regular service for given time in minutes
double calcRegular(double time);

//calculates premium service for given time in the day and night
double calcPremium(double dayTime, double nightTime);

int main(int argc, const char * argv[]){
    
    int accountNum;
    char serviceClass;
    string serviceName;
    
    double totalCost;
    
    cout << "Please type in you account number followed by your service class (r or R for regular, p or P for premium)" << endl;
    
    cin >> accountNum >> serviceClass;
    
    switch(serviceClass){
            
        case 'r':
        case 'R':
            
            double time;
            serviceName = "Regular";
            
            cout << "Please give the total time in minutes you were in a call" << endl;
            cin >> time;
            
            totalCost = calcRegular(time);
            break;
            
        case 'p':
        case 'P':
            
            double dayTime;
            double nightTime;
            serviceName = "Premium";
            
            cout << "Please give the total time in minutes you were in a phone call at day and then at night followed by a space (ex. 123 324)" << endl;
            cin >> dayTime >> nightTime;
            
            totalCost = calcPremium(dayTime, nightTime);
            break;
            
        default:
            cout << "ERROR: service class specified does not exist, restarting program" << endl;
            main(NULL, NULL);
    }
    
    cout << fixed << setprecision(2);
    
    cout << "\n\n\n" <<"Cost report for account #" << accountNum << endl
    << "Service class: " << serviceName << endl << "Total cost: "
    << totalCost << endl;
    
    return 0;
    
}

double calcRegular(double time){
    
    double result = 10.0;
    
    if(time > 50){
        result += (time - 50.0) * 0.2;
    }
    
    return result;
    
}

double calcPremium(double dayTime, double nightTime){
    
    double result = 25.0;
    
    if(dayTime > 75){
        result += (dayTime - 75.0) * 0.1;
    }
    
    if(nightTime > 100){
        result += (nightTime -100.0) * 0.05;
    }
    
    return result;
}


