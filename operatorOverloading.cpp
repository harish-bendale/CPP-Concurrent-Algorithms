#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
public:
    int value;
    A(int v = 0) : value(v) {}
    
    // Unary operators
    A operator+() const { return *this; }
    A operator-() const { return A(-value); }
    A operator*() const { return A(value * value); }
    A operator&() const { return A(value); }
    bool operator!() const { return value == 0; }
    A operator~() const { return A(~value); }
    A& operator++() { ++value; return *this; } // Prefix increment
    A operator++(int) { A temp = *this; ++value; return temp; } // Postfix increment
    A& operator--() { --value; return *this; } // Prefix decrement
    A operator--(int) { A temp = *this; --value; return temp; } // Postfix decrement
    
    // Binary operators
    A operator+(const A& other) const { return A(value + other.value); }
    A operator-(const A& other) const { return A(value - other.value); }
    A operator*(const A& other) const { return A(value * other.value); }
    A operator/(const A& other) const { return A(value / other.value); }
    A operator%(const A& other) const { return A(value % other.value); }
    A operator^(const A& other) const { return A(value ^ other.value); }
    A operator&(const A& other) const { return A(value & other.value); }
    A operator|(const A& other) const { return A(value | other.value); }
    bool operator<(const A& other) const { return value < other.value; }
    bool operator>(const A& other) const { return value > other.value; }
    bool operator==(const A& other) const { return value == other.value; }
    bool operator!=(const A& other) const { return value != other.value; }
    bool operator<=(const A& other) const { return value <= other.value; }
    bool operator>=(const A& other) const { return value >= other.value; }
    A operator<<(const A& other) const { return A(value << other.value); }
    A operator>>(const A& other) const { return A(value >> other.value); }
    bool operator&&(const A& other) const { return value && other.value; }
    bool operator||(const A& other) const { return value || other.value; }
    A operator,(const A& other) const { return other; }
    
    // Assignment operators
    A& operator=(const A& other) { value = other.value; return *this; }
    A& operator+=(const A& other) { value += other.value; return *this; }
    A& operator-=(const A& other) { value -= other.value; return *this; }
    A& operator*=(const A& other) { value *= other.value; return *this; }
    A& operator/=(const A& other) { value /= other.value; return *this; }
    A& operator%=(const A& other) { value %= other.value; return *this; }
    A& operator^=(const A& other) { value ^= other.value; return *this; }
    A& operator&=(const A& other) { value &= other.value; return *this; }
    A& operator|=(const A& other) { value |= other.value; return *this; }
    A& operator<<=(const A& other) { value <<= other.value; return *this; }
    A& operator>>=(const A& other) { value >>= other.value; return *this; }
    
    // Subscript operator
    int& operator[](int index) { return value; }
    
    // Function call operator
    A operator()(int x) const { return A(value + x); }
    
    // Arrow operator
    A* operator->() { return this; }
    
    // Type cast operator
    operator int() const { return value; }
};

// Non-member function overloads
A operator+(const A& lhs, const B& rhs);
A operator-(const A& lhs, const B& rhs);
A operator*(const A& lhs, const B& rhs);
A operator/(const A& lhs, const B& rhs);
A operator%(const A& lhs, const B& rhs);
A operator^(const A& lhs, const B& rhs);
A operator&(const A& lhs, const B& rhs);
A operator|(const A& lhs, const B& rhs);
bool operator<(const A& lhs, const B& rhs);
bool operator>(const A& lhs, const B& rhs);
bool operator==(const A& lhs, const B& rhs);
bool operator!=(const A& lhs, const B& rhs);
bool operator<=(const A& lhs, const B& rhs);
bool operator>=(const A& lhs, const B& rhs);
A operator<<(const A& lhs, const B& rhs);
A operator>>(const A& lhs, const B& rhs);
bool operator&&(const A& lhs, const B& rhs);
bool operator||(const A& lhs, const B& rhs);
A operator,(const A& lhs, const B& rhs);

class B {
public:
    int value;
    B(int v = 0) : value(v) {}
    // Provide definitions as needed for non-member operators
};

