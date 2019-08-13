#include <iostream>
#include "sort.h"
#include "search.h"
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
    cout<<"sort"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"selection: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<endl;
    cout<<"heap: ";
    for(int i=0;i<size;i++){
        cout<<array_heap_sort[i]<<", ";
    }
    cout<<endl;
    cout<<"quick: ";
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
    cout<<endl<<endl;
    cout<<"hash search"<<endl;
    cout<<"----------------------------------"<<endl;
    hash_open_address hash(8);          // probing sequence:
    hash.insert(33, "blue");          // 1,2,4,7,3,0,6,5 -> 1
    hash.insert(10, "yellow");        // 2,3,5,0,4,1,7,6 -> 2
    hash.insert(77, "red");           // 5,6,0,3,7,4,2,1 -> 5
    hash.insert(2, "white");          // 2,3,5,0,4,1,7,6 -> 3
    hash.display();
    hash.insert(8, "black");          // 0,1,3,6,2,7,5,4 -> 0
    hash.insert(47, "gray");          // 7,0,2,5,1,6,4,3 -> 7
    hash.insert(90, "purple");        // 2,3,5,0,4,1,7,6 -> 4
    hash.insert(1, "deep purple");    // 4,5,7,2,6,3,1,0 -> 6
    hash.display();
    hash.insert(15, "green");         // hash table overflow

    cout << "number#90 is " << hash.search(90) << "\n\n";

    hash.delete_key(90);
    cout << "after deleting (90,purple):\n";
    cout << "number#90 is " << hash.search(90) << "\n";

    hash.insert(12, "orange");        // 4,5,7,2,6,3,1,0 -> 4
    hash.display();
    cout<<"binary search"<<endl;
    cout<<"----------------------------------"<<endl;
    int array[17] = {6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97,99,100};
    printf("%d\n", binary_search(array, 15, 53));    // 10 50 60
    printf("%d\n", binary_search_recursive(array,0,14,14));
    printf("%d\n", binary_search_inf(array,93));

    return 0;
}