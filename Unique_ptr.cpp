#include <iostream>
#include<memory>
class temp{
public:
    temp(){ std::cout<<"Constructor instantiated "<<std::endl;}
    ~temp(){ std::cout<<"Destructor instantiated "<<std::endl;}
};
int main() {
    int *ptr;
    int p = 10;
    int * ptr2 = new int[5];
    for(int i=0;i<5;i++){
        ptr2[i] = i+1;
    }
    ptr = ptr2;
    std::cout<<*ptr<<std::endl;
    delete[] ptr; // Need to delete manually
    std::cout<<*ptr<<std::endl;// Ownership problem (It's working in mac and linux OS but could program trashed in other OS
    std::unique_ptr<temp> obj1 = std::unique_ptr<temp> (new temp);
    std::unique_ptr<temp[]> obj2 = std::unique_ptr<temp[]> (new temp[5]);
    std::unique_ptr<temp> obj3 = std::make_unique<temp>();
    
}
