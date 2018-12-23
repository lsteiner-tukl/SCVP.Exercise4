#include <systemc.h>

#include "transition.h"
#include "place.h"

// TOPLEVEL

SC_MODULE(toplevel)
{
public:
    transition<1,1> ACT, RD, PRE, WR;
    place<1,1> IDLE, ACTIVE;

    SC_CTOR(toplevel) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"),
                        IDLE(1), ACTIVE(0)
    {
        SC_THREAD(process);
        ACT.in(IDLE);
        ACT.out(ACTIVE);
        RD.in(ACTIVE);
        RD.out(ACTIVE);
        PRE.in(ACTIVE);
        PRE.out(IDLE);
        WR.in(ACTIVE);
        WR.out(ACTIVE);
    }

    void process()
    {
        while(true)
        {
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            ACT.fire();
            wait(10,SC_NS);
            RD.fire();
            wait(10,SC_NS);
            WR.fire();
            wait(10,SC_NS);
            PRE.fire();
            wait(10,SC_NS);
            ACT.fire();
            sc_stop();
        }
    }
};

int sc_main(int argc, char* argv[])
{
    toplevel t("t");

    sc_start();
    return 0;
}
