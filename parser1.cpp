#include <bits/stdc++.h>
#include "lexical2.cpp"

using namespace std;

void Program();
void declaration();
int dataType();
void identifier_list();
void statement_list();
int statement();
int assign_stat();
void expr();
void simple_expr();
void eprime();
void term();
void seprime();
int relop();
void factor();
void tprime();
int mulop();
int addop();
int decision_stat();
void dprime();
int looping_stat();






void Program(){
	if(strcmp(token.c_str(),"main") == 0){
		getToken();
		if(strcmp(token.c_str(),"(") == 0){
			getToken();
			if(strcmp(token.c_str(),")") == 0){
				getToken();
				if(strcmp(token.c_str(),"{") == 0){
					getToken();
					declaration();
					statement_list();
					if(strcmp(token.c_str(),"}") == 0){
						cout<<"Parse complete"<<endl;
						exit(0);
					}
					else{
						cout<<"Parse errorB"<<endl;
						exit(1);
					}
				}
				else{
					cout<<"Parse error"<<endl;
					exit(1);
				}
			}
			else{
					cout<<"Parse error"<<endl;
					exit(1);
				}
		}
		else{
					cout<<"Parse error"<<endl;
					exit(1);
				}

	}
	else{
					cout<<"Parse error"<<endl;
					exit(1);
				}

}

void declaration(){
	int ans=dataType();
	if(ans == 1){
		identifier_list();
		if(strcmp(token.c_str(),";") == 0){
			getToken();
			declaration();
		}
		else{
			cout<<"Parse error"<<endl;
			exit(1);
		}
	}
	else{
		return;
	}
		
}
int dataType(){
	if(strcmp(token.c_str(),"int") == 0 || strcmp(token.c_str(),"char") == 0){
		getToken();
		return 1;
	}
	else{
		return 0;
	}

}

void identifier_list(){
	if(strcmp(token.c_str(),"id") == 0){
		getToken();
		if(strcmp(token.c_str(),",") == 0){
			getToken();
			identifier_list();
		}
		else if (strcmp(token.c_str(),"[") == 0){
			getToken();
				if (strcmp(token.c_str(),"num") == 0){
					getToken();
					if (strcmp(token.c_str(),"]") == 0){
						getToken();
						if(strcmp(token.c_str(),",") == 0){
							getToken();
							identifier_list();
						}
						else
						{
							return;
						}

					}
				}
		}
		else{
			return;
		}
	}
	else{
		cout<<"Parse Error3"<<endl;
		exit(1);
	}
}
void statement_list(){
	int ans=statement();
	if(ans == 1){
		statement_list();
	}
	else{
		return;
	}
}

int statement(){
	int ans = assign_stat();
	if(ans == 0){
		if(strcmp(token.c_str(),"}") != 0)
			{
				ans=decision_stat();
				if(!ans){
					ans=looping_stat();
				}
				
			}
	}
	else{
		if(strcmp(token.c_str(),";") == 0){
				getToken();
				//cout<<"got this shiz"<<endl;
				return 1;
		}
		else{
			cout<<"Parse Errori"<<endl;
			exit(1);	
		}
	}
	
	return ans;
	
}

int decision_stat(){
	if(strcmp(token.c_str(),"if") == 0){
		//cout<<"got this if"<<endl;
		getToken();
		if(strcmp(token.c_str(),"(") == 0){
			//cout<<"got this ("<<endl;
			getToken();
			expr();
			if(strcmp(token.c_str(),")") == 0){
			//	cout<<"got this )"<<endl;
				getToken();
				if(strcmp(token.c_str(),"{") == 0){
					//cout<<"got this {"<<endl;
					getToken();
					statement_list();
					if(strcmp(token.c_str(),"}") == 0){
					//	cout<<"got this }"<<endl;
						getToken();
						dprime();
						return 1;
					}
					else{
						cout<<"Parse error decision_stat 5";
						exit(1);
					}
				}
				else{
						cout<<"Parse error decision_stat 4";
						exit(1);
					}
			}
			else{
						cout<<"Parse error decision_stat 3";
						exit(1);
					}
		}
		else{
						cout<<"Parse error decision_stat 2";
						exit(1);
					}
	
		}
	else{
		return 0;
	}

}




