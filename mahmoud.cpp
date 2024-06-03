#include <iostream>
#include <string>

using namespace std;

// Exercise Class
class Exercise {
private:
    string exerciseName;
    string exerciseType;
    double timeSpent;  // in minutes
    double caloriesBurnt;

public:
    // Constructors
    Exercise() : exerciseName(""), exerciseType(""), timeSpent(0), caloriesBurnt(0) {}
    Exercise(string name, string type, double time, double calories)
        : exerciseName(name), exerciseType(type), timeSpent(time), caloriesBurnt(calories) {}

    // Getters
    string getExerciseName() const { return exerciseName; }
    string getExerciseType() const { return exerciseType; }
    double getTimeSpent() const { return timeSpent; }
    double getCaloriesBurnt() const { return caloriesBurnt; }

    // Setters
    void setExerciseName(string name) { exerciseName = name; }
    void setExerciseType(string type) { exerciseType = type; }
    void setTimeSpent(double time) { timeSpent = time; }
    void setCaloriesBurnt(double calories) { caloriesBurnt = calories; }

    // Print method
    void printExerciseInfo() const {
        cout << "Exercise Name: " << exerciseName << endl;
        cout << "Exercise Type: " << exerciseType << endl;
        cout << "Time Spent: " << timeSpent << " minutes" << endl;
        cout << "Calories Burnt: " << caloriesBurnt << endl;
    }
};

// Cardio Class (inherits from Exercise)
class Cardio : public Exercise {
private:
    string intensity;
    double distance;  // in kilometers

public:
    // Constructors
    Cardio() : Exercise(), intensity(""), distance(0) {}
    Cardio(string name, string type, double time, double calories, string intensity, double distance)
        : Exercise(name, type, time, calories), intensity(intensity), distance(distance) {}

    // Getters
    string getIntensity() const { return intensity; }
    double getDistance() const { return distance; }

    // Setters
    void setIntensity(string intensity) { this->intensity = intensity; }
    void setDistance(double distance) { this->distance = distance; }

    // Print method
    void printCardioInfo() const {
        printExerciseInfo();
        cout << "Intensity: " << intensity << endl;
        cout << "Distance: " << distance << " km" << endl;
    }
};

// StrengthTraining Class (inherits from Exercise)
class StrengthTraining : public Exercise {
private:
    int setsCount;
    int repsCount;
    double weight;  // in kilograms

public:
    // Constructors
    StrengthTraining() : Exercise(), setsCount(0), repsCount(0), weight(0) {}
    StrengthTraining(string name, string type, double time, double calories, int sets, int reps, double weight)
        : Exercise(name, type, time, calories), setsCount(sets), repsCount(reps), weight(weight) {}

    // Getters
    int getSetsCount() const { return setsCount; }
    int getRepsCount() const { return repsCount; }
    double getWeight() const { return weight; }

    // Setters
    void setSetsCount(int sets) { setsCount = sets; }
    void setRepsCount(int reps) { repsCount = reps; }
    void setWeight(double weight) { this->weight = weight; }

    // Print method
    void printStrengthTrainingInfo() const {
        printExerciseInfo();
        cout << "Sets Count: " << setsCount << endl;
        cout << "Reps Count: " << repsCount << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main() {
    // Example For the usage of the classes
    Cardio run("Running", "Cardio", 30, 300, "High", 5);
    StrengthTraining lift("Weight Lifting", "Strength", 45, 400, 4, 12, 50);

    cout << "Cardio Exercise Info:" << endl;
    run.printCardioInfo();

    cout << endl;

    cout << "Strength Training Exercise Info:" << endl;
    lift.printStrengthTrainingInfo();

    return 0;
}
