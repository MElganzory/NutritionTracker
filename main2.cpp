#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <tuple>

using namespace std;

class FoodItem{

    private: 

    string name;
    float calories;
    float sugar;
    float sodium;
    float fats;
    float carbs;
    float protein;

    public:
        // CONSTRUCTOR 
        FoodItem(string n = "",float c = 0.0, float s = 0.0, float sod = 0.0, float fat = 0.0, float carb = 0.0 ,float p = 0.0){
            
            // name,calories,sugar,sodium,fats,carbs,protein-> in this order if you want to add items to the file list 
            name = n;
            calories = c;
            sugar = s;
            sodium = sod;
            fats = fat;
            carbs = carb;
            protein=p;
        }
        // SETTERS 
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

        void setProtein(float p) { 

            protein = p;
        }
        //GETTERS 

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
        float getProtein(){ 
            return protein; 
        }

         string getItemInfo() {

            string info;
            info += "Name: " + name + "\n";
            info += "Calories: " + to_string(calories) + " kcal\n";
            info += "Sugar: " + to_string(sugar) + "g\n";
            info += "Sodium: " + to_string(sodium) + "mg\n";
            info += "Fats: " + to_string(fats) + "g\n";
            info += "Carbs: " + to_string(carbs) + "g\n";
            info += "Protein: " + to_string(protein) + "g\n";
            return info;
        }

        void getItemInput() {

            cout << "Item name: ";
            getline(cin, name);

            cout << "Calories: ";
            cin >> calories;
            cin.ignore();

            cout << "Sodium: ";
            cin >> sodium;
            cin.ignore();

            cout << "Fats: ";
            cin >> fats;
            cin.ignore();

            cout << "Carbs: ";
            cin >> carbs;
            cin.ignore();

            cout << "Sugar: ";
            cin >> sugar;
            cin.ignore();

            cout << "Protein: ";
            cin >> protein;
            cin.ignore();
        }
};

class Meal {
    string mealName;
    FoodItem foodItems[100];
    int foodItemsCount{0};
    double totalCalories{0.0};

    public:
        Meal(string n = "") : mealName(n) {}

        string getMealName() {
             return mealName; 
        }

        void printMeal() {
            cout << "Meal : " << mealName << endl;
            cout << "------------------------------------------" << endl;



            for (int i = 0; i < foodItemsCount; i++) {
                cout << foodItems[i].getItemInfo() << endl;
                cout << "------------------------------------------" << endl;
            }
        }

        string getMealInfo() {
            return "Meal: " + mealName + " Total Calories: " + to_string(totalCalories);
        }

        void addFoodItems(FoodItem* fooditem) {
            foodItems[foodItemsCount] = *fooditem;
            foodItemsCount++;
            calculateCalorie();
        }

        void calculateCalorie() {
            double sumCalories{0.0};
            for (int i = 0; i < foodItemsCount; i++) {
                sumCalories += foodItems[i].getKcal();
            }
            totalCalories = sumCalories;
        }
};

class Goal {
    string goalName;
    string goalDesc;
    bool goalStatus{false};
    tm setDate;

    public:
        Goal(string gN = "", string gD = "") : goalName(gN), goalDesc(gD) {}

        string getGoalName(){ 
            return goalName;
         }
        string getGoalDesc(){
             return goalDesc;
         }
        bool getGoalStatus(){ 

            // if (goalStatus){
            //     return "Goal Achieved";
            // }
            // else{
            //     return "Unfinished Goal";
            // }
            return goalStatus;
         }
        void setGoalStatus(){ 
            goalStatus = !goalStatus;
         }

        void setGoal() {
            cout << "Goal Name: ";
            getline(cin, goalName);

            cout << "Goal Description: ";
            getline(cin, goalDesc);
        }
};

class DailyLog {
    string logName;
    Meal* meals[100];
    int mealCount{0};

    // add exercise array here

    public:
        DailyLog() {
            logName = "Log : " + to_string(rand());
        }

        void addMeal(Meal* meal) {
            meals[mealCount] = meal;
            meals[mealCount]->calculateCalorie();
            mealCount++;
        }

        string getLogName(){
             return logName; 
        }

        void printAllMeals() {
            for (int i = 0; i < mealCount; i++) {
                cout << "#" << i + 1 << " " << meals[i]->getMealInfo() << endl;
            }
        }
};

class User {
    string userID;
    string name;
    int age;
    double height;
    double weight;
    double bmi;
    string password;
    DailyLog userLog[100];
    Goal userGoal[100];
    int userLogCount{0};// remember to change to zero back
    int userGoalCount{0};

