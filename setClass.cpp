#include <iostream>
#include <set>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    // Overload the < operator for comparison
    bool operator<(const Person& other) const {
        return (name < other.name) || (name == other.name && age < other.age);
    }

    // Overload the << operator for output
    friend ostream& operator<<(ostream& os, const Person& p) {
        os << "Name: " << p.name << ", Age: " << p.age;
        return os;
    }
};

int main() {
    set<Person> people;

    // Adding people to the set
    people.insert(Person("Alice", 30));
    people.insert(Person("Bob", 25));
    people.insert(Person("Charlie", 35));
    people.insert(Person("Alice", 30)); // Duplicate, will not be added

    // Displaying the set
    cout << "People in the set:" << endl;
    for (const auto& person : people) {
        cout << person << endl;
    }

    return 0;
}