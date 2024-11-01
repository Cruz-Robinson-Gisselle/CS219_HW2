/*
Author: Gisselle Cruz-Robinson
Assignment: Programming Project 2
*/
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

uint32_t add(long, long);
uint32_t sub(long, long);
uint32_t logicShiftRight(uint32_t, int);
uint32_t logicShiftLeft(uint32_t, int);
uint32_t ArithShiftRight(int32_t, int);
uint32_t bitwiseAnd(uint32_t n1, uint32_t n2);
uint32_t bitwiseOr(uint32_t n1, uint32_t n2);
uint32_t bitwiseXOR(uint32_t n1, uint32_t n2);
uint32_t bitwiseNot(uint32_t);
string convertToHex(uint32_t);
bool checkOverflow(long n1, long n2, uint32_t sum);
void checkFlags(int& n, int& z, string);
void readFile(ifstream&, string&, long& o1, long& o2, string& s1, string& s2);

int main() {
    ifstream in;
    in.open("Programming-Project-2.txt");
    string command = "";
    long operand1, operand2;
    string operandString1, operandString2;
    int flagN = 0;
    int flagZ = 0;
    while(!in.eof()){
        //read txt file
        readFile(in, command, operand1, operand2, operandString1, operandString2);
        if(command == "ADD" || command == "ADDS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = add(operand1, operand2);
            string hexSum = convertToHex(result);
            cout << hexSum << endl;
            if(command == "ADDS"){
                checkFlags(flagN, flagZ, hexSum);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "SUB" || command == "SUBS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = sub(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "SUBS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "AND" || command == "ANDS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = bitwiseAnd(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "ANDS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "NOT" || command == "NOTS"){
            cout << command << " " << operandString1 << ": ";
            uint32_t result = bitwiseNot(operand1);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "NOTS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "ORR" || command == "ORRS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = bitwiseOr(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "ORRS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "XOR" || command == "XORS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = bitwiseXOR(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "XORS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "LSR" || command == "LSRS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = logicShiftRight(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "LSRS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "LSL" || command == "LSLS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = logicShiftLeft(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "LSLS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
        else if(command == "ASR" || command == "ASRS"){
            cout << command << " " << operandString1 << " " << operandString2 << ": ";
            uint32_t result = ArithShiftRight(operand1, operand2);
            string hexResult = convertToHex(result);
            cout << hexResult << endl;
            if(command == "ASRS"){
                checkFlags(flagN, flagZ, hexResult);
            }
            cout << "N: " << flagN << " Z: " << flagZ << endl;
        }
    }
    //Close file
    in.close();
    return 0;
}

/*
Checks if the operation has affected flags N or Z. N is set to 1 if the result is negative
(MSB is 1), and Z is set to 1 if the result is zero.
*/
void checkFlags(int& n, int& z, string hex){
    int32_t signedRes = stol(hex, nullptr, 16);
    if(signedRes < 0)
        n = 1;
    else 
        n = 0;
    if(signedRes == 0)
        z = 1;
    else 
        z = 0;
}

/*
Performs the add operation for the two operands.
*/
uint32_t add(long n1, long n2){
    uint32_t sum = n1 + n2;
    return sum;
}

/*
Performs the subtraction operation for the two operands.
*/
uint32_t sub(long n1, long n2){
    uint32_t result = n1 - n2;
    return result;
}

/*
Performs the logical shift right on the operand.
*/
uint32_t logicShiftRight(uint32_t n, int factor){
    uint32_t result = n / (pow(2, factor));
    return result;
}

/*
Performs the logical shift left on the operand.
*/
uint32_t logicShiftLeft(uint32_t n, int factor){
    uint32_t result = n * pow(2, factor);
    return result;
}


/*
Performs an arthimetic shift right on the operand by a factor of 2.
*/
uint32_t ArithShiftRight(int32_t n, int factor){
    int32_t shift = n >> factor;
    uint32_t result = shift;
    return result;
}

/*
Performs the bitwise AND operation for the two operands.
*/
uint32_t bitwiseAnd(uint32_t n1, uint32_t n2){
    uint32_t result = n1 & n2;
    return result;
}

/*
Performs the bitwise OR operation for the two operands.
*/
uint32_t bitwiseOr(uint32_t n1, uint32_t n2){
    uint32_t result = n1 | n2;
    return result;
}

/*
Performs the bitwise XOR operation for the two operands.
*/
uint32_t bitwiseXOR(uint32_t n1, uint32_t n2){
    uint32_t result = n1 ^ n2;
    return result;
}

/*
Performs the bitwise NOT operation for the two operands.
*/
uint32_t bitwiseNot(uint32_t n){
    uint32_t result = ~n;
    return result;
}

/*
convertToHex takes an unsigned 32-bit number and converts into hexadecimal. This done by the division and remainder method.
*/
string convertToHex(uint32_t n){
    char nibbles[8];
    for(int i = 7; i >= 0; i--){
        int r = n%16;
        if(r < 10)
            nibbles[i] = 48 + r;
        else
            nibbles[i] = 55 + r;
        n = n/16;
    }
    string hexValue = "";
    for(int i = 0;  i < 8; i++){
        hexValue = hexValue + nibbles[i];
    }
    //Simplify string
    int index = 0;
    for(int i = 0; i < 8; i++){
        if(hexValue[i] == '0' && i != 7)
            index++;
        else
            break;
    }
    hexValue = "0x" + hexValue.substr(index, (8-index));
    return hexValue;
}

/*
checkOverflow takes the long variables of the operand and the 32-bit unsigned sum. Overflow is checked by adding the two long variables and subtracting the sum by the max value
of uint32 - 1. Then, it checks if the sum and subtracted long sum are equivalent.
*/
bool checkOverflow(long n1, long n2, uint32_t sum){
    long equivalent = n1+n2-UINT32_MAX-1;
    if(sum == equivalent)
        return true;
    return false;
}

/*
readFile goes through the txt file for information about what command is to be done, and what two operands are involved.
*/
void readFile(ifstream& in, string& c, long& o1, long& o2, string& s1, string& s2){
    getline(in, c, ' ');
    string trash;
    if(c == "ASR" || c == "ASRS" || c == "LSR" || c == "LSRS" || c == "LSL" || c == "LSLS"){
        getline(in, trash, 'x');
        getline(in, s1, ' ');
        getline(in, s2);
        s1 = "0x" + s1;
        o1 = stol(s1, nullptr, 16);
        o2 = stol(s2, nullptr, 10);
    }
    else if(c == "NOT" || c == "NOTS"){
        getline(in, trash, 'x');
        getline(in, s1);
        s1 = "0x" + s1;
        o1 = stol(s1, nullptr, 16);
    }
    else{
        getline(in, trash, 'x');
        getline(in, s1, 'x');
        s1 = s1.substr(0, s1.length()-1);
        getline(in, s2);
        s1 = "0x" + s1;
        s2 = "0x" + s2;
        o1 = stol(s1, nullptr, 16);
        o2 = stol(s2, nullptr, 16);
    }
}

