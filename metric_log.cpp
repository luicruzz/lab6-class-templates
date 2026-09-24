/*
 * Course: COEN 2220 - Programming 2
 * Name: [Luis Cruz]
 * Lab: Lab 6 - Class Templates
 * Description: Generic metric log practice and ADT contract
 * Due date: [9/24/26]
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
    static const int CAPACITY = 4;
    T values[CAPACITY];
    int count;

public:
    MetricLog()
    {
        count = 0;
    }

    bool add(const T& value)
    {
        if (count == CAPACITY)
        {
            return false;
        }

        values[count] = value;
        count++;
        return true;
    }

    T get(int index) const
    {
        // Precondition: index is between 0 and count - 1.
        return values[index];
    }

    int size() const
    {
        return count;
    }

    bool isEmpty() const
    {
        return count == 0;
    }

    bool contains(const T& target) const;
};

// ===== Do not resolve these TODOs yet (Part D) =====

// TODO (Part D): Define MetricLog<T>::contains outside the class.
// It receives a generic target by const reference.
// Return true when an equal stored value exists; otherwise return false.

template <typename T>
bool MetricLog<T>::contains(const T& target) const
    {
        for (int index = 0; index < count; index++)
        {
         if (values[index] == target)
         {
            return true;
         }
     }

        return false;
    }

int main()
{
    MetricLog<int> waitlistCounts;

    waitlistCounts.add(6);
    waitlistCounts.add(11);

    cout << "First waitlist count: "
         << waitlistCounts.get(0) << endl;

    cout << "Stored waitlist counts: "
         << waitlistCounts.size() << endl;

    // ===== Do not resolve these TODOs yet (Part E) =====

    // TODO (Part E): Create a MetricLog<double> for session durations.
    // TODO (Part E): Add two dummy duration values to that log.
    // TODO (Part E): Use contains with one value that exists and one that does not exist.
    // TODO (Part E): Print descriptive English labels for all results.

    return 0;
}