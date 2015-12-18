//
// Created by user on 12/16/15.
//

#ifndef POCOSERVER_REQUEST_H
#define POCOSERVER_REQUEST_H


class RequestInterface {


public:
    virtual ~RequestInterface() { }
    RequestInterface() { }
    virtual bool processReques();

protected:
    char requestCode[3];
};


#endif //POCOSERVER_REQUEST_H
