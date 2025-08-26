#ifndef TOOLS_H
#define TOOLS_H

#include "Time.h"

// Function declarations

// Prints the landing time of a rocket
void printRocketLanding(Time launchTime, int durationSeconds);
void printRocketLanding(Time launchTime, Time duration);

// Prints the difference between two or three time objects
void printTimeDifference(Time t1, Time t2);
void printTimeDifference(Time t1, Time t2, Time t3);

// Sorts and prints two or three integers or Time objects
void printSort(int a, int b);
void printSort(int a, int b, int c);
void printSort(Time t1, Time t2);
void printSort(Time t1, Time t2, Time t3);

#endif