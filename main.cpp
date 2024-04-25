#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class HeartRates {
private:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    HeartRates(string first, string last, int month, int day, int year)
        : firstName(first), lastName(last), birthMonth(month), birthDay(day), birthYear(year) {}

    void setFirstName(string first) { firstName = first; }
    string getFirstName() const { return firstName; }

    void setLastName(string last) { lastName = last; }
    string getLastName() const { return lastName; }

    void setBirthMonth(int month) { birthMonth = month; }
    int getBirthMonth() const { return birthMonth; }

    void setBirthDay(int day) { birthDay = day; }
    int getBirthDay() const { return birthDay; }

    void setBirthYear(int year) { birthYear = year; }
    int getBirthYear() const { return birthYear; }

    int calculateAge() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int currentYear = 1900 + ltm->tm_year;
        int currentMonth = 1 + ltm->tm_mon;
        int currentDay = ltm->tm_mday;

        int age = currentYear - birthYear;

        if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay)) {
            age--;
        }

        return age;
    }

    int calculateMaxHeartRate() const {
        return 220 - calculateAge();
    }

    pair<int, int> calculateTargetHeartRate() const {
        int maxHeartRate = calculateMaxHeartRate();
        int lowerLimit = maxHeartRate * 0.5;  
        int upperLimit = maxHeartRate * 0.85;
        return make_pair(lowerLimit, upperLimit);
    }
};

int main() {
    string firstName, lastName;
    int birthMonth, birthDay, birthYear;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter birth day: ";
    cin >> birthDay;
    cout << "Enter birth year: ";
    cin >> birthYear;

    HeartRates person(firstName, lastName, birthMonth, birthDay, birthYear);

    cout << "\nPerson's Information:" << endl;
    cout << "First Name: " << person.getFirstName() << endl;
    cout << "Last Name: " << person.getLastName() << endl;
    cout << "Date of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear() << endl;

    int age = person.calculateAge();
    cout << "\nAge: " << age << " years" << endl;

    int maxHeartRate = person.calculateMaxHeartRate();
    cout << "Maximum Heart Rate: " << maxHeartRate << " bpm" << endl;

    pair<int, int> targetHeartRate = person.calculateTargetHeartRate();
    cout << "Target Heart Rate Range: " << targetHeartRate.first << " - " << targetHeartRate.second << " bpm" << endl;

    return 0;
}

