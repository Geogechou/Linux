#ifndef USER_PROFILE_H_
#define USER_PROFILE_H_
#include<string>
#include<map>
#include<ostream>
class userprofile {

    friend std::ostream & operator<<(std::ostream & out, userprofile & up);
  public:
    enum userLevel {
	Beginner,
	Professioner,
	Master
    };
     userprofile(std::string name, int correct_time, int guess_time,
		 userLevel lv = Beginner);
    bool operator==(userprofile & up) const;
    bool operator!=(userprofile & up) const;
  private:
     std::string user_name;
    int login_record;
    long login_time;
    int guess_time;
    int correct_time;
    userLevel level;
    static std::map < long, std::string > uid;
};
#endif
