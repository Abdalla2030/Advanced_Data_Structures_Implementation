# Advanced_Data_Structures_Implementation
Implementation of some data structures like B-Tree, suffix trie and suffix array

***************************************************************************************************
### Assignment-1  ( B-Tree )

* Implement a BTree data structure as described in our lecture with O(n) space and O(log n) Insert() and O(n) Print() operations.
* Use only standard C++, such that the following main() works. You are not allowed to modify the main().
* Your coding style must follow exactly the coding style specified in CodingStyle.pdf.
* Your code must be general and works for other data types and orders.
* You can assume that the number of levels in the BTree will not exceed 50.
* You are not allowed to include any files or built-in libraries, except for output.

## Example 
```
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
    return 0;
}
```
***************************************************************************************************
### Assignment-2  ( Suffix Trie )

* Implement a Suffix Trie data structure as described in our lecture with Search() operation for any substring.
* Each node in the trie must contain a linked list where each list element contains a character and child node pointer.
* Other methods are not allowed.
* Use your implementation of linked list. Do not use string class, use char arrays.
* Your code must be general to handle any indexed string or query.
* Use only standard C++, such that the following main() works. You are not allowed to modify the main().
* You are not allowed to include any files or built-in libraries, except for output.

## Example 
```
int main(){
    // Construct a suffix trie containing all suffixes of "bananabanaba$"    
    //            0123456789012    
    SuffixTrie t("bananabanaba$");   
    t.Search("ana"); // Prints: 1 3 7  
    t.Search("naba"); // Prints: 4 8    
    return 0;
}
```
***************************************************************************************************
### Assignment-3  ( Suffix Array )

* Implement a Suffix Array prefix doubling O(n (log n)^2) construction algorithm as described in our lecture.
* Do not use string class, use char arrays.
* Your code must be general to handle any string.
* Use standard C++, such that the following main() works. You are not allowed to modify the main().
* You are not allowed to include any files or built-in libraries, except for output.

Use the following method to construct the suffix array:
* Construct an array such that each element contains 3 integers:
   - ind: index of a suffix.
   - r1: the current order of the suffix.
   - r2: the order that will be used in case there is a tie in r1.
* At each stage, do the following:
   - Sort the above array using <r1,r2>.
   - Move sequentially on the array elements to update r1 for each element.
   - Sort the above array using ind.
   - Move sequentially on the array elements to update r2 for each element.
   
 ## Example 
```
int main(){
    SuffixArray t("ACGACTACGATAAC$");    
    t.ConstructUsingPrefixDoubling();   
    t.Print(); // Prints:  14 11 12  0  6  3  9 13  1  7  4  2  8 10  5   
    return 0;
}
// The following is just illustration for your help only, nothing required about it. Check lecture.
///////////////////////////////////////////////////////////////////////////////////////////////////
// i      0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
// t      A  C  G  A  C  T  A  C  G  A  T  A  A  C  $
// --------------------------------------------------
// k=0    1  2  3  1  2  4  1  2  3  1  4  1  1  2  0
// k=1    2  5  7  2  6  8  2  5  7  3  8  1  2  4  0
// k=2    3  7 10  4  9 13  3  8 11  5 12  1  2  6  0
// k=4    3  8 11  5 10 14  4  9 12  6 13  1  2  7  0
// sa=   14 11 12  0  6  3  9 13  1  7  4  2  8 10  5

///////////////////////////////////////////////////////////////////////////////////////////////////
```
