#include<mutex>
#include<iostream>
#include<thread>
using namespace std;
std::mutex mu;
void shared_print(string msg,int id)
{
    std::lock_guard<std::mutex>guard(mu);
    //mu.lock();//It will lock before it printed. So other thread could not use it.
    cout<<msg<<id<<endl;
    //mu.unlock();//It will unlock print after each printing.
}
void function_1()
{
    for(int i=0;i>=-100;i--)
       shared_print(string("From t1: "),i);
}
int main()
{
    thread t1(function_1);

    for(int i=0;i<100;i++)
    shared_print(string("from main: "),i);

    t1.join();
    return 0;
}

/*
(base) zcw@mukoedo1993:~/multithreading$ g++ mutex.cpp  -std=c++11 -pthread -o mutex
(base) zcw@mukoedo1993:~/multithreading$ ./mutex
from main: 0
from main: 1
from main: 2
from main: 3
from main: 4
from main: 5
from main: 6
from main: 7
from main: 8
from main: 9
from main: 10
From t1: 0
From t1: -1
From t1: -2
from main: 11
from main: 12
from main: 13
from main: 14
from main: 15
from main: 16
from main: 17
from main: 18
from main: 19
from main: 20
from main: 21
from main: 22
from main: 23
from main: 24
from main: 25
from main: 26
from main: 27
from main: 28
from main: 29
from main: 30
from main: 31
from main: 32
from main: 33
from main: 34
from main: 35
from main: 36
From t1: -3
From t1: -4
from main: 37
from main: 38
From t1: -5
From t1: -6
From t1: -7
From t1: -8
From t1: -9
From t1: -10
From t1: -11
From t1: -12
From t1: -13
From t1: -14
From t1: -15
From t1: -16
From t1: -17
From t1: -18
from main: 39
from main: 40
from main: 41
from main: 42
from main: 43
from main: 44
from main: 45
from main: 46
from main: 47
from main: 48
from main: 49
from main: 50
from main: 51
from main: 52
from main: 53
from main: 54
from main: 55
from main: 56
from main: 57
from main: 58
from main: 59
from main: 60
from main: 61
from main: 62
from main: 63
from main: 64
from main: 65
from main: 66
from main: 67
from main: 68
from main: 69
from main: 70
from main: 71
from main: 72
from main: 73
from main: 74
from main: 75
from main: 76
from main: 77
from main: 78
from main: 79
from main: 80
from main: 81
from main: 82
from main: 83
from main: 84
from main: 85
from main: 86
from main: 87
from main: 88
from main: 89
from main: 90
from main: 91
from main: 92
from main: 93
from main: 94
from main: 95
from main: 96
from main: 97
from main: 98
from main: 99
From t1: -19
From t1: -20
From t1: -21
From t1: -22
From t1: -23
From t1: -24
From t1: -25
From t1: -26
From t1: -27
From t1: -28
From t1: -29
From t1: -30
From t1: -31
From t1: -32
From t1: -33
From t1: -34
From t1: -35
From t1: -36
From t1: -37
From t1: -38
From t1: -39
From t1: -40
From t1: -41
From t1: -42
From t1: -43
From t1: -44
From t1: -45
From t1: -46
From t1: -47
From t1: -48
From t1: -49
From t1: -50
From t1: -51
From t1: -52
From t1: -53
From t1: -54
From t1: -55
From t1: -56
From t1: -57
From t1: -58
From t1: -59
From t1: -60
From t1: -61
From t1: -62
From t1: -63
From t1: -64
From t1: -65
From t1: -66
From t1: -67
From t1: -68
From t1: -69
From t1: -70
From t1: -71
From t1: -72
From t1: -73
From t1: -74
From t1: -75
From t1: -76
From t1: -77
From t1: -78
From t1: -79
From t1: -80
From t1: -81
From t1: -82
From t1: -83
From t1: -84
From t1: -85
From t1: -86
From t1: -87
From t1: -88
From t1: -89
From t1: -90
From t1: -91
From t1: -92
From t1: -93
From t1: -94
From t1: -95
From t1: -96
From t1: -97
From t1: -98
From t1: -99
From t1: -100
*/