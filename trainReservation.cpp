#include <iostream>
#include <string>
using namespace std;

struct Passenger
{
    string pnr;
    string name;
    int age;
    string trainNumber;
    int seatNumber;

    Passenger* previous;
    Passenger* next;
};

Passenger* head = NULL;
Passenger* tail = NULL;

// Add Reservation
void addReservation()
{
    Passenger* newPassenger = new Passenger;

    cout << "Enter PNR: ";
    cin >> newPassenger->pnr;

    cout << "Enter Passenger Name: ";
    cin >> newPassenger->name;

    cout << "Enter Age: ";
    cin >> newPassenger->age;

    cout << "Enter Train Number: ";
    cin >> newPassenger->trainNumber;

    cout << "Enter Seat Number: ";
    cin >> newPassenger->seatNumber;

    newPassenger->previous = NULL;
    newPassenger->next = NULL;

    if (head == NULL)
    {
        head = tail = newPassenger;
    }
    else
    {
        newPassenger->previous = tail;
        tail->next = newPassenger;
        tail = newPassenger;
    }

    cout << "Reservation Added Successfully!\n";
}

// Display Forward
void displayForward()
{
    if (head == NULL)
    {
        cout << "No Reservations Found.\n";
        return;
    }

    Passenger* temp = head;

    cout << "\n===== TRAIN RESERVATIONS =====\n";

    while (temp != NULL)
    {
        cout << "PNR           : " << temp->pnr << endl;
        cout << "Passenger Name: " << temp->name << endl;
        cout << "Age           : " << temp->age << endl;
        cout << "Train Number  : " << temp->trainNumber << endl;
        cout << "Seat Number   : " << temp->seatNumber << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

// Display Backward
void displayBackward()
{
    if (tail == NULL)
    {
        cout << "No Reservations Found.\n";
        return;
    }

    Passenger* temp = tail;

    cout << "\n===== RESERVATIONS BACKWARD =====\n";

    while (temp != NULL)
    {
        cout << "PNR           : " << temp->pnr << endl;
        cout << "Passenger Name: " << temp->name << endl;
        cout << "Age           : " << temp->age << endl;
        cout << "Train Number  : " << temp->trainNumber << endl;
        cout << "Seat Number   : " << temp->seatNumber << endl;
        cout << "-----------------------------\n";

        temp = temp->previous;
    }
}

// Search Reservation
void searchReservation()
{
    string searchPNR;

    cout << "Enter PNR to search: ";
    cin >> searchPNR;

    Passenger* temp = head;

    while (temp != NULL)
    {
        if (temp->pnr == searchPNR)
        {
            cout << "\nReservation Found!\n";
            cout << "PNR           : " << temp->pnr << endl;
            cout << "Passenger Name: " << temp->name << endl;
            cout << "Age           : " << temp->age << endl;
            cout << "Train Number  : " << temp->trainNumber << endl;
            cout << "Seat Number   : " << temp->seatNumber << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Reservation Not Found.\n";
}

// Cancel Reservation
void cancelReservation()
{
    string searchPNR;

    cout << "Enter PNR to cancel: ";
    cin >> searchPNR;

    Passenger* temp = head;

    while (temp != NULL && temp->pnr != searchPNR)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Reservation Not Found.\n";
        return;
    }

    // Only one node
    if (head == tail)
    {
        head = tail = NULL;
    }
    // First node
    else if (temp == head)
    {
        head = head->next;
        head->previous = NULL;
    }
    // Last node
    else if (temp == tail)
    {
        tail = tail->previous;
        tail->next = NULL;
    }
    // Middle node
    else
    {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    }

    delete temp;

    cout << "Reservation Cancelled Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== TRAIN RESERVATION SYSTEM =====\n";
        cout << "1. Add Reservation\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Search Reservation\n";
        cout << "5. Cancel Reservation\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            addReservation();
        else if (choice == 2)
            displayForward();
        else if (choice == 3)
            displayBackward();
        else if (choice == 4)
            searchReservation();
        else if (choice == 5)
            cancelReservation();
        else if (choice == 6)
            cout << "Program Ended.\n";
        else
            cout << "Invalid Choice.\n";

    } while (choice != 6);

    return 0;
}