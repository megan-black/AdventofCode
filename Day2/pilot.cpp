//    forward X increases the horizontal position by X units.
//   down X increases the depth by X units.
//    up X decreases the depth by X units.

#include "pilot.h"

void part1(){
    ifstream fin;
    fin.open("./input.txt");
    string cmd, num;
    int forward = 0, depth = 0, num_i = 0;
    for(int i = 0; i < 1000; i++)
    {
        fin >> cmd;
        fin >> num;
        num_i = stoi(num);
        if(cmd == "forward")
            forward += num_i;
        if(cmd == "up")
            depth -= num_i;
        if(cmd == "down")
            depth += num_i;
    }   
    fin.close();
    printf("Result part 1: %d * %d = %d\n", forward, depth, forward*depth);
}

void part2() {
    ifstream fin;
    fin.open("./input2.txt");
    string cmd, num;
    int forward = 0, depth = 0, aim = 0, num_i = 0;
    for(int i = 0; i < 1000; i++)
    {
        fin >> cmd;
        fin >> num;
        num_i = stoi(num);
        if(cmd == "forward") {
            forward += num_i;
            depth += (num_i * aim);
        }
        if(cmd == "up")
            aim -= num_i;
        if(cmd == "down")
            aim += num_i;
    }   
    fin.close();
    printf("Result part 2: %d * %d = %d\n", forward, depth, forward*depth);
}

int main() {
    part1();
    part2();

    return 0;
}