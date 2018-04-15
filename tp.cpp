#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <list>
using namespace std;

int main(int argc, char *argv[]) {
  
  //vector to put file content
  vector<char> v1;
  vector<int> v2;
  
  //counter
  int i = 0;
  int ii = 0;

  //Opening ratings.csv and targets.csv
  char ch;
  if(argc!=3) {
    cout << "Usage: tp ratings.csv targets.csv\n";
    return 1;
  }
  ifstream in(argv[1]); // input
  ifstream in2(argv[2]); // input 2
  if(!in) {
    cout << "Cannot open ratings.csv.\n";
    return 1;
  }

  if(!in2) {
    cout << "Cannot open targets.csv.\n";
    return 1;
  }

  char str[255];
  char str2[255];
  
  //Ignoring the fst line
  in.ignore(100, '\n');
  in2.ignore(20, '\n');

  //reading ratings.csv
  while(in) { 
    in.getline(str, 255);  // delim defaults to '\n'    
    if(in) cout << str << endl;
  }

  //reading targests.csv
  while(in2){
    in2.getline(str2, 255);
    
    //if(in2) cout << str2 << endl;
  }
  
  in.close();
  in2.close();
  return 0;
}
