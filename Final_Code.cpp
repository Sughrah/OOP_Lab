#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>   // For _getch()
#include <windows.h> // For colors and Sleep()
#include <ctime>     // For time-related functions
#include <cstdlib>   // For exit(), rand(), srand()
#include <iomanip>   // For std::setw
#include <sstream>   // For string streams
#include <limits>    // For numeric_limits

// Define color codes for console text
#define RESET_COLOR 7
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define BOLD_WHITE 15
#define BOLD_CYAN 11
#define BOLD_GREEN 10
#define BOLD_RED 12
#define BOLD_YELLOW 14

// Global handle for console manipulation
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// --- Utility and UI Functions ---
// Encapsulating low-level UI functions
void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void clearScreen() {
    system("cls");
}

void printHeader() {
    clearScreen();
  setColor(BOLD_YELLOW);
    std::cout << "\n\n";
    std::cout << "\t\t\t\t __      __     .__ .__           .__        \n";
    std::cout << "\t\t\t\t/  \\    /  \\  ____ |  | |  |   ___  __ |__| ______        \n";
    setColor(BOLD_CYAN);
    std::cout << "\t\t\t\t\\  \\/\\/  \\/ / __ \\|  | |  |   \\  \\/ / |  |/  ___/   \n";
    std::cout << "\t\t\t\t \\        / \\  ___/|  |_|  |__  \\  \\/  |  |\\___ \\      \n";
    setColor(BOLD_YELLOW);
    std::cout << "\t\t\t\t  \\__/\\  /    \\___  >____/____/    \\_/   |__/____  >      \n";
    std::cout << "\t\t\t\t      \\/      \\/                             \\/      \n";
    setColor(YELLOW);
    std::cout << "\t\t\t\t-----------------------------------------------------------\n";
    std::cout << "\t\t\t\t      Your Personal Productivity & Lifestyle Hub\n";
    std::cout << "\t\t\t\t-----------------------------------------------------------\n\n";
    setColor(RESET_COLOR);
}

void printSubHeader(const std::string& title) {
    printHeader();
    setColor(BOLD_YELLOW);
    std::cout << "\n\t\t\t\t<<<<<<<<<<<<<< " << title << " >>>>>>>>>>>>>>\n\n";
    setColor(RESET_COLOR);
}

void createFileIfNotExists(const std::string& filename) {
    std::ofstream file(filename, std::ios::app);
    file.close();
}

std::string getCurrentDateString() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "-" << std::setw(2) << std::setfill('0') << ltm->tm_mday;
    return ss.str();
}

std::string getCurrentMonthAndYear() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
    return ss.str();
}

std::string getYesterdayDateString() {
    time_t now = time(0);
    now -= 24 * 60 * 60;
    tm *ltm = localtime(&now);
    std::stringstream ss;
    ss << 1900 + ltm->tm_year << "-" << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon << "-" << std::setw(2) << std::setfill('0') << ltm->tm_mday;
    return ss.str();
}

