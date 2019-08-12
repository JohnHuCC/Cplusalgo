#include <iostream>
#include "sort.h"

int main() {
    int arr[6] = {15,9,8,1,4,11};
    int arr1[6] = {15,9,8,1,4,11};
    int arr2[6] = {15,9,8,1,4,11};
    int arr3[6] = {15,9,8,1,4,11};
    int arr4[16] = {0,2,5,6,3,2,5,9,5,2,15,9,8,1,4,11};
    vector<int> array_heap_sort(arr1,arr1+sizeof(arr1)/sizeof(int));
    vector<int> array_merge_sort(arr3,arr3+sizeof(arr3)/sizeof(int));
    vector<int> array_bucket_sort(arr4,arr4+sizeof(arr4)/sizeof(int));
    int size = sizeof(arr)/sizeof(int);
    int size_2 = sizeof(arr2)/sizeof(int);
    int size_3 = sizeof(arr3)/sizeof(int);
    int size_4 = sizeof(arr4)/sizeof(int);
    heap_sort(array_heap_sort);
    selection_sort(arr,size);
    quick_sort(arr2,0,size_2-1);
    merge_sort(array_merge_sort,0,size_3-1);
    bucket_sort(array_bucket_sort);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<array_heap_sort[i]<<", ";
    }
    cout<<endl;
    for(int i=0;i<size_2;i++){
        cout<<arr2[i]<<", ";
    }
    cout<<endl;
    cout<<"bucket: ";
    for(int i=0;i<size_4;i++){
        cout<<array_bucket_sort[i]<<", ";
    }
    cout<<endl;
    cout<<"merge: ";
    for(int i=0;i<size_3;i++){
        cout<<array_merge_sort[i]<<", ";
    }
    cout<<endl;


    return 0;
}