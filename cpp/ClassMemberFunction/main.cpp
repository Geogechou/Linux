#include<iostream>
#include "num_sequence.h"

int main()
{

    int pos = 10;
    num_sequence ns;
    ns.ns_type(5);
    int res = ns.get_elem(pos);
    std::cout << "pos " << pos << "=" << res << std::endl;
    return 0;
}
