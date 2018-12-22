#include "place.h"

place::place(unsigned int tokens): tokens(tokens)
{}

void place::addTokens(unsigned int n)
{
    tokens += n;
}

void place::removeTokens(unsigned int n)
{
    tokens -= n;
}

unsigned int place::testTokens()
{
    return tokens;
}
