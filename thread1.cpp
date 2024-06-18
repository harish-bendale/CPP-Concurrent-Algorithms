#include<iostream>
#include<thread>
int main(){
    auto lam= [](int x){
        std::cout<<" Lambda Function Data "<<x<<std::endl;
    };
    std::thread t(lam,10);
    std::thread t2(lam,20);
    std::thread t3(lam,30);
    t.join();
    t2.join();
    t3.join();
    std::cout<<"Main Function Thread "<<std::endl;
}