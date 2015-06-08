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

bool isUnique1(int A[], int first, int last){
    if(first>=last){
        return true;
    }
    if(!isUnique1(A, first, last-1)){
        return false;
    }
    if(!isUnique1(A, first+1, last)){
       return false;
    }
    return (A[first]!=A[last]);
}

bool isUnique2(int A[], int first, int last){
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

bool isUnique3(int A[], int first, int last){
    if(first>=last){
        return true;
    }
    //sorter(A, first, last);
    for(int i=first; i<last; i++){
        if(A[i]==A[i+1]){
            return false;
        }
    }
    return true;
}

void randomArray(int length, int A[]){      //assigns values to the inputted array.
    srand((unsigned)time(NULL));
    for(int k=0; k<length; k++){
        A[k]=rand() % (length*2) +1;
        cout<<"value given: "<<A[k]<<endl;
    }
    return;
}


void selectionSort(int tharray[], int length){   //selection sort
    int minni=0;
    int swapper;
    for(int j=0; j<length-1; j++){
        for(int k=j+1; k<length; k++){
            if(tharray[k]<tharray[minni]){
                minni=k;
            }
        }
        if(minni!=j){
            swapper=tharray[minni];
            tharray[minni]=tharray[j];
            tharray[j]=swapper;
        }
    }
    return;
}

void bubbleSort(int A[], int length){   //classic bubble sort
    bool done=false;
    int temp;
    while(!done){
        done=true;
        for(int k=1; k< length; k++){
            if(A[k]< A[k-1]){
                temp=A[k];
                A[k]=A[k-1];
                A[k-1]=temp;
                done=false;
            }
        }
    }
    return;
}


int main(){
    int length=20;
    int Array[length];
    randomArray(length,Array);
    int bubbleArray[length];
    for(int k=0; k<length; k++){  //makes bubbleArray a copy of Array
        bubbleArray[k]=Array[k];
    }
    bubbleSort(bubbleArray, length);

    int selectionArray[length];
    for(int k=0; k<length; k++){  //makes bubbleArray a copy of Array
        selectionArray[k]=Array[k];
    }
    selectionSort(selectionArray, length);  // selection sort
    for(int k=0; k<length; k++){
        cout<<"selection: "<<selectionArray[k]<<endl;
    }
    return 0;
}
