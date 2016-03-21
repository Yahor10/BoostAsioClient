//
// Created by ychabatarou on 21.3.16.
//

#ifndef BOOSTASIOCLIENT_PAYLOAD_H
#define BOOSTASIOCLIENT_PAYLOAD_H


class payload {

public:
    unsigned long _timestamp;
    long _hash;
    int _lenght;
    char* _key_data;


    payload(long _timestand, long _hash, int _lenght, char *_key_data) : _timestamp(_timestand), _hash(_hash),
                                                                         _lenght(_lenght), _key_data(_key_data) { }


    payload() { }

    virtual ~payload() {

    }
};


#endif //BOOSTASIOCLIENT_PAYLOAD_H
