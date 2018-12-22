#include <systemc.h>

#include "transition.h"
#include "place.h"

// TOPLEVEL

SC_MODULE(toplevel)
{
public:
    transition t1, t2;
    place p1, p2;

    SC_CTOR(toplevel) : t1("t1"), t2("t2"), p1(1), p2(0)
    {
        SC_THREAD(process);
        t1.in.bind(p1);
        t1.out.bind(p2);
        t2.in.bind(p2);
        t2.out.bind(p1);
    }

    void process()
    {
        while(true)
        {
            wait(10,SC_NS);
            t1.fire();
            wait(10,SC_NS);
            t1.fire();
            wait(10,SC_NS);
            t2.fire();
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
