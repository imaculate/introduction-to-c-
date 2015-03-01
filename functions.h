

#ifndef FUNCTIONS_H 
#define FUNCTIONS_H
#include <string>
#include <vector>
#include "student.h"

using namespace std;
namespace MSHIMA001{
   void addstudent(MSHIMA001::student New);
   void clear(void);
   bool printrecord( string number);
   bool printmean(string id);
   void printmenu();
   void printdatabase();
   void savedatabase();
}

#endif


