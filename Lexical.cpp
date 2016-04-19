#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <fstream>
using namespace std;

int main(){
  FILE* fp = fopen("test.c","r");
  char c;

  char keywords[][10] = {"main", "int", "char","if","for","while"};
  int nop = 12;
  char operators[] = {'+', '-', '*', '>', '<', '/', ';', '{','}','(',')', '='};
  int line = 1;
  int nok = 6;

  ofstream ident, func, array, keyword, lexemes;
  ident.open("identifiers.txt");
  func.open("function.txt");
  array.open("array.txt");
  lexemes.open("lexemes.txt");
  int noi = 0;



  while((c=getc(fp)) != EOF){
    if(c == '\n'){
      line++;
      lexemes<<endl;
      lexemes<<line<<" ";
    }

    else if(isalpha(c)){
      char s[100];
      int t = 0;
      do{
        s[t++] = c;
        c=getc(fp);
      }
      while (isalnum(c));
      s[t] = '\0';

      fseek(fp, -1, SEEK_CUR);
      int isKey = 0;
      for(int i = 0; i < nok; i++){
        if(strcmp(s, keywords[i]) == 0){
          isKey = 1;
          cout<<"keyword "<<s<<endl;
          break;
        }
      }
      int funcFlag = 0, arrayFlag = 0;

      if(!isKey){
        ident<<"<"<<s<<">";
        cout<<"<"<<s<<">"<<endl;
        lexemes<<"<id"<<">";
      }
      else{
        lexemes<<"<"<<s<<">";
      }

  }
  else{
    int isOper = 0;
    for(int i = 0; i < nop; i++){
      if(c == operators[i]){
        isOper = 1;
      }
    }
    if(isOper){
      lexemes<<"<"<<c<<">";
    }
  }
  }
}
