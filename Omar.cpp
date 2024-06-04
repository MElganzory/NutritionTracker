#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class FoodItem {
    string name;
    float calories;
    float sugar;
    float sodium;
    float fats;
    float carbs;
    float protein;

public:
    FoodItem(string n = "", float c = 0.0, float s = 0.0, float sod = 0.0, float fat = 0.0, float carb = 0.0, float p = 0.0)
        : name(n), calories(c), sugar(s), sodium(sod), fats(fat), carbs(carb), protein(p) {}


    //SETTERS 
    void setName(string n) {
         name = n;
     }
    void setKcal(float cal) { 
        calories = cal;
    }
    void setSugar(float sug) { 
        sugar = sug;
     }
    void setSodium(float sod) {
         sodium = sod; 
    }
    void setFats(float fat) {
         fats = fat;
     }
    void setCarbs(float carb) { 
        carbs = carb; 
    }
    void setProtein(float p) {
         protein = p;
     }

    //GETTERS
    
    string getName() { return name; }
    float getKcal() { return calories; }
    float getSugar() { return sugar; }
    float getSodium() { return sodium; }
    float getFats() { return fats; }
    float getCarbs() { return carbs; }
    float getProtein() { return protein; }

    string getItemInfo() {
        string info;
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

    string getMealName() { return mealName; }

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

    string getLogName() { return logName; }

    void printAllMeals() {
        for (int i = 0; i < mealCount; i++) {
            cout << "#" << i + 1 << " " << meals[i]->getMealInfo() << endl;
        }
    }
};

int main() {
   

    // Create some FoodItem objects
    FoodItem apple("Apple", 52, 10, 1, 0.2, 14, 0.3);
    FoodItem banana("orange", 89, 12, 1, 0.3, 23, 1.1);
    FoodItem sandwich(" chicken Sandwich", 250, 4, 500, 10, 30, 12);

    // Creating a Meal object
    Meal breakfast("Breakfast");

    // Add FoodItems to the Meal
    breakfast.addFoodItems(&apple);
    breakfast.addFoodItems(&banana);
    breakfast.addFoodItems(&sandwich);

    // Print the Meal details
    breakfast.printMeal();
    cout << breakfast.getMealInfo() << endl;

    // Create a DailyLog object
    DailyLog dailyLog;

    // Add the Meal to the DailyLog
    dailyLog.addMeal(&breakfast);

    // Print all meals in the DailyLog
    cout << "Daily Log: " << dailyLog.getLogName() << endl;
    dailyLog.printAllMeals();

    return 0;
}
