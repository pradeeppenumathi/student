#ifndef STUDENTDB_STUDENT_H
#define STUDENTDB_STUDENT_H


#include <string>
#include "Student.cpp"
#pragma once

//
//This mpodule is to provide utile operations 
//in doing student marks classifcation 
//
//


//Constants for input and output file name
string const  input_file_name = "StudentMarkDetails.txt";
string const  output_file_name = "StudentGradeDetails.txt";


// This is the data type of each student value
struct Student {
    string name;
    int total_no_of_marks;
    int* marks;
    float average;
    string grade;
};



//
//averageOfMarks
//
//Purpose: To find the average of each student’s marks
//Parameter(s) : 
// <1> marks : An array of marks of each student
// <2> noofValues : An unsigned integer value which has number of students.
//Precondition(s) :  no of values should not be zero
//Returns : Returns decimal value of avergae marks
//Side Effects: N/A
//
float averageOfMarks(const int *marks, unsigned int noofValues);



//
//gradeCalculator
//
//Purpose: To find the grade of each student.
//Parameter(s) : 
// <1> avergae : Decimal value of avergae marks
//Precondition(s) :  N/A
//Returns : String value of the student grade
//Side Effects: N/A
//
string gradeCalculator(float avergae);

//
//checkForName
//
//Purpose: To check weather the given string can be integer or not
//Parameter(s) : 
// <1> name : A string value which to check for it is  interger or not
//Precondition(s) : N/A
//Returns : Returns boolean value true if it is a string
//Side Effects:  N/A
//
bool checkForName(string name);

//
//getNumberofLinesinFile
//
//Purpose: To find the number of lines present in the given file
//Parameter(s) : 
// <1> filenmae : string value of file number
//Precondition(s) : File name should not be empty or null
//Returns : unsigned integer value of number of lines present in the file
//Side Effects:  N/A
//
unsigned int getNumberofLinesinFile(string filenmae);


#endif