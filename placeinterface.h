#ifndef PLACEINTERFACE_H
#define PLACEINTERFACE_H

#include <systemc.h>

class placeInterface : public sc_interface
{
public:
    virtual void addTokens(unsigned int n) = 0;
    virtual void removeTokens(unsigned int n) = 0;
    virtual unsigned int testTokens() = 0;
};


#endif // PLACEINTERFACE_H
