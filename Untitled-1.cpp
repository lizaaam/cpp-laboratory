#include <iostream>
#include <cstdint>
#include <cstring>
#include <limits>
#include <string>
using namespace std;

void printIntBits(int32_t value) {
    uint32_t u = static_cast<uint32_t>(value);
    cout << "Число: " << value << endl;
    cout << "Знак " << (u >> 31)  << " значение ";
    for (int i = 31; i >= 0; i--) {
        cout << ((u >> i) & 1);
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
    }
    cout << endl << endl;
}

void printUIntBits(uint32_t value) {
    cout << "Unsigned: " << value << endl;
    for (int i = 31; i >= 0; i--) {
        cout << ((value >> i) & 1);
        if (i % 8 == 0 && i != 0) {
            cout << " ";
        }
    }
    cout << endl << endl;
}


void printFloatBits(float value) {
    uint32_t bits;
    memcpy(&bits, &value, sizeof(bits));
    uint32_t sign = (bits >> 31) & 1;
    uint32_t exponent = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;
    cout << "Число float: " << value << endl;
    cout << "Знаковый бит: " << sign << endl;
    cout << "Поле порядка: ";
    for (int i = 7; i >= 0; i--) {
        cout << ((exponent >> i) & 1);
    }
    cout << endl;
    cout << "Поле мантиссы: ";
    for (int i = 22; i >= 0; i--) {
        cout << ((mantissa >> i) & 1);
    }
    cout << endl << endl;
}
void printDoubleBits(double value) {
    uint64_t bits;
    memcpy(&bits, &value, sizeof(bits));
    uint64_t sign = (bits >> 63) & 1;
    uint64_t exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0x000FFFFFFFFFFFFF;
    cout << "Число double: " << value << endl;
    cout << "Знаковый бит: " << sign << endl;
    cout <<"Поле порядка: ";
    for (int i = 10; i >= 0; i--) {
        cout << ((exponent >> i) & 1);
    }
    cout << endl;
    cout << "Поле мантиссы: ";
    for (int i = 51; i >= 0; i--) {
        cout << ((mantissa >> i) & 1);
    }
    cout << endl << endl;
}
void bit_change_int(int value, int number, string change){
    if (number < 0 || number >= 32){
    cout << "Неверный номер бита" << endl;
    return;
    }
    if (change != "установить" && change != "сбросить" && change != "инвертировать"){
        cout << "Указано неверное изменение" << endl;
         return;
    }
    uint32_t bits;
    memcpy(&bits, &value, sizeof(value));
    if (change == "установить"){
        bits |= 1u << number;
    }
    else if (change == "сбросить"){
        bits &= ~(1u << number);
    }
    else if (change == "инвертировать"){
        bits ^= 1u << number;
    }
    memcpy(&value, &bits, sizeof(value));
    cout << value << endl;
}

void bit_change_float(float value, int number, string change){
    if (change != "установить" && change != "сбросить" && change != "инвертировать"){
        cout << "Указано неверное изменение" << endl;
         return;
    }
    if (number < 0 || number >= 32){
    cout << "Неверный номер бита" << endl;
    return;
    }
    uint32_t bits;
    memcpy(&bits, &value, sizeof(value));
    if (change == "установить"){
        bits |= 1u << number;
    }
    else if (change == "сбросить"){
        bits &= ~(1u << number);
    }
    else if (change == "инвертировать"){
        bits ^= 1u << number;
    }
    memcpy(&value, &bits, sizeof(value));
    cout << value << endl;
}
void bit_change_double(double value, int number, string change){
    if (change != "установить" && change != "сбросить" && change != "инвертировать"){
        cout << "Указано неверное изменение" << endl;
         return;
    }
    if (number < 0 || number >= 64){
    cout << "Неверный номер бита" << endl;
    return;
    }
    uint64_t bits;
    memcpy(&bits, &value, sizeof(value));
    if (change == "установить"){
        bits |= uint64_t(1) << number;
    }
    else if (change == "сбросить"){
        bits &= ~(uint64_t(1) << number);
    }
    else if (change == "инвертировать"){
        bits ^= uint64_t(1) << number;
    }
    memcpy(&value, &bits, sizeof(value));
    cout << value << endl;
}

void multiplication_2( unsigned int value){
    cout << (value << 1) << endl;
}
int main() {
    cout << "bool: " << sizeof(bool) << " байт" << endl;
    cout << "char: "<< sizeof(char) << " байт" << endl;
    cout << "short int: " << sizeof(short int) << " байт" << endl;
    cout << "int: " << sizeof(int) << " байт" << endl;
    cout << "long int: " << sizeof(long int) << " байт" << endl;
    cout << "float: " << sizeof(float) << " байт" << endl;
    cout << "double: " << sizeof(double) << " байт" << endl;
    cout << "long double: " << sizeof(long double) << " байт" << endl;

    printIntBits(1);
    printIntBits(-5);
    printIntBits(0);
    printUIntBits(10);
   

    printFloatBits(3.14f);
    printFloatBits(-5.25f);
    printFloatBits(0.0f);
    printFloatBits(1.0e-40f);
    printFloatBits(numeric_limits<float>::infinity());
    printFloatBits(-numeric_limits<float>::infinity());
    printFloatBits(numeric_limits<float>::quiet_NaN());

    printDoubleBits(3.14);
    printDoubleBits(-5.25);
    printDoubleBits(0.0);
    printDoubleBits(1.0e-310);
    printDoubleBits(numeric_limits<double>::infinity());
    printDoubleBits(-numeric_limits<double>::infinity());
    printDoubleBits(numeric_limits<double>::quiet_NaN());
    

    bit_change_int(12, 2,"установить");
    bit_change_int(12, 2,"сбросить");
    bit_change_int(12, 2,"инвертировать");
    bit_change_float(13.5f ,2,"установить");
    bit_change_float(13.5f ,2,"сбросить");
    bit_change_float(13.5f ,2,"инвертировать");
    bit_change_double(1.5 ,2,"установить");
    bit_change_double(1.5 ,2,"сбросить");
    bit_change_double(1.5 ,2,"инвертировать");
    
    multiplication_2(4);
    multiplication_2(6);
    return 0;
}


