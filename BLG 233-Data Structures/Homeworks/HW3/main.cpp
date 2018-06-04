/* @Author
 * Student Name: Erdinc Kandemir
 * Student ID : 150150110
 * Date: 10.12.2017
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;
struct patientData{
    string name;
    int timeArriving;
    int timeNeed;
    string code;
};
struct node{
    patientData patient;
    node* next;
};//patient struct;

struct queue{
    node* front;
    node* back;
    void create();
    void enqueue(patientData);
    patientData dequeue();
    bool isEmpty();
};
void queue::create(){
    front = NULL;
    back = NULL;
}
void queue::enqueue(patientData patient){
    node* newNode = new node;
    newNode->next = NULL;
    newNode->patient = patient;
    
    if(!front){
        front = newNode;
        back = newNode;
        return;
    }
    else{
        back->next = newNode;
        back = newNode;
        return;
    }
}
patientData queue::dequeue(){
    node* tempNode = front;
    front = front->next;
    patientData tempPatient = tempNode->patient;
    delete tempNode;
    return tempPatient;
    
}
bool queue::isEmpty(){
    if(front == NULL)
        return true;
    else
        return false;
    
}
//queue functions

int main() {
    queue patientList,redNew,yellow,yellowNew,green,greenNew;
    patientList.create();redNew.create();yellow.create();yellowNew.create();green.create();greenNew.create();//create queues
    string temp;
    patientData newPatient,curPatient;
    int curTime = 0;
    
    ifstream fpatient;
    fpatient.open("patientsInfo.txt");//file operations
    getline(fpatient, temp);//discard first line
    if(fpatient.is_open()){
        while(!fpatient.eof()){
            fpatient>>newPatient.name>>newPatient.timeArriving>>newPatient.timeNeed>>newPatient.code;
            patientList.enqueue(newPatient);
        }
        fpatient.close();
        //read all patients and push to main queue
    }
    else{cout<<"file could not be opened."<<endl; return 0;}
    while(true){
        while(true){
            if(!patientList.isEmpty()){
                if(patientList.front->patient.timeArriving <= curTime){
                    newPatient = patientList.dequeue();
                    if(newPatient.code == "RED"){redNew.enqueue(newPatient);}
                    else if(newPatient.code == "YELLOW"){yellowNew.enqueue(newPatient);}
                    else if(newPatient.code == "GREEN"){greenNew.enqueue(newPatient);}
                }
                else{break;}//push newcomers to appropriate queues
            }
            else{break;}
            
        }
        if(!redNew.isEmpty()){              curPatient = redNew.dequeue();}
        else if (!yellowNew.isEmpty()){     curPatient = yellowNew.dequeue();}
        else if (!yellow.isEmpty()){        curPatient = yellow.dequeue();}
        else if (!greenNew.isEmpty()){      curPatient = greenNew.dequeue();}
        else if (!green.isEmpty()){         curPatient = green.dequeue();}//queue priorities
        else{
            if(patientList.isEmpty()){break;}//whole patients pushed to appropriate queues
            else{curTime++; cout << curTime << ".time slice No Treatment"<<endl;}//no current treatment
        }//getting patient based on priorities
        
        if(curPatient.code == "RED"){
            if(curPatient.timeNeed > 1){
                for(int i = 0; i <1 ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                    curPatient.timeNeed--;
                }
                curPatient.code = "YELLOW";
                yellow.enqueue(curPatient);
            }//red codded patient who will be continoue to treatment
            else{
                for(int i = 0; i <curPatient.timeNeed ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                }
            }//red codded patient who will be leave
        }
        else if(curPatient.code == "YELLOW"){
            if(curPatient.timeNeed > 2){
                for(int i = 0; i <2 ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                    curPatient.timeNeed--;
                }
                curPatient.code = "GREEN";
                green.enqueue(curPatient);
            }//yellow codded patient who will be continoue to treatment
            else{
                for(int i = 0; i <curPatient.timeNeed ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                }
            }//yellow codded patient who will be continoue to treatment
        }
        else if(curPatient.code == "GREEN"){
            if(curPatient.timeNeed > 3){
                for(int i = 0; i <3 ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                    curPatient.timeNeed--;
                }
                green.enqueue(curPatient);
            }//green codded patient who will be continoue to treatment
            else{
                for(int i = 0; i <curPatient.timeNeed ; i++){
                    curTime = curTime + 1;
                    cout<<curTime<<".time slice "<< curPatient.name<<endl;
                }
            }//green codded patient who will be continoue to treatment
        }//treatments
    }
    return 0;
}
