#include<iostream>
using namespace std;


int binarys(int arr[],int l,int h,int key){
    while(l<h){
        int mid = h + (h-l)/2;
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            return binarys(arr,l,mid-1,key);
        }
        return binarys(arr,mid+1,h,key);
    }
    return -1;
}