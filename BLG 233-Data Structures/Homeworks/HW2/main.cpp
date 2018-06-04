/* @Author
 * Student Name: Erdinc Kandemir
 * Student ID : 150150110
 * Date: 01.11.2017
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct studentInfo{
    studentInfo *prev;
    string name;
    string surname;
    string mailadress;
    studentInfo *next;
};

struct surnameMap{
    string surname;
    studentInfo *mail;
    surnameMap *next;
};


surnameMap *head;
void insertNode(studentInfo* student){
    surnameMap *traverse = head;
    surnameMap *tail = head;
    studentInfo *traverseStudent = NULL;
    string tempName, subName;
    string checkMail;
    int isfound = 0;
    if(!head){//first entry
        surnameMap *surNode = new surnameMap ;
        surNode->surname = student->surname;
        surNode->mail = student;
        surNode->mail->mailadress = student->surname + "@itu.edu.tr";

        head = surNode;

    }
    else{
        while(traverse){//other entries
            if( student -> surname == traverse -> surname){
                tempName = student -> surname + student -> name;
                traverseStudent = traverse -> mail;

                while (traverseStudent){
                    
                    checkMail = traverseStudent->mailadress.substr(0,traverseStudent->mailadress.find('@'));
                    if(tempName.compare(checkMail)<0){

                        
                        
                        traverseStudent = traverseStudent -> prev;//to compare with the previous one
                        checkMail = traverseStudent->mailadress.substr(0,traverseStudent->mailadress.find('@'));
                        
                        /*if(tempName.length() <= checkMail.length()){//number things
                            while(traverseStudent->next->mailadress[tempName.length()]<'9' && traverseStudent->next->mailadress[tempName.length()]>'0' && traverseStudent->next){
                                traverseStudent = traverseStudent->next;
                                checkMail = traverseStudent->mailadress.substr(0,traverseStudent->mailadress.find('@'));
                            }
                            
                            
                            if(tempName.compare(checkMail)==0){
                                student->mailadress = tempName+'2'+"@itu.edu.tr";
                                student->next = traverseStudent->next;
                                student->prev = traverseStudent;
                                traverseStudent->next = student;
                                student->next->prev = student;
                                return;
                            }
                            else{
                                if(tempName.compare(traverseStudent->mailadress.substr(0,tempName.length()))==0){
                                    if(traverseStudent->mailadress[tempName.length()]<'9' && traverseStudent->mailadress[tempName.length()]>'0'){
                                        int order = stoi(checkMail.substr(tempName.length()+1,checkMail.length()));
                                        order++;
                                        student->mailadress=tempName+to_string(order)+"@itu.edu.tr";
                                        student->next = traverseStudent->next;
                                        student->prev = traverseStudent;
                                        traverseStudent->next = student;
                                        student->next->prev = student;
                                        return;
                                    }
                                }
                            }
                        
                        }*/
                        
                        
                        subName = tempName.substr(0,checkMail.length());
                        

                        
                        
                        while(checkMail != subName){
                            checkMail = checkMail.substr(0,checkMail.length() - 1);
                            subName = subName.substr(0,subName.length() - 1);//decreasing one by one
                        }
                        student -> mailadress = tempName.substr(0,subName.length()+1)+"@itu.edu.tr";
                        student->next = traverseStudent->next;
                        student->prev = traverseStudent;
                        traverseStudent->next = student;
                        student->next->prev = student;
                        
                        isfound = 1;

                        break;
                    }
                    else if(!traverseStudent->next){//add to last
                        
                        checkMail = traverseStudent->mailadress.substr(0,traverseStudent->mailadress.find('@'));
                        /*if(tempName.length() <= checkMail.length()){//number things
                            if(tempName == checkMail){
                                student->mailadress = tempName+'2'+"@itu.edu.tr";
                                student->next = traverseStudent->next;
                                student->prev = traverseStudent;
                                traverseStudent->next = student;
                                return;
                            }
                            else{
                                if(tempName == checkMail.substr(0,tempName.length())){
                                    if(checkMail[tempName.length()]<'9' && checkMail[tempName.length()]>'0'){
                                        int order = stoi(checkMail.substr(tempName.length()+1,checkMail.length()));
                                        order++;
                                        student->mailadress=tempName+to_string(order)+"@itu.edu.tr";
                                        student->next = traverseStudent->next;
                                        student->prev = traverseStudent;
                                        traverseStudent->next = student;
                                        return;
                                    }
                                }
                            }
                            
                        }*/
                        
                        
                        
                        
                        subName = tempName.substr(0,checkMail.length());
                        while(checkMail != subName){
                            checkMail = checkMail.substr(0,checkMail.length() - 1);
                            subName = subName.substr(0,subName.length() - 1);//decreasing one by one
                        }
                        student -> mailadress = tempName.substr(0,subName.length()+1)+"@itu.edu.tr";
                        student->next = NULL;
                        student->prev = traverseStudent;
                        traverseStudent->next = student;
                        
                        
                        isfound = 1;
                        
                        break;

                    
                    
                    }
                    traverseStudent = traverseStudent ->next;
                }
                
            }
            traverse = traverse->next;
        }
        if (!isfound){//first person of surnames
            traverse = head;
            while (traverse){
                if (student->surname.compare(traverse->surname)<0){
                    surnameMap *newsurname = new surnameMap;
                    if(tail != head){
                        tail->next = newsurname;
                        newsurname->next = traverse;
                        newsurname->surname = student->surname;
                        newsurname->mail = student;
                        student->mailadress = student->surname + "@itu.edu.tr";
                        student->prev = NULL;
                        break;
                    }
                    else{
                        newsurname->next = head;
                        head = newsurname;
                        newsurname->surname = student->surname;
                        newsurname->mail = student;
                        student->mailadress = student->surname + "@itu.edu.tr";
                        student->prev = NULL;
                        break;

                    
                    
                    }
                }
                tail = traverse;
                traverse = traverse->next;
            }
        
        }
        
    }
}

