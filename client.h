//
// Created by ychabatarou on 17.3.16.
//

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "payload/payload.h"

using boost::asio::ip::tcp;

#ifndef BOOSTASIOCLIENT_CLIENT_H
#define BOOSTASIOCLIENT_CLIENT_H


class client {

public:

    client(std::string host,int port ,boost::asio::io_service&);

    void sendMessage(payload & messag);

private:

    tcp::socket _socket;
    tcp::endpoint _endpoint;

    void putLongToArray(unsigned  char* arr,long val,long skip);
};


#endif //BOOSTASIOCLIENT_CLIENT_H
