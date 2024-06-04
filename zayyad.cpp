#include <iostream>
#include <string>
#include <tuple>

using namespace std;



class Goal{
    string goalName;
    string goalDesc;
    bool goalStatus {false};

    public:
        Goal(string gN = "", string gD = "") : goalName(gN),goalDesc(gD){}

        string getGoalName(){
            return goalName;
        } 
        string getGoalDesc(){
            return goalDesc;
        }
        string getGoalStatus(){
            if (goalStatus){
                return "Goal Achieved";
            }
            else{
                return "Unfinished Goal";
            }
        }

        void setGoal(){
            cout  << "Goal Name: ";
            getline(cin,goalName);

            cout << "Goal Description: ";
            getline(cin,goalDesc);
        }

        void setGoalStatus(){
            goalStatus = !goalStatus;
        }

        void setName(string n){
            goalName = n;
        }

        void setDesc(string desc){
            goalDesc = desc;
        }
};

class User{
    string userID;
    string name;
    int age;
    double height;
    double weight;
    double bmi;
    string password;
    // DailyLog userLog[100];
    Goal userGoal[100];
    int userLogCount {0}; // remember to change to zero back
    int userGoalCount {0};

    public:
        User(string n = "",string p = "",int a = 0,double w = 0.0,double h = 0.0) : name(n),password(p),height(h),weight(w),age(a){
            userID = "User" + to_string(rand());
            calculateBMI();
        }
        

        string getName(){
            return name;
        }

        string getUserID(){
            return userID;
        }

        int getAge(){
            return age;
        }
        double getHeight(){
            return height;
        }
        double getWeight(){
            return weight;
        }      


        void setName(string n){
            name = n;
        };
        void setPassword(string p){
            password = p;
        }
        void setUserID(string UID){
            userID = UID;
        } // temporary 

        void setAge(int a){
            age = a;
        }

        void setHeight(double h){
            height = h;
        }

        void setWeight(double w){
            weight  = w;
        }

        // other functions 

        void displayInfo(){
            cout << "------------------------DISPLAY INFORMATION---------------------" << endl;
            cout << "User Information: " << endl;
            cout << "Name : " << name << endl << "Age: "  << age << endl << "Height: " << height  << endl << "Weight: " << weight << endl << "BMI: " << bmi << endl;
            cout << "---------------------------------------------------------------" << endl;
        }

        void calculateBMI(){
            bmi = weight/((height*height/100));
        }

        bool checkUserName(string uID){
            if (userID == uID){
                return true;
            }
            return false;
        }

        bool checkPassword(string pass){
            if (password == pass){
                return true;
            }
            return false;
        }

        // DailyLog* getCurrLog(){
        //     return &userLog[userLogCount];
        // }

        // void displayAllDailyLog(){
        //     for (int i = 0; i < userLogCount + 1 ;i++){
        //         cout << "#" << i + 1 << " Daily Log" << endl;
        //         userLog[i].printAllMeals();
        //     }
        // }

        void addDailyLog(){
            userLogCount++;
            // we dont need to create new log all log object exist and constructor already execute
        }        

        void displayAllGoals(){
            for ( int i = 0; i < userGoalCount; i++){
                cout << "#" << i + 1 << " Goal" << "\nUser Goal: " << userGoal[i].getGoalName()  << "\nGoalDesc: " << userGoal[i].getGoalDesc() << "\nGoalStatus: " << userGoal[i].getGoalStatus() << endl;   
                cout << "--------------------------------------" << endl;
            }
        }

        void createGoal(){
            userGoal[userGoalCount].setGoal();
            userGoalCount++;
        }

        void setGoalStatus(int goalNum){
            if (goalNum - 1 < userGoalCount + 1){
                userGoal[goalNum - 1].setGoalStatus();
                cout << "Goal Successfully Changed" << endl;
            }
            else{
                cout << "No Particular Goal";
            }
        }

};


class UserRecord{
    User *userProfile[100];
    int userProfileCount {0};

