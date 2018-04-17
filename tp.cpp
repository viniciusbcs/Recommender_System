#include <iostream>
#include <string.h>
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
#include <iterator>
#include <cmath>
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
  
  //vector
  long int aux1 = 0;
  long int aux2 = 0;
  long int aux3 = 0;
  long int aux4 = 0;
  long int aux5 = 0;

  //target.csvs
  vector <string> uservec2(userlist2.size());
  vector <string> productvec2(productlist2.size());
  
  //ratings.csv
  vector <string> uservector(userlist.size());
  vector <string> productvec(productlist.size());
  vector <int> ratevec(ratelist.size());

  //targets file in a vector (uservec2)
  while(!userlist2.empty()){
    uservec2[aux1] =  userlist2.front();
    userlist2.pop_front();
    aux1 += 1;
  } 
    
  userlist2.clear();

  //targets file in a vector (productvec2)
  while(!productlist2.empty()){
    productvec2[aux2] = productlist2.front();
    productlist2.pop_front();
    aux2 += 1;
  } //up to here is ok! No seg fault!
  
  productlist2.clear();

  //ratings file in a vector (uservec)
  while(!userlist.empty()){
    uservector[aux3] =  userlist.front();
    userlist.pop_front();
    aux3 += 1;
  }

  userlist.clear();
  
  //ratings file in a vector (productlist)
  while(!productlist.empty()){
    productvec[aux4] = productlist.front();
    productlist.pop_front();
    aux4 += 1;
  }

  productlist.clear();
  
  //ratings file in a vector (rates)
  while(!ratelist.empty()){
    ratevec[aux5] = stoi(ratelist.front());
    ratelist.pop_front();
    aux5 += 1;
  }
  
  ratelist.clear();

  //Close files
  in.close();
  in2.close();
  cout << aux5;

  //Open writing file;
  ofstream myfile;
  myfile.open ("submission.csv");
  myfile << "UserId:ItemId,Prediction\n";

  int result1;
  int result2;
  int final;
  //Select the target
  for(long int loop = 0; loop < aux1; loop++){
    //myfile << uservec2[loop]<< ":" << productvec2[loop] << ",\n";
    if(uservec2[loop] != uservector[loop]){
      for(long int loop2 = 0; loop2 < 1528; loop2++){
        if(productvec2[loop] == productvec[loop2]){
        //myfile << uservec2[loop]<< ":" << productvec2[loop] << ",\n";
        }
        
         result1 =ratevec[loop2] + ratevec[loop];
         result2 = sqrt(pow(ratevec[loop2],2))+sqrt(pow(ratevec[loop],2));       
         
      }
    }
    final = (result1/result2)*6;
    myfile << uservec2[loop]<< ":" << productvec2[loop] << "," << final << "\n";
  }
  
  myfile.close();
  return 0;
}
