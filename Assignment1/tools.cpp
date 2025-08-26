#include "tools.h"
#include "Time.h"
#include <iostream>
#include <cmath>

using namespace std;

// Rocket Landing implementation
void printRocketLanding(Time launchTime, int durationSeconds) {
    long launch_s = launchTime.toSecond();
    long landing_s = launch_s + durationSeconds;

    int days = landing_s / 86400; // 86400 seconds in a day
    Time landingTime(landing_s);

    cout << "Landing time: ";
    if (days > 0) {
        cout << "[+" << days << " day" << (days > 1 ? "s" : "") << "],";
    }
    landingTime.print();
}

void printRocketLanding(Time launchTime, Time duration) {
    // Reuse the first function to avoid code duplication
    printRocketLanding(launchTime, duration.toSecond());
}


// Time Difference implementation
void printTimeDifference(Time t1, Time t2) {
    long diff_s = abs(t1.toSecond() - t2.toSecond());
    Time diffTime(diff_s);
    cout << "Time difference: " << diff_s << ", ";
    diffTime.print();
    cout << endl;
}

void printTimeDifference(Time t1, Time t2, Time t3) {
    // Reuse the two-parameter version
    printTimeDifference(t1, t2);
    printTimeDifference(t1, t3);
    printTimeDifference(t2, t3);
}

// Sort implementation for integers
void printSort(int a, int b) {
    if (a < b) cout << a << " " << b << endl;
    else cout << b << " " << a << endl;
}

void printSort(int a, int b, int c) {
    int min, mid, max;
    min = (a < b && a < c) ? a : (b < c ? b : c);
    max = (a > b && a > c) ? a : (b > c ? b : c);
    mid = (a + b + c) - min - max;
    cout << min << " " << mid << " " << max << endl;
}

// Sort implementation for Time objects
void printSort(Time t1, Time t2) {
    if (t1.toSecond() < t2.toSecond()) {
        t1.print(); cout << " | "; t2.print();
    } else {
        t2.print(); cout << " | "; t1.print();
    }
    cout << endl;
}

void printSort(Time t1, Time t2, Time t3) {
    Time *p1 = &t1, *p2 = &t2, *p3 = &t3;
    if (p1->toSecond() > p2->toSecond()) swap(p1, p2);
    if (p2->toSecond() > p3->toSecond()) swap(p2, p3);
    if (p1->toSecond() > p2->toSecond()) swap(p1, p2);

    p1->print(); cout << " | "; p2->print(); cout << " | "; p3->print();
    cout << endl;
}