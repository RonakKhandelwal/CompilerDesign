#include <bits/stdc++.h>
#include "lexical2.cpp"

using namespace std;

void start();
void expr1();
void expr2();
void condition();
int relop();
int term();

void start()
{
	if(strcmp(token.c_str(),"FOR") == 0){
		getToken();
		if(strcmp(token.c_str(),"(") == 0){
			getToken();
			expr1();
			if(strcmp(token.c_str(),";") == 0){
				getToken();
				condition();
				if(strcmp(token.c_str(),";") == 0){
					getToken();
					expr2();
					if(strcmp(token.c_str(),")") == 0){
						getToken();
						expr1();
					}
					else{
						cout<<"Error 1 \n";
						exit(1);
					}
				}
				else{
						cout<<"Error 2 \n";
						exit(1);
					}
			}
			else{
						cout<<"Error 3 \n";
						exit(1);
					}
		}
		else{
						cout<<"Error 4 \n";
						exit(1);
					}

	}
	else{
						cout<<"Error 5 \n";
						exit(1);
					}

}
void expr1()
{
	if(strcmp(token.c_str(),"id") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			getToken();
			if(strcmp(token.c_str(),"num") == 0){
				getToken();
			}
			else
			{
						cout<<"Error 11 \n";
						exit(1);
			}
		}
		else
		{
			cout<<"Error 12 \n";
			exit(1);
		}
	}
	else{		
			cout<<"Error 13 \n";
			exit(1);
		}
}

void condition()
{
	int ans=0,ans1=0;
	ans=term();
	if(ans==0)
	{
		cout<<"Error 21 \n";
			exit(1);
	}
	else
	{
		ans1=relop();
		if(ans1==0)
		{
			cout<<"Error 22 \n";
			exit(1);
		}
		else
		{	
			ans=term();
			if(ans==0)
			{
				cout<<"Error 23 \n";
				exit(1);
			}
		}
	}
}

int term()
{
	if((strcmp(token.c_str(),"id") == 0)||(strcmp(token.c_str(),"num") == 0)){
		getToken();
		return 1;
	}
	else
		return 0;
}
int relop(){
			
	if((strcmp(token.c_str(),">") == 0)||(strcmp(token.c_str(),"<") == 0)){
	getToken();
	return 1;
	}
	else
	return 0;
}

void expr2()
{
	if(strcmp(token.c_str(),"id") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			getToken();
			term();
			if(strcmp(token.c_str(),"+") == 0){
				getToken();
				term();
			}
			else
			{		
			cout<<"Error 31 \n";
			exit(1);
			}
		}
		else
		{		
			cout<<"Error 32 \n";
			exit(1);
		}
	}
	else
	{		
			cout<<"Error 33 \n";
			exit(1);
	}

}

int main(){
	tokenizer();
	getToken();
	start();
	cout<<"Parse complete"<<endl;
	return 0;

}