#include<iostream>
#include<vector>
#include<thread>
void merge(std::vector<int> &v,int left,int mid,int right){
    std::vector<int> temp;
    int l1 = left;
    int l2 = mid+1;
    while(l1 <= mid and l2 <= right){
        if(v[l1] < v[l2]){
            temp.push_back(v[l1]);
            l1++;
        }else{
            temp.push_back(v[l2]);
            l2++;
        }
    }
    while(l1 <= mid){
            temp.push_back(v[l1]);
            l1++;
        
    }
    while(l2 <= right){
            temp.push_back(v[l2]);
            l2++;
    }
    
    for(int i=0;i<temp.size();i++){
        v[i+left] = temp[i];
    }
}
void mergeSort(std::vector<int> &v,int left,int right){
    if(left < right){
        int mid = (left+right)/2;
        
        std::thread t1(mergeSort,std::ref(v),left,mid);
        std::thread t2(mergeSort,std::ref(v),mid+1,right);
        t1.join();
        t2.join();
        merge(v,left,mid,right);
    }
}
int main(){
    int size = 1e3+7;
    std::vector<int> v(size);
        
    for (int i = 0; i < size; ++i) {
        v[i] = std::rand();
    }
    mergeSort(v,0,size);
    for(int &i : v){
        std::cout<<i<<" ";
    }
}
