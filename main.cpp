#include <iostream>
#include <string>
using namespace std;



class User{
    string userID;
    string name;
    int age;
    double height;
    double weight;
    double bmi;
    string password;
    DailyLog userLog[100];
    Goal userGoal[100];

    public:
        User(string n,string p,int a,double w,double h) : name(n),password(p),height(h),weight(w),age(a){
            userID = "User" + to_string(rand());
        }
};


class UserRecord{

};


class Goal{

};

class DailyLog{

};


int main(){
    return 0;
}