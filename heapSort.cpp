#include <iostream>

using namespace std; 
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify(int arr[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest])
        largest = l;
    if(r<n && arr[r]>arr[largest])
        largest = r;
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    for(int i=n-1;i>=0;i--){
        swap(&arr[i],&arr[0]);
        heapify(arr,i,0);
    }
}

int main()
{
    cout<<"Hello World";
    
    int arr[]={6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    
    
    heapsort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    
    return 0;
}
