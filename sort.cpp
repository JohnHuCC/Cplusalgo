//
// Created by JohnnyHu on 2019-08-12.
//
#include "sort.h"
#include <iostream>
#include <vector>
using namespace std;
//----------------------------------------------------------
void bucket_sort(vector<int> &arr){
    int length = arr.size();
    vector<int> buckets(length,0);

    for(int i=0;i<length;i++){
        buckets[arr[i]]++;
    }
    int index = 0;
    for(int i=0;i<length;i++){
        for(int j=0;j<buckets[i];j++){
            arr[index++] = i;
        }
    }
}

//----------------------------------------------------------
const int Max = 0x3f3f3f;
void merge(vector<int> &arr,int front, int mid,int end){
    vector<int> left_sub(arr.begin()+front,arr.begin()+mid+1),
            right_sub(arr.begin()+mid+1,arr.begin()+end+1);
    left_sub.insert(left_sub.end(),Max);
    right_sub.insert(right_sub.end(),Max);

    int index_left = 0,index_right = 0;

    for(int i=front; i<=end;i++){
        if(left_sub[index_left] <= right_sub[index_right]){
            arr[i] = left_sub[index_left];
            index_left++;
        }else{
            arr[i] = right_sub[index_right];
            index_right++;
        }
    }
}

void merge_sort(vector<int> &arr, int front,int end){
    if(front < end){
        int mid = (front+end)/2;
        merge_sort(arr,front,mid);
        merge_sort(arr,mid+1,end);
        merge(arr, front, mid, end);
    }
}
//----------------------------------------------------------
void swap(int &a,int &b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}

int partition(int *arr,int front,int end){
    int pivot = arr[end];
    int i = front-1;
    for(int j = front;j < end; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[end]);
    return i;
}

void quick_sort(int *arr, int front, int end){
    if(front<end){
        int pivot = partition(arr,front,end);
        quick_sort(arr,front,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}
//----------------------------------------------------------
void max_heapify(vector<int> &arr,int root, int size){
    int left = 2*root;
    int right = 2*root+1;
    int largest = 0;

    if(left <= size && arr[left] > arr[root]){
        largest = left;
    }else{
        largest = root;
    }

    if(right <= size && arr[right]>arr[largest]) largest = right;

    if(largest!=root){
        swap(arr[largest],arr[root]);
        max_heapify(arr,largest,size);
    }

}

void build_max_heap(vector<int> &arr){
    for(int i=arr.size()/2;i>=1;i--){
        max_heapify(arr,i,arr.size()-1);
    }
}

void heap_sort(vector<int> &arr){
    arr.insert(arr.begin(),0);
    build_max_heap(arr);
    int size = arr.size()-1;
    for(int i = arr.size()-1;i>=2;i--){
        swap(arr[1],arr[i]);
        size--;
        max_heapify(arr,1,size);
    }
    arr.erase(arr.begin());
}

//----------------------------------------------------------
void selection_sort(int *arr,int arr_size){
    int smallest_pos = 0;
    for(int i=0;i<arr_size;i++){
        smallest_pos = i;
        for(int j=i+1;j<arr_size;j++){
            if(arr[j]<arr[smallest_pos]){
                smallest_pos = j;
            }
        }
        swap(arr[i],arr[smallest_pos]);
    }
}

//----------------------------------------------------------

void insertion_sort(int *arr,int arr_size){
    for(int i=1;i<arr_size;i++){
        int key = arr[i];
        int j = i-1;
        while(key<arr[j] && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

