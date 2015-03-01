

#ifndef FUNCTIONS_H 
#define FUNCTIONS_H
#include <string>
#include <vector>
#include "student.h"

using namespace std;
namespace MSHIMA001{
   void clear(void);
   bool printrecord(vector<student> records, string number);
   bool printmean(vector<student> records,string id);
   void printmenu();
   void printdatabase();
   void savedatabase();
}

#endif


