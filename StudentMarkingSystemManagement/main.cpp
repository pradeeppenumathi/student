#include "Student.h"

#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;

int main(){
    //variable initialization
    string each_line,each_value="";
    bool vlaueChecker=true;
    int no_of_students=0;
    struct Student student;
    struct Student *student_list;

    //initialization of files
    ifstream fileData(input_file_name);
    ofstream writeData(output_file_name);

    if(!fileData) { 
      cerr << "Error while oprning the file" << endl;
      exit(1);
   }
   
   //Dynamic memory allocation for output student type array
    unsigned int no_of_lines = getNumberofLinesinFile(input_file_name);
    student_list = new (nothrow) Student[no_of_lines];

   try {
    
    //Read each stuent record
    while(getline(fileData,each_value)) {
        stringstream each_line(each_value);
        vlaueChecker = true;
        student = {};
        while(getline(each_line, each_value, ' ')){
            //To read all the  which include first last middel name ...
          if(checkForName(each_value) && vlaueChecker){
            student.name = student.name + " "+ each_value;
          }else if(vlaueChecker) { 
            //Dynamic memory allcaotion for marks
            student.marks = new int[stoi(each_value)];
            vlaueChecker=false;
          }else {
            //Storing all marks for each student
            student.marks[student.total_no_of_marks ] = stoi(each_value);
            student.total_no_of_marks ++;
         }
        }
    // Find the averge of the marks
    student.average= averageOfMarks(student.marks,student.total_no_of_marks);
    //Find the grade for each each student based on the average
    student.grade = gradeCalculator(student.average);
    student_list[no_of_students] = student;
    no_of_students++;
   }

   for(int i=0;i<no_of_lines;i++){
    student = student_list[i];
    if( !writeData ) { // file couldn't be opened
      writeData << "Error while oprning the file" << endl;
      exit(1);
    }

    //Print output to the consocle 
    cout << left << setfill(' ') << setw(30) << student.name 
    << left << setfill(' ') << setw(30) << student.average 
    << left << setfill(' ') << setw(30) << student.grade  << endl;

    //write the values to the output file
    writeData << " " << student.name  << " "<<  student.total_no_of_marks;
    for(int i=0;i<student.total_no_of_marks ;i++){
    writeData << " "<< student.marks[i]  ;
    }
    writeData << " "<< student.average << " " << student.grade << endl;
   }


  } catch(exception& e) {
      cerr << "MyException caught" << endl;
      cerr << e.what() << endl;
   }


   delete [] student_list;  
   student_list = NULL;     


   //close all the opned file
   fileData.close();
   writeData.close();
   return 0;
} 