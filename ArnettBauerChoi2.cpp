/*
Authors: Austin Arnett, Aaron Choi, Brian Bauer
Course: Data Structures
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract:  The program times 3 different algorithms for checking different sized arrays for repeated elements.
Preconditions:  none
Postconditions: returns a table with the times of the different algorithms on different sized arrays.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

bool isUnique1(int[] A, first, last){
    if(first>=last){
        return true;
    }
    if(!isUnique1(A, first, last-1){
        return false;
    }
    if(!isUnique1(A, first+1, last){
       return false;
    }
    return (A[first]!=A[last]);
}

bool isUnique2(int[] A, first, last){
    if(first>=last){
        return true;
    }
    for(int k=first; k<last; k++){
        for(int j=k+1; j<=last; j++){
            if(A[first]==A[last]){
                return false;
            }
        }
    }
    return true;
}

bool isUnique3(int[] A, first, last){
    if(first>=last){
        return true;
    }
    sorter(A, first, last);
    for(int i=first; i<last; i++){
        if(A[i]==a[i+1]){
            return false;
        }
    }
    return true;
}

int * randomArray(int length){
    srand(time(NULL));
    int newarray[length];
    rand();
    for(int k=0; k<length; k++){
        newarray[k]=rand() % length +1;
    }
    return newarray;
}


int * selectionSort(int tharray[], int length){
    int minni=0;
    int j;
    int k;
    int swapper;
    for( j=0; j<length; j++){
        for(k=0; k<length; k++){
            if(tharray[k]<tharray[minni]){
                k=minni;
            }
        }
        if(minni!=j){
            swapper=tharray[minni];
            tharray[minni]=tharray[j];
            tharray[j]=swapper;
        }
    }
    return tharray;
}

int main(){


    return 0;
}
