#include <cstdlib>
#include "functions.h"
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "student.h"


using namespace std;
vector<MSHIMA001::student> records;

void MSHIMA001::clear(void) { 
   system("clear"); 
}

 void MSHIMA001::addstudent(MSHIMA001::student New){
   records.push_back(New); 
 }


bool MSHIMA001::printrecord( string number){
    bool found = false;
   
   for(unsigned i=0;i < records.size(); i++){
      if(records[i].studentnumber.compare(number)==0){
         found = true;
         cout<<records[i].name << " with student number " << records[i].studentnumber << "has record " << records[i].classrecord<<endl;
      }
   }
   return found;
}


bool MSHIMA001::printmean( string id){
   bool found = false;
   for(unsigned i=0;i< records.size(); i++){
      if(records[i].studentnumber==id){
         found = true;
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
         
      }
   }
		
   return found;
   
}
void MSHIMA001::printmenu(){
   cout<< "PrintMenu() called."<<endl;
   cout<<"1: Add student \n2. Read database\n3. Save database \n4. Display given student data\n5. Grade student.\n6. Clear terminal."<<endl;
  
		
		
}
	
	
void MSHIMA001::printdatabase(){

	cout<< "readdatabase() called"<<endl;
   
}

void MSHIMA001::savedatabase(){
   cout<<"savedatabase() called"<<endl;
}