    public:
        User(string n = "", string p = "", int a = 0, double w = 0.0, double h = 0.0) : name(n), password(p), height(h), weight(w), age(a) {
            userID = "User" + to_string(rand());
            calculateBMI();
        }

        string getName(){
            return name;
         }
        string getUserID(){
            return userID;
         }
        void setUserID(string UID){ 
            userID = UID;  // temporary
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

        void displayInfo() {
            cout << "-------------------------------------------------------------" << endl;
            cout << "User Information: " << endl;
            cout << "Name : " << name << endl << "Age: " << age << endl << "Height: " << height << endl << "Weight: " << weight << endl << "BMI: " << bmi << endl;
            // below here would be the dailyLog
            // below here world be goals
            cout << "-------------------------------------------------------------" << endl;
        }

        void calculateBMI() {
            bmi = weight / ((height * height / 100));
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

        DailyLog* getCurrLog() {
            return &userLog[userLogCount];
        }

        void displayAllDailyLog() {
            for (int i = 0; i < userLogCount + 1; i++) {
                cout << "#" << i + 1 << " Daily Log" << endl;
                userLog[i].printAllMeals();
            }
        }

        void addDailyLog() {
            userLogCount++;
        // we dont need to create new log all log object exist and constructor already execute

        }

        void displayAllGoals() {
            for (int i = 0; i < userGoalCount; i++) {
                cout << "#" << i + 1 << " Goal" << "\nUser Goal: " << userGoal[i].getGoalName() << "\nGoalDesc: " << userGoal[i].getGoalDesc() << "\nGoalStatus: " << userGoal[i].getGoalStatus() << endl;
            }
        }

        void createGoal() {
            userGoal[userGoalCount].setGoal();
            userGoalCount++;
        }

        void setGoalStatus(int goalNum) {
            if (goalNum - 1 < userGoalCount) {
                userGoal[goalNum - 1].setGoalStatus();
                cout << "Goal Successfully Changed" << endl;
            } else {
                cout << "No Particular Goal";
            }
        }
};

class UserRecord {
    User* userProfile[100];
    int userProfileCount{0};

    public:
        UserRecord() {}

        void addUser(User* user) {
            userProfile[userProfileCount] = user;
            userProfileCount++;
        }

        void removeUser(string userID) {
            for (int i = 0; i < userProfileCount; i++) {
                if (userProfile[i]->getUserID() == userID) {
                    userProfile[i] = nullptr;
                    userProfileCount--;
                    break;
                }
            }
        }

        int getUserCount() {
            return userProfileCount;
        }

        User* getUser(int i) {
            return userProfile[i];
        }
};

void registerUser(UserRecord* data) {
    string name;
    int age;
    double height;
    double weight;
    string password;

    cout << "Name: ";
    getline(cin, name);

    cout << "Age: ";
    cin >> age;
    cin.ignore();

    cout << "Height: ";
    cin >> height;
    cin.ignore();

    cout << "Weight: ";
    cin >> weight;
    cin.ignore();

    cout << "Your Password: ";
    getline(cin, password);

    try {
        User* userRegistered = new User(name, password, age, height, weight);
        cout << "Successfully Registered" << endl;
        cout << "Please Remember your ID" << endl;
        cout << "Your ID: " << userRegistered->getUserID() << endl;
        data->addUser(userRegistered);
    } catch (...) {
        cout << "Invalid input somewhere kindly register again";
    }
}





tuple<bool, User*> log_in(UserRecord* data) {
    string userID;
    string password;

    cout << "------------------------" << endl;
    cout << "Your UserID: ";
    getline(cin, userID);
    cout << "Your Password: ";
    getline(cin, password);
    cout << "-------------------------" << endl;

    for (int i = 0; i < data->getUserCount(); i++) {
        if (data->getUser(i)->checkUserName(userID)) {
            if (data->getUser(i)->checkPassword(password)) {
                return make_tuple(true, data->getUser(i));
            } else {
                cout << "Invalid Password Try Again" << endl;
            }
        } else {
            cout << "User not found" << endl;
        }
    }
    return make_tuple(false, nullptr);
}

void loadFoodItems(FoodItem foodItems[], int& count) { // ADDED 
    ifstream file("food_items.txt");
    if (!file) {
        cout << "Error: Unable to open food items file." << endl;
        return;
    }

    string name;
    float calories, sugar, sodium, fats, carbs, protein;
    count = 0;

    while (file >> name >> calories >> sugar >> sodium >> fats >> carbs >> protein) {
        foodItems[count] = FoodItem(name, calories, sugar, sodium, fats, carbs, protein);
        count++;
    }

    file.close();
}

void displayFoodItems(FoodItem foodItems[], int count) { //ADDED 
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << foodItems[i].getName() << " (" << foodItems[i].getKcal() << " kcal)" << endl;
    }
}



void mealFeature(DailyLog* currLog, FoodItem foodItems[], int foodItemCount) { // CORECTED to give the user choice either to add himself of choose 
    int numOfFoodItems{0};
    string mealName;
    cout << "----------Add Meals------------" << endl;

    cout << "Name of the Meal: ";
    getline(cin, mealName);
    Meal* newMeal = new Meal(mealName);

    int choice;
    cout << "How would you like to add food items?\n1. Choose from the file\n2. Enter manually\n";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "How many items do you want to add from the list?: ";
        cin >> numOfFoodItems;
        cin.ignore();

        for (int i = 0; i < numOfFoodItems; i++) {
            int itemChoice;
            displayFoodItems(foodItems, foodItemCount);
            cout << "Choose an item by number: ";
            cin >> itemChoice;
            cin.ignore();

            if (itemChoice > 0 && itemChoice <= foodItemCount) {
                newMeal->addFoodItems(&foodItems[itemChoice - 1]);
            } else {
                cout << "Invalid choice, try again." << endl;
                i--; // Retry the current item
            }
        }
    } else if (choice == 2) {
        cout << "How many items do you want to add manually?: ";
        cin >> numOfFoodItems;
        cin.ignore(); //  assume the right input is given;

        for (int i = 0; i < numOfFoodItems; i++) {
            FoodItem newItem;
            cout << "Enter details for item " << i + 1 << ":\n";
            newItem.getItemInput();
            newMeal->addFoodItems(&newItem);
        }
    } else {
        cout << "Invalid choice, returning to menu.\n";
        return;
    }