int looping_stat(){
	if(strcmp(token.c_str(),"while") == 0){
		getToken();
		if(strcmp(token.c_str(),"(") == 0){
			getToken();
			expr();
			if(strcmp(token.c_str(),")") == 0){
				getToken();
				if(strcmp(token.c_str(),"{") == 0){
					getToken();
					statement_list();
					if(strcmp(token.c_str(),"}") == 0){
						getToken();
						return 1;
					}
					else{
						cout<<"Error } expected"<<endl;
						exit(1);

					}


					
				}
				else{
						cout<<"Error { expected"<<endl;
						exit(1);

					}
			}
			else{
						cout<<"Error ) expected"<<endl;
						exit(1);

					}
		}
		else{
						cout<<"Error ( expected"<<endl;
						exit(1);

					}
	}
	
	else if(strcmp(token.c_str(),"for") == 0){
		getToken();
		if(strcmp(token.c_str(),"(") == 0){
			getToken();
			assign_stat();
			if(strcmp(token.c_str(),";") == 0){
				getToken();
				//cout<<"got this shiz"<<endl;
				
			
			expr();
			if(strcmp(token.c_str(),";") == 0){
				getToken();
				assign_stat();
				if(strcmp(token.c_str(),")") == 0){
					getToken();
					if(strcmp(token.c_str(),"{") == 0){
						getToken();
						statement_list();
						if(strcmp(token.c_str(),"}") == 0){
							getToken();
							return 1;
						}
						else{
							cout<<"some } expected"<<endl;
							exit(1);

					}

					}
					else{
						cout<<"some { expected"<<endl;
						exit(1);

					}

				}
				else{
						cout<<"some ) expected"<<endl;
						exit(1);

					}

				//cout<<"got this shiz"<<endl;
				
			}
			else{
				cout<<"Parse Error ;"<<endl;
				exit(1);	
			}
		}
			else{
				cout<<"Parse Error ;"<<endl;
				exit(1);	
			}

		}
		else{
						cout<<"some ( expected"<<endl;
						exit(1);

					}

	}
	else{
			cout<<"some loop expected"<<endl;
			exit(1);

		}
	


}

void dprime(){
	if(strcmp(token.c_str(),"else") == 0){
		getToken();
		if(strcmp(token.c_str(),"{") == 0){
			getToken();
			statement_list();
			if(strcmp(token.c_str(),"}") == 0){
				getToken();
			}
			else{
				cout<<"parse error dprime }";
				exit(1);
			}
		}
		else{
			cout<<"parse error dprime {";
			exit(1);
		}
	}
	else{
		return;
	}
}
int assign_stat(){
	if(strcmp(token.c_str(),"id") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			getToken();
			expr();
			
		}
		else{
			cout<<"Parse Error2 assign"<<endl;
			exit(1);
		}

	}
	else{
			return 0;
	}
}


void expr(){
	simple_expr();
	eprime();


}

void simple_expr(){
	term();
	seprime();

}
void eprime(){
	int ans= relop();
	if(ans == 1){
		simple_expr();		
	}
	else{
		return;
	}

}
void seprime(){
	int ans = addop();
	if(ans == 1){
		term();
		seprime();
	}
	else{
		return;
	}

}

int addop(){
	if( strcmp(token.c_str(),"+") == 0 || strcmp(token.c_str(),"-") == 0){
		getToken();
		return 1;
	}
	else
		return 0;
}

void term(){
	factor();
	tprime();

}

void factor(){
	if(strcmp(token.c_str(),"id") == 0 || strcmp(token.c_str(),"num") == 0){
		getToken();
	}
	else{
		cout<<"Parse error factor"<<endl;
		exit(1);
	}
}

void tprime(){
	int ans = mulop();
	if(ans == 1){
		factor();
		tprime();
	}
	else{
		return;
	}
}

int mulop(){
	if(strcmp(token.c_str(),"*") == 0 || strcmp(token.c_str(),"%") == 0 || strcmp(token.c_str(),"/") == 0){
		getToken();
		return 1;

	}
	else{
		return 0;
	}
}

int relop(){
	if(strcmp(token.c_str(),"=") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			return 1;
		}
		else{
			return 0;
		}

	}
	if(strcmp(token.c_str(),"!") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			return 1;
		}
		else{
			return 0;
		}
	}
	if(strcmp(token.c_str(),">") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			getToken();
			return 1;
		}
		else if(strcmp(token.c_str(),"id") == 0){
			return 1;
		}
		else if(strcmp(token.c_str(),"num") == 0){
			return 1;
		}
		else
			return 0;
	}

	if(strcmp(token.c_str(),"<") == 0){
		getToken();
		if(strcmp(token.c_str(),"=") == 0){
			getToken();
			return 1;
		}
		else if(strcmp(token.c_str(),"id") == 0){
			return 1;
		}
		else if(strcmp(token.c_str(),"num") == 0){
			return 1;
		}
		else
			return 0;
	}

	
}




int main(){
	tokenizer();
	getToken();
	Program();
	cout<<"Parse complete"<<endl;
	return 0;

}
