#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <string>

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    // Constructors
    Time(); // Default constructor
    Time(int totalSeconds); // Constructor from seconds
    Time(int h, int m); // Constructor from hours and minutes
    Time(int h, int m, int s); // Constructor with all parameters

    // Setters and Getters
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Utility Methods
    long toSecond() const; // Converts time to total seconds
    void fromSecond(long totalSeconds); // Converts total seconds to H:M:S format
    void next(int n = 1); // Advances the clock by n seconds

    // Print Methods
    void print() const; // Prints in hh:mm:ss format
    void printAmPm() const; // Prints in 12-hour AM/PM format with rounding
    void printTime() const; // Prints in Time(h,m,s) format

    std::string toString() const;
    int compare(const Time& other) const;
};

#endif