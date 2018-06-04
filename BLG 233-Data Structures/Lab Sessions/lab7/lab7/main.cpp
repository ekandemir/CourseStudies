#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cctype>
#define RIGHT   1
#define LEFT    2
#define UP      3
#define DOWN    4

using namespace std;


typedef struct d{
    int x;
    int y;
    int right;
    int left;
    int down;
    int up;
    int camefrom;
}StackDataType, position;

struct Node{
    StackDataType data;
    Node *next;
};

struct Stack{
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
}

StackDataType Stack::pop(){
    Node *topnode;
    StackDataType temp;
    topnode = head;
    head = head->next;
    temp = topnode->data;
    delete topnode;
    return temp;
}

bool Stack::isEmpty(){
    return head == NULL;
}

void printlab(char l[22][22]) {
    for (int i = 0; i < 22; i++) {
        for (int j = 0; j < 22; j++)
            cout << l[i][j];
        cout << endl;
    }
    cout << endl << endl;
}


char lab[22][22]={  {"  ###################"},
                    {"# ###################"},
                    {"# ###################"},
                    {"#         ###########"},
                    {"### #################"},
                    {"### #################"},
                    {"###          ########"},
                    {"############ ########"},};

int main(){
    Stack s;
    s.create();
    position entrance = {0,1,0,0,0,0,0};
    position exit = {13,7,0,0,0,0,0};
    position p = entrance;
    p.camefrom = LEFT;
    printlab(lab);
    bool goback = false;
    while (p.x != exit.x || p.y != exit.y) {
        lab[p.y][p.x]='o';
        printlab(lab);
        //first find in how many directions we can move
        if (!goback) { //if not calculated before
            p.right = 0;
            p.left = 0;
            p.down = 0;
            p.up = 0;
            if (p.x<7 && lab[p.y][p.x+1]!='#') p.right=1;//right
            if (p.x>0 && lab[p.y][p.x-1]!='#') p.left=1;//left
            if (p.y<7 && lab[p.y+1][p.x]!='#') p.down=1;//down
            if (p.y>0 && lab[p.y-1][p.x]!='#') p.up=1;//up
        }
        else
            goback = false;
        bool moved = true;
        position past = p;
        if (p.down && p.camefrom != DOWN)  {
            p.y++;
            p.camefrom = UP;
            past.down = 0;
        }
        else if (p.up && p.camefrom != UP) {
            p.y--;
            p.camefrom = DOWN;
            past.up = 0;
        }
        else if (p.left && p.camefrom != LEFT) {
            p.x--;
            p.camefrom = RIGHT;
            past.left = 0;
        }
        else if (p.right && p.camefrom != RIGHT) {
            p.x++;
            p.camefrom = LEFT;
            past.right = 0;
        }
        else moved = false;
        
        if (p.x != exit.x || p.y != exit.y) {
            if ( (p.down + p.up + p.right + p.left) > 2) {
                //there is more than one choice, push onto stack and
                //continue in that chosen direction. Let the choices
                //you have not selected remain marked on the stack.
                s.push(past);
            }
            if (!moved) {
                // has to go back
                if ( !s.isEmpty() ) {
                    p = s.pop();
                    goback = true;
                }
            }
        }
    }//end of while
    lab[p.y][p.x] = 'o';
    printlab(lab);
    cout << "PATH found" << endl;
    s.close();
    return EXIT_SUCCESS;
}

