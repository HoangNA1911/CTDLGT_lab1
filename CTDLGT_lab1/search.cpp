#include <iostream>
using namespace std;

int linearSearch(int arr[],int n, int x){
    int i;
    for( i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}
int linearSearchSentinal(int arr[],int n, int x){
    int last=arr[n-1];
    arr[n-1]=x;
    int i=0;
    while(arr[i]!=x){
        i++;
    }
    arr[n-1]=last;
    if(arr[n-1]==x||i<n-1){
        return i;
    }
    return -1;
}
int binarySearch(int arr[],int n, int x){
    int last=n-1, first=0,middle;
    while(first<=last){
        middle=(first+last)/2;
        if(arr[middle]==x){
            return middle;
        }
        if(x>arr[middle]){
            first=middle+1;
        }
        else if(x<arr[middle]){
            last=middle-1;
        }
    }
    return -1;
}
int linearsearchpoint(int *a, int n, int key){
    for(int i=0;i<n;i++){
        if(*(a+i)==key){
            return i;
        }
    }
    return false;
}
int SentinelLinearSearch(int* a, int n, int key){
    int last=a[n-1];
    a[n-1]=key;
    int i=0;
    while(a[i]!=key){
        i++;
    }
    a[n-1]=last;
    if(a[n-1]==key||i<n-1){
        return i;
    }
    return -1;
}

int main(){
    int arr[6]={1,2,3,4,5,6};
    cout<<SentinelLinearSearch(arr,6,6);
    return 0;
}