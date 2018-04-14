#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

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

  ch = getc(fp);
  ch2 = getc(fp2);
  
  while (ch!=EOF) {
    putchar(ch);
    ch = getc(fp);
  }

  while (ch2!=EOF) {
    putchar(ch2);
    ch2 = getc(fp2);
  }
    
  fclose(fp2);
  fclose(fp);
  return 0;
}
