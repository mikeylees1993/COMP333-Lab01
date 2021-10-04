#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
/*
Name: Lauren Smith 
COMP333 Lab Exercerise 1 
Learning about structs 
*/

// Structs Definition 
struct StudentRec
{
    string studentName;
    int assignmentTotal;
    int testTotal;
    char letterGrade;
};
//constants 
const int SIZE = 10;
//Prototypes 
int loadArray(StudentRec[]);
void showArray(const int&,const StudentRec[],ofstream&);
int main()
{
    StudentRec studentList[SIZE];
    int noStudents;
    ofstream outputFile("student.rpt");
    if(!outputFile.is_open())
    {
        cout<<"Report File is not opened";
        system("pause");
        exit(-1);
    }
    noStudents = loadArray(studentList);
    showArray(noStudents,studentList,outputFile);
    system("type student.data");
    system("type student.rpt");
    system("pause");
}
int loadArray(StudentRec studList[])
{
    int length =0;
    ifstream inputFile("student.data");
    if(!inputFile.is_open())
    {
        cout<<"Database file cannot be open ";
        system("pause");
        exit(-20);
    }
    for(;length<SIZE;length++)
    {
        getline(inputFile,studList[length].studentName);
        if(inputFile.eof())
            break;
        
        inputFile>>studList[length].assignmentTotal;
        inputFile>>studList[length].testTotal;
        inputFile>>studList[length].letterGrade;
        inputFile.ignore(80,'\n');
    }
    return length;
}
void showArray(const int &length,const StudentRec studlist[],ofstream &outputFile)
{
    outputFile<<left<<setw(20)<<"Student Name"
              <<right<<setw(20)<<"Assign Total"
              <<right<<setw(20)<<"Test Total"
              <<right<<setw(20)<<"Grade"<<endl;
    for(int count=0;count<length;count++)
    {
        outputFile<<left<<setw(20)<<studlist[count].studentName
              <<right<<setw(20)<<studlist[count].assignmentTotal
              <<right<<setw(20)<<studlist[count].testTotal
              <<right<<setw(20)<<studlist[count].letterGrade<<endl;   
    }
    outputFile<<endl;
    outputFile << "Number of Students: "<<length<<endl;
}