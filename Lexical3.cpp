#include <iostream>
#include <fstream>
#include <fcntl.h>

using namespace std;

int main(){

  FILE *fp;
  fp = fopen("hello.txt","r");
  char c;
  ofstream file;
  file.open("lex.txt");
  while((c = getc(fp)) != EOF){
    if (c == '\n') {
      file<<endl;
    }
    else if(isalpha(c)){
      char str[100];
      int i = 0;
      do{
        str[i++] = c;
        c = getc(fp);
      }while(isalnum(c) && c != EOF);
      str[i]='\0';
      fseek(fp, -1, SEEK_CUR);
      file<<"<"<<str<<">";
    }
    else if(c != ' '){
      file<<"<"<<c<<">";
    }
  }
}
