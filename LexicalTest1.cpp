#include <fstream>
#include <iostream>
#include <fcntl.h>
#include <string>


using namespace std;

string token;
fstream file;



void tokenizer(){
  FILE* fp = fopen("test1.c","r");
  char c;
  char keywords[][10] = {"a", "the", "boy", "dog", "sees", "pets", "$"};
  ofstream lexemes, lex;
  lex.open("lex.txt");
  lexemes.open("lexemes.txt");


  while((c = getc(fp)) != EOF){
    if(isalpha(c)){
      char str[100];
      int i=0;
      do{
        str[i++]=c;
        c=getc(fp);
      }while(isalpha(c) && c != EOF);
      str[i]='\0';
      fseek(fp, -1, SEEK_CUR);
      for(i = 0;i<7;i++){
        if(strcmp(str, keywords[i]) == 0){
          lexemes<<"<"<<str<<">";
          lex<<"<"<<str<<">"<<endl;
        }
      }
    }
    else if(c == '$'){
      lexemes<<"<"<<c<<">";
      lex<<"<"<<c<<">"<<endl;
    }
  }
  file.open("lex.txt");
}

void getToken(){
  if(getline(file, token)){
    const char *start = token.c_str();
    const char *end = start + token.size();
    token = string(start+1, end-1);
    cout<<token<<endl;
  }
  else{
    cout<<"Error parsing token"<<endl;
    exit(1);
  }
}
