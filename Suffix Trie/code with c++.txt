// Abdalla Fadl Shehata
// 20190305
// 3CS-S3
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////
 class linkedlistNode;
 class linkedlist;
 class TrieNode;
 class suffixTrie;
///////////////////////////////////////////////////////////
class linkedlistNode {
    public:
    TrieNode *data;
    linkedlistNode *next;
};
///////////////////////////////////////////////////////////
class linkedlist {
    private :
    linkedlistNode *root;
public:
    linkedlist(){
           root = nullptr;
    }

    linkedlistNode *getRoot(){
           return root;
    }

    linkedlistNode *getTail(){
           linkedlistNode *temp = root;
          while (temp->next != nullptr)
                     temp = temp->next;
           return temp;
    }

    void addNewNode(TrieNode *c){
        // first TrieNode insert  will insert in linked list
        if (root == nullptr) {
            root = new linkedlistNode;
            root->next = nullptr;
            root->data = c;
           return;
    }
    linkedlistNode *newNode = new linkedlistNode;
    newNode->next = nullptr;
    newNode->data = c;
    linkedlistNode *temp = root;
    while (temp->next != nullptr){
            temp = temp->next;
    }
    temp->next = newNode;
    }
};
///////////////////////////////////////////////////////////
class TrieNode {
    public :
    char c;
    linkedlist l;
};
//////////////////////////////////////////////////////////////
class suffixTrie {
    private :
    TrieNode *root;
    int length;
    char *str;    // char array

    int calculateSize(char *arr){
           int res = 0;
          for (int i = 0; arr[i] != '\0'; i++)
                 res++;
         return res;
    }

    TrieNode *insert2(char c, TrieNode *temp){
        char x = temp->c;
        linkedlistNode *loopNode = temp->l.getRoot();
        while (loopNode != nullptr) {
                if (loopNode->data->c == c) {
                        return loopNode->data;
                }
        loopNode = loopNode->next;
    }
    TrieNode *newTrieNode = new TrieNode;
    newTrieNode->c = c;
    temp->l.addNewNode(newTrieNode);
    temp = temp->l.getTail()->data;
    return temp;
    }

    void insert(char arr[], int index){
            TrieNode *temp = root;
            for (int i = index; i < length; i++) {
                    if (index == length - 1) {
                            TrieNode *newNode = new TrieNode;
                            newNode->c = arr[i];
                            root->l.addNewNode(newNode);
                            break;
            } else{
                            temp = insert2(arr[i], temp);
            }
        }
    }

public:

    suffixTrie(char *arr){
        str = arr;
        root = new TrieNode;
        root->c = 'o';
        length = calculateSize(arr);
        for (int i = length - 1; i >= 0; i--)
                insert(arr, i);
    }

    void Search(char *arr){
        TrieNode *temp2;
        int substringLength = calculateSize(arr);
        int nodeCounter = 0;
        TrieNode *temp = root;
        for (int i = 0; i < length; i++) {
            char x = str[i];
            linkedlistNode *loopNode = temp->l.getRoot();
            while (loopNode != nullptr) {
                temp2=temp;
                char y = loopNode->data->c;
                if (loopNode->data->c == str[i]) {
                    temp = loopNode->data;
                    if (loopNode->data->c == arr[nodeCounter]) {
                        if (substringLength > 1) {
                            if (nodeCounter == 1)
                                temp2 = temp;
                        }
                        nodeCounter++;
                    } else{
                        if(nodeCounter>1){
                            temp=temp2;
                            i--;
                        }
                        nodeCounter = 0;
                    }
                    break;
                }
                loopNode = loopNode->next;
            }
            if (nodeCounter == substringLength) {
                cout << i - nodeCounter + 1 << " ";
                i = i - nodeCounter + 1;
                nodeCounter = 0;
                temp = temp2;
            }
        }
        cout << endl;
        }

};
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
int main()
{

  // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //            0123456789012
    suffixTrie t("bananabanaba$");
    t.Search("ana"); // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8

    return 0;
}
