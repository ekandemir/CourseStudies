//
//  main.cpp
//  lab6
//
//  Created by Developing on 25.10.2017.
//  Copyright © 2017 erdinckandemir. All rights reserved.
//

#include <iostream>

using namespace std;
struct stack{
    char data;
    stack *prev;
    

};
stack *top;

void create(){
    top = NULL;
}

void push(char a){
    stack *newnode;
    newnode = new stack;
    newnode->data = a;
    newnode->prev = top;
    top = newnode;
    
}

char pop(){
    char a = top->data;
    stack * temp;
    temp = top;
    top = top->prev;
    delete temp;
    return a;
}




int priorityof(char operation){
    if(operation == '*' || operation == '/'){
        return 3;
    }
    else if(operation == '+' || operation == '-'){
        return 2;
    }
    else if(operation == '(' || operation == ')'){
        return 1;
    }
    else return 0;
}

int main(int argc, const char * argv[]) {
    char e[50];
    
    char postfix[50];
    for(int i = 0 ; i < 50 ; i++){postfix[i] = '\0';e[i] = '\0';}
    char temp = '\0';
    create();
    while(strcmp(e,"EXIT")){
        cout <<"Please enter infix expression : "<<endl;
        cin>>e;
        
        for (int i = 0 ; i < strlen(e) ; i++){
            if(e[i] == '\0'){
                for(int j = 0 ; j < 50 ; j++){
                    if(postfix[j] == '\0'){
                        
                        temp = pop();
                        if(temp != '\0'){
                            postfix[j] = temp;
                        }
                        else{
                            break;
                        }
                    }
                    
                }

            
            }
            
            if(priorityof(e[i]) == 0){
                for(int j = 0 ; j < 50 ; j++){
                    if(postfix[j] == '\0'){
                        postfix[j] = e[i];
                        break;
                    }
                
                }
            
            
            }
            else{
                if (priorityof(e[i]) == 1){
                    if(e[i] == '('){
                        push(e[i]);
                    }
                    else{
                        for(int j = 0 ; j < 50 ; j++){
                            if(postfix[j] == '\0'){
                                
                                temp = pop();
                                if(temp != '\0'){
                                    postfix[j] = temp;
                                }
                                else{
                                    break;
                                }
                            }
                            
                        }
 
                    
                    }
                }
                else {
                    if(top){
                        
                            if (priorityof(e[i]) < top -> data){
                                for(int j = 0 ; j < 50 ; j++){
                                    if(postfix[j] == '\0'){
                                        
                                        temp = pop();
                                        if(temp != '\0'){
                                            postfix[j] = temp;
                                        }
                                        else{
                                            break;
                                        }
                                    }
                                    
                                } 
                            
                            }
                    
                        
                    }
                    else{
                        push(e[i]);
                    
                    }
                        
                    
                    
                }
                
            }
            
            
        }
        
    
    cout<<postfix;
    }
    
    return 0;
}
