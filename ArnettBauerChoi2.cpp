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
#include<ctime>
#include<vector>

using namespace std;



void randomArray(int length, int A[]){      //assigns values to the inputted array.
    for(int k=0; k<length; k++){
        A[k]=length-k;
    }
    int temp;
    for(int k=0; k<length; k=k+2){
        temp=A[k+1];
        A[k+1]=A[k];
        A[k]=temp;
    }
    return;
}

void PrintArray(int length, int A[]){
    if(length>20){
        return;
    }
    std::cout << "Given: [";
    for(int i = 0; i < length-1; i++){
        std::cout << A[i] << ", ";
    }
    std::cout << A[length-1] << "]" << std::endl;

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

void vectorSelectSort(vector<int> A){//helper function for bucketsort
    int tempArray[A.size()];
    for(unsigned int k=0; k<A.size(); k++){   //make vector into array
        tempArray[k]=A[k];
    }
    A.clear();
    selectionSort(tempArray, A.size());
    for(unsigned int k=0; k<A.size(); k++){    //put sorted array into vector
        A.push_back(tempArray[k]);
    }
    return;
}

void QuickSort(int Array[], int first, int last){
    int i = first, j = last;
    int tmp;
    int pivot = Array[first + (last-first)/2];

    // partition
    while (i <= j) {
        while (Array[i] < pivot)
              i++;
        while (Array[j] > pivot)
              j--;
        if (i <= j) {
              tmp = Array[i];
              Array[i] = Array[j];
              Array[j] = tmp;
              i++;
              j--;
        }
    };

    // recursion
    if (first < j)
        QuickSort(Array, first, j);

    if (i < last)
        QuickSort(Array, i, last);
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
        //cout<<"SELECTION SORT USED"<<endl;
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

        cout<<"firstVec: ";
        for(unsigned int k=0; k<firstVector.size(); k++){
            cout<<firstVector[k];
        }

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
        for(int j=k+1; j<last; j++){
            if(A[k]==A[j]){
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

    selectionSort(A,last);//assuming bucket sort is the fastest
    for(int i=first; i<last; i++){
        if(A[i]==A[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
//        int Array[length];
//        cout << "Array has been initialized" << endl;
//        randomArray(length,Array);
/*        cout<<"Array: ";
        for(int k=0; k<length; k++){
            cout<<Array[k]<<"|";
        }
        cout<<endl;
//    cout << "After random generation" << endl;

        int bubbleArray[length];
        for(int k=0; k<length; k++){  //makes bubbleArray a copy of Array
            bubbleArray[k]=Array[k];
        }
        bubbleSort(bubbleArray, length);
        cout << "bubbleArray: ";
        for(int k=0; k<length; k++){
            cout<<bubbleArray[k]<<"|";
        }cout<<endl;

        int selectionArray[length];
        for(int k=0; k<length; k++){  //makes selectionArray a copy of Array
            selectionArray[k]=Array[k];
        }
        selectionSort(selectionArray, length);  // selection sort
        cout<<"selectionArray: ";
        for(int k=0; k<length; k++){
            cout<<selectionArray[k]<<"|";
        }cout<<endl;



        int QuickArray[length];
        for(int k=0; k<length; k++){  //makes QuickArray a copy of Array
            QuickArray[k]=Array[k];
        }
        QuickSort(QuickArray, 0, length-1);
        cout << "quickArray: ";
        for(int k=0; k<length; k++){
            cout<<QuickArray[k]<<"|";
        }
        cout << endl;
*//*
        for(int k=0; k<34; k++){
            int Array[length];
            randomArray(length,Array);

        clock_t    start1;

        start1 = std::clock();
        cout << "Before Algorithm 1" << std::endl;
        if(isUnique1(Array,0,length)==true){
            cout<<"Algorithm 1 says it is unique."<< endl;
        }
        cout << "After Algorithm 1" << std::endl;
        double time1=(std::clock() - start1) / (double)(CLOCKS_PER_SEC / 1000);
        cout<<"length of "<<length<<" time--> isUnique1: "<<time1/1000.0<<" sec"<<endl;
        }*/
/*
  for(int length=195000; length<=1000000; length=length+5000){
     int Array[length];
     randomArray(length,Array);
     std::clock_t    start2;

     start2 = std::clock();
     if(isUnique2(Array, 0, length)==true){
      cout<<"Algorithm 2 says it is unique."<< endl;
     }
     double time2=(std::clock() - start2) / (double)(CLOCKS_PER_SEC / 1000);
     cout<<"length of "<<length<<" time--> isUnique2: "<<time2/1000.0<<" sec"<<endl;
  }*/

  for(int length=150000; length<1000000; length=length+5000){
     int Array[length];
     randomArray(length,Array);
     std::clock_t    start3;

     start3 = std::clock();
     PrintArray(length,Array);
     if(isUnique3(Array, 0, length)==true){
      cout<<"Algorithm 3 says it is unique."<< endl;
     }
     double time3=(std::clock() - start3) / (double)(CLOCKS_PER_SEC / 1000);
     cout<<"length of "<<length<<" time--> isUnique3: "<<time3/1000.0<<" sec"<<endl;
  }

    return 0;
}
