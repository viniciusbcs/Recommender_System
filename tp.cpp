#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
//#define _GNU_SOURCE

using namespace std;

int main(int argc, char *argv[]) {
  FILE *fp;
  FILE *fp2;
  char ch, ch2;

  if(argc!=3) {
    cout << "Você esqueceu de digitar o nome do arquivo.\n";
    exit(1);
  }

  if((fp=fopen(argv[1], "r"))==NULL) {
    cout << "O arquivo não pode ser aberto.\n";
    exit(1);
  }
	
  if((fp2=fopen(argv[2],"r"))==NULL) {
    cout << "O arquivo não pode ser aberto.\n";
    exit(1);
  } 
  
  while(ch != EOF){
    if(ch == ','){
      cout << " ";
    }else {
    cout << ch;
    }
    ch = gets(fp);
  }
  cout << "\n";
  
  fclose(fp2);
  fclose(fp);
  return 0;
}