    currLog->addMeal(newMeal);
    cout << "Meals Added Successfully!!" << endl;
}

void menu(User* user, FoodItem foodItems[], int foodItemCount) {
    int choice{0};
    int goalChoice{0};
    DailyLog* currLog{user->getCurrLog()};
    cout << "WELCOME TO NUTATION CHECKER APP" << endl;

    while (choice != 9) {
        cout << "-------------------------------------------------------nuTrackerApp HomePage-------------------\n";
        cout << "1. Add Meals\t2. Add Exercise\t3. Add Goals\t4. View Goals\t5. Set Goals\t6. View Daily Log\n7. Add Daily Log\t8. Display User Info\t9. Exit" << endl;
        cout << "------------------------------------------------------------------------------------------------\n";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                mealFeature(currLog, foodItems, foodItemCount);
                break;
            case 2:
                // Add exercise feature here
                break;
            case 3:
                user->createGoal();
                cout << "Goal Successfully Created" << endl;
                break;
            case 4:
                cout << "Displaying All Goals" << endl;
                cout << "-----------------------------" << endl;
                user->displayAllGoals();
                cout << "-----------------------------" << endl;
                break;
            case 5:
                cout << "Change Goal Status" << endl;
                cout << "-----------------------------" << endl;
                user->displayAllGoals();
                cout << "-----------------------------" << endl;
                cout << "Which Goals you have finished? :";
                cin >> goalChoice;
                user->setGoalStatus(goalChoice);
                break;
            case 6:
                cout << "Displaying All Daily Logs" << endl;
                cout << "-----------------------------" << endl;
                user->displayAllDailyLog();
                cout << "-----------------------------" << endl;
                break;
            case 7:
                user->addDailyLog();
                currLog = user->getCurrLog();
                cout << "Successfully Created New Daily Log" << endl;
                break;
            case 8:
                user->displayInfo();
                break;
        }
    }
}

int main() {
    UserRecord AllData;
    FoodItem foodItems[100];
    int foodItemCount{0};

    loadFoodItems(foodItems, foodItemCount);

    User* userTest = new User("Zayyad", "123", 21, 45.0, 170.0);
    userTest->setUserID("user123");
    // userTest->setPassword("123");
    AllData.addUser(userTest);

    int status{1};
    int choice{0};

    bool logged_in{false};
    User* userInfo{nullptr};

    while (status == 1) {
        cout << "1. Log In\t2. Register\t3. Exit: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                tie(logged_in, userInfo) = log_in(&AllData);
                status = 2;
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

    if (logged_in) {
        menu(userInfo, foodItems, foodItemCount);
        logged_in = false;
    }
    return 0;
}
