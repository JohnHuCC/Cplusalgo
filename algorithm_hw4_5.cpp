#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <fstream>
#define SWAP(x,y) int tmp=x;x=y;y=tmp;
#define TLETime 300
using namespace std;
int SSTLEDataNumber=-1;
void CopyArray(int*,int*,int);
float SelectionSort(int*,int);
float MergeSort(int*,int);
float RadixSort(int*,int);
int QCompare(const void*,const void*);
float QSort(int*,int);
float StdSort(int*,int);
void RandomValue(size_t size);
string Num2StdString(int);
template<class T>void swap(T *a,T *b);
template<class T>void Adjust(T *a,const int root,const int n);
template<class T>void HeapSort(T *a,const int n);
float HeapSort_OutputB(int *data,int amount);
int main(){
	srand(time(NULL));
    int createNumber=0;
    string fileName;
    while(1){
        cout<<"Input data number: ";
        cin>>createNumber;
        if(createNumber!=0){
        	 fileName="_"+Num2StdString(createNumber)+".txt";
	       		 fstream ofs;
	        ofs.open(fileName.c_str(),ios::out);
	        ofs<<createNumber<<endl;
	        while(createNumber--){
	            ofs<<rand()<<endl;
	        }
	        ofs.close();
	        cout<<"["<<fileName<<"] Success"<<endl;
		}else{
			break;
		}
  
    }
//	RandomValue(amount);
    fstream ifs;
    string us_fileName[10]={"_100.txt","_500.txt","_1000.txt","_5000.txt","_10000.txt","_50000.txt","_100000.txt","_500000.txt","_1000000.txt"};
    int fileNumbers,c,j;
    int* data;
    int* tmpData;
    int dataNumber;
    float getTime;
    
    fileNumbers=10;
    c=0;
    while(fileNumbers--){
        cout<<"Now processing: "<<us_fileName[c]<<endl;
        ifs.open(us_fileName[c].c_str(),ios::in);
        if(ifs){
            ifs>>dataNumber;
            cout<<"Get data length: "<<dataNumber<<endl;
            data=new int[dataNumber];
            tmpData=new int[dataNumber];
            cout<<"Now inputing data... ";
            j=0;
            while(j<dataNumber&&ifs>>tmpData[j]){
                j++;
            }
            cout<<"(Success)"<<endl;
            ifs.close();
            ///-----
            CopyArray(tmpData,data,dataNumber);
//            cout<<"Now sorting data(Selection Sort)... ";
//            getTime=SelectionSort(data,dataNumber);
//            if(getTime!=-1){
//                cout<<"use "<<getTime<<" seconds"<<endl;
//            }else{
//                cout<<"*** TLE ***"<<endl;
//            }
            ///-----
            ///-----
            CopyArray(tmpData,data,dataNumber);
            cout<<"Now sorting data(Merge Sort)... ";
            getTime=MergeSort(data,dataNumber);
            cout<<"use "<<getTime<<" seconds"<<endl;
            ///-----
            ///-----
//            CopyArray(tmpData,data,dataNumber);
//            cout<<"Now sorting data(Radix Sort)... ";
//            getTime=RadixSort(data,dataNumber);
//            cout<<"use "<<getTime<<" seconds"<<endl;
            ///-----
            ///-----
            CopyArray(tmpData,data,dataNumber);
            cout<<"Now sorting data(QSort)... ";
            getTime=QSort(data,dataNumber);
            cout<<"use "<<getTime<<" seconds"<<endl;
            ///-----
            ///-----
            CopyArray(tmpData,data,dataNumber);
            cout<<"Now sorting data(Std Sort)(Quick+insertion)... ";
            getTime=StdSort(data,dataNumber);
            cout<<"use "<<getTime<<" seconds"<<endl;
            ///-----
            CopyArray(tmpData,data,dataNumber);
            cout<<"Now sorting data(Heap Sort)... ";
            getTime=HeapSort_OutputB(data,dataNumber);
            cout<<"use "<<getTime<<" seconds"<<endl;
            ///-----
            cout<<"--------------------"<<endl;
            delete data;
            delete tmpData;
        }
        c++;
    }
    cout<<endl;
    system("pause");
    return 1;
}
string Num2StdString(int num){
    string ans="";
    string numberString="0123456789";
    while(num){
        ans=numberString[num%10]+ans;
        num/=10;
    }
    return ans;
}

