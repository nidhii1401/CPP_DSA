#include <iostream>
using namespace std;

int Partition(int *arr,int s, int e){
    int pivot = arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
        int PivotIndex = s+cnt;
        swap(arr[s],arr[PivotIndex]);

        // Left and right array ko sambhal lete hai

        int a=s, b=e;
        while(a < PivotIndex && b > PivotIndex){

            while(arr[a] < pivot){
                a++;
            }
            while(arr[b] > pivot){
                b++;
            }
            if(a < PivotIndex && b > PivotIndex){
                swap(arr[a++],arr[b--]);
            }
        }

    return PivotIndex;
    


}

void QuickSort(int *arr,int s,int e ){

    //Base Case
    if(s>=e){
        return;
    }
    //partion krdo
    int p = Partition(arr,s,e);

    // Recursive Calls
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);


}

int main(){

    int arr[7] = {34,45,2,31,67,89,4};
    int n =7;

    QuickSort(arr,0,n-1);
    for(int i =0; i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}