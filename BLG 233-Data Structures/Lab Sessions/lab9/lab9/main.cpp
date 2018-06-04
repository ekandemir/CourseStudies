#include <iostream>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;
const int N = 7;
int randgen(int i) {return rand() % i;}

struct node {
    int data;
    node* left;
    node* right;
    void setnull();
};

struct holder {
    node* parent;
    int dir;
};

void node::setnull()
{
    left = NULL;
    right = NULL;
}

struct tree {
    node* root;
    void init();
    void createTree();
    void removeTree(node* p);
    void printPreorder(node* p);
    void printInorder(node* p);
    void printPostorder(node* p);
    int findMax(node* p, int& mx);
    int findMin(node* p, int& mn);
    int findNumNode(node* p);
    int findNumLeaf(node* p);
    int findDepth(node* p);
    int calculateSum(node* p);
    float calculateAverage(node* p);
};

void tree::init()
{
    root = NULL;
}

void tree::createTree()
{
    // generate random array array
    int array[N];
    for (int i = 0; i < N; i++) array[i] = i + 1;
    random_shuffle(&array[0], &array[N], randgen);
    
    // assign root
    root = new node;
    root->setnull();
    root->data = array[0];
    
    // add directions to queue
    queue<holder> order;
    order.push({root, 0});
    order.push({root, 1});
    
    for (int i = 1; i < N; i++) {
        holder next = order.front(); order.pop();
        node* p;
        switch (next.dir) {
            case 0:
                next.parent->left = new node;
                p = next.parent->left;
                break;
            case 1:
                next.parent->right = new node;
                p = next.parent->right;
                break;
        }
        p->setnull();
        p->data = array[i];
        order.push({p, 0});
        order.push({p, 1});
    }
    
    while (!order.empty()) order.pop();
    return;
}

void tree::removeTree(node* p)
{
    if (p) {
        removeTree(p->left);
        removeTree(p->right);
        delete p;
    }
}

void tree::printPreorder(node* p)
{
    if (p) {
        cout << p->data << " - ";
        printPreorder(p->left);
        printPreorder(p->right);
    }
}

void tree::printInorder(node* p)
{
    if (p) {
        printInorder(p->left);
        cout << p->data << " - ";
        printInorder(p->right);
    }
}

void tree::printPostorder(node* p)
{
    if (p) {
        printPostorder(p->left);
        printPostorder(p->right);
        cout << p->data << " - ";
    }
}

int tree::findMax(node* p, int& mx)
{
    if (p) {
        if (mx < p->data) mx = p->data;
        findMax(p->left, mx);
        findMax(p->right, mx);
    }
    return mx;
}

int tree::findMin(node* p, int& mn)
{
    if (p) {
        if (mn > p->data) mn = p->data;
        findMin(p->left, mn);
        findMin(p->right, mn);
    }
    return mn;
}

int tree::findNumNode(node* p)
{
    if (p == NULL) return 0;
    return 1 + findNumNode(p->left) + findNumNode(p->right);
}

int tree::findNumLeaf(node*p)
{
    if (p == NULL) return 0;
    else if (p->left == NULL && p->right == NULL) return 1;
    return findNumLeaf(p->left) + findNumLeaf(p->right);
}

int tree::findDepth(node* p)
{
    if (p == NULL) return 0;
    int l = findDepth(p->left);
    int r = findDepth(p->right);
    if (l > r) return l + 1;
    else return r + 1;
}

int tree::calculateSum(node* p)
{
    if (p == NULL) return 0;
    return p->data + calculateSum(p->left) + calculateSum(p->right);
}

float tree::calculateAverage(node* p)
{
    return calculateSum(p) / (float)findNumNode(p);
}

void menu()
{
    cout << "0.   close" << endl;
    cout << "1.   createTree" << endl;
    cout << "2.   removeTree" << endl;
    cout << "3.   printPreorder" << endl;
    cout << "4.   printInorder" << endl;
    cout << "5.   printPostorder" << endl;
    cout << "6.   findMax" << endl;
    cout << "7.   findMin" << endl;
    cout << "8.   findNumNode" << endl;
    cout << "9.   findNumLeaf" << endl;
    cout << "10.  findDepth" << endl;
    cout << "11.  calculateSum" << endl;
    cout << "12.  calculateAverage" << endl;
}

int main() {
    srand(time(NULL));
    tree lol;
    lol.init();
    bool isCreated = false;
    bool cont = true;
    int input;
    int min, max;
    
    while (cont) {
        menu();
        if (!isCreated) {cout << "PLEASE CREATE TREE FIRST" << endl;}
        
        
        
        cin >> input;
        
        switch (input) {
            case 0:
                cont = false;
                lol.removeTree(lol.root);
                lol.init();
                isCreated = false;
                break;
            case 1:
                lol.createTree();
                isCreated = true;
                cout << "TREE CREATED" << endl;
                break;
            case 2:
                lol.removeTree(lol.root);
                lol.init();
                isCreated = false;
                cout << "TREE REMOVED" << endl;
                break;
            case 3:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                lol.printPreorder(lol.root);
                cout << endl << endl;
                break;
            case 4:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                lol.printInorder(lol.root);
                cout << endl << endl;
                break;
            case 5:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                lol.printPostorder(lol.root);
                cout << endl << endl;
                break;
            case 6:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                max = 0;
                cout << lol.findMax(lol.root, max) << endl;
                break;
            case 7:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                min = N + 1;
                cout << lol.findMin(lol.root, min) << endl;
                break;
            case 8:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                cout << lol.findNumNode(lol.root) << endl;
                break;
            case 9:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                cout << lol.findNumLeaf(lol.root) << endl;
                break;
            case 10:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                cout << lol.findDepth(lol.root) << endl;
                break;
            case 11:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                cout << lol.calculateSum(lol.root) << endl;
                break;
            case 12:
                if (!isCreated) {
                    cout << "PLEASE CREATE TREE FIRST" << endl;
                    break;
                }
                cout << lol.calculateAverage(lol.root) << endl;
                break;
        }
    }
    return 0;
}


void creation_menu()
{
    cout << "0.   close" << endl;
    cout << "1.   createTree" << endl;
}
