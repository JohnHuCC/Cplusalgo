//
// Created by JohnnyHu on 2019-08-12.
//

#ifndef ALGORHITHMS_SORT_H
#define ALGORHITHMS_SORT_H
#include <iostream>
#include <vector>
using namespace std;
void bucket_sort(vector<int> &arr);
void merge(vector<int> &arr,int front, int mid,int end);
void merge_sort(vector<int> &arr, int front,int end);
void swap(int &a,int &b);
int partition(int *arr,int front,int end);
void quick_sort(int *arr, int front, int end);
void max_heapify(vector<int> &arr,int root, int size);
void build_max_heap(vector<int> &arr);
void heap_sort(vector<int> &arr);
void selection_sort(int *arr,int arr_size);
void insertion_sort(int *arr,int arr_size);
#endif //ALGORHITHMS_SORT_H