void CopyArray(int* from,int* to,int l){
    int i;
    for(i=0;i<l;i++){
        to[i]=from[i];
    }
    return;
}

template<class T>
void swap(T *a,T *b){
	T *temp=NULL;
	temp=a;
	a=b;
	b=temp;
}

template<class T>
void Adjust(T *a,const int root,const int n)
{
	T e=a[root];
	int j=0;
	for(j=2*root;j<=n;j*=2){
		if(j<n&&a[j]<a[j+1])j++;
		if(e>=a[j])break;
		a[j/2]=a[j];
	}
	a[j/2]=e;
}

template<class T>
void HeapSort(T *a,const int n){
	for(int i=n/2;i>=1;i--)
		Adjust(a,i,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(a[1],a[i+1]);
		Adjust(a,1,i);
	}
}

float HeapSort_OutputB(int *data,int amount){
	int *arr = new int[amount];
	int *temp = new int[amount];
	for (int j = 0; j < amount; ++j)
		temp[j] = arr[j];
		clock_t _T_start,_T_end;
  	  	_T_start=clock();
		HeapSort(temp, amount);
		_T_end=clock();
		delete[] arr;
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}

float SelectionSort(int *data,int length){
    if(SSTLEDataNumber!=-1&&SSTLEDataNumber<=length){
        return -1;
    }
    int i,j,minNumber;
    clock_t _T_start,_T_end;
    _T_start=clock();
    for(i=0;i<length;i++){
        minNumber=i;
        for(j=i+1;j<length;j++){
            if((float)(clock()-_T_start)/CLOCKS_PER_SEC>=TLETime){
                SSTLEDataNumber=length;
                return -1;
            }
            if(data[j]<data[minNumber]){
                minNumber=j;
            }
        }
        if(i!=minNumber){
            SWAP(data[i],data[minNumber]);
        }
    }
    _T_end=clock();
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}
float MergeSort(int *data,int length){
    int i,leftMin,leftMax,rightMin,rightMax,next;
    int *tmp = new int[length];
    clock_t _T_start,_T_end;
    _T_start=clock();
    for(i=1;i<length;i*=2){
        for(leftMin=0;leftMin<length-i;leftMin=rightMax){
            rightMin=leftMax=leftMin+i;
            rightMax=leftMax+i;
            if(rightMax>length){
                rightMax=length;
            }
            next=0;
            while(leftMin<leftMax&&rightMin<rightMax){
                tmp[next++]=data[leftMin]>data[rightMin]?data[rightMin++]:data[leftMin++];
            }
            while(leftMin<leftMax){
                data[--rightMin]=data[--leftMax];
            }
            while(next>0){
                data[--rightMin]=tmp[--next];
            }
		}
	}
    _T_end=clock();
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}
float RadixSort(int* data,int length){
    int tmp[10][length],tmpCounter[10],i,j,maxW=5,wCounter=0,tmpNumber,tmpCenter,dataIndex;
    for(i=0;i<10;i++){
        tmpCounter[i]=0;
    }
    clock_t _T_start,_T_end;
    _T_start=clock();
    while(wCounter<maxW){
        for(i=0;i<length;i++){
            tmpNumber=data[i];
            for(j=0;j<wCounter;j++){
                tmpNumber/=10;
            }
            tmpCenter=tmpNumber%10;
            tmp[tmpCenter][tmpCounter[tmpCenter]]=data[i];
            tmpCounter[tmpCenter]++;
        }
        dataIndex=0;
        for(i=0;i<10;i++){
            for(j=0;j<tmpCounter[i];j++){
                data[dataIndex]=tmp[i][j];
                dataIndex++;
            }
            tmpCounter[i]=0;
        }
        wCounter++;
    }
    _T_end=clock();
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}
int QCompare(const void *a,const void *b){
     return *(int*)a-*(int*)b;
}
float QSort(int* data,int length){
    clock_t _T_start,_T_end;
    _T_start=clock();
    qsort((void*)data,length,sizeof(int),QCompare);
    _T_end=clock();
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}
float StdSort(int* data,int length){
    clock_t _T_start,_T_end;
    _T_start=clock();
    sort(data,data+length);
    _T_end=clock();
    return (float)(_T_end-_T_start)/CLOCKS_PER_SEC;
}
