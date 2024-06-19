#include "Car.hpp"
#include<string>
int main() {
    Car myCar(10,false);

    
    myCar.start();
    myCar.drive();
    myCar.stop();

    return 0;
}
