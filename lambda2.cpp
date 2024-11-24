#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(const string& name, int age) : name(name), age(age) {}
};

// Function to print a vector of Person objects
void printPeople(const vector<Person>& people) {
    for (const auto& person : people) {
        cout << "Name: " << person.name << ", Age: " << person.age << endl;
    }
}

int main() {
    vector<Person> people = {
        Person("Alice", 30),
        Person("Bob", 25),
        Person("Charlie", 35),
        Person("David", 20),
        Person("Eve", 28)
    };

    // Use a lambda to filter out people older than 30
    cout << "People older than 30:" << endl;
    vector<Person> olderThan30;
    copy_if(people.begin(), people.end(), back_inserter(olderThan30), [](const Person& p) {
        return p.age > 30;
    });
    printPeople(olderThan30);

    // Use a lambda to sort people by age
    cout << "\nPeople sorted by age:" << endl;
    sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age; // Sort in ascending order of age
    });
    printPeople(people);

    // Use a lambda to find a person by name
    string searchName = "Charlie";
    auto it = find_if(people.begin(), people.end(), [&searchName](const Person& p) {
        return p.name == searchName;
    });

    if (it != people.end()) {
        cout << "\nFound: " << it->name << ", Age: " << it->age << endl;
    } else {
        cout << "\nPerson not found." << endl;
    }

    return 0;
}