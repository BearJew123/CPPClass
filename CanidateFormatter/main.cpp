
#include <iostream>

using namespace std;



//Canidate struct
struct Canidate{
    
    string firstName;
    string lastName;
    
    int votes;
    
    //pure percent value
    double lowPercent;
    
};

//Functions

Canidate ParseCanidate();
void CalculateAverages(Canidate cans[], int size);
void SortByVotes(Canidate cans[], int size);

//Vars
const int CANIDATE_NUM = 5;

Canidate canidates[CANIDATE_NUM];

int main(int argc, const char * argv[])
{

    cout << "Please enter each canidates first name, last name and the number of votes they received with a space inbetween each" << endl;
    
    for(int i = 0; i < CANIDATE_NUM; i++){
        
        canidates[i] = ParseCanidate();
        
    }
    
    SortByVotes(canidates, CANIDATE_NUM);
    CalculateAverages(canidates, CANIDATE_NUM);
    
    cout << "\nCanidates\tVotes\tVoter Percentiles\n\n";
    
    for(int i = 0; i < CANIDATE_NUM; i++){
        
        cout << canidates[i].lastName << ", " << canidates[i].firstName
        << "\t" << canidates[i].votes << "\t" << canidates[i].lowPercent * 100.0 << endl;
        
    }
    
    cout << "The Winner of the election is "
    << canidates[0].firstName << " " << canidates[0].lastName << endl;
    
    return 0;
}

//Parses a canidate in the order: first name, last name, vote number
Canidate ParseCanidate(){
    
    Canidate can;
    
    cin >> can.firstName >> can.lastName >> can.votes;
    
    return can;
    
}

//Calculates the percentiles of the votes received
void CalculateAverages(Canidate cans[], int size){
    
    int totalVotes = 0;
    
    for(int i = 0; i < size; i++){
        
        totalVotes += cans[i].votes;
        
    }
    
    for(int i = 0; i < size; i++){
        
        cans[i].lowPercent = cans[i].votes/(double)totalVotes;
        
    }
}

//Sorts Canidates by the number of votes they have
void SortByVotes(Canidate cans[], int size){
    
    for(int i = 0; i < size; i++){
        
        int highestIndex = i;
        
        for(int c = i; c < size; c++){
            
            if(cans[highestIndex].votes < cans[c].votes){
                
                highestIndex = c;
                
            }
        }
        
        Canidate temp = cans[i];
        cans[i] = cans[highestIndex];
        cans[highestIndex] = temp;
        
    }
}