// Non-member function definitions
A operator+(const A& lhs, const B& rhs) { return A(lhs.value + rhs.value); }
A operator-(const A& lhs, const B& rhs) { return A(lhs.value - rhs.value); }
A operator*(const A& lhs, const B& rhs) { return A(lhs.value * rhs.value); }
A operator/(const A& lhs, const B& rhs) { return A(lhs.value / rhs.value); }
A operator%(const A& lhs, const B& rhs) { return A(lhs.value % rhs.value); }
A operator^(const A& lhs, const B& rhs) { return A(lhs.value ^ rhs.value); }
A operator&(const A& lhs, const B& rhs) { return A(lhs.value & rhs.value); }
A operator|(const A& lhs, const B& rhs) { return A(lhs.value | rhs.value); }
bool operator<(const A& lhs, const B& rhs) { return lhs.value < rhs.value; }
bool operator>(const A& lhs, const B& rhs) { return lhs.value > rhs.value; }
bool operator==(const A& lhs, const B& rhs) { return lhs.value == rhs.value; }
bool operator!=(const A& lhs, const B& rhs) { return lhs.value != rhs.value; }
bool operator<=(const A& lhs, const B& rhs) { return lhs.value <= rhs.value; }
bool operator>=(const A& lhs, const B& rhs) { return lhs.value >= rhs.value; }
A operator<<(const A& lhs, const B& rhs) { return A(lhs.value << rhs.value); }
A operator>>(const A& lhs, const B& rhs) { return A(lhs.value >> rhs.value); }
bool operator&&(const A& lhs, const B& rhs) { return lhs.value && rhs.value; }
bool operator||(const A& lhs, const B& rhs) { return lhs.value || rhs.value; }
A operator,(const A& lhs, const B& rhs) { return A(rhs.value); }

int main() {
    A a1(10), a2(20);
    B b1(30);

    cout << "a1 + a2: " << (a1 + a2).value << endl;
    cout << "a1 + b1: " << (a1 + b1).value << endl;

    cout << "a1 - a2: " << (a1 - a2).value << endl;
    cout << "a1 - b1: " << (a1 - b1).value << endl;

    cout << "a1 * a2: " << (a1 * a2).value << endl;
    cout << "a1 * b1: " << (a1 * b1).value << endl;

    cout << "a1 / a2: " << (a1 / a2).value << endl;
    cout << "a1 / b1: " << (a1 / b1).value << endl;

    cout << "a1 % a2: " << (a1 % a2).value << endl;
    cout << "a1 % b1: " << (a1 % b1).value << endl;

    cout << "a1 ^ a2: " << (a1 ^ a2).value << endl;
    cout << "a1 ^ b1: " << (a1 ^ b1).value << endl;

    cout << "a1 & a2: " << (a1 & a2).value << endl;
    cout << "a1 & b1: " << (a1 & b1).value << endl;

    cout << "a1 | a2: " << (a1 | a2).value << endl;
    cout << "a1 | b1: " << (a1 | b1).value << endl;

    cout << "a1 < a2: " << (a1 < a2) << endl;
    cout << "a1 < b1: " << (a1 < b1) << endl;

    cout << "a1 > a2: " << (a1 > a2) << endl;
    cout << "a1 > b1: " << (a1 > b1) << endl;

    cout << "a1 == a2: " << (a1 == a2) << endl;
    cout << "a1 == b1: " << (a1 == b1) << endl;

    cout << "a1 != a2: " << (a1 != a2) << endl;
    cout << "a1 != b1: " << (a1 != b1) << endl;

    cout << "a1 <= a2: " << (a1 <= a2) << endl;
    cout << "a1 <= b1: " << (a1 <= b1) << endl;

    cout << "a1 >= a2: " << (a1 >= a2) << endl;
    cout << "a1 >= b1: " << (a1 >= b1) << endl;

    cout << "a1 << a2: " << (a1 << a2).value << endl;
    cout << "a1 << b1: " << (a1 << b1).value << endl;

    cout << "a1 >> a2: " << (a1 >> a2).value << endl;
    cout << "a1 >> b1: " << (a1 >> b1).value << endl;

    cout << "a1 && a2: " << (a1 && a2) << endl;
    cout << "a1 && b1: " << (a1 && b1) << endl;

    cout << "a1 || a2: " << (a1 || a2) << endl;
    cout << "a1 || b1: " << (a1 || b1) << endl;

    cout << "a1 , a2: " << (a1 , a2).value << endl;
    cout << "a1 , b1: " << (a1 , b1).value << endl;

    cout << "a1 = a2: " << (a1 = a2).value << endl;
    cout << "a1 += a2: " << (a1 += a2).value << endl;
    cout << "a1 -= a2: " << (a1 -= a2).value << endl;
    cout << "a1 *= a2: " << (a1 *= a2).value << endl;
    cout << "a1 /= a2: " << (a1 /= a2).value << endl;
    cout << "a1 %= a2: " << (a1 %= a2).value << endl;
    cout << "a1 ^= a2: " << (a1 ^= a2).value << endl;
    cout << "a1 &= a2: " << (a1 &= a2).value << endl;
    cout << "a1 |= a2: " << (a1 |= a2).value << endl;
    cout << "a1 <<= a2: " << (a1 <<= a2).value << endl;
    cout << "a1 >>= a2: " << (a1 >>= a2).value << endl;

    cout << "a1[0]: " << a1[0] << endl;
    a1[0] = 100;
    cout << "a1[0] after assignment: " << a1[0] << endl;

    cout << "a1(10): " << a1(10).value << endl;

    A* ptr = a1.operator->();
    cout << "a1->value: " << ptr->value << endl;

    int castValue = static_cast<int>(a1);
    cout << "castValue: " << castValue << endl;

    return 0;
}
