/* Author: Yuan Bo
 * Date: 4/16 2021
 * Description:
 * This assignment has you creating an OOP Calendar application allowing for the
 * user to create appointments and reminders on a custom calendar.
 * user should follow the message showed up on the screen.
 * the make file will make a file called "calendar"
 * */

#include "bo_calendar.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


//calendar--------------------------------------------------------------------------------------------------------------
calendar::calendar() {
    this->calendarName = "Calendar";
    this->dayArray = new day[30];
    this->startDay = 1;
}

//this method will take the calendarName, howMandy day and start day to crate a calendar.
calendar::calendar(std::string calendarName, int howManyDay, int startDay) {
    this->calendarName = calendarName;
    this->howManyDay = howManyDay;
    this->dayArray = new day[howManyDay];
    for (int i = 0; i < howManyDay; i++) {
        if (startDay > 7) {
            startDay = 1;
        }
        dayArray[i] = day((i + 1), startDay);
        startDay++;
    }
}

//this method will be input a int and day number and a string note to add a new reminder
void calendar::addErrand(int dayNum, std::string note) {
    dayArray[dayNum - 1].addErrand(note);
}

//this method is a override method and it will be input a int and day number, start Hour number, start Min number,
// end hour number and a end min number then a string note to add a new appointment
void calendar::addErrand(int dayNum, int startHour, int startMin, int endHour, int endMin, std::string note) {
    dayArray[dayNum - 1].addErrand(startHour, startMin, endHour, endMin, note);
}

//this method will able to delete a errand the user choose by call the deleteErrand from day class.
void calendar::deleteErrand(int dayNum, int textNum) {
    dayArray[dayNum - 1].deleteErrand(textNum);
}

//this method will out put a file contain the calendar info by take a file name
void calendar::makeFile(std::string fileName) {
    std::string fileText = calendarName;
    fileText += "\n";
    for (std::size_t i = 0; i < calendarName.size(); i++) {
        fileText += "-";
    }
    fileText += "\n";

    for (int i = 0; i < howManyDay; i++) {
        fileText += dayArray[i].to_string();
        fileText += dayArray[i].noWeekDayDetailString();
        fileText += "\n";
    }
    std::ofstream calendarFile;
    calendarFile.open(fileName);
    calendarFile << fileText;
    calendarFile.close();

}

//return calendar name
std::string calendar::getCalendarName() {
    return calendarName;
}

//this method will only return some detail from a user pick date.
std::string calendar::getOneDayText(int dayNumber) {
    std::string detailText = dayArray[dayNumber].detailString();
    return detailText;
}

//this method will return the detail of errand user just deleted.
std::string calendar::getOneDayDeleteText(int dayNumber) {
    std::string detailText = dayArray[dayNumber].deleteString();
    return detailText;
}

//this is a to string method in calendar return some general string info of the calendar.
std::string calendar::to_string() {
    std::string calendarText;
    for (int i = 0; i < howManyDay; i++) {
        calendarText += dayArray[i].to_string();
    }
    return calendarText;
}

//day-------------------------------------------------------------------------------------------------------------------
day::day() {
    this->dayNum = -1;
    this->whichDay = -1;
}

day::day(int dayNum, int whichDay) {
    this->dayNum = dayNum;
    this->whichDay = whichDay;
}

//this method will only take a note and make a new reminder.
void day::addErrand(std::string note) {
    reminderVector.push_back(new reminder(note));
}

//this method will take start hour, start min, end hour, end min and a string to crate a new appointment
void day::addErrand(int startHour, int startMin, int endHour, int endMin, std::string note) {
    reminderVector.push_back(new reminder(startHour, startMin, endHour, endMin, note));
}

//this method will delete an errand user pick
void day::deleteErrand(int reminderNum) {
    cout << "\"" << reminderVector[reminderNum - 1]->to_string() << "\" Deleted" << endl;
    delete reminderVector[reminderNum - 1];
    reminderVector.erase(reminderVector.begin() + reminderNum - 1);
}

//this method will return the reminder vector of this day.
std::vector<reminder *> day::getReminder() {
    return reminderVector;
}

//this method will print out the detail of the errand user just deleted.
std::string day::deleteString() {
    std::string deleteDetail = "Errands:\n";
    for (std::size_t i = 0; i < reminderVector.size(); i++) {
        deleteDetail += std::to_string(i + 1) + ". ";
        deleteDetail += (reminderVector.at(i))->to_string();
        deleteDetail += "\n";
    }
    return deleteDetail;
}

