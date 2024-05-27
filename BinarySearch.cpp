#include <iostream>
using namespace std;

int BinarySearch(int arr[],int size, int key){
    int start = 0;
    int end= size-1;
    while (start <= end){   
        int mid =  start +(end-start)/2; 
        if (arr[mid]==key) return mid;
        if (key<arr[mid])  end = mid -1;
        else start=mid+1;   
    }
    return -1;
}

int main(){

    int even[8]= {2,4,6,7,8,12,56,78};
    int odd[7]= {2,5,6,7,13,15,18};

    int index1 =  BinarySearch(even, 8, 78);
    int index2= BinarySearch(odd, 7, 15);

    cout << "Index of 78 is " << index1 << endl;
    cout << "Index of 15 is " << index2;

    return 0;
}