#include<iostream>
#include<stdlib.h>
#include<string>
#include<bitset>
#include<cmath>
#include<chrono>
#include<thread>
#include<fstream>
using namespace std;
void delay_ns(int ns) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
}
int main(){
    string inst;
    int registers[8] = {0};
    int memory[8][8] = {0};
    bool running = true;
    ifstream file("program.bin");
    if(!file){
        cerr << "Error";
        return 1;
    }
    while (file >> inst && running) {
        cout << ">> ";
        if (inst == "111000000000") { // HALT instruction
            running = false;
            cout << "Halting execution.\n";
            break;
        }else{
            string opcode_c;
    string reg1;
    string operand;
    int opcode_i;
    opcode_c.push_back(inst[0]);
    opcode_c.push_back(inst[1]);
    opcode_c.push_back(inst[2]);
    reg1.push_back(inst[3]);
    reg1.push_back(inst[4]);
    reg1.push_back(inst[5]);
    operand.push_back(inst[6]);
    operand.push_back(inst[7]);
    operand.push_back(inst[8]);
    operand.push_back(inst[9]);
    operand.push_back(inst[10]);
    operand.push_back(inst[11]);
    int operand_i= stoi(operand,nullptr,2);
    int regindex = stoi(reg1,nullptr,2);
    if(opcode_c == "000"){
        registers[regindex] = operand_i & 0xff;
        cout <<"Data "<< operand_i << " Loaded into R"<<regindex<<"\n";
    }else if(opcode_c == "001"){
        registers[regindex] += operand_i & 0xFF;
        cout << registers[regindex] <<" Is the result of the addition\n";
    }else if(opcode_c == "010"){
        registers[regindex] -= operand_i & 0xff;
        cout << registers[regindex] <<" Is the result of the subtraction\n";
    }else if(opcode_c == "011"){
        int addr = operand_i;
        int row = addr/8;
        int col = addr%8;
        delay_ns(100);
        registers[regindex] = memory[row][col];
        cout << "Loaded " <<registers[regindex]<< " into R" << regindex << " with a delay of 100ns\n";
    }else if(opcode_c == "100"){
        int addr = operand_i;
        int row = addr/8;
        int col = addr%8;
        delay_ns(80);
        memory[row][col] = registers[regindex];
        cout << "Stored " << registers[regindex] << " into memory location "<<"[" << row << "]"<< "[" <<col<< "] with a delay of 80ns\n";
    }
    }
}
    return 0;
}