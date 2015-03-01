#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "student.h"
#include "functions.h"
#include "functions.cpp"

//driver file for the database application. It runs a loop until the user enters q


using namespace std;
using namespace MSHIMA001;
int main(void){
   string word;
   string number , id;
  //infinite loop.
   for(;;){
      printmenu();
      cout<<"Enter a number (or q to quit) and press return."<<endl;
      getline(cin, word);
      
      if(word!="q"){
         std::istringstream iss(word);
         int choice;
         iss >> choice;
         switch(choice){
            case 1  :
               {
                  string name, surname, studentnumber, classrecord;
               
               
                  cout<<"Enter students' first name:"<<endl;
                  getline(cin, name);
               
                  cout<<"Enter students' surname:"<<endl;
                  getline(cin, surname);
               
                  cout<<"Enter students' studentnumber:"<<endl;
                  getline(cin, studentnumber);
               
                  cout<<"Enter students classrecord:"<<endl;
                  getline(cin, classrecord);
               
                  student NewStudent;
                  
                  NewStudent.name = name;
                  NewStudent.surname = surname;
                  NewStudent.studentnumber = studentnumber;
                  NewStudent.classrecord = classrecord;
                 
               
                  addstudent(NewStudent);
               
               
               
               
                  break;
               }
            case 2:
               {
                  printdatabase();
               
                  break; 
               
               
               }
            case 3:
               {
                  savedatabase();
                  break;
               }
            
            case 4:
               {
                  
                  cout<<"Which student do you want to look up?"<<endl;
                  getline(cin, number);
                  
                  while(!printrecord(number)){
                  // if unknown id is entered keep asking until user quits.
                     cout<<"Student number not found, enter student number, enter x to quit"<<endl;
                     getline(cin, number);
                     if(number.compare("x")==0){
                        break;
                     }
                     
                  }
                  break;
               
               }
            case 5:
               {
                  
                  cout<<"Which student do you want to grade?"<<endl;
                  getline(cin, id);
                  while(!printmean(id)){
                     cout<<"Student number not found, enter student number, enter x to quit"<<endl;
                     getline(cin, id);
                     if(id.compare("x")==0){
                        break;
                     }
                     
                  
                  }
                  break;
               
               
               }
            case 6:
               {
                  clear();
                  break;
               
               }
            default:
               { 
               
                  cout<<"You have entered an invalid choice,Please try again"<<endl;
                  getline(cin,word );
                  
               }
         }
      
      }else{
         cout<<"Bye!"<<endl;
         break;
      
      }
   }
   return 0;
	
	
}


