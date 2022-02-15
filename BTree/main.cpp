// Abdalla Fadl Shehata
// 20190305
// 3CS-S3
#include <iostream>
using namespace std;
template<class T, int order>
///////////////////////////////////////////////////
class Node {
public:
    T *keys;
    int keysNumber;
    Node **childs;
    bool LeafNode;
     ///////////////////////////////////////////////
    Node(bool LeafNode = true) {
        this->LeafNode = LeafNode;
        keys = new T[order];
        childs = new Node<T, order> *[order + 1];
        keysNumber = 0;
        for (int i = 0; i <= order; i++){
            childs[i] = nullptr;
        }
    }
     ///////////////////////////////////////////////
    Node<T, order> *Insert(T key, Node<T, order> *node, Node<T, order> *root) {
        if (LeafNode) {
            int i = keysNumber-1;
            // sort keys in ascending order
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i+1] = key;
            keysNumber++;
        } else {// if not leafnode
            int i = 0;
            while (i < keysNumber && key > keys[i]) {
                i++;
            }
            childs[i]->Insert(key, this, root);
        }
        // IF Number of Keys is greater than order-1
        if (keysNumber == order) {
            if (this == root) {
                Node *temp = new Node<T, order>;
                temp->LeafNode= false;
                temp->childs[0] = this;
                temp->split(this);
                return temp;

            } // IF not root
            else {
                node->split(this);
            }
        }
        return root;
    }
     ///////////////////////////////////////////////
    void split(Node<T, order> *node) {
        Node *rightNode = new Node<T, order>();
        int idex = 0, middleIndex = (order - 1) / 2;
        T middleValue = node->keys[middleIndex];
        int numKeyNode = node->keysNumber;
        for (int i = middleIndex + 1; i < numKeyNode; i++) {
            rightNode->keys[idex] = node->keys[i];
            idex++;
            node->keysNumber = (node->keysNumber) - 1;
            rightNode->keysNumber = (rightNode->keysNumber) + 1;
        }
        if (!node->LeafNode) {
            int j = 0;
            for (int i = (order + 1) / 2; i <= order; i++) {
                rightNode->childs[j++] = node->childs[i];
            }
            rightNode->LeafNode = node->LeafNode;
        }
        int j = order - 1;
        while (childs[j] != node) {
            childs[j + 1] = childs[j];
            j--;
        }
        childs[j + 1] = rightNode;
        j = keysNumber;
        while (j > 0 && keys[j - 1] > middleValue) {
            keys[j] = keys[j - 1];
            j--;
        }
            keys[j] = middleValue;
            keysNumber++;
            node->keysNumber = (node->keysNumber) - 1;
      }
         ///////////////////////////////////////////////
        void print() {
        static int space = 0 ;
        for (int i = 1; i <= space; i++){
            cout <<" ";
        }
        for (int i = 0; i < keysNumber; ++i) {
            if (i != 0){
                cout<<",";
            }
            cout << keys[i] ;
        }
        cout<<endl;
        for (int i = 0; i <keysNumber+ 1; ++i) {
            if (childs[i] != nullptr){
                space++;
                childs[i]->print();
                space--;
            }
        }
    }
};
/////////////////////////////////////////////////////
template<class T, int order>
class BTree{
private:
    Node<T,order>*root;
public:
    BTree(){
        root = nullptr;
    }
     ///////////////////////////////////////////////
    void Insert(T key){
        if(root == nullptr){
            root=new Node<T,order>;
            root->keys[0]=key;
            root->keysNumber++;
        }
        else{
            root = root->Insert(key,root,root);
        }
    }
     ///////////////////////////////////////////////
    void Print(){
        if(root != nullptr){
            root->print();
        }
    }
    ///////////////////////////////////////////////
    ~BTree(){
            delete root;
    }
     ///////////////////////////////////////////////
};
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////////////////////////////////////////////////////////
int main(){

   // Abdalla Fadl Shehata
// 20190305
// 3CS-S3
#include <iostream>
using namespace std;
template<class T, int order>
///////////////////////////////////////////////////
class Node {
public:
    T *keys;
    int keysNumber;
    Node **childs;
    bool LeafNode;
     ///////////////////////////////////////////////
    Node(bool LeafNode = true) {
        this->LeafNode = LeafNode;
        keys = new T[order];
        childs = new Node<T, order> *[order + 1];
        keysNumber = 0;
        for (int i = 0; i <= order; i++){
            childs[i] = nullptr;
        }
    }
     ///////////////////////////////////////////////
    Node<T, order> *Insert(T key, Node<T, order> *node, Node<T, order> *root) {
        if (LeafNode) {
            int i = keysNumber-1;
            // sort keys in ascending order
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i+1] = key;
            keysNumber++;
        } else {// if not leafnode
            int i = 0;
            while (i < keysNumber && key > keys[i]) {
                i++;
            }
            childs[i]->Insert(key, this, root);
        }
        // IF Number of Keys is greater than order-1
        if (keysNumber == order) {
            if (this == root) {
                Node *temp = new Node<T, order>;
                temp->LeafNode= false;
                temp->childs[0] = this;
                temp->split(this);
                return temp;

            } // IF not root
            else {
                node->split(this);
            }
        }
        return root;
    }
     ///////////////////////////////////////////////
    void split(Node<T, order> *node) {
        Node *rightNode = new Node<T, order>();
        int idex = 0, middleIndex = (order - 1) / 2;
        T middleValue = node->keys[middleIndex];
        int numKeyNode = node->keysNumber;
        for (int i = middleIndex + 1; i < numKeyNode; i++) {
            rightNode->keys[idex] = node->keys[i];
            idex++;
            node->keysNumber = (node->keysNumber) - 1;
            rightNode->keysNumber = (rightNode->keysNumber) + 1;
        }
        if (!node->LeafNode) {
            int j = 0;
            for (int i = (order + 1) / 2; i <= order; i++) {
                rightNode->childs[j++] = node->childs[i];
            }
            rightNode->LeafNode = node->LeafNode;
        }
        int j = order - 1;
        while (childs[j] != node) {
            childs[j + 1] = childs[j];
            j--;
        }
        childs[j + 1] = rightNode;
        j = keysNumber;
        while (j > 0 && keys[j - 1] > middleValue) {
            keys[j] = keys[j - 1];
            j--;
        }
            keys[j] = middleValue;
            keysNumber++;
            node->keysNumber = (node->keysNumber) - 1;
      }
         ///////////////////////////////////////////////
        void print() {
        static int space = 0 ;
        for (int i = 1; i <= space; i++){
            cout <<" ";
        }
        for (int i = 0; i < keysNumber; ++i) {
            if (i != 0){
                cout<<",";
            }
            cout << keys[i] ;
        }
        cout<<endl;
        for (int i = 0; i <keysNumber+ 1; ++i) {
            if (childs[i] != nullptr){
                space++;
                childs[i]->print();
                space--;
            }
        }
    }
};
/////////////////////////////////////////////////////
template<class T, int order>
class BTree{
private:
    Node<T,order>*root;
public:
    BTree(){
        root = nullptr;
    }
     ///////////////////////////////////////////////
    void Insert(T key){
        if(root == nullptr){
            root=new Node<T,order>;
            root->keys[0]=key;
            root->keysNumber++;
        }
        else{
            root = root->Insert(key,root,root);
        }
    }
     ///////////////////////////////////////////////
    void Print(){
        if(root != nullptr){
            root->print();
        }
    }
    ///////////////////////////////////////////////
    ~BTree(){
            delete root;
    }
     ///////////////////////////////////////////////
};
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
////////////////////////////////////////////////////////
int main(){

   // Construct a BTree of order 3, which stores int data
    BTree<int,3> t1;
    t1.Insert(1);
    t1.Insert(5);
    t1.Insert(0);
    t1.Insert(4);
    t1.Insert(3);
    t1.Insert(2);
    t1.Print(); // Should output the following on the screen:
    /*
    1,4
      0
      2,3
      5
    */
    // Construct a BTree of order 5, which stores char data
    BTree<char,5> t;
    // Look at the example in our lecture:
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');
    t.Print(); // Should output the following on the screen:
    /*
    K
      C,G
        A,B
        D,E,F
        H,I,J
      N,R
        L,M
        P,Q
        S,T
    */

    return 0 ;
}
