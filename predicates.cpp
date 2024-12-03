//predicate is a function, function object (functor), or lambda expression that returns a boolean value (true or false)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

class IsUnderAge {
public:
    IsUnderAge(int a) : ageLimit(a) {}

    bool operator()(const Person& p) const {
        return p.age < ageLimit; // Predicate: returns true if the person's age is less than the age limit
    }

private:
    int ageLimit;
};

bool isEven(int n) {
    return n % 2 == 0;
}

class IsOdd {
public:
    bool operator()(int n) const {
        return n % 2 != 0;
    }
};

int main48() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    //function pointer as a predicate
    int count = count_if(numbers.begin(), numbers.end(), isEven);
    cout << "Number of even numbers: " << count <<   endl;


    //===============================================================//

    // functor as a predicate
    IsOdd isOdd;
    int count1 = count_if(numbers.begin(), numbers.end(), isOdd);
    cout << "Number of odd numbers: " << count1 << endl;


    //===============================================================//

    // lambda expression as a predicate
    int count2 = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 3; // Predicate: check if number is greater than 3
    });

    cout << "Number of elements greater than 3: " << count2 << endl;


    //===============================================================//


    vector<Person> people = {
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 15},
        {"Diana", 25}
    };

    int ageLimit = 21;

    // Remove people under the age limit
    auto newEnd = remove_if(people.begin(), people.end(), IsUnderAge(ageLimit));
    people.erase(newEnd, people.end());

    cout << "People aged " << ageLimit << " and above:\n";
    for (const auto& person : people) {
        cout << person.name << " (" << person.age << ")\n";
    }




    return 0;
}