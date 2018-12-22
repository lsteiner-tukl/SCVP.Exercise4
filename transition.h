#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <systemc.h>
#include "place.h"

SC_MODULE(transition)
{
public:
    sc_port<place> in, out;

    SC_CTOR(transition): in("in"), out("out")
    {}

    void fire();
};

#endif // TRANSITION_H
