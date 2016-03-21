//
// Created by ychabatarou on 17.3.16.
//

#include "client.h"
#include "payload/payload.h"

client::client(std::string host, int port, boost::asio::io_service & io_service):_socket(io_service),_endpoint(boost::asio::ip::address::from_string(host),port) {

    _socket.connect(_endpoint);

}

void client::sendMessage(payload & message) {
    boost::system::error_code ignored_error;

    unsigned long int longTimeStamp = message._timestamp;
    unsigned int longHash = message._hash;

    unsigned char byteArray[8]; // TODO parse all correct size
    putLongToArray(byteArray,longTimeStamp,0);
    putLongToArray(byteArray,longHash,4);

    const boost::asio::mutable_buffers_1 &buffers = boost::asio::buffer(byteArray,8);
    boost::asio::write(_socket, buffers,
                       boost::asio::transfer_all(), ignored_error);


}

void client::putLongToArray(unsigned  char *arr,long val,long skip) {
    // convert from an unsigned long int to a 4-byte array
    arr[0+skip] = (int)((val >> 24) & 0xFF) ;
    arr[1 + skip] = (int)((val >> 16) & 0xFF) ;
    arr[2 + skip] = (int)((val >> 8) & 0XFF);
    arr[3 + skip] = (int)((val & 0XFF));

}