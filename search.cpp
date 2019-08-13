//
// Created by JohnnyHu on 2019-08-13.
//
#include "search.h"
string hash_open_address::search(int key) {
    int i = 0;
    while(i != size){
        int j = quadratic_probing(key,i);
        if(table[j].key == key){
            return table[j].val;
        }else{
            i++;
        }
    }
    return "data not found!\n";
}

void hash_open_address::delete_key(int key){
    int i=0;
    while(i != size){
        int j = quadratic_probing(key,i);
        if(table[j].key == key){
            table[j].key = 0;
            table[j].val = "";
            count--;
            return;
        }else{
            i++;
        }
    }
    cout<<"...data not found"<<endl;
}

void hash_open_address::insert(int key, string val) {
    int i=0;
    while(i != size){
        int j = quadratic_probing(key,i);
        if(table[j].key == 0){
            table[j].key = key;
            table[j].val = val;
            count++;
            return;
        }else{
            i++;
        }
    }
    cout<<"Overflow!!"<<endl;
}

int hash_open_address::quadratic_probing(int key,int i){
    return ((int)((key% size)+0.5*i+0.5*i*i)% size);
}

void hash_open_address::display() {
    for(int i=0;i<size;i++){
        cout<< "slot#" << i <<":("<<table[i].key<<","<<table[i].val<<")"<<endl;
    }
    cout<<endl;
}

//--------------------------------------------------------------
int binary_search_inf(int *arr, int val){
    if(arr[0]==val)return 0;
    else{
        int low = 1,up = 2,mid;
        while(arr[up]<val)low = up,up*=2;

        if(arr[up]== val)return up;
        while(low <= up){
            mid = (low + up)/2;
            if(arr[mid]== val)return mid;
            else if(arr[mid]>val)up = mid - 1;
            else low = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(int *A, int low, int up, int key)
{
    if(low <= up) {
        int mid = (low + up)/2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
            return binary_search_recursive(A, low, mid-1, key);
        else
            return binary_search_recursive(A, mid+1, up, key);
    }
    return -1;
}

int binary_search(int *arr,int end, int val){
    int left = 0,right = end-1;
    while(left < right){
        int mid = (left + right)/2;
        if(arr[mid]<val){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return right;
}

