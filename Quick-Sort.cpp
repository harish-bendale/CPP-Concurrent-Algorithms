#include<iostream>
#include<thread>

int qSort(std::vector<int> &v,int left,int right){
    int ele = v[left];
    int l = left;
    int r = right;
    while(l < r){
        while(l <= right-1 and v[l] <= ele) l++;
        while(r >= left+1 and v[r] > ele) r--;
        if(l < r) std::swap(v[l],v[r]);
    }
    
    std::swap(v[left],v[r]);
    return r;
}
void quickSort(std::vector<int> &v,int left,int right){
    if(left < right){
        int ele = qSort(v,left,right);
        
        std::thread t1(quickSort,std::ref(v),left,ele-1);
        std::thread t2(quickSort,std::ref(v),ele+1,right);
        t1.join();
        t2.join();
    }
}
int main(){
    int size = 1e3+7;
    std::vector<int> v(size);
    for(int i=0;i<size;i++){
        v[i] = std::rand();
    }
    std::cout<<"Before Sort "<<std::endl;
    for(auto &i : v){
        std::cout<<i<<" ";
    }
    
    quickSort(v,0,size-1);
    std::cout<<"Ater Sort "<<std::endl;
    for(auto &i : v){
        std::cout<<i<<" ";
    }
}
