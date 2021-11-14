#include<iostream>
using namespace std;


void merge(int arr[],int start,int end,int mid){
    int temp[end-start+1];
    int i=start,j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;k++;
        }
        else{
            temp[k]=arr[j];
            j++;k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;i++;
    }
    while(j<=end){
        temp[k]=temp[j];
        k++;j++;
    }
    
    for(int i=start;i<=end;i++){
        arr[i] = temp[i-start];
    }
}
void mergeSort(int arr[],int start,int end){// 7 6 5 4 3 2        3 = 6/2  2 = 5/2
    int mid = start+(end-start)/2;//2; 
    if(start<end){
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }
}
int main(){
    int arr[] = {7,6,5,4,3,2,n-1};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}