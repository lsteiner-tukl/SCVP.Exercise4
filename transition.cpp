#include "transition.h"

/*
template<unsigned int N, unsigned int M>
void transition<N, M>::fire()
{
    bool allTokens = true;

    for(unsigned int i = 0; i < N; i++) // N access possible?
    {
        if(in[i]->testTokens() == 0)
        {
            allTokens = false;
            break;
        }
    }

    if(allTokens)
    {
        std::cout << this->name() << ": Fired" << std::endl;

        for(unsigned int i = 0; i < N; i++)
            in[i]->removeTokens(1);

        for(unsigned int i = 0; i < M; i++)
            out[i]->addTokens(1);
    }
    else
        std::cout << this->name() << ": NOT Fired" << std::endl;
}
*/
