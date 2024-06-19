#include <string>
using namespace std;
#ifndef CAR_H
#define CAR_H

class Car {
public:
    
    Car(int yr,bool ruuning);

    
    ~Car();

    
    void start();
    void stop();
    void drive();

private:
    int m_year;
    bool m_isRunning;
};

#endif 
