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
  
  //list structur for ratings.csve
  list<string> userlist;
  list<string> productlist;
  list<string> ratelist;
  list<string> timelist;

  //list structure for targets.csv
  list<string> userlist2;
  list<string> productlist2;

  //Opening ratings.csv and targets.csv
  char ch;
  if(argc!=3) {
    cout << "Usage: tp ratings.csv targets.csv\n";
    return 1;
  }

  ifstream in(argv[1]); // input 1
  ifstream in2(argv[2]); // input 2
  
  if(!in) {
    cout << "Cannot open ratings.csv.\n";
    return 1;
  }

  if(!in2) {
    cout << "Cannot open targets.csv.\n";
    return 1;
  }

  //ratings.csv read
  char user[255];
  char product[255];
  char rate[255];
  char time[255];

  //targets.csv read
  char user2[255];
  char product2[255];
  
  //Ignoring the fst line
  in.ignore(100, '\n');
  in2.ignore(100, '\n');

  //reading ratings.csv
  while(in) { 
    in.getline(user, 255, ':');  // delim defaults to '\n'    
    in.getline(product, 255, ',');
    in.getline(rate, 255, ',');
    in.getline(time, 255, '\n');
    userlist.push_back(user);
    productlist.push_back(product);
    ratelist.push_back(rate);
  }
  
  while(in2) {
    in2.getline(user2, 255, ':');
    in2.getline(product2, 255, '\n');
    userlist2.push_back(user2);
    productlist2.push_back(product2);
  }

  /* Out teste
  while(!userlist.empty()){
    cout << userlist.front();
    userlist.pop_front();
    cout << "\n";
  }
  
  while(!productlist2.empty()){
    cout << productlist2.front();
    productlist2.pop_front();
    cout << "\n";
  }
  */

  in.close();
  in2.close();
  return 0;
}
