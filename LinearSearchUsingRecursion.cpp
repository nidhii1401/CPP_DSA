#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int key){
    // Base Case
    if (size == 0) return false;
    if(arr[0]== key) return true;
    else{
        bool remaining = LinearSearch(arr+1, size-1, key);
        return remaining;
    }    
}

int main(){

    int arr[5] = {2,4,5,6,8};
    int size = 5;
    int key = 10;

    int ans = LinearSearch(arr,5,8);
    if(ans) cout << "Present" << endl;
    else  cout << "Not Present" << endl;
        
}