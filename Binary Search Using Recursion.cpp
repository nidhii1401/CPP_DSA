#include <iostream>
using namespace std;



bool BinarySearch(int arr[],int start, int end, int key){

    int mid = start + ((end-start)/2);


    // Base case 
     if(start > end)
        return false;

     // Founded the element 
     if(arr[mid] == key)
        return true;

    if (arr[mid] < key)
    {
      return BinarySearch(arr,mid+1,end , key);
    }
    else{
        return BinarySearch(arr,start,mid-1,key);
    }
}

int main(){

    int arr[6] = {2,4,6,10,14,16};
    int size =  sizeof(arr)/sizeof(arr[0]);
    int key = 16;
    int start = 0;
    int end = size-1;

    int ans = BinarySearch(arr , start, end, key);
    if (ans)
        cout << "Key is found" << endl;
    else
        cout<< "Key not found" << endl;

    return 0;
}