
#include <iostream>

using namespace std;

struct student{
    
    string firstName;
    string lastName;
    
    double score;
    char letterGrade;
    
};

student ParseStudent();

void Sort(student students[], int size);
void PrintStudentList(student students[], int size);

const int STUDENT_COUNT = 20;

student students[STUDENT_COUNT];

int main(int argc, const char * argv[])
{

    cout << "Please enter " << STUDENT_COUNT
    << " students in this format:\nFirstName LastName Score(Can be decimal)\nand press enter before inputing next student. Please note that spaces are important."
    << endl;
    
    for(int i =0; i < STUDENT_COUNT; i++){
        
        students[i] = ParseStudent();
        
    }
    
    Sort(students, STUDENT_COUNT);
    PrintStudentList(students, STUDENT_COUNT);
   
    return 0;
}

student ParseStudent(){
    
    student value;
    
    cin >> value.firstName >> value.lastName >> value.score;
    
    //Error checking
    while(value.score > 100 || value.score < 0){
        cout << "Invalid Score please reinput score:" << endl;
        cin >> value.score;
    }
    
    //Letter grade
    if(value.score >= 90.0)
        value.letterGrade = 'A';
    
    else if(value.score >= 80.0)
        value.letterGrade = 'B';
    
    else if(value.score >= 70.0)
        value.letterGrade = 'C';
    
    else if(value.score >= 60.0)
        value.letterGrade = 'D';
    
    else
        value.letterGrade = 'F';
    
    return value;
    
}

void Sort(student students[], int size){
    
    for(int i = 0; i < size; i++){
        
        int highestIndex = i;
        
        for(int c = i; c < size; c++){
            
            if(students[highestIndex].score < students[c].score){
                
                highestIndex = c;
                
            }
        }
        
        student temp = students[i];
        students[i] = students[highestIndex];
        students[highestIndex] = temp;
        
    }
}

void PrintStudentList(student students[], int size){
    
    cout << "\nStudent Name :: Score :: Letter Grade" << endl;
    
    for(int i = 0; i < size; i++){
     
        cout << students[i].lastName << ", " << students[i].firstName
        << " :: " << students[i].score << "%" << " :: " << students[i].letterGrade << endl;
        
    }
    
    cout << "\nStudent with highest score is "
    << students[0].firstName << " " << students[0].lastName
    << " with a " << students[0].score << "%" << endl;
    
}