//this method will return a string with no week day for out put the file
std::string day::noWeekDayDetailString() {
    std::string noWeekDayDetailString = "";
    for (std::size_t i = 0; i < reminderVector.size(); i++) {
        noWeekDayDetailString += "\t";
        noWeekDayDetailString += (reminderVector.at(i))->to_string();
        noWeekDayDetailString += "\n";
    }
    return noWeekDayDetailString;
}

//this method will print a string for a day's detail
std::string day::detailString() {
    std::string reminderDetail = " - ";
    if (whichDay == 1) {
        reminderDetail += "Monday: ";
    } else if (whichDay == 2) {
        reminderDetail += "Tuesday: ";
    } else if (whichDay == 3) {
        reminderDetail += "Wednesday: ";
    } else if (whichDay == 4) {
        reminderDetail += "Thursday: ";
    } else if (whichDay == 5) {
        reminderDetail += "Friday: ";
    } else if (whichDay == 6) {
        reminderDetail += "Saturday: ";
    } else if (whichDay == 7) {
        reminderDetail += "Sunday: ";
    }
    reminderDetail += "\n";
    if (!reminderVector.empty()) {
        for (std::size_t i = 0; i < reminderVector.size(); i++) {
            reminderDetail += "\t";
            reminderDetail += (reminderVector.at(i))->to_string();
            reminderDetail += "\n";
        }
    } else {
        reminderDetail += "\t";
        reminderDetail += "no reminder and appointment in this day";
        reminderDetail += "\n";
    }
    return reminderDetail;
}

//this to string will return a string have the simple info of one day
std::string day::to_string() {
    std::string dayText = std::to_string(dayNum) + " - ";
    if (whichDay == 1) {
        dayText += "Monday: ";
    } else if (whichDay == 2) {
        dayText += "Tuesday: ";
    } else if (whichDay == 3) {
        dayText += "Wednesday: ";
    } else if (whichDay == 4) {
        dayText += "Thursday: ";
    } else if (whichDay == 5) {
        dayText += "Friday: ";
    } else if (whichDay == 6) {
        dayText += "Saturday: ";
    } else if (whichDay == 7) {
        dayText += "Sunday: ";
    }


    if (reminderVector.size() == 0) {
        dayText += "No Errands\n";
    } else {
        dayText += std::to_string(reminderVector.size()) + " Errands\n";
    }
    return dayText;
}


//reminder--------------------------------------------------------------------------------------------------------------

reminder::reminder(std::string note) {
    this->note = note;
    this->startHour = -1;
    this->startMin = -1;
    this->endHour = -1;
    this->endMin = -1;
};

reminder::reminder(int startHour, int startMin, int endHour, int endMin, std::string note) {
    this->startHour = startHour;
    this->startMin = startMin;
    this->endHour = endHour;
    this->endMin = endMin;
    this->note = note;
};

//this is a override to string will return detail of one reminder/appointment
//in this method, if user enter a min number which is from 0 to 9, and add a 0 in front of it.
std::string reminder::to_string() {
    std::string reminderText;
    if (startHour == -1) {
        reminderText = "Reminder  -  ";
        reminderText += note;
    } else {
        reminderText = "Appointment  -  ";
        reminderText += std::to_string(startHour);
        reminderText += ":";
        switch (startMin) {
            case 0 :
                reminderText += "00";
                break;
            case 1 :
                reminderText += "01";
                break;
            case 2 :
                reminderText += "02";
                break;
            case 3 :
                reminderText += "03";
                break;
            case 4 :
                reminderText += "04";
                break;
            case 5 :
                reminderText += "05";
                break;
            case 6 :
                reminderText += "06";
                break;
            case 7 :
                reminderText += "07";
                break;
            case 8 :
                reminderText += "08";
                break;
            case 9 :
                reminderText += "09";
                break;
            default :
                reminderText += std::to_string(startMin);
        }
        reminderText += " - ";
        reminderText += std::to_string(endHour);
        reminderText += ":";
        switch (endMin) {
            case 0 :
                reminderText += "00";
                break;
            case 1 :
                reminderText += "01";
                break;
            case 2 :
                reminderText += "02";
                break;
            case 3 :
                reminderText += "03";
                break;
            case 4 :
                reminderText += "04";
                break;
            case 5 :
                reminderText += "05";
                break;
            case 6 :
                reminderText += "06";
                break;
            case 7 :
                reminderText += "07";
                break;
            case 8 :
                reminderText += "08";
                break;
            case 9 :
                reminderText += "09";
                break;
            default :
                reminderText += std::to_string(endMin);
        }
        reminderText += " - ";
        reminderText += note;
    }
    return reminderText;
}