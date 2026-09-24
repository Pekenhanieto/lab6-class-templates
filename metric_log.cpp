/*
 * Course: COEN 2220 - Programming 2
 * Name: [Julian A. Pagan Hernandez]
 * Lab: Lab 6 - Class Templates
 * Description: Generic metric log practice and ADT contract
 * Due date: [09/24/2026]
 */

#include <iostream>
using namespace std;

/*
 * MetricLog ADT
 *
 * Data:
 * [Complete in Part E: describe the values managed by this log.]
 *
 * Operations:
 * [Complete in Part E: describe add(value).]
 * [Complete in Part E: describe get(index) and its precondition.]
 * [Complete in Part E: describe contains(target).]
 * [Complete in Part E: describe size() and isEmpty().]
 */

template <typename T>
class MetricLog
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Add a constant for a fixed capacity of four values.
    const int CAPACITY = 4;
    // TODO (Part C): Add an array that stores values of the generic type.
    T values[4];
    // TODO (Part C): Add an int that tracks how many values are stored.
    int count;

public:
    // TODO (Part C): Write a constructor that creates an empty log.
    MetricLog() : CAPACITY(4), count(0) {}

    // TODO (Part C): Write add. It receives one generic value by const reference.
    // Return false when the log has no remaining capacity.
    bool add(const T& value) {
        if (count >= CAPACITY) {
            return false;
        }
        values[count] = value;
        count++;
        return true;
    }

    // TODO (Part C): Write get. It receives a valid index and returns its stored value.
    T get(int index) const {
        if (index < 0 || index >= count) {
            cout << "Error: Index out of bounds." << endl;
            // Return a default-constructed value or handle the error as appropriate
            return T();
        }
        return values[index];
    }

    // TODO (Part C): Write size as a const member function.
    int size() const {
        return count;
    }

    // TODO (Part C): Write isEmpty as a const member function.
    bool isEmpty() const {
        return count == 0;
    }

    bool contains(const T& target) const; // Declaration of contains member function
};

// ===== Do not resolve these TODOs yet (Part D) =====

// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.

// Here's the definition of the contains member function outside the class:
template <typename T>
bool MetricLog<T>::contains(const T& target) const {
        for (int i = 0; i < count; ++i) {
            if (values[i] == target) {
                return true;
            }
        }
        return false;
    }



int main()
{
    cout << boolalpha;        // Print bool values as true or false.
    MetricLog<int> waitlistCounts;

    // Add two waitlist counts to the log.
    waitlistCounts.add(6);
    waitlistCounts.add(11);

    // Print the first waitlist count and the number of stored waitlist counts.
    cout << "First waitlist count: " << waitlistCounts.get(0) << endl;
    cout << "Stored waitlist counts: " << waitlistCounts.size() << endl;

    // ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    MetricLog<double> sessionDurations; // Create a log for session durations

    // TODO (Part E): Add two dummy duration values to that log.
    sessionDurations.add(120.5); // Add a session duration of 120.5 seconds
    sessionDurations.add(180.0); // Add a session duration of 180.0 seconds

    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    bool exists1 = sessionDurations.contains(120.5); // Check for a value that exists
    bool exists2 = sessionDurations.contains(90.0); // Check for a value that does not exist

    // TODO (Part E): Print descriptive English labels for all results.
    cout << "Session duration of 120.5 seconds: " << (exists1 ? "Found" : "Not Found") << endl; // Print result for the first value
    cout << "Session duration of 90.0 seconds: " << (exists2 ? "Found" : "Not Found") << endl; // Print result for the second value

    return 0;
}