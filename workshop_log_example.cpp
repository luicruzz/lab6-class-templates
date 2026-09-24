/*
 * Course: COEN 2220 - Programming 2
 * Name: [Luis Cruz]
 * Lab: Lab 6 - Class Templates
 * Description: Guided example - a generic workshop metric log
 * Due date: [9/24/26]
 */

#include <iostream>
using namespace std;

template <typename T>
class WorkshopLog
{
private:
    static const int CAPACITY = 4;
    T values[CAPACITY];
    int count;

public:
    WorkshopLog()
    {
        count = 0;
    }

    int size() const
    {
        return count;
    }

    bool isEmpty() const
    {
        return count == 0;
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
};

int main()
{
    cout << boolalpha;

    WorkshopLog<int> attendanceCounts;

    cout << "Attendance records: " << attendanceCounts.size() << endl;
    cout << "Log is empty: " << attendanceCounts.isEmpty() << endl;

        attendanceCounts.add(32);
        attendanceCounts.add(47);

    cout << "Attendance records: "
     << attendanceCounts.size() << endl;

    WorkshopLog<double> workshopRatings;

    workshopRatings.add(4.25);
    workshopRatings.add(4.75);

    cout << "First workshop rating: "
         << workshopRatings.get(0) << endl;

    cout << "Second workshop rating: "
         << workshopRatings.get(1) << endl;

    return 0;
}