#include <iostream>
#include <thread>
#include <atomic>

using int32 = __int32;
using namespace std;
//atomic : 한번에 이루어지거나 아에 실행이안되거나
//DB에서 트랜잭션에서 묵어서 한번에 실행되는 단위 같은것
//여기서는 어셈블리어에서 동작하는 수준을 말하는 것
//c++에서는 한줄짜리코드지만 기계어에선 아니기때문
//거기다 생각보다 atomic이 느리다고한다.
atomic<int32> sum = 0;

void Add() {
    for (int32 i = 0; i < 100'0000; i++) {
        sum.fetch_add(1);
        //sum++;
    }
}

void Sub() {
    for (int32 i = 0; i < 100'0000; i++) {
        sum.fetch_add(-1);
        //sum--;
    }

}

int main()
{

    cout << sum << endl;

    thread t1(Add);
    thread t2(Sub);


    t1.join();
    t2.join();
    cout << sum << endl;
}
