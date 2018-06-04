//
//  main.cpp
//  lab4
//
//  Created by Developing on 11.10.2017.
//  Copyright © 2017 erdinckandemir. All rights reserved.
//

#include <iostream>
using namespace std;

struct phoneNumber{
    
    char *type;
    char *number;
    phoneNumber* next;
    
};
struct phoneBook{
    phoneBook *prev;
    char *name;
    phoneNumber *number;
    phoneBook *next;
    
};
phoneBook * head;

void addPerson();
void addNumber();
void removePerson();
void removeNumber();
void updatePerson();
void updateNumber();
void list();
void search();

void deleteAll(){
    phoneBook *traverse = head;
    phoneNumber *traverseNumber = NULL;
    phoneBook *temp;
    phoneNumber *tempNumber;
    while(traverse){
        
        traverseNumber = traverse ->number;
        while(traverseNumber){
            
            
            cout<<"|||"<<traverseNumber->type<<"--"<<traverseNumber->number<<"|||DELETED       ";
            tempNumber = traverseNumber->next;
            delete traverseNumber;
            traverseNumber = tempNumber;
        
        }
        cout<<traverse->name<<"-DELETED"<<endl;
        
        temp = traverse->next;
        delete traverse;
        traverse = temp;
    
    }
    cout<<"ALL MEMORY DEALLOCATED!!!"<<endl;
}



int main(int argc, const char * argv[]) {
    char operation='a';
    while(operation != 'x'){
        cout<<endl<<"*****************"<<endl;
        cout<<"a _ Add Person"<<endl;
        cout<<"b _ Add Number"<<endl;
        cout<<"c _ Remove Person"<<endl;
        cout<<"d _ Remove Number"<<endl;
        cout<<"e _ Update Person"<<endl;
        cout<<"f _ Update Number"<<endl;
        cout<<"g _ Search"<<endl;
        cout<<"h _ List"<<endl;
        cout<<"x _ Exit"<<endl;
        cout<<"*****************"<<endl;
        cin>>operation;
        
        switch (operation) {
            case 'a'://add person
                addPerson();
                break;
            case 'b'://add number
                addNumber();
                break;
            case 'c'://remove person
                removePerson();
                break;
            case 'd'://remove number
                removeNumber();
                break;
            case 'e'://update person
                updatePerson();
                break;
            case 'f'://update number
                updateNumber();
                break;
            case 'g'://search
                search();
                break;
            case 'h'://list
                list();
                break;
            default:
                deleteAll();
                cout<<"Please enter a valid operator"<<endl;
                break;
        }
        
    }
    
    return 0;
}

