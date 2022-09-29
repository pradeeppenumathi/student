/**
 * @file Student.cpp
 *
 *
 * @ingroup StudentMarkingSystemManagement
 *
 * @author Pradeep Penumarthi
 * Contact: pph759@uregina.ca
 *
 */

#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//
// This file provides the implementaion of basic util funcation for student operation
//

// Calculate the average vaue of student marks
float averageOfMarks(const int *marks, unsigned int noofValues)
{
     float average, sum = 0;
     for (int j = 0; j < noofValues; j++)
     {
          sum = marks[j] + sum;
     }
     average = sum / noofValues;
     return average;
}

// To clasify the student grades based on the marks average
string gradeCalculator(float avergae)
{
     if (avergae >= 95 && avergae <= 100)
          return "A";
     else if (avergae >= 91.67 && avergae < 95)
          return "A-";
     else if (avergae >= 88.3 && avergae < 91.67)
          return "B+";
     else if (avergae >= 85 && avergae < 88.3)
          return "B";
     else if (avergae >= 81.67 && avergae < 85)
          return "B-";
     else if (avergae >= 78.33 && avergae < 81.67)
          return "C";
     else if (avergae >= 75 && avergae < 78.33)
          return "C-";
     else if (avergae >= 71.67 && avergae < 75)
          return "C-";
     else if (avergae >= 68.33 && avergae < 71.67)
          return "D+";
     else if (avergae >= 65 && avergae < 68.33)
          return "D";
     else if (avergae >= 61.67 && avergae < 65)
          return "D-";
     else
          return "F";
}

// if the value can't be type cast to int then it is a string
bool checkForName(string name)
{
     try
     {
          stoi(name);
     }
     catch (exception &e)
     {
          return true;
     }
     return false;
}

// iterate  the file and count lines untill you reach end of the file
unsigned int getNumberofLinesinFile(string filenmae)
{
     unsigned int number_of_lines = 0;
     string line;
     fstream myfile(filenmae);
     while (getline(myfile, line))
          ++number_of_lines;
     myfile.close();
     return number_of_lines;
}
