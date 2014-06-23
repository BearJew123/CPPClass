/*
 * A random number game based on the time as a seed
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

void Run(int maxNum, int maxAttempts);
void Test(int key, int value, int max);

int main(int argc, const char * argv[]){

    const int maxAttempts = 5;
    const int maxNumber = 100;
    bool running = true;
    
    //Seed taken from time
    srand(time(nullptr));
    
    //Running loop
    while(running){
        
        //Runs actual game
        Run(maxNumber, maxAttempts);
        
        //Asks if you would like to continue playing
        char val;
        cout << "Would you like to play again?(Y or N)" << endl;
        cin >> val;
        if(val != 'Y' && val !='y')
            running = false;
    }
    
}

//Runs single game with the given maxs
void Run(int maxNum, int maxAttempts){
    
  
    
    //Winning number
    int number = rand() % maxNum;
    
    //The guess
    int lastGuess = 0;
    //Attempts taken
    int attempts = 0;
    
    if(number == lastGuess)
        number += rand();

    cout << "Your number has been selected!\nYou will have " << maxAttempts << " attempts to find the right number\nGo" << endl;
    
       
    do{
        
        //Test numbers to get outputs will give a general placement of number initially
        if(attempts != 0)
            Test(number, lastGuess, maxNum);
        
        //Obtain and check guess
        cin >> lastGuess;
        if(lastGuess > maxNum || lastGuess < 0){
            cout << "Invalid Number value must be between 0 and " << maxNum << endl;
            attempts--;
        }
        
        attempts++;
        
    }while(lastGuess != number && attempts < maxAttempts);
    
    //Checks loss
    if(attempts >= maxAttempts){
        cout << "Sorry you exceeded your attempts. You Lose!" << endl;
        return;
    }
    
    //Win
    cout << "Congradulations! You won with " << attempts << " attempts" << endl;
    
}

//Tests if a number is greater than, slightly greater than, less than or slightly less than
//NOTE is not completely accurate to the books problem gives limits at 50, 33, and 16, this is due to how the limits are calculated
void Test(int key, int value, int max){
   
    int temp = abs(value - key);
    //Thresholds detemined by maximum
    int maxThres = max/2.0;
    int midThres = max/4.0;
    int lowThres = max/6.0;
    
    string prefix;
    string postfix;
    
    //Prefix handles(Magnitude)
    if(temp > maxThres)
        prefix = "Very";
    else if(temp > midThres && temp < maxThres)
        prefix = "";
    else if(temp > lowThres && temp < midThres)
        prefix = "Moderately";
    else
        prefix = "Somewhat";
    
    //Postfix handles
    if(value-key >= 0){
        postfix = "High";
    }else
        postfix = "Low";
    
    cout << "Number is " << prefix <<" "<< postfix << endl;
    
}
