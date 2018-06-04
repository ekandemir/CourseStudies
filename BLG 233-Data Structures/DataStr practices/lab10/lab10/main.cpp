
#include <iostream>
using namespace std;

struct phoneNode{
    string phoneNum;
    phoneNode* next =NULL;
};


struct person{
    string name;
    phoneNode* number = NULL;
};


struct node{
    person data;
    node* right = NULL;
    node* left = NULL;
    
};
struct BST{
    node* root;
    void create();
    void emptyTree(node*);
    void add(node*);
    void remove(string);
    node* search(string);
    void print(node*);
    void removeNode(string);
};
void BST::create(){
    root = NULL;
    cout<<"List has been crated!!!"<<endl;
}


node* BST::search(string name){
    node *traverse;
    traverse = root;
    while(traverse){
        if(name.compare(traverse->data.name)<0){
            traverse = traverse->left;
        }
        else if(name.compare(traverse->data.name)>0){
            traverse = traverse->right;
        }
        else{return traverse;}
    }
    return NULL;
}

void BST::removeNode(string name){
    node *traverse,*parent;
    traverse = root;
    parent = traverse;
    while(traverse){
        if(name.compare(traverse->data.name)<0){
            parent = traverse;
            traverse = traverse->left;
        }
        else if(name.compare(traverse->data.name)>0){
            parent = traverse;
            traverse = traverse->right;
        }
        else{
            if(!traverse->left && !traverse->right){
                if(parent->left->data.name.compare(name)==0){
                    parent->left = NULL;
                    //delete traverse;
                    return;
                }
                else{
                    parent->right = NULL;
                    //delete traverse;
                    return;
                }
                
            }
            else if(traverse->left && !traverse->right){
                //only left
                if(parent->left->data.name.compare(name)==0){
                    parent->left = traverse->left;
                    //delete traverse;
                    return;
                }
                else{
                    parent->right = traverse->left;
                    //delete traverse;
                    return;
                }
            }
            else if(!traverse->left && traverse->right){
                //only right
                if(parent->left->data.name.compare(name)==0){
                    parent->right = traverse->right;
                    //delete traverse;
                    return;
                }
                else{
                    parent->left = traverse->right;
                    //delete traverse;
                    return;
                }
            }
            else{
                //both
                node* temp = traverse->right;
                while(temp->left){
                    temp = temp->left;
                }
                temp->left = traverse->left;
                traverse->left = NULL;
                if(parent->left->data.name.compare(name)==0){
                    //l dir
                    
                    parent->left = traverse->right;
                    traverse->right = NULL;
                    traverse->left = NULL;
                    delete traverse;
                    traverse = NULL;
                    return;
                }
                else{
                    //r dir
                    
                    parent->right = traverse->right;
                    traverse->right = NULL;
                    traverse->left = NULL;

                    delete traverse;
                    traverse=NULL;
                    return;
                }
                
                
                
            }
        }
    }
    
}

    
    

void BST::add(node * newNode){
    node * traverse;
    traverse = root;
    phoneNode* traverseNum;
    phoneNode* newNum;
    int comparison;
    if (root == NULL){root = newNode;}
    else if(!search(newNode->data.name)){
        while(traverse){
            comparison = newNode->data.name.compare(traverse->data.name);
            if(comparison <0){
                if(traverse->left != NULL){
                    traverse = traverse->left;
                }
                else{
                    traverse->left = newNode;
                    break;
                }
                
            }
            else if(comparison > 0){
                if(traverse->right != NULL){
                    traverse = traverse->right;
                }
                else{
                    traverse->right = newNode;
                    break;
                }
                
            }
        }
    }
    else{
        traverse = search(newNode->data.name);
        traverseNum =traverse->data.number;
        if(traverseNum){
            while(traverseNum->next){
                traverseNum = traverseNum->next;
                
            }
            newNum = new phoneNode;
            newNum->phoneNum = newNode->data.number->phoneNum;
            traverseNum ->next = newNum;
        }
        else{
            newNum = new phoneNode;
            newNum->phoneNum = newNode->data.number->phoneNum;
            traverseNum = newNum;

            traverseNum = newNum;
        }
    }
}
void BST::print(node * p){
    if(p){
        print(p->left);
        cout<<p->data.name<<"--->>";
        phoneNode* traverseNum = p->data.number;
        while(traverseNum){
            cout<<traverseNum->phoneNum<<"|";
            traverseNum = traverseNum->next;
        }
        cout<<endl;
        print(p->right);
        
    }
    
}
using namespace std;
int main(int argc, const char * argv[]) {
    BST a;
    char operation = 'a';
    while(operation != 'e'){
        cout<<"Select operation {c,a,u,s,e}"<<endl;
        cin>>operation;
        switch (operation) {
            case 'c':{
                a.create();
                break;
            }
            case 'a':{
                node* newNode;
                newNode = new node;
                cout<<"Name:"; cin>>newNode->data.name;
                phoneNode* newNum = new phoneNode;
                cout<<"Number:";cin>>newNum->phoneNum;
                newNode->data.number = newNum;
                a.add(newNode);
                break;
            }
            case 'p':{
                a.print(a.root);
                break;
                
            }
            case 's':{
                string toSearch;
                cin>>toSearch;
                if(a.search(toSearch)){
                    node* search =  a.search(toSearch);
                    cout<< search->data.name<<"---->";
                    phoneNode* traverseNum = search->data.number;
                    while(traverseNum){
                        cout<<traverseNum->phoneNum<<"|";
                        traverseNum = traverseNum->next;
                    }
                }
                   else{cout<<"not found";}
            }
            case 'r':{
                string toRemove;
                cin>>toRemove;
                a.removeNode(toRemove);
                break;
            }
            case 'u':{
                string name;
                string newName;
                cout<<"name to update";
                cin>>name;
                phoneNode* headList = a.search(name)->data.number;
                node* updateNode = new node;
                cout<<"new name:";
                cin>>newName;
                updateNode->data.name = newName;
                updateNode->data.number = headList;
                a.removeNode(name);
                a.add(updateNode);
                break;
            }
            default:{
                break;
            }
        }
    }
    return 0;
}
