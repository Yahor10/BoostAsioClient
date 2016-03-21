#include <iostream>
#include "client.h"
#include "boost/thread.hpp";

using namespace std;


boost::asio::io_service io_service;

void f1(){
    printf("start  f1 thread \n");

    client *client1 = new client("127.0.0.1",3030,io_service);
    io_service.run();
    printf("start send messages!");

    for(int i=0;i < 10;i++){
        const boost::posix_time::ptime ptime = boost::posix_time::second_clock::local_time();
        long milliseconds = ptime.time_of_day().total_milliseconds();
        payload t(milliseconds,32,0,"my message");
        client1->sendMessage(t);
        printf("send message %d",i);
    }

}

void f2(){
    client *client1 = new client("127.0.0.1",3031,io_service);
    io_service.run();
    for(int i=0;i < 10;i++){
        const boost::posix_time::ptime ptime = boost::posix_time::second_clock::local_time();
        long milliseconds = ptime.time_of_day().total_milliseconds();
        payload t(milliseconds,32,0,"my message");
        client1->sendMessage(t);
    }
}


int main() {

    boost::thread t1(f1);

//    boost::thread t2(f2);

    t1.join();
//    t2.join();

//    boost::thread t1(boost::bind(&::f1,_1,3030));
//    t1.join();
    return 0;
}