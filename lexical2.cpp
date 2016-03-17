#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include <bits/stdc++.h>

using namespace std;

struct SymbolTable{

	int id, numargs, size, lineno;
	char lexname[50], type[10], scope[10], rettype[10];
	char **arglist;
};

string token;
fstream tokenList;



void tokenizer(){

	char lastKeyword[10];
	 

		SymbolTable st[100];
		for(int i = 0; i < 100; i++)
			st[i].id = -1;
		int line = 1, key_flag = 0, lid = 0;
		char keywords[][10] = {{"char"}, {"int"}, {"if"}, {"else"}, {"while"}, {"include"},{"main"},{"for"}}, c;
		FILE *frp = fopen("file.cpp", "r");
		FILE *fwp = fopen("lexemes.txt", "w");		
		while((c = getc(frp)) != EOF){
		
			if(c == '\n'){

				//putc(c, fwp);
				line++;
			} else if(isalpha(c)){

				char s[100];
				int i = 0;
				do{

					s[i++] = c;
					c = getc(frp);
				}while(isalnum(c));
				s[i] = '\0';
				fseek(frp, -1, SEEK_CUR);
				key_flag = 0;
				for(i = 0; i < 8; i++){

					if(!strcmp(s, keywords[i])){

						key_flag = 1;
						putc('<', fwp);
						fputs(s, fwp);
						putc('>', fwp);putc('\n', fwp);
						strcpy(lastKeyword, s);
					}
				}
				if(!key_flag){

					int isFuncFlag = 0, isArrFlag = 0;
					char sta[10];
					if(c == '['){
						
						fseek(frp, 1, SEEK_CUR);
						i = 0;
						c = getc(frp);
						do{

							sta[i++] = c;
							c = getc(frp);		
						}while(isdigit(c));
						sta[i] = '\0';
						fseek(frp, -strlen(sta)-2, SEEK_CUR);
						isArrFlag = 1;
					} else if(c == '(')
						isFuncFlag = 1;
					int no = 7;
					for(i = 0; i < strlen(s); i++)
						no = no*13 + s[i];
					no %= 100;
				
					if(st[no].id == -1){

						lid++;
						st[no].id = lid;
						strcpy(st[no].lexname, s);
						if(!isFuncFlag){
							strcpy(st[no].type, lastKeyword);
							strcpy(st[no].rettype, "null");
						}
						else{
							strcpy(st[no].type, "fn");
							strcpy(st[no].rettype, lastKeyword);
						}
						st[no].size = 0;
						if(isArrFlag)
							st[no].size = atoi(sta);
						int scope_flag = 0;
						for(int check = 0; check < 100; check++)
							if(!strcmp(st[check].lexname, "main")){
							
								strcpy(st[no].scope, "local");
								scope_flag = 1;
							}
						if(scope_flag == 0)
							strcpy(st[no].scope, "global");
						st[no].numargs = 0;
						st[no].lineno = line;
						st[no].arglist = new char *[10];
						
					}
					//printf("Is it secret? Is is safe : %d, %d\n", no, st[no].id);

					putc('<', fwp);
					fputs("id", fwp);
					//putc('0' + st[no].id, fwp);
					putc('>', fwp);putc('\n', fwp);
				}
			} else if(isdigit(c)){

				char s[100];
				int i = 0;
				do{

					s[i++] = c;
					c = getc(frp);
				}while(isdigit(c));
				s[i] = '\0';
				putc('<', fwp);
				fputs("num", fwp);//changedA
				putc('>', fwp);putc('\n', fwp);
				fseek(frp, -1, SEEK_CUR);
			} else if(c != ' ' && c != '\t'){

				
				if(c == '\'' || c == '\"'){
					
					c = getc(frp);				
					putc('<', fwp);
					while(c != '\'' && c != '\"'){

						putc(c, fwp);
						c = getc(frp);
					}
					putc('>', fwp);putc('\n', fwp);											
				} else if(c == '+'){

					c = getc(frp);
					if(c == '+'){

						putc('<', fwp);
						fputs("inc", fwp);
						putc('>', fwp);putc('\n', fwp);
					} else{
						fseek(frp, -2, SEEK_CUR);
						c = getc(frp);
						putc('<', fwp);
						putc(c, fwp);
						putc('>', fwp);putc('\n', fwp);
					}
				} else{

					putc('<', fwp);
					putc(c, fwp);
					putc('>', fwp);putc('\n', fwp);
				}
			}
		}
		
		/*cout<<"Line No\t\t"<<"Lexeme Name\t\t"<<"Type\t\t"<<"Scope\t\t"<<"Return Type\t\tSize";
		cout<<endl;
		for(int i = 0; i < 100; i++)
			if(st[i].id != -1)
				cout<<st[i].lineno<<"\t\t"<<st[i].lexname<<"\t\t\t"<<st[i].type<<"\t\t"<<st[i].scope<<"\t\t"<<st[i].rettype<<"\t\t\t"<<st[i].size<<endl;
*/
		fclose(fwp);
		fclose(frp);
	
	
	tokenList.open("lexemes.txt");
}


string getToken(){
	if(getline(tokenList,token)){
		const char* start=token.c_str();
		const char* end=start+token.size();
		token=string(start+1,end-1);
		cout<<token<<endl;

		return token;
	}
	else{
		cout<<"ERROR!!!! Token"<<endl;
		exit(1);
	}
}