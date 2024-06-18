#include <iostream>
class mike{
 public:
    mike(){
        std::cout<<"Constructor called "<<std::endl;
    }
    
    ~mike(){
        std::cout<<"Destructour called "<<std::endl;
    }
};
int main() {
    mike obj1;
    std::cout<<"Hello there in the main function "<<std::endl;
    return 0;
}