    public:
        UserRecord(){}
        void addUser(User *user){
            userProfile[userProfileCount] = user;
            userProfileCount++;
        }
        void removeUser(string userID){
            for (int i = 0; i < userProfileCount; i++){
                if (userProfile[i]->getUserID() == userID){
                    userProfile[i] = nullptr;
                    userProfileCount--;
                    break;
                }
            }
        }
        int getUserCount(){
            return userProfileCount;
        }   
        User* getUser(int i){
            return userProfile[i];
        }
};



void registerUser(UserRecord *data){
    string name;
    int age;
    double height;
    double weight;
    string password;

    cout << "Name:";
    getline(cin,name);

    cout << "Age:";
    cin >> age;
    cin.ignore();
    
    cout << "Height:";
    cin >> height;
    cin.ignore();
    
    cout << "Weight:";
    cin >> weight; 
    cin.ignore();

    cout << "Your Password:";
    getline(cin,password);

    try {
        User *userRegistered  = new User(name,password,age,height,weight);
        cout << "Successfully Registered" << endl;
        cout << "Please Remember your ID" << endl;
        cout << "Your ID: " << userRegistered->getUserID() << endl;
        data->addUser(userRegistered);
    }
    catch(...){
        cout << "Invalid input somewhere kindly register again";
    }
}



tuple <bool,User*> log_in(UserRecord *data){
    
    string userID;
    string password;

    cout << "------------------------" << endl;
    cout << "Your UserID: ";
    getline(cin,userID);
    cout << "Your Password: ";
    getline(cin,password);
    cout << "-------------------------" << endl;

    for (int i = 0; i < data->getUserCount(); i++){
        if (data->getUser(i)->checkUserName(userID)){
            if(data->getUser(i)->checkPassword(password)){
                return make_tuple(true,data->getUser(i));
            }
            else{
                cout << "Invalid Password Try Again" << endl;
                break;
            }
        }
        else{
            cout << "User not found" << endl;
        }
    }
    return make_tuple(false,nullptr);

}



void menu(User *userLogged){
    int choice {0};
    int goalChoice {0};

    while (choice != 5){
        cout << "-------------------------------------------------------------------" << endl;
        cout << "1.Add Goal\t2.View Goal\t3.Checkmark Goal\t4.Display Profile\t5.Exit" << endl;
        cout << "-------------------------------------------------------------------" << endl;

        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                cout << "--------------------CREATE GOAL-----------" << endl;
                userLogged->createGoal();
                cout << "-------------------------------------------" << endl;
                break;
            case 2:
                cout << "--------------DISPLAY GOAL------------" << endl;
                userLogged->displayAllGoals();
                break;
            case 3:
                cout << "---------------CHECKMARK GOAL----------------" << endl;
                userLogged->displayAllGoals();
                
                cout << "\n Which Goals you have achieved" << endl;
                cin >> goalChoice;
                cin.ignore();

                userLogged->setGoalStatus(goalChoice);
                break;
            case 4:
                cout << "---------------DISPLAY PROFILE-----------" << endl;
                userLogged->displayInfo();
                break;
        }
    }
}

int main(){

    UserRecord AllData;

    User *userTest = new User("Zayyad","123",21,45.0,170.0);
    userTest->setUserID("user123");
    User *userTest2 = new User("Ahmad","456",30,65,180.0);
    userTest2->setUserID("user345");

    AllData.addUser(userTest);
    AllData.addUser(userTest2);
    
    bool logged_in {false};
    User *userInfo{nullptr};

    int choice {0};


    while (choice != 3){
        cout << "-----------------------------------" << endl;
        cout << "1. Register\t 2.Log In\t 3.Exit:" << endl;
        cout << "-----------------------------------" << endl;

        cin >> choice;
        cin.ignore();

        switch (choice){
            case 1:
                registerUser(&AllData);
                break;
            case 2:
                tie(logged_in,userInfo) = log_in(&AllData);
                if(logged_in){
                    menu(userInfo);
                }
                break;
        }    
    }

    return 0;
}