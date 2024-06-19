#include "Car.hpp"
#include <iostream>


Car::Car(int yr,bool running){
        std::cout<<"Constructor Insantiated"<<std::endl;
    m_year = yr;
    m_isRunning = running;
    }


Car::~Car() {}


void Car::start() {
    if (!m_isRunning) {
        m_isRunning = true;
        std::cout << "Car started." << std::endl;
    } else {
        std::cout << "Car is already running." << std::endl;
    }
}

void Car::stop() {
    if (m_isRunning) {
        m_isRunning = false;
        std::cout << "Car stopped." << std::endl;
    } else {
        std::cout << "Car is already stopped." << std::endl;
    }
}

void Car::drive() {
    if (m_isRunning) {
        std::cout << "Driving the car." << std::endl;
    } else {
        std::cout << "Cannot drive, car is not running." << std::endl;
    }
}

