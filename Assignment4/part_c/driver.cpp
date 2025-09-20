// driver.cpp
#include <iostream>
#include "List.h"
#include "Utility.h"
#include "Point.h"

int main() {
    std::cout << "<<< List<int> >>>" << std::endl;
    List<int> list1;
    std::cout << "list1: " << list1 << std::endl;
    std::cout << "append{1,2,3}: " << list1.append(1).append(2).append(3) << std::endl;
    std::cout << "length(): " << list1.length() << std::endl;
    List<int> list2(list1);
    std::cout << "list2(list1): " << list2 << std::endl;
    std::cout << "list1.extend(list2).remove(0): " << list1.extend(list2).remove(0) << std::endl;
    std::cout << "count(3): " << list1.count(3) << std::endl;
    list2 = list1;
    std::cout << "list2=list1: " << list2 << std::endl;
    list2[0] = 100;
    list2[-1] = 200;
    std::cout << "list2{[0]=100, [-1]=200}: " << list2 << std::endl;
    std::cout << "index (2): " << list2.index(2) << std::endl;
    std::cout << "list2 slicing: " << list2["2:"] + list2[":3"] + list2["1:-1"] << std::endl;
    std::cout << "list1: " << list1 << std::endl;
    list1 += list2["2:"];
    std::cout << "list1{+= & slicing}: " << list1 << std::endl;
    list1.clear();
    std::cout << "list1.clear(): " << list1 << std::endl;

    std::cout << "\n<<< List<string> >>>" << std::endl;
    List<std::string> list3, list4, list5;
    std::cout << "list3, list4, list5: " << list3 << ", " << list4 << ", " << list5 << std::endl;
    std::cout << "list3.append(): " << list3.append("London").append("is").append("the").append("capital").append("of") << std::endl;
    std::cout << "list4.append(): " << list4.append("Great").append("Britian") << std::endl;
    std::cout << "list5.append(): " << list5.append("Paris").append("France") << std::endl;
    list3 += list4;
    std::cout << "list3 += list4: " << list3 << std::endl;
    std::cout << "slicing & [index]: " << std::endl;
    std::cout << list3 << std::endl << list3[":4"] << std::endl << list3["-2:"] << " - " << list3[0] << std::endl;
    std::cout << list5[":1"] + list3["1:-2"] + list5["1:"] << std::endl;

    std::cout << "\n<<< Functions >>>" << std::endl;
    std::cout << "list2, doTwice (list2): " << list2 << ", " << doTwice(list2) << std::endl;
    std::cout << "list5, doTwice (list5): " << list5 << ", " << doTwice(list5) << std::endl;

    int arr1[] = { 7,2,14,5,10 };
    std::cout << "maxT<int>: " << maxT(arr1, 5) << std::endl;

    std::string arr2[] = { "aaa", "abcd", "aaaaa", "qwerty", "qaz" };
    std::cout << "maxT<string>: " << maxT(arr2, 5) << std::endl;

    Point arr3[] = { Point(1,0), Point(), Point(7,2), Point(3,12), Point(5,6) };
    std::cout << "maxT<Point>: " << maxT(arr3, 5).toString() << std::endl;

    return 0;
}