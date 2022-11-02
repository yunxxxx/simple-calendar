/* Author: Yuan Bo
 * Date: 4/16 2021
 * Description:
 * This assignment has you creating an OOP Calendar application allowing for the
 * user to create appointments and reminders on a custom calendar.
 * user should follow the message showed up on the screen.
 * the make file will make a file called "calendar"
 * */

#pragma once
#ifndef BO_CALENDAR_H
#define BO_CALENDAR_H

#include <string>
#include <vector>

using namespace std;

//call the reminder and the day first so C++ know what I'm talking about.
class reminder;

class day;

class calendar {
private:
    std::string calendarName;
    int howManyDay;
    day *dayArray;
    int startDay;

public:
    calendar();

    calendar(std::string calendarName, int howManyDay, int startDay);

    //method

    void addErrand(int dayNum, std::string note);

    void addErrand(int dayNum, int startHour, int startMin, int endHour, int endMin, std::string note);

    void deleteErrand(int dayNum, int textNum);

    void makeFile(std::string fileName);

    std::string getCalendarName();

    std::string getOneDayText(int dayNumber);

    std::string getOneDayDeleteText(int dayNumber);

    std::string to_string();

};

class day {
private:
    int dayNum;
    int whichDay;

public:
    std::vector<reminder *> reminderVector;

    day();

    day(int dayNum, int whichDay);

    //method

    void addErrand(std::string note);

    void addErrand(int startHour, int startMin, int endHour, int endMin, std::string note);

    void deleteErrand(int reminderNum);

    std::vector<reminder *> getReminder();

    std::string noWeekDayDetailString();

    std::string deleteString();

    std::string detailString();

    virtual std::string to_string();

};

//make the reminder a virtual of day class
class reminder final : public virtual day {
private:
    int startHour;
    int startMin;
    int endHour;
    int endMin;
    std::string note;

public:
    reminder(std::string note);

    reminder(int startHour, int startMin, int endHour, int endMin, std::string note);

    //override to string
    virtual std::string to_string();
};

#endif
