#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <systemc.h>
#include "place.h"

template<unsigned int N = 1, unsigned int M = 1>
SC_MODULE(transition)
{
public:
    sc_port<place<>, N, SC_ALL_BOUND> in;
    sc_port<place<>, M, SC_ALL_BOUND> out;

    SC_CTOR(transition): in("in"), out("out")
    {}

    void fire()
    {
        bool allTokens = true;

        for(unsigned int i = 0; i < N; i++) // N access possible?
        {
            if(!(in[i]->testTokens()))
            {
                allTokens = false;
                break;
            }
        }

        if(allTokens)
        {
            std::cout << this->name() << ": Fired" << std::endl;

            for(unsigned int i = 0; i < N; i++)
                in[i]->removeTokens();

            for(unsigned int i = 0; i < M; i++)
                out[i]->addTokens();
        }
        else
            std::cout << this->name() << ": NOT Fired" << std::endl;
    }
};

#endif // TRANSITION_H
