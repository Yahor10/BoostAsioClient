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
#include <boost/thread.hpp>

using boost::asio::ip::tcp;

#ifndef BOOSTASIOCLIENT_CLIENT_H
#define BOOSTASIOCLIENT_CLIENT_H


class client {

public:

    client(std::string host,int port ,boost::asio::io_service&);

    void sendMessage(payload & messag);

    void startListen();
private:

    tcp::socket _socket;
    tcp::endpoint _endpoint;

    void putLongToArray(unsigned  char* arr,long val,long skip);

    void async_read_handler(const boost::system::error_code& e,std::size_t bytes);
    std::vector<char> _answers;
};


#endif //BOOSTASIOCLIENT_CLIENT_H
