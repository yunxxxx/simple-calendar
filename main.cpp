/* Author: Yuan Bo
 * Date: 4/16 2021
 * Description:
 * This assignment has you creating an OOP Calendar application allowing for the
 * user to create appointments and reminders on a custom calendar.
 * user should follow the message showed up on the screen.
 * the make file will make a file called "calendar"
 * */


#include "bo_calendar.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
    cout << "Welcome to CSE240 Calendar" << endl;

    int userPickNum = 0, dayNum, lineNum, howManyDay, startDay, errandTypeNum = 0;
    string calendarName, note, fileName;

    //will keep asking user to pick one correct option
    while (userPickNum == 0) {
        cout << "1. Build a new Calendar" << endl;
        cout << "2. Exit" << endl;
        cin >> userPickNum;
        cout << endl;
        if (userPickNum != 1 && userPickNum != 2) {
            system("clear");
            cout << "please enter a correct number" << endl;
            userPickNum = 0;
        }
    }

    //if user pick 2, set it to 0 then let user exit the function.
    if (userPickNum == 2) {
        userPickNum = 0;
    }

    //if user pick 1, let the user enter the calendar correction board.
    if (userPickNum != 0) {
        system("clear");
        cout << "Building a new calendar." << endl;
        cout << "Give your calendar a title:  " << endl;
        cin.ignore();
        getline(cin, calendarName);
        cout << endl;

        //set howManyDay to -1 and keep ask user for a positive number
        howManyDay = -1;
        while (howManyDay < 1) {
            cout << "How many days should this calendar have? " << endl;
            cin >> howManyDay;
            cout << endl;
            if (howManyDay < 1) {
                system("clear");
                cout << "Please enter a number greater than 0" << endl;
                cout << endl;
            }
        }

        //set startDay to -1 and keep ask user for a number between 1 and 7;
        startDay = -1;
        while (startDay < 1 || startDay > 7) {
            cout << "What day does your calendar start on? " << endl;
            cout << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday" << endl;
            cin >> startDay;
            cout << endl;
            if (startDay < 1 || startDay > 7) {
                system("clear");
                cout << "Please enter a correct day number" << endl;
                cout << endl;
            }
        }

        system("clear");
        calendar *newCalendar = new calendar(calendarName, howManyDay, startDay);
        cout << "Your Calendar has been created. " << endl;
        cout << endl;
        while (userPickNum != 0) {
            cout << "What would you like to do?" << endl;
            cout
                    << "1. Display Whole Calendar\n2. Display a Single Day\n3. Add an Errand\n4. Delete an Errand\n5. Save to a file\n0. Exit "
                    << endl;
            cin >> userPickNum;
            cout << endl;

            if (userPickNum == 1) {
                system("clear");
                cout << "Calendar: \"" << calendarName << "\"" << endl;

                cout << newCalendar->to_string() << endl;
            } else if (userPickNum == 2) {
                system("clear");
                cout << newCalendar->to_string() << endl;
                cout << "Select which day to display: " << endl;
                cout << "Day (1 –" << howManyDay << ") (0 - Back to main menu)" << endl;
                cout << ">> ";
                cin >> dayNum;
                system("clear");
                if (dayNum != 0) {
                    if (dayNum > 0) {
                        cout << newCalendar->getOneDayText(dayNum - 1) << endl;
                    }
                }
            } else if (userPickNum == 3) {
                system("clear");
                cout << "Calendar:" << endl;
                cout << newCalendar->to_string() << endl;
                cout << endl;
                cout << "Add an Errand" << endl;
                cout << "Select which day you want to add an Errand to:" << endl;
                cout << "Day (1 –" << howManyDay << ") (0 - Back to main menu)" << endl;
                cout << ">> ";
                cin >> dayNum;
                system("clear");
                if (dayNum != 0) {
                    if (dayNum > 0) {
                        cout << "What type of Errand?" << endl;
                        //set the errandTypeNum to -1 and enter the while loop, never go out of the while loop tile user enter 1 or 2 or 0
                        errandTypeNum = -1;
                        while (errandTypeNum < 0 || errandTypeNum > 2) {
                            cout << "1. Reminder\n2. Appointment\n0. Back to main menu\n>> ";
                            cin >> errandTypeNum;
                            if (errandTypeNum < 0 || errandTypeNum > 2) {
                                system("clear");
                                cout << "Please enter a valued command" << endl;
                            }
                            if (errandTypeNum != 0) {
                                if (errandTypeNum == 1) {
                                    cout << "Enter reminder text:  ";
                                    cin.ignore();
                                    getline(cin, note, '\n');
                                    newCalendar->addErrand(dayNum, note);
                                    system("clear");
                                    cout << "errand added" << endl;
                                }
                                if (errandTypeNum == 2) {
                                    //when people enter some time is not valued, system will ask user to enter a valued one.
                                    int startHour = -1, startMin = -1, endHour = -1, endMin = -1;
                                    while (startHour < 0 || startHour > 23) {
                                        cout << "Enter start time hour (24 hour clock): ";
                                        cin >> startHour;
                                        cout << endl;
                                        if (startHour < 0 || startHour > 23) {
                                            cout << "Please enter a valued time" << endl;
                                        }
                                    }

                                    while (startMin < 0 || startMin > 59) {
                                        cout << "Enter start time minutes: ";
                                        cin >> startMin;
                                        cout << endl;
                                        if (startMin < 0 || startMin > 59) {
                                            cout << "Please enter a valued time" << endl;
                                        }
                                    }

                                    while (endHour < 0 || endHour > 23) {
                                        cout << "Enter end time hours (24 hour clock): ";
                                        cin >> endHour;
                                        cout << endl;
                                        if (endHour < 0 || endHour > 23) {
                                            cout << "Please enter a valued time" << endl;
                                        }
                                    }

                                    while (endMin < 0 || endMin > 59) {
                                        cout << "Enter end time minutes: ";
                                        cin >> endMin;
                                        cout << endl;
                                        if (endMin < 0 || endMin > 59) {
                                            cout << "Please enter a valued time" << endl;
                                        }
                                    }

                                    cout << "Enter reminder text:  ";
                                    cin.ignore();
                                    getline(cin, note, '\n');
                                    cout << endl;

                                    newCalendar->addErrand(dayNum, startHour, startMin, endHour, endMin, note);
                                    system("clear");
                                    cout << "errand added" << endl;
                                }
                            }
                        }
                    }
                }
            } else if (userPickNum == 4) {
                system("clear");
                cout << "Calendar:" << endl;
                cout << newCalendar->to_string() << endl;
                cout << endl;
                cout << "Remove an Errand" << endl;
                cout << "Select which day you want to remove an Errand from: " << endl;
                cout << "Day (1 –" << howManyDay << ") (0 - Back to main menu)" << endl;
                cout << ">> ";
                cin >> dayNum;
                system("clear");
                if (dayNum != 0) {

                    cout << "You have chosen " << newCalendar->getOneDayText(dayNum - 1) << endl;

                    cout << newCalendar->getOneDayDeleteText(dayNum - 1) << endl;
                    cout << "Which would you like to delete? (0- Back to main menu) " << endl;
                    cout << ">> ";
                    cin >> lineNum;
                    system("clear");
                    if (lineNum != 0) {
                        newCalendar->deleteErrand(dayNum, lineNum);
                        cout << endl;
                    }
                }
            } else if (userPickNum == 5) {
                cout << "Please enter the filename to store to (don't include the file type)" << endl;
                cout << ">> ";
                cin.ignore();
                getline(cin, fileName);
                fileName += ".txt";
                newCalendar->makeFile(fileName);
                system("clear");
                cout << fileName << " has been created" << endl;
                cout << endl;
            } else {
                // if user enter a number is not 5 and not 0, ask user to enter a correct number
                if (userPickNum != 0) {
                    system("clear");
                    cout << "Please enter a correct command number" << endl;
                    cout << endl;
                }
            }

        }
    }
}

