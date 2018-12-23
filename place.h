#ifndef PLACE_H
#define PLACE_H

#include "placeinterface.h"

template<unsigned int Win = 1, unsigned int Wout = 1>
class place : public placeInterface
{
public:
    place(unsigned int tokens): tokens(tokens) {}

    void addTokens()
    {
        tokens += Win;
    }

    void removeTokens()
    {
        tokens -= Wout;
    }

    bool testTokens()
    {
        return (tokens >= Wout);
    }

private:
    unsigned int tokens;
};

#endif // PLACE_H
