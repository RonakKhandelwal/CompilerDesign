#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>


using namespace std;




void wtype(string l){
	const char *start=l.c_str();
	const char *end=start+l.size();
	int flag=0;
	while(start<end){
		if(*start == ' '||*start == ','){
			start++;
		}
		else{
			break;
		}
	}
	string temp=string(start,end);
	cout<<temp<<" ";
	
	//ty<<"-<"<<temp<<">-";
}

int main(){

	fstream fp;
	ofstream key,operators,identifiers,numbers,result,type;
	identifiers.open("iden");
	numbers.open("numbers");
	operators.open("operators");
	key.open("keywords");
	result.open("result");
	fp.open("hello.cpp");
	type.open("types");
	string line;
	char buffer[100];
	char keywords[][12]={{"int"},{"double"},{"float"},{"namespace"},{"#include"},{"char"},{"while"},{"for"},{"if"},{"else"},{"return"},{"main()"}};
	int tno=4;
	char types[][20]={{"int"},{"char"},{"double"},{"float"}};

	int noi=0;

	int i=0;
	int lno=0;

	while(getline(fp,line)){
		result<<lno<<"\t";
		const char *start=line.c_str();
		const char *end=start+line.size();
		const char *token=start;
		string dtype;
		int flag=0;

		while(start < end){
			if(*start == ' '){
				string tok=string(token,start);
				for(int i=0;i<tno;i++){
					if( strcmp(tok.c_str(),types[i]) == 0 ){
						//type<<tok<<endl;
						//cout<<tok<<endl;
						dtype=tok;
						const char*  temp2=start;
						const char* temptok=start;
						//cout<<"a"<<endl;
						while(temp2<end && *temp2 != ';'){
							//cout<<*temp2;
							if(*temp2 == ','){
								cout<<"<"<<dtype<<">";
								wtype(string(temptok,temp2));
								//cout<<"<"<<dtype<<">"<<"-<"<<string(temptok,temp2)<<">-";
								temptok=temp2;
							}
							temp2++;
						}
						//cout<<"<"<<dtype<<">";
						wtype(string(temptok,temp2));
								//cout<<"<"<<dtype<<">"<<"-<"<<string(temptok,temp2)<<">-";
						break;
					}
				}
				//cout<<tok<<endl;
				start++;
				token=start;
				continue;
			}
			start++;
		}
		cout<<endl;
		lno++;
	}
	

}