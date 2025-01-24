/*



Exercise 3-1. Our binary search makes two tests inside the loop, 
when one would suffice (at the price of more tests outside.) 
Write a version with only one test inside the loop and measure 
the difference in run-time.
*/
#include <stdio.h>

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] 
int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else // found match
            return mid;
    }
    return -1; // no match 
}

int better_binsearch(int x, int v[], int n){
    //edit this one!
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else // found match
            return mid;
    }
    return -1; // no match 
}

int main(){

    return 0;
}
