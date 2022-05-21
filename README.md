# Advanced_Data_Structures_Implementation
Implementation of some data structures like BTree, suffix trie and suffix array

***************************************************************************************************
Assignment 1  ( BTree )

* Implement a BTree data structure as described in our lecture with O(n) space and O(log n) Insert() and O(n) Print() operations.
* Use only standard C++, such that the following main() works. You are not allowed to modify the main().
* Your coding style must follow exactly the coding style specified in CodingStyle.pdf.
* Your code must be general and works for other data types and orders.
* You can assume that the number of levels in the BTree will not exceed 50.
* You are not allowed to include any files or built-in libraries, except for output.
* Do not write the main() again in your submission.

int main()
{
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
    return 0;
}

***************************************************************************************************
Assignment 2  ( Suffix Trie )


***************************************************************************************************
Assignment 2  ( Suffix Array )





