#include <systemc.h>

#include "transition.h"
#include "place.h"

// TOPLEVEL
SC_MODULE(subnet)
{
public:
    transition<1, 1, 1> ACT;
    transition<1, 1, 0> RD, PRE, WR;
    place<1, 1> ACTIVE;

    SC_CTOR(subnet) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"),
                      ACTIVE(0)
    {
        ACT.out(ACTIVE);
        ACT.inhibitors(ACTIVE);
        RD.in(ACTIVE);
        RD.out(ACTIVE);
        PRE.in(ACTIVE);
        WR.in(ACTIVE);
        WR.out(ACTIVE);
    }
};


SC_MODULE(toplevel)
{
public:
    subnet s1, s2;
    place<1, 1> IDLE;

    SC_CTOR(toplevel) : s1("s1"), s2("s2"),
                        IDLE(2)
    {
        SC_THREAD(process);
        s1.ACT.in(IDLE);
        s1.PRE.out(IDLE);
        s2.ACT.in(IDLE);
        s2.PRE.out(IDLE);
    }

    void process()
    {
        while(true)
        {
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s1.RD.fire();
            wait(10,SC_NS);
            s1.WR.fire();
            wait(10,SC_NS);
            s1.PRE.fire();
            wait(10,SC_NS);
            s1.ACT.fire();
            wait(10,SC_NS);
            s2.ACT.fire();
            wait(10,SC_NS);
            s2.ACT.fire();
            wait(10,SC_NS);
            s1.PRE.fire();
            wait(10,SC_NS);
            s2.PRE.fire();
            wait(10,SC_NS);
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
