// Abdalla Fadl Shehata
// 20190305
// 3CS-S3
#include <iostream>
using namespace std;
/////////////////////////////////////////////////////////
struct Suffix{
    int ind;   // index of a suffix
    int r1 ;    // the current order of the suffix
    int r2 ;    // the order that will be used in case there is a tie in r1
};
//////////////////////////////////////////////////////////
// return true if the order of s1 < s2
bool compare(Suffix s1,Suffix s2) {
    if (s1.r1 == s2.r1){
            if ( s1.r2 < s2.r2 ){
                return true ;
            }
            else {
                return false ;
            }
    }
    else {
        if ( s1.r1 < s2.r1){
            return true ;
        }
        else {
           return false ;
        }
    }
}
///////////////////////////////////////////////////////////
void mergeFun(Suffix *suffix,int l,int mid,int r) {
    int len1 = mid-l+1;
    int len2 = r - mid;
    Suffix *leftPart, *rightPart;
    leftPart = new Suffix[len1];
    rightPart = new Suffix[len2];

    for (int i = 0; i < len1; i++) {
        leftPart[i] = suffix[i + l];
    }

    for (int i = 0; i < len2; i++) {
        rightPart[i] = suffix[i + mid + 1];
    }

    // merge the 2 arrays leftPart && rightPart to suffix array
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (compare(leftPart[i],rightPart[j])) {
            suffix[k] = leftPart[i];
            i++;
        } else {
            suffix[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        suffix[k++] = leftPart[i++];
    }

    while (j < len2) {
        suffix[k++] = rightPart[j++];
    }
}
//////////////////////////////////////////////////////////////////////
void mergeSort(Suffix *suffix,int l,int r){
    if(l>=r)
        return;
    int mid = (l+r-1)/2;
    mergeSort(suffix,l,mid);
    mergeSort(suffix,mid+1,r);
    mergeFun(suffix,l,mid,r);
}
////////////////////////////////////////////////////////////////////////
class SuffixArray{
    char* str; // input string
    int length = 0 ;
    int* res;
public:
    SuffixArray(char* input){
        str = input;
        int i = 0;
        while(str[i] != '\0'){
            i++;
            length++;
        }
        res = new int[length];
    }
    ///////////////////////////////////////////////////////////////////////
    void ConstructUsingPrefixDoubling(){
        struct Suffix suffixes[length];
        for(int i=0;i<length;i++){
            suffixes[i].ind=i;
            suffixes[i].r1= str[i]-'a';
            if((i+1)<length){
                suffixes[i].r2= str[i+1]-'a';
            }else{
                suffixes[i].r2= -1;
            }
        }
        // sort all suffixes according to first 2 characters
         mergeSort(suffixes,0,length-1);
        int m[length];
        for(int j=4;j<2*length;j=j*2){
            int rank=0;
            int rankP = suffixes[0].r1;
            suffixes[0].r1=rank;
            m[suffixes[0].ind]=0;
            for(int i=1;i<length;i++){
                if (suffixes[i].r1 == rankP && suffixes[i].r2 == suffixes[i-1].r2)
                {
                rankP = suffixes[i].r1;
                suffixes[i].r1 = rank;
                }
                else
                {
                    rankP = suffixes[i].r1;
                    rank++;
                    suffixes[i].r1 = rank;
                }
                m[suffixes[i].ind] = i;
            }
            for(int i=0;i<length;i++){
                int next=suffixes[i].ind+(j/2);
                if(next<length){
                    suffixes[i].r2=suffixes[m[next]].r1;
                }
                else{
                    suffixes[i].r2=-1;
                }
            }
            mergeSort(suffixes,0,length-1);
        }
        // store result
        for(int i=0;i<length;i++){
            res[i]=suffixes[i].ind;
        }
    }
    ////////////////////////////////////////////////////////////
    void Print(){
        for (int i = 0; i < length; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
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