void addPerson(){
    phoneBook *newNode;
    newNode = new phoneBook[1];
    phoneBook *traverse = head;
    char temp[30];
    if (!head){//first record
        newNode->prev=NULL;
        newNode->number=NULL;
        newNode->next=NULL;
        cout<<"Enter name"<<endl;
        cin>>temp;
        newNode->name = new char[strlen(temp)+1];
        strcpy(newNode->name, temp);
        head = newNode;
    }
    else{//other records
        
        cout<<"Enter name"<<endl;
        cin>>temp;
        newNode->name = new char[strlen(temp)+1];
        strcpy(newNode->name, temp);
        newNode->number=NULL;
        if( strcmp(newNode->name, traverse->name)<0 ){
            newNode->next = traverse;
            traverse->prev = newNode;
            newNode ->prev = NULL;
            head = newNode;

        }
        else{
            while(traverse->next){
                
               
                
                
                if(strcmp(newNode->name, traverse->next->name)<0){
                    
                
                newNode->next = traverse->next;
                traverse->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev=traverse;
                break;
                }
                else{
                    traverse=traverse->next;
                }
        

            
            }
            if(!traverse->next){
                
                traverse->next = newNode;
                newNode->prev = traverse;
                newNode->next=NULL;

        }
        
            
            
        }
        
    }
    
    
}
void addNumber(){
    phoneBook *traverse = head;
    phoneNumber *traverseNumber;
    phoneNumber *newNumber = new phoneNumber[1];
    int control = 1;
    char tempName[30];
    char temp[30];
    while(control){
        cout<<"Enter name"<<endl;
        cin>> tempName;
        traverse = head;
        while(traverse){
            if (strcmp(traverse->name,tempName) == 0){
                                control=0;
                traverseNumber = traverse->number;

                cout<<"Enter Number"<<endl;
                cin>>temp;
                newNumber->number = new char[strlen(temp)+1];
                strcpy(newNumber->number, temp);
                cout<<"Ender type of Number"<<endl;
                cin>>temp;
                newNumber->type = new char[strlen(temp)+1];
                strcpy(newNumber->type,temp);
                newNumber->next=NULL;
                if(!traverseNumber){
                    traverse->number = newNumber;
                    break;}
                
                else{
                    while(traverseNumber->next){
                        traverseNumber = traverseNumber->next;
                        
                    }
                    traverseNumber->next = newNumber;
                    break;
                }
                    }
            else{traverse = traverse->next;}
        
        
        }
    }
    cin.ignore(1000,'\n');
}
void removePerson(){
    phoneBook *traverse = head;
    int control = 1;
    char tempName[15];
    while(control){
        cout<<"Enter name"<<endl;
        cin>> tempName;
        traverse = head;
        while(traverse){
            if (strcmp(traverse->name,tempName) == 0){
                control = 0;
                if(!traverse->prev){
                    if(!traverse->next){
                        delete traverse;
                        head = NULL;
                        break;
                    }
                    else{
                        head = traverse->next;
                        traverse->next->prev = NULL;
                        break;
                    }
                }
                else if (!traverse->next){
                    traverse->prev->next = NULL;
                    delete traverse;
                    break;
                    
                    
                
                }
                else{
                    traverse->next->prev = traverse->prev;
                    traverse->prev->next = traverse->next;
                
                delete traverse;
                break;
                }
            }
            else{
                traverse = traverse->next;
            }
        }
    }



}
void removeNumber(){
    phoneBook *traverse = head;
    int control = 1;
    char tempName[15];
    phoneNumber *traverseNumber;
    phoneNumber *tail;
    int i=1;
    int order= 0;
    
    
    while(control){
        cout<<"Enter name:"<<endl;
        cin>> tempName;
        traverse = head;
        while(traverse){
            if (strcmp(traverse->name,tempName) == 0){
                control = 0;
                
                traverseNumber = traverse->number;
                while(traverseNumber){
                    cout<<i<<'-'<<traverseNumber->type<<':'<<traverseNumber->number<<endl;
                    traverseNumber=traverseNumber->next;
                    
                    i++;
                }
                traverseNumber = traverse->number;
                cout<<"Please enter the index of number"<<endl;
                cin>>order;
                tail = NULL;
                for (int i = 1; i < order; i++){
                    
                    tail = traverseNumber;
                    traverseNumber = traverseNumber->next;
                }
                
                if(!tail){
                    traverse->number = traverse->number->next;
                    delete traverseNumber;
                    break;
                
                }
                else{
                    tail->next = traverseNumber->next;
                    delete traverseNumber;
                    break;
                
                }
                
            }
            traverse = traverse -> next;
        }
    }
    







}
void updatePerson(){
    phoneBook *traverse = head;
    int control = 1;
    char tempName[15];
    while(control){
        cout<<"Enter name to update:"<<endl;
        cin>> tempName;
        traverse = head;
        while(traverse){
            if (strcmp(traverse->name , tempName) == 0){
                control = 0;
                if(!traverse->prev){
                    if(!traverse->next){
                        head = NULL;
                        break;
                    }
                    else{
                        head = traverse->next;
                        traverse->next->prev = NULL;
                        break;
                    }
                }
                else if (!traverse->next){
                    traverse->prev->next = NULL;
                    break;
                    
                    
                    
                }
                else{
                    traverse->next->prev = traverse->prev;
                    traverse->prev->next = traverse->next;
                    
                    break;
                }
            }
            else{
                traverse = traverse->next;
            }
        }
    }//cracking the connection-remove
    
    phoneBook *newNodea;
    newNodea = new phoneBook[1];
    phoneBook *traversea = head;
    char temp[30];
    
    if (!head){//first record
        newNodea->prev=NULL;
        newNodea->number=NULL;
        newNodea->next=NULL;
        cout<<"Enter new name"<<endl;
        cin>>temp;
        newNodea->name = new char[strlen(temp)+1];
        strcpy(newNodea->name, temp);
        head = newNodea;
    }
    else{//other records
        cout<<"Enter new name"<<endl;
        cin>>temp;
        newNodea->name = new char[strlen(temp)+1];
        strcpy(newNodea->name, temp);
        newNodea->number=NULL;
        if( strcmp(newNodea->name, traversea->name)<0 ){
            newNodea->next = traversea;
            traversea->prev = newNodea;
            newNodea ->prev = NULL;
            head = newNodea;
            
        }
        else{
            while(traversea->next){
                
                
                
                
                if(strcmp(newNodea->name, traversea->next->name)<0){
                    
                    
                    newNodea->next = traversea->next;
                    traversea->next = newNodea;
                    newNodea->next->prev = newNodea;
                    newNodea->prev=traversea;
                    break;
                }
                else{
                    traversea=traversea->next;
                }
                
                
                
            }
            if(!traversea->next){
                
                traversea->next = newNodea;
                newNodea->prev = traversea;
                newNodea->next=NULL;
                
            }
            
            
            
        }
        
    }

    
    newNodea->number = traverse->number;
    delete traverse;
    
    

}
void updateNumber(){phoneBook *traverse = head;
    int control = 1;
    char tempName[15];
    phoneNumber *traverseNumber;
    phoneNumber *tail;
    int i=1;
    int order= 0;
    
    
    while(control){
        cout<<"Enter name"<<endl;
        cin>> tempName;
        traverse = head;
        while(traverse){
            if (strcmp(traverse->name,tempName) == 0){
                control = 0;
                
                traverseNumber = traverse->number;
                while(traverseNumber){
                    cout<<i<<'-'<<traverseNumber->type<<':'<<traverseNumber->number<<endl;
                    traverseNumber=traverseNumber->next;
                    
                    i++;
                }
                traverseNumber = traverse->number;
                cout<<"Please enter the index of number"<<endl;
                cin>>order;
                tail = NULL;
                for (int i = 1; i < order; i++){
                    
                    tail = traverseNumber;
                    traverseNumber = traverseNumber->next;
                }
                
                cout<<"Enter new number"<<endl;
                cin>>traverseNumber->number;
                cout<<"Enter the type of the number:"<<endl;
                cin>>traverseNumber->type;
                break;
                
            }
            traverse = traverse->next;
        }
    }
    
    
    
    
    
    
    
}
void list(){
    cout<<"Name"<<'\t'<<"Number(s)"<<endl;
    phoneBook *traverse = head;
    phoneNumber *traverseNumber;
    while (traverse){
        cout<<traverse->name<<"-->>";
        traverseNumber = traverse->number;
        while(traverseNumber){
            cout<<traverseNumber->type<<':'<<traverseNumber->number<<"|";
            traverseNumber=traverseNumber->next;
        }
        cout<<endl;
        traverse= traverse->next;
    
    }
    
}
void search(){
    char search[15];
    char temp[15];
    for(int i = 0 ; i <14 ; i++){
        search[i]=NULL;
        temp[i]=NULL;
    }
    cout<<"Enter word to search"<<endl;
    cin>>search;
    phoneBook *traverse = head;
    phoneNumber *traverseNumber;

    
    while(traverse){
        
        
        
        for(int i = 0 ; i<strlen(search) ; i++){
            temp[i] = traverse->name[i];
            
            
        
        }
        if(strcmp(temp,search)>0){
    
        break;
        }
        
        
        cout<<traverse->name<<endl;
        cout<<search<<endl;
    
        if(strncmp(traverse->name, search, strlen(search))==0){
                cout<<traverse->name<<"-->>";
                traverseNumber = traverse->number;
                while(traverseNumber){
                    cout<<traverseNumber->type<<':'<<traverseNumber->number<<"|";
                    traverseNumber=traverseNumber->next;
                }
                cout<<endl;
            
            
            

        
        
        
        
        }
    
        traverse = traverse->next;




    }




}
