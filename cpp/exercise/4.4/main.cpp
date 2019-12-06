#include<iostream>
#include "userprofile.h"

int main()
{
    userprofile user("george", 5, 10);
    userprofile user2("georges", 4, 10, userprofile::Master);
    std::cout << user;
    bool res = (user != user2);
    std::cout << "user!=user2? " << res << std::endl;
    return 0;
}