// Function to safely get a validated integer input
int getValidInt(int min, int max) {
    int value;
    while (true) {
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout << "\t\tInvalid input. Please enter a number between " << min << " and " << max << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// --- Data Structures ---
struct Date {
    int day, month, year;
};

// --- OOP Core Classes ---

// Base Class for all Application Modules
// This is a key part of polymorphism. All modules will inherit from this class.
class Module {
protected:         // This is main parrents class from which task management, fitness, habit, finance and mental wellness classes will inherit
    std::string currentUser;
public:
    Module(const std::string& user) : currentUser(user) {}
    virtual ~Module() = default;

    // A pure virtual function. This forces all derived classes to implement a `runMenu` method.
    // This is the core of our polymorphic design.
    virtual void runMenu() = 0;
};

// User Management Class (Encapsulates user data and authentication logic)
class User {
private:
    std::string username;
    std::string password;
    std::string email;

    std::string cipher(const std::string& text) {
        std::string result = text;
        for (char& c : result) {
            c += 5;
        }
        return result;
    }

public:
    void registerUser() {
        printSubHeader("User Registration");
        std::cout << "\t\tEnter Username: ";
        std::cin >> username;
        std::ifstream userFile("users.txt");
        std::string line;
        bool exists = false;
        while (getline(userFile, line)) {
            if (line.substr(0, line.find(',')) == username) {
                exists = true;
                break;
            }
        }
        userFile.close();
        if (exists) {
            setColor(RED);
            std::cout << "\n\t\tUsername already taken. Please try another.\n";
            setColor(RESET_COLOR);
            Sleep(2000);
            return;
        }
        std::cout << "\t\tEnter Password: ";
        std::cin >> password;
        std::cout << "\t\tEnter Email: ";
        std::cin >> email;
        std::ofstream outFile("users.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << username << "," << cipher(password) << "," << email << std::endl;
            outFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tRegistration successful! Press any key to continue...\n";
            setColor(RESET_COLOR);
            _getch();
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open users file.\n";
            setColor(RESET_COLOR);
        }
    }

    std::string loginUser() {
        while (true) {
            printSubHeader("User Login");
            std::cout << "\t\tEnter Username (or type 'back' to return): ";
            std::cin >> username;
            if (username == "back") return "";
            std::cout << "\t\tEnter Password: ";
            std::cin >> password;
            std::ifstream userFile("users.txt");
            std::string line;
            bool found = false;
            if (userFile.is_open()) {
                while (getline(userFile, line)) {
                    std::string storedUser = line.substr(0, line.find(','));
                    std::string storedPass = line.substr(line.find(',') + 1, line.rfind(',') - line.find(',') - 1);
                    if (storedUser == username && storedPass == cipher(password)) {
                        found = true;
                        break;
                    }
                }
                userFile.close();
            }
            if (found) {
                setColor(GREEN);
                std::cout << "\n\t\tLogin successful! Welcome, " << username << "!\n";
                setColor(RESET_COLOR);
                Sleep(1500);
                return username;
            } else {
                setColor(RED);
                std::cout << "\n\t\tInvalid username or password. Press any key to try again...\n";
                setColor(RESET_COLOR);
                _getch();
                clearScreen();
            }
        }
    }
};

// --- Derived Classes (Modules) ---

// All these classes now inherit from the `Module` base class.
// This is a key example of inheritance.

//*******************************************************************************************************************
                                                  //  study and task Management Class
//********************************************************************************************************************

class TaskManager : public Module {
private:
    std::string getTaskFilePath() const {
        return "study_tasks_" + currentUser + ".txt";
    }

public:
    TaskManager(const std::string& user) : Module(user) {}

    int getPendingTaskCount() const {
        std::ifstream inFile(getTaskFilePath());
        if (!inFile.is_open()) return 0;
        std::string line;
        int count = 0;
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            try {
                size_t lastComma = line.rfind(',');
                if (lastComma != std::string::npos) {
                    int status = std::stoi(line.substr(lastComma + 1));
                    if (status == 0) {
                        count++;
                    }
                }
            } catch (const std::exception& e) {
                // Skip invalid lines
            }
        }
        inFile.close();
        return count;
    }

    void addTask() {
        printSubHeader("Add a New Study Task");
        std::string title;
        int priority = 0;
        Date dueDate;
        std::cout << "\t\tEnter Task Title (use underscores for spaces): ";
        getline(std::cin, title);
        std::cout << "\t\tEnter Priority (1-High, 2-Medium, 3-Low): ";
        priority = getValidInt(1, 3);
        std::cout << "\t\t---------   Due Date For Task:  ----------------- \n";
        std::cout << "\t\tEnter Due Date (Day-1-31): ";
        dueDate.day = getValidInt(1, 31);
        std::cout << "\t\tEnter Due Date (Month-1-12): ";
        dueDate.month = getValidInt(1, 12);
        std::cout << "\t\tEnter Due Date (Month-2025-2050): ";
        dueDate.year = getValidInt(2025, 2050);
        
        std::ofstream outFile(getTaskFilePath(), std::ios::app);
        if (outFile.is_open()) {
            outFile << title << "," << priority << "," << dueDate.day << "," << dueDate.month << "," << dueDate.year << ",0\n";
            outFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tTask added successfully!\n";
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open tasks file for writing.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
    
    void viewTasks() {
        printSubHeader("Your Study Tasks");
        std::ifstream inFile(getTaskFilePath());
        if (!inFile.is_open() || inFile.peek() == EOF) {
            std::cout << "\t\tNo tasks found. Add one first!\n";
            _getch();
            return;
        }
        std::string line;
        int count = 0;
        setColor(YELLOW);
        std::cout << "\t\t------------------------------------------------------------------\n";
        std::cout << "\t\t # |      Title      | Priority |   Due Date   | Status\n";
        std::cout << "\t\t------------------------------------------------------------------\n";
        setColor(RESET_COLOR);
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            count++;
            try {
                size_t pos1 = line.find(',');
                size_t pos2 = line.find(',', pos1 + 1);
                size_t pos3 = line.find(',', pos2 + 1);
                size_t pos4 = line.find(',', pos3 + 1);
                size_t pos5 = line.find(',', pos4 + 1);
                
                std::string title = line.substr(0, pos1);
                int priority = std::stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
                int day = std::stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
                int month = std::stoi(line.substr(pos3 + 1, pos4 - pos3 - 1));
                int year = std::stoi(line.substr(pos4 + 1, pos5 - pos4 - 1));
                int status = std::stoi(line.substr(pos5 + 1));

                std::cout << "\t\t " << std::setw(2) << count << " | " << std::setw(15) << std::left << title.substr(0, 15) << " | ";
                if (priority == 1) { setColor(RED); std::cout << "High  "; }
                else if (priority == 2) { setColor(YELLOW); std::cout << "Medium"; }
                else { setColor(GREEN); std::cout << "Low   "; }
                setColor(RESET_COLOR);
                std::cout << " | " << day << "/" << month << "/" << year << " | ";
                if (status == 1) { setColor(BOLD_GREEN); std::cout << "Done\n"; }
                else { setColor(BOLD_RED); std::cout << "Pending\n"; }
                setColor(RESET_COLOR);
            } catch (const std::exception& e) {
                std::cout << "\t\t [Error reading task " << count << "]\n";
            }
        }
        std::cout << "\t\t------------------------------------------------------------------\n";
        inFile.close();
        _getch();
    }
    
    // The `runMenu()` method now encapsulates all task-related menu logic
    void runMenu() override {
        char choice;
        do {
            printSubHeader("Study Section");
            std::cout << "\t\t\t1. Add Task\n";
            std::cout << "\t\t\t2. View Tasks\n";
            std::cout << "\t\t\t3. Mark Task as Completed\n";
            std::cout << "\t\t\t4. Delete Task\n";
            std::cout << "\t\t\t5. Daily Review & Suggestions\n";
            std::cout << "\t\t\t6. Start Pomodoro Timer\n";
            setColor(YELLOW);
            std::cout << "\t\t\t7. Back to Main Menu\n";
            setColor(RESET_COLOR);
            std::cout << "\n\t\t\tEnter your choice: ";
            choice = _getch();
            switch (choice) {
                case '1': addTask(); break;
                case '2': viewTasks(); break;
                case '3': markTaskCompleted(); break;
                case '4': deleteTask(); break;
                case '5': dailyReview(); break;
                case '6': startPomodoro(); break;
                case '7': return;
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }

private:
    void markTaskCompleted() {
        printSubHeader("Mark Task as Completed");
        viewTasks();
        std::cout << "\n\t\tEnter the number of the task to mark as completed: ";
        std::ifstream inFile(getTaskFilePath());
        if (!inFile.is_open()) {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open tasks file.\n";
            setColor(RESET_COLOR);
            _getch();
            return;
        }

        int totalTasks = 0;
        std::string line;
        while (getline(inFile, line)) {
            if (!line.empty()) {
                totalTasks++;
            }
        }
        inFile.close();
        
        if (totalTasks == 0) {
            _getch();
            return;
        }

        int taskNumber = getValidInt(1, totalTasks);
        
        inFile.open(getTaskFilePath());
        std::ofstream tempFile("temp_tasks.txt");
        int count = 0;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.empty()) {
                tempFile << line << std::endl;
                continue;
            }
            count++;
            if (count == taskNumber) {
                size_t lastComma = line.rfind(',');
                if (lastComma != std::string::npos) {
                    line.replace(lastComma + 1, 1, "1");
                    found = true;
                }
            }
            tempFile << line << std::endl;
        }
        inFile.close();
        tempFile.close();
        if (found) {
            remove(getTaskFilePath().c_str());
            rename("temp_tasks.txt", getTaskFilePath().c_str());
            setColor(GREEN);
            std::cout << "\n\t\tTask marked as completed!\n";
        } else {
            remove("temp_tasks.txt");
            setColor(RED);
            std::cout << "\n\t\tTask not found or invalid number.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }

    void deleteTask() {
        printSubHeader("Delete a Task");
        viewTasks();
        std::ifstream inFile(getTaskFilePath());
        if (!inFile.is_open()) {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open tasks file.\n";
            setColor(RESET_COLOR);
            _getch();
            return;
        }

        int totalTasks = 0;
        std::string line;
        while (getline(inFile, line)) {
            if (!line.empty()) {
                totalTasks++;
            }
        }
        inFile.close();
        
        if (totalTasks == 0) {
            _getch();
            return;
        }

        std::cout << "\n\t\tEnter the number of the task to delete: ";
        int taskNumber = getValidInt(1, totalTasks);
        
        inFile.open(getTaskFilePath());
        std::ofstream tempFile("temp_tasks.txt");
        int count = 0;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.empty()) {
                tempFile << line << std::endl;
                continue;
            }
            count++;
            if (count == taskNumber) {
                found = true;
                continue;
            }
            tempFile << line << std::endl;
        }
        inFile.close();
        tempFile.close();
        if (found) {
            remove(getTaskFilePath().c_str());
            rename("temp_tasks.txt", getTaskFilePath().c_str());
            setColor(GREEN);
            std::cout << "\n\t\tTask deleted successfully!\n";
        } else {
            remove("temp_tasks.txt");
            setColor(RED);
            std::cout << "\n\t\tTask not found.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
    
    void dailyReview() {
        printSubHeader("Daily Review & Suggestions");
        std::string reviewFile = "daily_review_" + currentUser + "_" + getCurrentDateString() + ".txt";
        std::ifstream checkReview(reviewFile);
        if (checkReview.is_open()) {
            setColor(YELLOW);
            std::cout << "\t\tYou have already completed your daily review for today. Great job!\n";
            setColor(RESET_COLOR);
            checkReview.close();
            _getch();
            return;
        }
        checkReview.close();
        std::ifstream inFile(getTaskFilePath());
        if (!inFile.is_open()) {
            std::cout << "\t\tNo tasks found to review.\n";
            _getch();
            return;
        }
        std::string line;
        int completedCount = 0;
        int pendingCount = 0;
        std::cout << "\t\t--- Your Daily Progress ---\n";
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            try {
                size_t lastComma = line.rfind(',');
                int status = std::stoi(line.substr(lastComma + 1));
                if (status == 1) {
                    completedCount++;
                } else {
                    pendingCount++;
                }
            } catch (const std::exception& e) {
                // Skip invalid line
            }
        }
        inFile.close();
        setColor(BOLD_GREEN);
        std::cout << "\t\tCompleted Tasks: " << completedCount << "\n";
        setColor(BOLD_RED);
        std::cout << "\t\tPending Tasks: " << pendingCount << "\n\n";
        setColor(RESET_COLOR);
        if (pendingCount > 0) {
            setColor(YELLOW);
            std::cout << "\t\t--- Smart Suggestions ---\n";
            std::cout << "\t\tYou have pending tasks. Here are some high-priority ones:\n";
            setColor(RESET_COLOR);
            std::ifstream suggestionsFile(getTaskFilePath());
            while (getline(suggestionsFile, line)) {
                if (line.empty()) continue;
                try {
                    size_t firstComma = line.find(',');
                    std::string title = line.substr(0, firstComma);
                    line.erase(0, firstComma + 1);
                    int priority = std::stoi(line.substr(0, line.find(',')));
                    size_t lastComma = line.rfind(',');
                    int status = std::stoi(line.substr(lastComma + 1));
                    if (status == 0 && priority == 1) {
                        std::cout << "\t\t- " << title << "\n";
                    }
                } catch (const std::exception& e) {
                    // Skip invalid line
                }
            }
            suggestionsFile.close();
        } else {
            setColor(GREEN);
            std::cout << "\t\tGreat job! All tasks completed.\n";
            setColor(RESET_COLOR);
        }
        std::ofstream reviewFileOut(reviewFile);
        if (reviewFileOut.is_open()) {
            reviewFileOut << "completed";
            reviewFileOut.close();
        }
        _getch();
    }
    
    void startPomodoro() {
        printSubHeader("Pomodoro Timer");
        int workMinutes = 25;
        setColor(CYAN);
        std::cout << "\n\t\tStarting a 25-minute focus session!\n";
        std::cout << "\t\tPress any key to cancel early.\n\n";
        setColor(RESET_COLOR);
        for (int i = workMinutes * 60; i > 0; --i) {
            if (_kbhit()) {
                _getch();
                std::cout << "\n\n\t\tTimer cancelled.\n";
                _getch();
                return;
            }
            std::cout << "\r\t\tTime remaining: " << std::setw(2) << std::setfill('0') << i / 60 << "m " << std::setw(2) << std::setfill('0') << i % 60 << "s    ";
            Sleep(1000);
        }
        setColor(GREEN);
        std::cout << "\n\n\t\tTime for a 5-minute break! Great work!\n";
        Beep(523, 1000);
        setColor(RESET_COLOR);
        _getch();
    }
};

class FitnessTracker : public Module {
private:
    std::string getWaterFilePath() const {
        return "water_" + currentUser + ".txt";
    }

public:
    FitnessTracker(const std::string& user) : Module(user) {}

    int getTodayWaterIntake() const {
        std::ifstream inFile(getWaterFilePath());
        if (!inFile.is_open()) return 0;
        std::string line;
        int intake = 0;
        std::string todayDate = getCurrentDateString();
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            size_t commaPos = line.find(',');
            if (commaPos == std::string::npos) continue;
            std::string fileDate = line.substr(0, commaPos);
            if (fileDate == todayDate) {
                try {
                    intake = std::stoi(line.substr(commaPos + 1));
                } catch (const std::exception& e) {
                    intake = 0;
                }
                break;
            }
        }
        inFile.close();
        return intake;
    }

    void runMenu() override {
        char choice;
        do {
            printSubHeader("Fitness Section");
            std::cout << "\t\t\t1. BMI Calculator\n";
            std::cout << "\t\t\t2. Set Fitness Goal\n";
            std::cout << "\t\t\t3. Provide Nutrition Suggestions\n";
            std::cout << "\t\t\t4. Water Intake Tracker\n";
            setColor(YELLOW);
            std::cout << "\t\t\t5. Back to Main Menu\n";
            setColor(RESET_COLOR);
            std::cout << "\n\t\t\tEnter your choice: ";
            choice = _getch();
            switch (choice) {
                case '1': calculateBMI(); break;
                case '2': setFitnessGoal(); break;
                case '3': provideNutritionSuggestions(); break;
                case '4': trackWater(); break;
                case '5': return;
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }
private:
    void calculateBMI() {
        printSubHeader("BMI Calculator");
        float height, weight;
        std::cout << "\t\tEnter your height in meters (e.g., 1.75): ";
        while(!(std::cin >> height) || height <= 0) {
            setColor(RED);
            std::cout << "\n\t\tInvalid input. Please enter a positive number: ";
            setColor(RESET_COLOR);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << "\t\tEnter your weight in kilograms (e.g., 70): ";
        while(!(std::cin >> weight) || weight <= 0) {
            setColor(RED);
            std::cout << "\n\t\tInvalid input. Please enter a positive number: ";
            setColor(RESET_COLOR);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        float bmi = weight / (height * height);
        std::cout << "\n\t\tYour BMI is: " << bmi << std::endl;
        setColor(BOLD_YELLOW);
        std::cout << "\t\tCategory: ";
        if (bmi < 18.5) std::cout << "Underweight\n";
        else if (bmi >= 18.5 && bmi < 24.9) std::cout << "Normal weight\n";
        else if (bmi >= 25 && bmi < 29.9) std::cout << "Overweight\n";
        else std::cout << "Obesity\n";
        setColor(RESET_COLOR);
        _getch();
    }

    void setFitnessGoal() {
        printSubHeader("Fitness Goal Setting");
        std::string goal;
        std::cout << "\t\tWhat is your fitness goal?\n";
        std::cout << "\t\t1. Bulk (Gain muscle)\n";
        std::cout << "\t\t2. Cut (Lose fat)\n";
        std::cout << "\t\t3. Maintain (Stay at current weight)\n";
        std::cout << "\t\tEnter your choice (1-3): ";
        int choice = getValidInt(1, 3);
        switch (choice) {
            case 1: goal = "Bulk"; break;
            case 2: goal = "Cut"; break;
            case 3: goal = "Maintain"; break;
            default: goal = "Unspecified"; break;
        }
        std::ofstream goalFile("fitness_goals_" + currentUser + ".txt");
        if (goalFile.is_open()) {
            goalFile << goal << std::endl;
            goalFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tYour goal has been set to: " << goal << "\n";
            setColor(RESET_COLOR);
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open goals file.\n";
            setColor(RESET_COLOR);
        }
        _getch();
    }

    void provideNutritionSuggestions() {
        printSubHeader("Nutrition Suggestions");
        std::ifstream goalFile("fitness_goals_" + currentUser + ".txt");
        if (!goalFile.is_open() || goalFile.peek() == EOF) {
            std::cout << "\t\tPlease set a fitness goal first.\n";
            _getch();
            return;
        }
        std::string goal;
        getline(goalFile, goal);
        goalFile.close();
        setColor(CYAN);
        std::cout << "\t\tBased on your goal to " << goal << ", here are some general tips:\n\n";
        setColor(RESET_COLOR);
        if (goal == "Bulk") {
            std::cout << "\t\t- Calorie intake: 2500-3000 calories/day\n";
            std::cout << "\t\t- Focus on protein and complex carbs.\n";
            std::cout << "\t\t- Suggested foods: Chicken breast, brown rice, nuts, protein shakes.\n";
        } else if (goal == "Cut") {
            std::cout << "\t\t- Calorie intake: 1500-2000 calories/day\n";
            std::cout << "\t\t- Focus on lean protein and vegetables.\n";
            std::cout << "\t\t- Suggested foods: Fish, salads, lean beef, quinoa.\n";
        } else if (goal == "Maintain") {
            std::cout << "\t\t- Calorie intake: 2000-2500 calories/day\n";
            std::cout << "\t\t- Maintain a balanced diet of all food groups.\n";
            std::cout << "\t\t- Suggested foods: Whole grains, fruits, vegetables, lean meats.\n";
        } else {
            std::cout << "\t\t- No specific suggestions available for your goal.\n";
        }
        _getch();
    }

    void trackWater() {
        printSubHeader("Water Intake Tracker");
        int glasses;
        std::cout << "\t\tHow many glasses of water did you drink today? ";
        glasses = getValidInt(0, 100);
        std::ofstream outFile(getWaterFilePath(), std::ios::out);
        if (outFile.is_open()) {
            outFile << getCurrentDateString() << "," << glasses << std::endl;
            outFile.close();
        }
        setColor(GREEN);
        std::cout << "\n\t\tGreat job staying hydrated! Logged " << glasses << " glasses.\n";
        if (glasses < 8) {
            setColor(YELLOW);
            std::cout << "\t\tReminder: Try to drink at least 8 glasses a day!\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
};
//*******************************************************************************************************************
                                                  //  Finance and calculation Class
//********************************************************************************************************************
class FinanceManager : public Module {
private:
    std::string getExpensesFilePath() const {
        return "expenses_" + currentUser + ".txt";
    }

    std::string getBudgetFilePath() const {
        return "budget_" + currentUser + ".txt";
    }

public:
    FinanceManager(const std::string& user) : Module(user) {}

    double getTotalMonthlyExpenses() const {
        std::ifstream inFile(getExpensesFilePath());
        if (!inFile.is_open()) return 0.0;
        double total = 0.0;
        std::string line;
        std::string currentMonth = getCurrentMonthAndYear();
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            try {
                size_t comma1 = line.find(',');
                size_t comma2 = line.find(',', comma1 + 1);
                double amount = std::stod(line.substr(0, comma1));
                std::string date = line.substr(comma2 + 1);
                if (date.substr(0, 7) == currentMonth) {
                    total += amount;
                }
            } catch (const std::exception& e) {
                // Skip invalid lines
            }
        }
        inFile.close();
        return total;
    }
    
    void runMenu() override {
        char choice;
        do {
            printSubHeader("Finance Section");
            std::cout << "\t\t\t1. Add Expense\n";
            std::cout << "\t\t\t2. Set Monthly Budget\n";
            std::cout << "\t\t\t3. View Monthly Summary & Insights\n";
            std::cout << "\t\t\t4. Delete an Expense\n";
            setColor(YELLOW);
            std::cout << "\t\t\t5. Back to Main Menu\n";
            setColor(RESET_COLOR);
            std::cout << "\n\t\t\tEnter your choice: ";
            choice = _getch();
            switch (choice) {
                case '1': addExpense(); break;
                case '2': setBudget(); break;
                case '3': viewSummary(); break;
                case '4': deleteExpense(); break;
                case '5': return;
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }
private:
    void addExpense() {
        printSubHeader("Add a New Expense");
        double amount;
        std::string category;
        std::string date;
        
        // Input validation for amount
        while (true) {
            std::cout << "\t\tEnter expense amount ($): ";
            std::string amountStr;
            std::cin >> amountStr;
            std::stringstream ss(amountStr);
            if (ss >> amount && amount > 0) {
                break;
            } else {
                setColor(RED);
                std::cout << "\n\t\tInvalid input. Please enter a positive number.\n";
                setColor(RESET_COLOR);
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::cout << "\t\tEnter expense category (e.g., Food_Transport): ";
        std::cin >> category;
        date = getCurrentDateString();
        std::ofstream outFile(getExpensesFilePath(), std::ios::app);
        if (outFile.is_open()) {
            outFile << std::fixed << std::setprecision(2) << amount << "," << category << "," << date << std::endl;
            outFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tExpense added successfully!\n";
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open expenses file.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
    
    void setBudget() {
        printSubHeader("Set Your Monthly Budget");
        double budget;
        std::cout << "\t\tEnter your monthly budget: $";
        while(!(std::cin >> budget) || budget <= 0) {
            setColor(RED);
            std::cout << "\n\t\tInvalid input. Please enter a positive number: $";
            setColor(RESET_COLOR);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::ofstream outFile(getBudgetFilePath());
        if (outFile.is_open()) {
            outFile << budget << std::endl;
            outFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tMonthly budget of $" << budget << " set successfully!\n";
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open budget file.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
    
    void viewSummary() {
        printSubHeader("Monthly Expense Summary & Insights");
        
        // C++ vanilla approach: fixed-size array of structs instead of a map
        const int MAX_CATEGORIES = 100; // Define a reasonable maximum
        struct CategorySummary {
            std::string category;
            double total = 0.0;
        };
        CategorySummary categoryTotals[MAX_CATEGORIES];
        int numCategories = 0;

        std::ifstream inFile(getExpensesFilePath());
        if (inFile.is_open()) {
            std::string line;
            std::string currentMonth = getCurrentMonthAndYear();
            while (getline(inFile, line)) {
                if (line.empty()) continue;
                try {
                    size_t comma1 = line.find(',');
                    size_t comma2 = line.find(',', comma1 + 1);
                    double amount = stod(line.substr(0, comma1));
                    std::string category = line.substr(comma1 + 1, comma2 - comma1 - 1);
                    std::string date = line.substr(comma2 + 1);
                    if (date.substr(0, 7) == currentMonth) {
                        bool found = false;
                        for (int i = 0; i < numCategories; ++i) {
                            if (categoryTotals[i].category == category) {
                                categoryTotals[i].total += amount;
                                found = true;
                                break;
                            }
                        }
                        if (!found && numCategories < MAX_CATEGORIES) {
                            categoryTotals[numCategories].category = category;
                            categoryTotals[numCategories].total = amount;
                            numCategories++;
                        }
                    }
                } catch (...) {
                    continue;
                }
            }
            inFile.close();
        }

        if (numCategories == 0) {
            std::cout << "\t\tNo expenses logged for this month yet.\n";
            _getch();
            return;
        }

        double total = 0;
        std::cout << "\t\t--- Category-wise Insights (This Month) ---\n";
        for (int i = 0; i < numCategories; ++i) {
            total += categoryTotals[i].total;
            std::cout << "\t\t" << categoryTotals[i].category << ": $" << categoryTotals[i].total << std::endl;
        }
        
        std::cout << "\t\t--------------------------------------\n";
        setColor(BOLD_CYAN);
        std::cout << "\t\tTotal Expenses (This Month): $" << total << std::endl;
        double monthlyBudget = 0;
        std::ifstream budgetFile(getBudgetFilePath());
        if (budgetFile.is_open()) {
            budgetFile >> monthlyBudget;
            budgetFile.close();
        }
        if (monthlyBudget > 0) {
            std::cout << "\t\tMonthly Budget: $" << monthlyBudget << std::endl;
            if (total > monthlyBudget) {
                setColor(BOLD_RED);
                std::cout << "\t\tStatus: You are OVER budget by $" << total - monthlyBudget << "!\n";
            } else {
                setColor(BOLD_GREEN);
                std::cout << "\t\tStatus: You are UNDER budget by $" << monthlyBudget - total << "!\n";
            }
        }
        setColor(RESET_COLOR);
        _getch();
    }
    
    void deleteExpense() {
        printSubHeader("Delete an Expense");
        std::ifstream inFile(getExpensesFilePath());
        if (!inFile.is_open() || inFile.peek() == EOF) {
            std::cout << "\t\tNo expenses found to delete.\n";
            _getch();
            return;
        }
        inFile.close();

        // Display expenses to the user
        int count = 0;
        std::string line;
        inFile.open(getExpensesFilePath());
        setColor(YELLOW);
        std::cout << "\t\t------------------------------------------------\n";
        std::cout << "\t\t # |      Amount      | Category       | Date\n";
        std::cout << "\t\t------------------------------------------------\n";
        setColor(RESET_COLOR);
        while(getline(inFile, line)) {
            if (line.empty()) continue;
            count++;
            try {
                size_t comma1 = line.find(',');
                size_t comma2 = line.find(',', comma1 + 1);
                std::string amountStr = line.substr(0, comma1);
                std::string category = line.substr(comma1 + 1, comma2 - comma1 - 1);
                std::string date = line.substr(comma2 + 1);
                std::cout << "\t\t " << std::setw(2) << count << " | " << std::setw(15) << std::left << amountStr << "| " << std::setw(15) << std::left << category << "| " << date << std::endl;
            } catch (const std::exception& e) {
                 std::cout << "\t\t [Error reading expense " << count << "]\n";
            }
        }
        inFile.close();
        std::cout << "\t\t------------------------------------------------\n";

        std::ifstream inFileCheck(getExpensesFilePath());
        int totalExpenses = 0;
        while (getline(inFileCheck, line)) {
            if (!line.empty()) {
                totalExpenses++;
            }
        }
        inFileCheck.close();
        if (totalExpenses == 0) {
            _getch();
            return;
        }

        std::cout << "\n\t\tEnter the number of the expense to delete: ";
        int expenseNumber = getValidInt(1, totalExpenses);
        
        std::ifstream inFile2(getExpensesFilePath());
        std::ofstream tempFile("temp_expenses.txt");
        if (!inFile2.is_open() || !tempFile.is_open()) {
            setColor(RED);
            std::cout << "\n\t\tError opening files.\n";
            setColor(RESET_COLOR);
            _getch();
            return;
        }
        
        count = 0;
        bool found = false;
        while(getline(inFile2, line)) {
            if (line.empty()) continue;
            count++;
            if (count == expenseNumber) {
                found = true;
                continue;
            }
            tempFile << line << std::endl;
        }

        inFile2.close();
        tempFile.close();

        if (found) {
            remove(getExpensesFilePath().c_str());
            rename("temp_expenses.txt", getExpensesFilePath().c_str());
            setColor(GREEN);
            std::cout << "\n\t\tExpense deleted successfully!\n";
        } else {
            remove("temp_expenses.txt");
            setColor(RED);
            std::cout << "\n\t\tInvalid expense number.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
};

//*******************************************************************************************************************
                                                  //  Habit Tracking Class
//********************************************************************************************************************

class HabitTracker : public Module {
private:
    std::string getHabitsFilePath() const {
        return "habits_" + currentUser + ".txt";
    }

public:
    HabitTracker(const std::string& user) : Module(user) {}

    void runMenu() override {
        char choice;
        do {
            printSubHeader("Habits & Hobbies");
            std::cout << "\t\t\t1. Add a New Habit\n";
            std::cout << "\t\t\t2. View Your Habits\n";
            std::cout << "\t\t\t3. Track a Habit (Check-in)\n";
            std::cout << "\t\t\t4. Delete a Habit\n";
            setColor(YELLOW);
            std::cout << "\t\t\t5. Back to Main Menu\n";
            setColor(RESET_COLOR);
            std::cout << "\n\t\t\tEnter your choice: ";
            choice = _getch();
            switch (choice) {
                case '1': addHabit(); break;
                case '2': viewHabits(); break;
                case '3': trackHabit(); break;
                case '4': deleteHabit(); break;
                case '5': return;
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }
private:
    void addHabit() {
        printSubHeader("Add a New Habit");
        std::string title;
        std::cout << "\t\tEnter the habit title (e.g., 'Read_for_30min'): ";
        getline(std::cin, title);
        std::ofstream outFile(getHabitsFilePath(), std::ios::app);
        if (outFile.is_open()) {
            outFile << title << ",0," << "none" << std::endl;
            outFile.close();
            setColor(GREEN);
            std::cout << "\n\t\tHabit added successfully!\n";
        } else {
            setColor(RED);
            std::cout << "\n\t\tError: Could not open habits file.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }

    void viewHabits() {
        printSubHeader("Your Habits");
        std::ifstream inFile(getHabitsFilePath());
        if (!inFile.is_open() || inFile.peek() == EOF) {
            std::cout << "\t\tNo habits found. Add one first!\n";
            _getch();
            return;
        }
        std::string line;
        setColor(YELLOW);
        std::cout << "\t\t------------------------------------\n";
        std::cout << "\t\t      Habit      |  Current Streak\n";
        std::cout << "\t\t------------------------------------\n";
        setColor(RESET_COLOR);
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            try {
                size_t comma1 = line.find(',');
                size_t comma2 = line.find(',', comma1 + 1);
                std::string title = line.substr(0, comma1);
                int streak = std::stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
                std::cout << "\t\t" << std::setw(15) << std::left << title.substr(0, 15) << " | " << streak << " days\n";
            } catch (const std::exception& e) {
                std::cout << "\t\t [Error reading habit]\n";
            }
        }
        std::cout << "\t\t------------------------------------\n";
        inFile.close();
        _getch();
    }

    void trackHabit() {
        printSubHeader("Track a Habit");
        viewHabits();
        std::string title;
        std::cout << "\n\t\tEnter the habit title to track today: ";
        getline(std::cin, title);
        std::ifstream inFile(getHabitsFilePath());
        std::ofstream tempFile("temp_habits.txt");
        std::string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.empty()) {
                tempFile << line << std::endl;
                continue;
            }
            size_t comma1 = line.find(',');
            std::string habitTitle = line.substr(0, comma1);
            if (habitTitle == title) {
                try {
                    size_t comma2 = line.find(',', comma1 + 1);
                    int streak = std::stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
                    std::string lastDate = line.substr(comma2 + 1);
                    std::string today = getCurrentDateString();
                    if (lastDate == today) {
                        setColor(YELLOW);
                        std::cout << "\n\t\tYou have already checked in for this habit today!\n";
                        setColor(RESET_COLOR);
                        found = true;
                        tempFile << line << std::endl;
                    } else if (lastDate == getYesterdayDateString() || lastDate == "none") {
                        streak++;
                        tempFile << habitTitle << "," << streak << "," << today << std::endl;
                        setColor(GREEN);
                        std::cout << "\n\t\tStreak updated for " << title << " to " << streak << "!\n";
                        setColor(RESET_COLOR);
                        found = true;
                    } else {
                        streak = 1;
                        tempFile << habitTitle << "," << streak << "," << today << std::endl;
                        setColor(RED);
                        std::cout << "\n\t\tStreak for " << title << " reset. New streak is 1.\n";
                        setColor(RESET_COLOR);
                        found = true;
                    }
                } catch (const std::exception& e) {
                    tempFile << line << std::endl;
                }
            } else {
                tempFile << line << std::endl;
            }
        }
        inFile.close();
        tempFile.close();
        if (found) {
            remove(getHabitsFilePath().c_str());
            rename("temp_habits.txt", getHabitsFilePath().c_str());
        } else {
            remove("temp_habits.txt");
            setColor(RED);
            std::cout << "\n\t\tHabit not found.\n";
            setColor(RESET_COLOR);
        }
        _getch();
    }
    
    void deleteHabit() {
        printSubHeader("Delete a Habit");
        std::ifstream inFile(getHabitsFilePath());
        if (!inFile.is_open() || inFile.peek() == EOF) {
            std::cout << "\t\tNo habits found to delete.\n";
            _getch();
            return;
        }
        
        // Count habits to get the valid range for user input
        int totalHabits = 0;
        std::string line;
        while (getline(inFile, line)) {
            if (!line.empty()) {
                totalHabits++;
            }
        }
        inFile.close();
        
        if (totalHabits == 0) {
            _getch();
            return;
        }
        
        // Re-open and display habits with a number
        inFile.open(getHabitsFilePath());
        setColor(YELLOW);
        std::cout << "\t\t------------------------------------\n";
        std::cout << "\t\t # |      Habit      |  Current Streak\n";
        std::cout << "\t\t------------------------------------\n";
        setColor(RESET_COLOR);
        int count = 0;
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            count++;
            try {
                size_t comma1 = line.find(',');
                size_t comma2 = line.find(',', comma1 + 1);
                std::string title = line.substr(0, comma1);
                int streak = std::stoi(line.substr(comma1 + 1, comma2 - comma1 - 1));
                std::cout << "\t\t " << std::setw(2) << count << " | " << std::setw(15) << std::left << title.substr(0, 15) << " | " << streak << " days\n";
            } catch (const std::exception& e) {
                 std::cout << "\t\t [Error reading habit " << count << "]\n";
            }
        }
        std::cout << "\t\t------------------------------------\n";
        inFile.close();
        
        std::cout << "\n\t\tEnter the number of the habit to delete: ";
        int habitNumber = getValidInt(1, totalHabits);

        // Delete the habit
        inFile.open(getHabitsFilePath());
        std::ofstream tempFile("temp_habits.txt");
        count = 0;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.empty()) continue;
            count++;
            if (count == habitNumber) {
                found = true;
                continue;
            }
            tempFile << line << std::endl;
        }

        inFile.close();
        tempFile.close();

        if (found) {
            remove(getHabitsFilePath().c_str());
            rename("temp_habits.txt", getHabitsFilePath().c_str());
            setColor(GREEN);
            std::cout << "\n\t\tHabit deleted successfully!\n";
        } else {
            remove("temp_habits.txt");
            setColor(RED);
            std::cout << "\n\t\tInvalid habit number.\n";
        }
        setColor(RESET_COLOR);
        _getch();
    }
};

//*******************************************************************************************************************
                                                  //  Mental Wellness Class
//********************************************************************************************************************
class WellnessManager : public Module {
public:
    WellnessManager(const std::string& user) : Module(user) {}

    void runMenu() override {
        char choice;
        do {
            printSubHeader("Mental Wellness");
            std::cout << "\t\t\t1. Get a Motivational Quote\n";
            std::cout << "\t\t\t2. Get a Mind Exercise\n";
            std::cout << "\t\t\t3. Take a Quiz\n"; // New option for the quiz
            setColor(YELLOW);
            std::cout << "\t\t\t4. Back to Main Menu\n";
            setColor(RESET_COLOR);
            std::cout << "\n\t\t\tEnter your choice: ";
            choice = _getch();
            switch (choice) {
                case '1': showQuote(); break;
                case '2': showMindExercise(); break;
                case '3': takeQuiz(); break; // Call the new quiz function
                case '4': return;
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }
private:
    void showQuote() {
        printSubHeader("Daily Motivational Quote");
        std::ifstream quoteFile("quotes.txt");
        if (!quoteFile.is_open() || quoteFile.peek() == EOF) {
            std::cout << "\t\tCould not find 'quotes.txt' or it is empty.\n";
            _getch();
            return;
        }

        // Count lines to pick a random one
        int lineCount = 0;
        std::string line;
        while (getline(quoteFile, line)) {
            if (!line.empty()) {
                lineCount++;
            }
        }
        quoteFile.clear();
        quoteFile.seekg(0);

        if (lineCount > 0) {
            srand(time(0));
            int randomIndex = rand() % lineCount;
            for (int i = 0; i < randomIndex; ++i) {
                getline(quoteFile, line);
            }
            getline(quoteFile, line);
            setColor(CYAN);
            std::cout << "\n\t\t\"" << line << "\"\n";
            setColor(RESET_COLOR);
        } else {
            std::cout << "\n\t\tNo quotes found in the file.\n";
        }
        quoteFile.close();
        _getch();
    }

    void showMindExercise() {
        printSubHeader("Quick Mind Exercise");
        std::ifstream exerciseFile("exercises.txt");
        if (!exerciseFile.is_open() || exerciseFile.peek() == EOF) {
            std::cout << "\t\tCould not find 'exercises.txt' or it is empty.\n";
            _getch();
            return;
        }
        
        // Count lines to pick a random one
        int lineCount = 0;
        std::string line;
        while (getline(exerciseFile, line)) {
            if (!line.empty()) {
                lineCount++;
            }
        }
        exerciseFile.clear();
        exerciseFile.seekg(0);

        if (lineCount > 0) {
            srand(time(0));
            int randomIndex = rand() % lineCount;
            for (int i = 0; i < randomIndex; ++i) {
                getline(exerciseFile, line);
            }
            getline(exerciseFile, line);
            setColor(GREEN);
            std::cout << "\n\t\tYour challenge: " << line << "\n";
            setColor(RESET_COLOR);
        } else {
            std::cout << "\n\t\tNo exercises found in the file.\n";
        }
        exerciseFile.close();
        _getch();
    }

    void takeQuiz() {
        printSubHeader("Mental Wellness Quiz");
        std::ifstream quizFile("quiz_questions.txt");
        if (!quizFile.is_open() || quizFile.peek() == EOF) {
            setColor(RED);
            std::cout << "\n\t\tQuiz file not found or is empty. Please add questions to 'quiz_questions.txt'.\n";
            setColor(RESET_COLOR);
            _getch();
            return;
        }

        int totalQuestions = 0;
        std::string line;
        while(getline(quizFile, line)) {
            if (!line.empty()) {
                totalQuestions++;
            }
        }
        quizFile.close();

        if (totalQuestions == 0) {
            setColor(RED);
            std::cout << "\n\t\tNo questions found in the quiz file.\n";
            setColor(RESET_COLOR);
            _getch();
            return;
        }

        std::cout << "\t\tThe quiz has a total of " << totalQuestions << " questions.\n";
        std::cout << "\t\tHow many questions would you like to take? ";
        int numQuestions = getValidInt(1, totalQuestions);

        int score = 0;
        int questionsAsked = 0;
        srand(time(0));

        for (int i = 0; i < numQuestions; ++i) {
            // Re-open and reset file pointer for each question to simulate random access
            quizFile.open("quiz_questions.txt");
            if (!quizFile.is_open()) {
                setColor(RED);
                std::cout << "\n\t\tError: Could not open quiz file.\n";
                setColor(RESET_COLOR);
                return;
            }
            
            int randomLine = rand() % totalQuestions;
            for (int j = 0; j < randomLine; ++j) {
                getline(quizFile, line);
            }
            getline(quizFile, line);
            quizFile.close();
            
            if (line.empty()) {
                continue;
            }

            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            size_t pos3 = line.find(',', pos2 + 1);
            size_t pos4 = line.find(',', pos3 + 1);

            std::string question = line.substr(0, pos1);
            std::string correctAnswer = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string optionB = line.substr(pos2 + 1, pos3 - pos2 - 1);
            std::string optionC = line.substr(pos3 + 1, pos4 - pos3 - 1);
            std::string optionD = line.substr(pos4 + 1);
            
            std::string shuffledOptions[4] = {correctAnswer, optionB, optionC, optionD};
            for (int k = 0; k < 4; ++k) {
                int swapIndex = rand() % 4;
                std::string temp = shuffledOptions[k];
                shuffledOptions[k] = shuffledOptions[swapIndex];
                shuffledOptions[swapIndex] = temp;
            }

            questionsAsked++;
            printSubHeader("Question " + std::to_string(questionsAsked));
            std::cout << "\t\t" << question << "\n\n";
            std::cout << "\t\t1. " << shuffledOptions[0] << "\n";
            std::cout << "\t\t2. " << shuffledOptions[1] << "\n";
            std::cout << "\t\t3. " << shuffledOptions[2] << "\n";
            std::cout << "\t\t4. " << shuffledOptions[3] << "\n\n";
            
            std::cout << "\t\tEnter your choice (1-4): ";
            int userChoice = getValidInt(1, 4);
            
            if (shuffledOptions[userChoice - 1] == correctAnswer) {
                setColor(GREEN);
                std::cout << "\n\t\tCorrect!\n";
                score++;
            } else {
                setColor(RED);
                std::cout << "\n\t\tIncorrect. The correct answer was: " << correctAnswer << "\n";
            }
            setColor(RESET_COLOR);
            _getch();
        }

        printSubHeader("Quiz Results");
        setColor(BOLD_YELLOW);
        std::cout << "\n\t\tYou scored " << score << " out of " << questionsAsked << "!\n";
        setColor(RESET_COLOR);
        if (score == questionsAsked) {
            setColor(BOLD_GREEN);
            std::cout << "\t\tPerfect score! You are a genius!\n";
            setColor(RESET_COLOR);
        } else if (score > questionsAsked / 2) {
            setColor(CYAN);
            std::cout << "\t\tGreat job! Keep up the good work.\n";
            setColor(RESET_COLOR);
        } else {
            setColor(BOLD_RED);
            std::cout << "\t\tYou can do better next time. Keep practicing!\n";
            setColor(RESET_COLOR);
        }
        _getch();
    }
};

// Application Core Class (Manages the overall flow and the collection of modules)
class App {
private:
    std::string currentUser;
    TaskManager* taskModule;
    FitnessTracker* fitnessModule;
    FinanceManager* financeModule;
    HabitTracker* habitModule;
    WellnessManager* wellnessModule;
public:
    App(const std::string& user) : currentUser(user) {
        taskModule = new TaskManager(user);
        fitnessModule = new FitnessTracker(user);
        financeModule = new FinanceManager(user);
        habitModule = new HabitTracker(user);
        wellnessModule = new WellnessManager(user);
    }

    ~App() {
        delete taskModule;
        delete fitnessModule;
        delete financeModule;
        delete habitModule;
        delete wellnessModule;
    }

    void showDashboard() {
        char choice = 0;
        do {
            printHeader();
            setColor(BOLD_WHITE);
            std::cout << "\n\t\t\tWelcome, " << currentUser << "! What would you like to focus on today?\n\n";
            setColor(RESET_COLOR);
            
            setColor(BOLD_YELLOW);
            std::cout << "\t\t\t\t------------------------------------\n";
            std::cout << "\t\t\t\t    YOUR DAILY PROGRESS DASHBOARD   \n";
            std::cout << "\t\t\t\t------------------------------------\n";
            setColor(RESET_COLOR);
            
            int pendingTasks = taskModule->getPendingTaskCount();
            setColor(BOLD_CYAN);
            std::cout << "\t\t\t\t| Pending Tasks: " << std::setw(11) << std::right << pendingTasks << " |\n";
            setColor(RESET_COLOR);

            int waterIntake = fitnessModule->getTodayWaterIntake();
            setColor(BOLD_CYAN);
            std::cout << "\t\t\t\t| Water Intake : " << std::setw(11) << std::right << waterIntake << " glasses |\n";
            setColor(RESET_COLOR);
            
            double totalMonthlyExpenses = financeModule->getTotalMonthlyExpenses();
            setColor(BOLD_CYAN);
            std::cout << "\t\t\t\t| Total Expenses: " << std::setw(10) << std::right << "$" << totalMonthlyExpenses << " |\n";
            setColor(RESET_COLOR);
            
            std::cout << "\t\t\t\t------------------------------------\n\n";
            
            std::cout << "\t\t\t\t+------------------------+\n";
            std::cout << "\t\t\t\t|"; setColor(BOLD_GREEN); std::cout << " 1. Study Manager     "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|"; setColor(BOLD_RED); std::cout << " 2. Fitness Tracker   "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|"; setColor(BOLD_YELLOW); std::cout << " 3. Finance Hub       "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|"; setColor(BOLD_CYAN); std::cout << " 4. Habits & Hobbies  "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|"; setColor(BOLD_CYAN); std::cout << " 5. Mental Wellness   "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|------------------------|\n";
            std::cout << "\t\t\t\t|"; setColor(YELLOW); std::cout << " 6. Logout            "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t|"; setColor(RED); std::cout << " 7. Exit Application  "; setColor(RESET_COLOR); std::cout << "|\n";
            std::cout << "\t\t\t\t+------------------------+\n";
            std::cout << "\n\t\t\t\tEnter your choice: ";
            choice = _getch();
            
            switch (choice) {
                case '1': taskModule->runMenu(); break;
                case '2': fitnessModule->runMenu(); break;
                case '3': financeModule->runMenu(); break;
                case '4': habitModule->runMenu(); break;
                case '5': wellnessModule->runMenu(); break;
                case '6':
                    setColor(YELLOW);
                    std::cout << "\n\n\t\t\t\tLogging out. See you soon!\n";
                    setColor(RESET_COLOR);
                    Sleep(1500);
                    return;
                case '7':
                    setColor(CYAN);
                    std::cout << "\n\n\t\t\t\tThank you for using AuraSync! Exiting...\n\n";
                    setColor(RESET_COLOR);
                    Sleep(1500);
                    exit(0);
                default:
                    setColor(RED);
                    std::cout << "\n\t\t\t\tInvalid choice. Please try again.\n";
                    setColor(RESET_COLOR);
                    _getch();
                    break;
            }
        } while (true);
    }
};

//*******************************************************************************************************************
                                                  //  Main function Stimulation and Logics
//********************************************************************************************************************
// --- Main Function ---
int main() {
    User user;
    std::string loggedInUser;
    
    createFileIfNotExists("users.txt");
    createFileIfNotExists("quotes.txt");
    createFileIfNotExists("exercises.txt");
    createFileIfNotExists("quiz_questions.txt");
    
    std::ofstream quotesFile("quotes.txt", std::ios::app);
    if (quotesFile.is_open() && quotesFile.tellp() == 0) {
        quotesFile << "The only way to do great work is to love what you do." << std::endl;
        quotesFile << "The future belongs to those who believe in the beauty of their dreams." << std::endl;
        quotesFile << "Believe you can and you're halfway there." << std::endl;
        quotesFile.close();
    }
    std::ofstream exercisesFile("exercises.txt", std::ios::app);
    if (exercisesFile.is_open() && exercisesFile.tellp() == 0) {
        exercisesFile << "Try to name five things you can see, hear, and feel right now." << std::endl;
        exercisesFile << "Solve a simple brain teaser puzzle online." << std::endl;
        exercisesFile << "Write a short paragraph about your favorite memory from this week." << std::endl;
        exercisesFile.close();
    }
    std::ofstream quizFile("quiz_questions.txt", std::ios::in);
    if (quizFile.is_open() && quizFile.tellp() == 0) {
        quizFile << "What_is_the_capital_of_France?,Paris,London,Berlin,Rome" << std::endl;
        quizFile << "What_is_2+2?,4,3,5,6" << std::endl;
        quizFile << "What_is_the_largest_ocean?,Pacific_Ocean,Atlantic_Ocean,Indian_Ocean,Arctic_Ocean" << std::endl;
        quizFile << "What_is_the_color_of_the_sky_on_a_clear_day?,Blue,Green,Red,Yellow" << std::endl;
        quizFile.close();
    }
    
    while (true) {
        printHeader();
        std::cout << "\n\t\t\t\t\t1. Login\n";
        std::cout << "\t\t\t\t\t2. Register\n";
        std::cout << "\t\t\t\t\t3. Exit\n";
        std::cout << "\n\t\t\t\t\tEnter your choice: ";
        char choice = _getch();
        
        switch (choice) {
            case '1':
                loggedInUser = user.loginUser();
                if (!loggedInUser.empty()) {
                    App myApp(loggedInUser);
                    myApp.showDashboard();
                }
                break;
            case '2':
                user.registerUser();
                break;
            case '3':
                setColor(CYAN);
                std::cout << "\n\n\t\t\t\tThank you for using Wellvish!\n\n";
                setColor(RESET_COLOR);
                return 0;
            default:
                setColor(RED);
                std::cout << "\n\t\t\t\tInvalid choice. Please try again.\n";
                setColor(RESET_COLOR);
                _getch();
                break;
        }
    }
    return 0;
}
