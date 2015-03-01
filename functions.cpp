#include <cstdlib>
#include "functions.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "student.h"
//file containing declarations methods used in the driver file.

using namespace std;
vector<MSHIMA001::student> records;

void MSHIMA001::clear(void) { 
   system("clear"); 
}

void MSHIMA001::addstudent(MSHIMA001::student New){
   bool found = false;
   for(unsigned i = 0; i< records.size(); i++){
      if(New.studentnumber.compare(records[i].studentnumber)==0){
         records[i].name = New.name;
         records[i].surname = New.surname;
         records[i].classrecord = New.classrecord;
         found = true;
         break;
      }
   }
   if(!found){
      records.push_back(New);
   }
    
   cout<< "Added "<< New.name<< " !"<<endl;
   
}
//assumption made: we have few entries that a vector is enough to store them.
bool MSHIMA001::printrecord( string number){

   
   for(unsigned i=0;i < records.size(); i++){
      if(records[i].studentnumber==number){
         
         cout<<records[i].name << " with student number " << records[i].studentnumber << " has record " << records[i].classrecord<<endl;
         return true;
      }
      
   }
   return false;
}


bool MSHIMA001::printmean( string id){
  
   for(unsigned i=0;i< records.size(); i++){
      if(records[i].studentnumber.compare(id)==0){
         
         string record = records[i].classrecord;
            
         istringstream iss(record);
         string s;
         int sum=0, n=0;
         while ( getline( iss, s, ' ' ) ) {
            std::istringstream iss( s);
            int val;
            iss >> val;
            //int val = atoi(s);
            sum+=val;
            n++;
         
         }
         
            
         
         
            
         cout<<"Student "<< records[i].name<< " with student number " << id <<" has an average of " <<(double)sum/n<< endl; 
         return true;
      }
   }
		
   return false;
   
}
void MSHIMA001::printmenu(){
   cout<< "PrintMenu() called."<<endl;
   cout<<"1: Add student \n2. Read database\n3. Save database \n4. Display given student data\n5. Grade student.\n6. Clear terminal."<<endl;
  
		
		
}
	
	
void MSHIMA001::printdatabase(){
   cout<< "readdatabase() called"<<endl;
   string line;
   ifstream db ("database.txt");
   
   if (db.is_open())
   {   
      cout<<"Database contains entries for following students: "<<endl;
      cout<<"Name:               Surname:            StudentNumber: ClassRecord:"<<endl;
   
      
      while ( getline (db,line) )
      {
         istringstream iss(line);
      
      
         cout<<line<<endl;
      
      
      
      }
      db.close();
   }
   
   else cout << "Unable to open database"<<endl;
	
   
}

void MSHIMA001::savedatabase(){
   cout<<"savedatabase() called"<<endl;
   ofstream db("database.txt");
   //db.open("database.txt", std::ios_base::app);
   if (db.is_open())
   {
      string name, surname, classrecord, studentnumber, entry;
      for(unsigned i=0; i< records.size(); i++){
      
         name = records[i].name;
         surname = records[i].surname;
         classrecord = records[i].classrecord;
         studentnumber = records[i].studentnumber;
      
         name = name + string(20-name.size(),' ');// assuming the maximm length of a name is 20 characters., add extra spaces if necessary
         surname = surname + string(20-surname.size(),' ');
         classrecord = classrecord + string(16-classrecord.size(),' ');
         studentnumber = studentnumber + string(15-studentnumber.size(),' ');
        
         entry = name + surname+ studentnumber+ classrecord;
      
         db <<entry<<endl;
       
      
      }
      db.close();
     
   }
   else{ 
      }
}
