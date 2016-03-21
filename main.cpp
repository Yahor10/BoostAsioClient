#include <iostream>
#include "client.h"
#include "boost/thread/thread.hpp";

using namespace std;


boost::asio::io_service io_service;

void f1(int port){
    client *client1 = new client("127.0.0.1",port,io_service);
    io_service.run();
    for(int i=0;i < 10;i++){
        const boost::posix_time::ptime ptime = boost::posix_time::second_clock::local_time();
        long milliseconds = ptime.time_of_day().total_milliseconds();
        payload t(milliseconds,32,0,"my message");
        client1->sendMessage(t);
    }
}

void f2(int port){
    client *client1 = new client("127.0.0.1",port,io_service);
    io_service.run();
    for(int i=0;i < 10;i++){
        const boost::posix_time::ptime ptime = boost::posix_time::second_clock::local_time();
        long milliseconds = ptime.time_of_day().total_milliseconds();
        payload t(milliseconds,32,0,"my message");
        client1->sendMessage(t);
    }
}


int main() {
    return 0;
}