#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Person {
    string name;
    int age;

    // Constructor for convenience
    Person(string n, int a) : name(n), age(a) {}

    // Overloading the < operator for sorting
    bool operator<(const Person& other) const {
        return age < other.age; // Sort by age
    }
};

// Function to print the vector of Person objects
void printPeople(const vector<Person>& people) {
    for (const auto& person : people) {
        cout << person.name << " (" << person.age << ")" << endl;
    }
}

int main63() {
    // Create a vector of Person objects
    vector<Person> people = {
        Person("Sasuke", 30),
        Person("Tanjiro", 25),
        Person("Anya", 35),
        Person("Grifith", 28)
    };

    printPeople(people);

    // 1. Sort
    sort(people.begin(), people.end());
    cout << "Sorted by age:" << endl;
    printPeople(people);

    // 2. Sort in reverse order
    sort(people.rbegin(), people.rend());
    cout << "\nSorted in reverse order:" << endl;
    printPeople(people);

    // 3. Reverse
    reverse(people.begin(), people.end());
    cout << "\nReversed order:" << endl;
    printPeople(people);

    // 4. Max element
    auto maxPerson = *max_element(people.begin(), people.end());
    cout << "\nOldest person: " << maxPerson.name << " (" << maxPerson.age << ")" << endl;

    // 5. Min element
    auto minPerson = *min_element(people.begin(), people.end());
    cout << "Youngest person: " << minPerson.name << " (" << minPerson.age << ")" << endl;

    // 6. Accumulate ages
    int totalAge = accumulate(people.begin(), people.end(), 0, [](int sum, const Person& p) {
        return sum + p.age;
    });
    cout << "\nTotal age: " << totalAge << endl;

    // 7. Count people older than 28
    int countOlderThan28 = count_if(people.begin(), people.end(), [](const Person& p) {
        return p.age >= 28;
    });
    cout << "Count of people older than 28: " << countOlderThan28 << endl;

    // 8. Find a specific person
    auto it = find_if(people.begin(), people.end(), [](const Person& p) {
        return p.name == "Grifith";
    });
    if (it != people.end()) {
        cout << "Found: " << it->name << " (" << it->age << ")" << endl;
    } else {
        cout << "Charlie not found." << endl;
    }

    // 9. Binary search for a person by age
    sort(people.begin(), people.end()); // Sort again for binary search
    Person searchPerson("Sasuke", 30); // Dummy person to search for age
    bool found = binary_search(people.begin(), people.end(), searchPerson, [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
    if (found) {
        cout << "Person with age 30 found." << endl;
    } else {
        cout << "Person with age 30 not found." << endl;
    }

    // 10. Lower bound for age 30
    auto lower = lower_bound(people.begin(), people.end(), Person("Sasuke", 30), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
    if (lower != people.end()) {
        cout << "Lower bound for age 30: " << lower->name << " (" << lower->age << ")" << endl;
    } else {
        cout << "No lower bound found for age 30." << endl;
    }

    // 11. Upper bound for age 30
    auto upper = upper_bound(people.begin(), people.end(), Person("Sasuke", 30), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
    if (upper != people.end()) {
        cout << "Upper bound for age 30: " << upper->name << " (" << upper->age << ")" << endl;
    } else {
        cout << "No upper bound found for age 30." << endl;
    }

    return 0;
}