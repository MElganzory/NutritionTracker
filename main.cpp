#include <iostream>
#include <string>
#include <time.h>
using namespace std;



class FoodItem{
    string name;
    float calories;
    float sugar;
    float sodium;
    float fats;
    float carbs;

    public:
        FoodItem(string n = "",float c = 0.0, float s = 0.0, float sod = 0.0, float fat = 0.0, float carb = 0.0){
            name = n;
            calories = c;
            sugar = s;
            sod = sodium;
            fats = fat;
            carbs = carb;
        }

        void setName(string n){
            name = n;
        }

        void setKcal(float cal){
            calories = cal;
        }

        void setSugar(float sug){
            sugar = sug;
        }

        void setSodium(float sod){
            sodium = sod;
        }

        void setFats(float fat){
            fats = fat;
        }

        void setCarbs(float carb){
            carbs = carb;
        }

        
        string getName(){
             return name;
        }

        float getKcal(){
             return calories;
        }

        float getSugar(){
             return sugar;
        }

        float getSodium(){
             return sodium;
        }

        float getFats(){
            return fats;
        }

        float getCarbs(){
            return carbs;
        }

        string getItemInfo(){
            string info;
            info += "Calories: " + to_string(calories) + " kcal\n";
            info += "Sugar: " +to_string(sugar) + "g\n";
            info += "Sodium: " +to_string(sodium) + "mg\n";
            info += "Fats: " +to_string(fats) + "g\n";
            info += "Carbs: " + to_string(carbs) + "g\n";
            return info;
        }
        



};

class Meal{
    string mealName;
    FoodItem *foodItems[100];
    int foodItemsCount {0};
    double totalCalories {0.0};

    public:
        Meal(string n = "") : mealName(n){}
        
        string getMealName(){
            return mealName;
        }
        
        void printMeal(){
            cout << "Meal : " << mealName << endl;
            cout << "------------------------------------------" << endl;


            for (int i = 0; i < foodItemsCount; i++){
                cout << foodItems[i]->getItemInfo() << endl;
                cout << "------------------------------------------" << endl;
            }
        }

        string getMealInfo(){
            return "Meal: " + mealName + " Total Calories: " + to_string(totalCalories);
        }

        void addFoodItems(FoodItem *fooditem){
            foodItems[foodItemsCount];
            foodItemsCount++;
        }

        void calculateCalorie(){
            double sumCalories {0.0};
            for (int i = 0; i < foodItemsCount; i++){
                sumCalories += foodItems[i]->getKcal();
            }
            totalCalories = sumCalories;
        }
};



class Goal{
    string goalName;
    string goalDesc;
    bool goalStatus;
    tm setDate;

    public:
        Goal(string gN = "", string gD = "") : goalName(gN),goalDesc(gD){
            goalStatus = false;
        }

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
            return "Unfinished Goal";
        }
        void setGoalStatus(){
            goalStatus = !goalStatus;
        }
};

class DailyLog{
    string logName;
    Meal *meals[100];
    int mealCount { 0 };
    // add exercise array here

    public:
        DailyLog(){
            logName = "Log : " + to_string(rand()) ;
        }

        void addMeal(Meal *meals){
            meals[mealCount];
            mealCount++;
        }

        string getLogName(){
            return logName;
        }

        void printAllMeals(){
            for (int i = 0; i < mealCount ; i++){
                cout << "#" << i+1 << " " << meals[i]->getMealInfo() << endl;
            }
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
    DailyLog userLog[100];
    Goal userGoal[100];

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
        void setPassword(string p){
            password = p;
        }
        void displayInfo(){
            cout << "-------------------------------------------------------------" << endl;
            cout << "User Information: " << endl;
            cout << "Name : " << name << endl << "Age: "  << age << endl << "Height: " << height  << endl << "Weight: " << weight << endl << "BMI: " << bmi << endl;
            // below here would be the dailyLog
            // below here world be goals
            cout << "-------------------------------------------------------------" << endl;
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


bool log_in(UserRecord *data){
    
    string userID;
    string password;

    cout << "------------------------" << endl;
    cout << "Your UserID:";
    getline(cin,userID);
    cout << "Your Password";
    getline(cin,password);
    cout << "-------------------------" << endl;

    for (int i = 0; i < data->getUserCount(); i++){
        if (data->getUser(i)->checkUserName(userID)){
            if(data->getUser(i)->checkPassword(password)){
                return true;
            }
            else{
                cout << "Invalid Password Try Again" << endl;
            }
        }
        else{
            cout << "User not found" << endl;
            return false;
        }
    }
}


int main(){

    UserRecord AllData;
    int status {1};
    int choice {0};
    bool logged_in {false};

    while (status == 1){

        cout << "1. Log In\t 2.Register\t 3.Exit:  ";
        cin >> choice;
        cin.ignore();

        switch(choice){
            case 1:
                logged_in = log_in(&AllData);
                break;
            case 2:
                registerUser(&AllData);
                break;
            case 3:
                status = 2;
                break;
            default:
                status = 1; 
        }
    }

    if (logged_in){
        
    }
    
    // for (int i = 0; i < AllData.getUserCount(); i++){
    //     User* currUser = AllData.getUser(i);
    //     currUser->displayInfo();
    // }


    return 0;
}