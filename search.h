//
// Created by JohnnyHu on 2019-08-13.
//

#ifndef ALGORHITHMS_search_H
#define ALGORHITHMS_search_H
#include <iostream>
#include <string>

using namespace std;

struct dict{
    int key;
    string val;
    dict():key(0),val(""){};
    dict(int k,string s):key(k),val(s){};
};

class hash_open_address{
private:
    int size,count;
    dict *table;

    int quadratic_probing(int key,int i);
public:
    hash_open_address():size(0),count(0),table(0){}; //struct initialize?
    hash_open_address(int m):size(m),count(0){
        table = new dict[size];
    }
    void insert(int key,string val);
    void delete_key(int key);
    string search(int key);
    void display();
};

int binary_search_inf(int *arr, int val);
int binary_search_recursive(int *A, int low, int up, int key);
int binary_search(int *arr,int end, int val);
#endif //ALGORHITHMS_search_H
