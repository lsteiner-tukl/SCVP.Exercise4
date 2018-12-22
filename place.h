#ifndef PLACE_H
#define PLACE_H

#include "placeinterface.h"

class place : public placeInterface
{
public:
    place(unsigned int tokens);
    void addTokens(unsigned int n);
    void removeTokens(unsigned int n);
    unsigned int testTokens();
private:
    unsigned int tokens;
};

#endif // PLACE_H
