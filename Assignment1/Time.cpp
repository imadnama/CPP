#include "Time.h"
#include <iostream>
#include <cmath>

using namespace std;

// Helper function for validation.
void validate(int& h, int& m, int& s) {
    if (h < 0 || h > 23) h = 0;
    if (m < 0 || m > 59) m = 0;
    if (s < 0 || s > 59) s = 0;
}

// Default constructor: initializes to 23:59:59
Time::Time() : hours(23), minutes(59), seconds(59) {}

// Constructor from total seconds
Time::Time(int totalSeconds) {
    fromSecond(totalSeconds);
}

// Constructor from hours and minutes
Time::Time(int h, int m) {
    int s = 0;
    validate(h, m, s);
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}

// Constructor with all parameters
Time::Time(int h, int m, int s) {
    validate(h, m, s);
    this->hours = h;
    this->minutes = m;
    this->seconds = s;
}

// Setters with validation
void Time::setHours(int h) {
    if (h >= 0 && h <= 23) this->hours = h;
    else this->hours = 0;
}
void Time::setMinutes(int m) {
    if (m >= 0 && m <= 59) this->minutes = m;
    else this->minutes = 0;
}
void Time::setSeconds(int s) {
    if (s >= 0 && s <= 59) this->seconds = s;
    else this->seconds = 0;
}

// Getters
int Time::getHours() const {
    return hours;
}
int Time::getMinutes() const {
    return minutes;
}
int Time::getSeconds() const {
    return seconds;
}

// Converts time object to total seconds
long Time::toSecond() const {
    return hours * 3600 + minutes * 60 + seconds;
}

// Updates time object from a total second count
void Time::fromSecond(long totalSeconds) {
    if (totalSeconds < 0) totalSeconds = 0;
    this->hours = (totalSeconds / 3600) % 24;
    this->minutes = (totalSeconds % 3600) / 60;
    this->seconds = totalSeconds % 60;
}

// Advances time by n seconds
void Time::next(int n) {
    long total = toSecond();
    total += n;
    fromSecond(total);
}

// Prints in hh:mm:ss format
void Time::print() const {
    cout << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << ":"
         << (seconds < 10 ? "0" : "") << seconds;
}

// Prints in Time(h,m,s) format
void Time::printTime() const {
    cout << "Time(" << hours << "," << minutes << "," << seconds << ")";
}

// Prints in hh:mm_AM/PM format with rounding
void Time::printAmPm() const {
    long total = toSecond() + 30;
    Time roundedTime(total);

    int h = roundedTime.getHours();
    int m = roundedTime.getMinutes();
    const char* am_pm = (h < 12) ? "AM" : "PM";

    h = h % 12;
    if (h == 0) { // 12 AM (midnight) and 12 PM (noon)
        h = 12;
    }

    cout << (h < 10 ? "0" : "") << h << ":"
         << (m < 10 ? "0" : "") << m << "_" << am_pm;
}