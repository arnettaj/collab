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
#include<vector>

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

void vectorSelectSort(vector<int> A){
    int tempArray[A.size()];
    for(unsigned int k=0; k<A.size(); k++){   //make vector into array
        tempArray[k]=A[k];
    }
    selectionSort(tempArray, A.size());
    for(unsigned int k=0; k<A.size(); k++){    //put sorted array into vector
        A[k]=tempArray[k];
    }
    return;
}

void bucketSort(int Array[], int length){
    int minni=Array[0];
    int maxxi=Array[0];
    for(int k=0; k<length; k++){
        if(Array[k]<minni){
            minni=Array[k];
        }
        if(Array[k]>maxxi){
            maxxi=Array[k];
        }
    }
    if(length<=20){
        selectionSort(Array,length);
        cout<<"SELECTION SORT USED"<<endl;
    }
    else{
        int fakerange=(maxxi-minni)-((maxxi-minni)%5);
        vector<int> firstVector;  //buckets
        vector<int> secondVector;
        vector<int> thirdVector;
        vector<int> fourthVector;
        vector<int> fifthVector;
        int firstMax=fakerange/5+minni;
        int secondMax=(fakerange/5)*2+minni;
        int thirdMax=(fakerange/5)*3+minni;
        int fourthMax=(fakerange/5)*4+minni;
        for(int k=0; k<length; k++){       //sorts the array into the buckets
            if(Array[k]<=firstMax){
                firstVector.push_back(Array[k]);
            }
            else if(Array[k]<=secondMax){
                secondVector.push_back(Array[k]);
            }
            else if(Array[k]<=thirdMax){
                thirdVector.push_back(Array[k]);
            }
            else if(Array[k]<=fourthMax){
                fourthVector.push_back(Array[k]);
            }
            else if(Array[k]>fourthMax){
                fifthVector.push_back(Array[k]);
            }
        }
        vectorSelectSort(firstVector);  //sorts the vectors with selection sort
        vectorSelectSort(secondVector);
        vectorSelectSort(thirdVector);
        vectorSelectSort(fourthVector);
        vectorSelectSort(fifthVector);

        int counter=0;
        for(unsigned int k=counter; k<firstVector.size(); k++){       //combines the vectors into the array
            Array[k]=firstVector[k];
        }
        counter=firstVector.size();
        for(unsigned int k=counter; k<counter+secondVector.size(); k++){
            Array[k]=secondVector[k];
        }
        counter=counter+secondVector.size();
        for(unsigned int k=counter; k<counter+thirdVector.size(); k++){
            Array[k]=thirdVector[k];
        }
        counter=counter+thirdVector.size();
        for(unsigned int k=counter; k<counter+fourthVector.size(); k++){
            Array[k]=fourthVector[k];
        }
        counter=counter+fourthVector.size();
        for(unsigned int k=counter; k<counter+fifthVector.size(); k++){
            Array[k]=fifthVector[k];
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
    for(int k=0; k<length; k++){  //makes selectionArray a copy of Array
        selectionArray[k]=Array[k];
    }
    selectionSort(selectionArray, length);  // selection sort

    int bucketArray[length];
    for(int k=0; k<length; k++){  //makes bucketArray a copy of Array
        bucketArray[k]=Array[k];
    }
    bucketSort(bucketArray, length);
    for(int k=0; k<length; k++){
        cout<<"bucket: "<<bucketArray[k]<<endl;
    }
    return 0;
}
