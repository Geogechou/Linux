#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<ostream>
#include "userprofile.h"
using namespace std;

std::map < long, std::string > userprofile::uid;
userprofile::userprofile(string name, int c_time, int g_time,
			 userLevel lv):user_name(name),
correct_time(c_time), guess_time(g_time), level(lv)
{
    srand(time(0));
    long record = rand();
    map < long, string >::iterator it = uid.find(record);
    //保证每个用户的唯一id

    while (it != uid.end()) {
	record = rand();
	it = uid.find(record);
    }

    uid[record] = name;
    login_record = record;
    login_time = time(0);
}

bool userprofile::operator==(userprofile & up) const
{
    return this->user_name == up.user_name;
}

bool userprofile::operator!=(userprofile & up) const
{
    return !(*this == up);
}

//重载<<不可声明为成员函数
std::ostream & operator<<(std::ostream & out, userprofile & user)
{

    out << "name:" << user.user_name << ",login_time:" << user.login_time
	<< ",login_record:" << user.login_record 
	<< ",guess_time:" << user.guess_time 
	<< ",correct_time:" << user.correct_time 
	<< ",level:" << user.level << endl;
    return out;
}

