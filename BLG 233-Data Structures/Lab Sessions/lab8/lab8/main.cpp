//
//  main.cpp
//  lab8
//
//  Created by Developing on 22.11.2017.
//  Copyright © 2017 erdinckandemir. All rights reserved.
//

#include <iostream>
#define N 3
typedef char* StackDataType;
struct Node{
    StackDataType data;
    Node *next;
};

struct Stack{
    int count = 0;
    Node *head;
    void create();
    void close();
    void push(StackDataType);
    StackDataType pop();
    bool isEmpty();
};

void Stack::create(){
    head = NULL;
}
void Stack::close(){
    Node *traverse;
    while(head != NULL){
        traverse = head;
        head = head->next;
        delete traverse;
    }
}

void Stack::push(StackDataType newdata){
    Node *newnode = new Node;
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
    count++;
}

StackDataType Stack::pop(){
    Node *topnode;
    StackDataType temp;
    topnode = head;
    head = head->next;
    temp = topnode->data;
    delete topnode;
    count--;
    return temp;
}

bool Stack::isEmpty(){
    return head == NULL;
}


struct Queue{
    int count = 0;
    Node *head,*tail;
    void create();
    void close();
    void push(StackDataType);
    StackDataType pop();
    bool isEmpty();
};


void Queue::create(){
    head = NULL;
}
void Queue::close(){
    Node *traverse;
    while(head != NULL){
        traverse = head;
        head = head->next;
        delete traverse;
    }
}



void Queue::push(StackDataType newdata){
    Node *newnode = new Node;
    newnode->data = newdata;
    if(isEmpty()){
        head = newnode;
        tail = newnode;
        
        
    }
    else{
        tail->next = newnode;
        tail = newnode;
    
    }
    count++;

}
bool Queue::isEmpty(){
    return head == NULL;
}

StackDataType Queue::pop(){
    Node *topnode;
    StackDataType temp;
    topnode = head;
    head = head->next;
    temp = topnode->data;
    delete topnode;
    count--;
    return temp;
    }

using namespace std;


void list(Stack a1,Stack a2,Stack a3, Stack a4, Queue temp){
    Node *traverse;
    traverse = a1.head;
    cout <<"Area 1 :  ";
    
    while(traverse){
        cout<<traverse->data<<"  ||  ";
        traverse = traverse->next;
    }
    cout<<endl;
    traverse = a2.head;
    cout <<"Area 2 :  ";
    
    while(traverse){
        cout<<traverse->data<<"  ||  ";
        traverse = traverse->next;
    }
    cout<<endl;
    traverse = a3.head;
    cout <<"Area 3 :  ";
    
    while(traverse){
        cout<<traverse->data<<"  ||  ";
        traverse = traverse->next;
    }
    cout<<endl;
    traverse = a4.head;
    cout <<"Area 4 :  ";
    
    while(traverse){
        cout<<traverse->data<<"  ||  ";
        traverse = traverse->next;
    }
    cout<<endl;
    traverse = temp.head;
    cout <<"Outside :  ";
    
    while(traverse){
        cout<<traverse->data<<"  ||  ";
        traverse = traverse->next;
    }
    cout<<endl;
}


using namespace std;


int main(int argc, const char * argv[]) {

   
    
    Stack a1,a2,a3,a4;
    a1.create();a2.create();a3.create();a4.create();
    Queue temp;
    temp.create();
    char operation = 'A';
    int check = 1;
    char *tempPlate = new char[10];

    while(operation != 'E'){
        cout<<"choose operation : "<<endl;
        cin>>operation;

        switch (operation){
            case 'A' : case 'a' : {
                cout << "Enter license plate : "<<endl;
                char *license = new char[10];
                cin >>license;
                if (a1.count < N){
                    a1.push(license);
                }
                else if(a2.count<N){
                    a2.push(license);
                
                }
                else if(a3.count<N){
                    a3.push(license);
                
                }
                else if(a4.count<N){
                    a4.push(license);
                
                }
                else{
                
                    temp.push(license);
                }
                
                break;
            }
                
            case 'B': case 'b':{
                cout << "Enter license plate : "<<endl;
                char *license = new char[10];
                cin >> license;
                Node *traverse = a1.head;
                while(traverse){
                    if(strcmp(traverse->data,license) == 0){
                        //a1 found
                        while(true){
                            tempPlate = a1.pop();
                            if(((strcmp(tempPlate,license)) != 0)){
                                if(a2.count<N){a2.push(tempPlate);}
                                else if(a3.count<N){a3.push(tempPlate);}
                                else if(a4.count<N){a4.push(tempPlate);}
                                else {temp.push(tempPlate);}

                            }
                            else{
                                while(!temp.isEmpty()){
                                    a1.push(temp.pop());
                                    
                                }
                                check = 0;
                                break;
                            }
                            
                        }
                        
                    }
                    traverse = traverse->next;
                }
                traverse = a2.head;
                while(traverse){
                    if(strcmp(traverse->data,license)==0){
                        //a2 found
                        while(true){
                            tempPlate = a2.pop();
                            if(((strcmp(tempPlate,license)) != 0)){
                                if(a1.count<N){a2.push(tempPlate);}
                                else if(a3.count<N){a3.push(tempPlate);}
                                else if(a4.count<N){a4.push(tempPlate);}
                                else {temp.push(tempPlate);}
                                
                            }
                            else{
                                while(!temp.isEmpty()){
                                    a2.push(temp.pop());
                                    
                                }
                                check = 0;
                                break;
                            }
                            
                        }
                        
                    }
                     traverse = traverse->next;
                }
                traverse = a3.head;
                while(traverse){
                    if(strcmp(traverse->data,license)==0){
                        //a3 found
                        while(true){
                            tempPlate = a3.pop();
                            if(((strcmp(tempPlate,license)) != 0)){
                                if(a1.count<N){a1.push(tempPlate);}
                                else if(a2.count<N){a2.push(tempPlate);}
                                else if(a4.count<N){a4.push(tempPlate);}
                                else {temp.push(tempPlate);}
                                
                            }
                            else{
                                while(!temp.isEmpty()){
                                    a3.push(temp.pop());
                                    
                                }
                                check = 0;

                                break;
                            }
                           
                        }

                        
                    }
                     traverse = traverse->next;
                }
                traverse = a4.head;
                while(traverse){
                    if(strcmp(traverse->data,license)==0){
                        //a4 found
                        while(true){
                            tempPlate = a4.pop();
                            if(((strcmp(tempPlate,license)) != 0)){
                                if(a1.count<N){a2.push(tempPlate);}
                                else if(a2.count<N){a2.push(tempPlate);}
                                else if(a3.count<N){a3.push(tempPlate);}
                                else {temp.push(tempPlate);}
                                
                            }
                            else{
                                while(!temp.isEmpty()){
                                    a4.push(temp.pop());
                                    
                                }
                                check = 0;

                                break;
                            }
                            
                            
                        }

                                          }
                     traverse = traverse->next;
                }
                if(check){
                    cout<<"Plate Not Found"<<endl;
                
                }
                break;
            }
            case 'L' : case 'l' :{
                list(a1, a2, a3, a4, temp);
            }
                
        }
    }
    
    
    
    
    return 0;
}