void createList(){
    head = NULL;
}


void insertAll(){
//insert from file
    ifstream fstudentlist;
    string name,surname;
    fstudentlist.open("newStudentList.txt");
    while( !fstudentlist.eof() ){
        studentInfo *newstudent;
        newstudent = new studentInfo;
        fstudentlist >> name;
        newstudent->name = name; fstudentlist>> surname;
        newstudent->surname = surname;
        insertNode(newstudent);
    
    }
    cout<<"All records inserted from the file..."<<endl;
}
void insertNewRecord(){
//insert from user entry
    
    studentInfo *student = new studentInfo;
    cout<<"Please enter name of student : "<<endl;
    cin>>student->name;
    cout<<"Please enter surname of student : "<<endl;
    cin>>student->surname;
    insertNode(student);
    
}

void deleteStudent(){
}

void deleteSurnameNode(){
}


void updateList(){
    surnameMap *traverse = head;
    studentInfo *traverseStudent = NULL;
    while(traverse){
        cout<< traverse->surname<<endl;
        traverseStudent = traverse->mail;
        while(traverseStudent){
            
        cout<< traverseStudent->mailadress<<"--";
        traverseStudent = traverseStudent ->next;

        }
        
                traverse = traverse->next;
        
    }}

void writeToFile(){
}

void deleteMemory(){//releasing dynamic memories
    surnameMap *tail, *traverse = head;
    studentInfo *tailStudent, *traverseStudent = NULL;
    while(traverse){
        traverseStudent = traverse->mail;
        while(traverseStudent){
            tailStudent = traverseStudent;
            traverseStudent = traverseStudent ->next;
            delete tailStudent;
        }
        
        
        tail = traverse;
        traverse = traverse->next;
        delete tail;
    }
}

int main(int argc, const char * argv[]) {
    int operation = 0;
    while (operation != 99){
        cout<<"***************************************"<<endl;
        cout<<"* *********************************** *"<<endl;
        cout<<"* *                                 * *"<<endl;
        cout<<"* *  1) Create                      * *"<<endl;
        cout<<"* *  2) Insert All                  * *"<<endl;
        cout<<"* *  3) Insert New Record           * *"<<endl;
        cout<<"* *  4) Delete Student              * *"<<endl;
        cout<<"* *  5) Delete Surname Node         * *"<<endl;
        cout<<"* *  6) Update                      * *"<<endl;
        cout<<"* *  7) Write to File               * *"<<endl;
        cout<<"* *                                 * *"<<endl;
        cout<<"* *  99) EXIT                       * *"<<endl;
        cout<<"* *                                 * *"<<endl;
        cout<<"* *********************************** *"<<endl;
        cout<<"*******    Enter a choice:   **********"<<endl;
        
        cin>>operation;
        switch (operation) {
            case 1:
                createList();
                break;
            case 2:
                insertAll();
                break;
            case 3:
                insertNewRecord();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                deleteSurnameNode();
                break;
            case 6:
                updateList();
                break;
            case 7:
                writeToFile();
                break;
                
            default:
                break;
        }
        
        
        
        
    }
    deleteMemory();
    return 0;
}
