#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


using namespace std;

int main(){

	FILE *fp;
	ofstream key,operators,identifiers,numbers;
	identifiers.open("iden");
	numbers.open("numbers");
	operators.open("operators");
	key.open("keywords");
	fp=fopen("hello.cpp","r");
	char c=getc(fp);
	char buffer[100];
	char keywords[][11]={{"int"},{"double"},{"float"},{"namespace"},{"#include"},{"char"},{"while"},{"for"},{"if"},{"else"},{"return"}};

	int noi=0;

	int i=0;
	while(c != EOF){

		if(isdigit(c)){
			numbers<<c<<endl;
			cout<<c<<endl;
			c=getc(fp);
			continue;
		}

		if(c==' '||c==','||c==';'||c=='\n'||c=='\t'){
			buffer[i]='\0';
			puts(buffer);
			int flag=0;
			for(int i=0;i<11;i++){
				if(strcmp(buffer,keywords[i]) == 0){
					key<<buffer<<endl;
					flag =1;
					
				}
			}


			

			if(flag == 0){
				if(strcmp(buffer,"") != 0){		
					identifiers<<buffer<<"<ID,"<<noi++<<">"<<endl;
				}
			}
			
			memset(buffer,'\0',i+1);
			i=0;

			c=getc(fp);
			continue;

		}
		else if((int)c >= 37 && (int)c <= 47 || ((int)c >= 58 && (int)c <= 63 ) || ((int)c >= 123 && (int)c <= 125 )  ){
			operators<<c<<endl;
			puts(buffer);
			memset(buffer,'\0',i+1);
			i=0;

			c=getc(fp);
			continue;
		}
		buffer[i]=c;
		c=getc(fp);
		i++;
	}

}