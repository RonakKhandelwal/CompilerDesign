#include <iostream>
#include <string.h>
#include "LexicalTest1.cpp"
using namespace std;

void Sentance();
void E();
int noun_phase();
void verb_phase();
int article();
void noun();
void verb();

void Sentance(){
  int ans = 0;
  ans = noun_phase();
  if(ans == 1){
    verb_phase();
    if(strcmp(token.c_str(), "$") == 0){
      cout<<"Parse complete"<<endl;
      exit(0);
    }
    E();
  }

}

void E(){
  Sentance();
}

int noun_phase(){
  int ans = 0;
  ans = article();
  if(ans == 1)noun();
  return ans;
}

int article(){
  if(strcmp(token.c_str(), "a") == 0){
    cout<<"get Token called article"<<endl;getToken();
    return 1;
  }
  else if(strcmp(token.c_str(), "the") == 0){
    cout<<"get Token called article"<<endl;getToken();
    return 1;
  }
  else{
    return 0;
  }
}

void noun(){
  if(strcmp(token.c_str(), "boy") == 0){
    cout<<"get Token called noun"<<endl;getToken();
    return;
  }
  else if(strcmp(token.c_str(), "dog") == 0){
    cout<<"get Token called noun"<<endl;getToken();
  }
  else{
    cout<<"Noun Expected Parse error";
    exit(1);
  }
}
void verb_phase(){
  verb();
  noun_phase();
}
void verb(){
  if(strcmp(token.c_str(), "sees") == 0){
    cout<<"get Token called verb"<<endl;getToken();
  }
  else if(strcmp(token.c_str(), "pets") == 0){
    cout<<"get Token called verb"<<endl;getToken();
  }
  else{
    cout<<"Verb Expected Parse error";
    exit(1);
  }
}




int main(){
  tokenizer();
  cout<<"get Token called"<<endl;getToken();
  Sentance();
  cout<<"Parse Complete";
}
