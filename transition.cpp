#include "transition.h"

void transition::fire()
{
    if(in->testTokens() >= 1)
    {
        std::cout << this->name() << ": Fired" << std::endl;
        in->removeTokens(1);
        out->addTokens(1);
    }
    else
        std::cout << this->name() << ": NOT Fired" << std::endl;
}
