#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <chrono>

using namespace std;

struct Patient {
    int id;
    string name;
    int triagePriority;
    int severity;
    long long arrivalTime;

    // Constructor
    Patient(int _id, string _name, int _priority, int _severity, long long _time)
        : id(_id), name(_name), triagePriority(_priority), severity(_severity), arrivalTime(_time) {}
};

struct Compare {
    bool operator()(const Patient& a, const Patient& b) {
        // Sort by triagePriority, then severity, then arrivalTime
        if (a.triagePriority != b.triagePriority)
            return a.triagePriority > b.triagePriority;
        if (a.severity != b.severity)
            return a.severity < b.severity; 
        return a.arrivalTime > b.arrivalTime;
    }
};
int main() {
    priority_queue<Patient, vector<Patient>, Compare> pq;

    auto currentTime = []() -> long long {
        return chrono::duration_cast<chrono::milliseconds>(
                   chrono::system_clock::now().time_since_epoch())
            .count();
    };

    // Adding patients
    pq.push(Patient(1, "Alice", 1, 8, currentTime()));
    pq.push(Patient(2, "Bob", 2, 5, currentTime() + 1000)); 
    pq.push(Patient(3, "Charlie", 1, 9, currentTime() + 2000));
    pq.push(Patient(4, "David", 3, 6, currentTime() + 3000));

    // Processing patients
    cout << "Order of patients to be seen:\n";
    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << "ID: " << p.id << ", Name: " << p.name
             << ", Priority: " << p.triagePriority
             << ", Severity: " << p.severity
             << ", Arrival Time: " << p.arrivalTime << "ms\n";
    }

    return 0;
}