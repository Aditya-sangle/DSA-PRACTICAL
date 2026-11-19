#include <iostream>
#include <string>
using namespace std;

struct Call
{
    string phone;
    string name;
    string duration;
    Call* next;
};

Call* head = NULL;


// Add a call record
void addCall()
{
    Call* newCall = new Call;

    cout << "Enter Caller Name: ";
    cin >> newCall->name;

    cout << "Enter Phone Number: ";
    cin >> newCall->phone;

    cout << "Enter Call Duration: ";
    cin >> newCall->duration;

    newCall->next = NULL;

    if (head == NULL)
    {
        head = newCall;
    }
    else
    {
        Call* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newCall;
    }

    cout << "Call added successfully!\n";
}


// Display call records
void displayCalls()
{
    if (head == NULL)
    {
        cout << "Call Log is Empty.\n";
        return;
    }

    Call* temp = head;

    cout << "\n===== CALL LOG =====\n";

    while (temp != NULL)
    {
        cout << "Caller Name   : " << temp->name << endl;
        cout << "Phone Number  : " << temp->phone << endl;
        cout << "Call Duration : " << temp->duration << endl;
        cout << "-------------------------\n";

        temp = temp->next;
    }
}


// Search call record
void searchCall()
{
    string searchNumber;

    cout << "Enter phone number to search: ";
    cin >> searchNumber;

    Call* temp = head;

    while (temp != NULL)
    {
        if (temp->phone == searchNumber)
        {
            cout << "\nCall Found!\n";
            cout << "Caller Name   : " << temp->name << endl;
            cout << "Phone Number  : " << temp->phone << endl;
            cout << "Call Duration : " << temp->duration << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Call Not Found.\n";
}


// Delete call record
void deleteCall()
{
    string searchNumber;

    cout << "Enter phone number to delete: ";
    cin >> searchNumber;

    if (head == NULL)
    {
        cout << "Call Log is Empty.\n";
        return;
    }

    // Delete first node
    if (head->phone == searchNumber)
    {
        Call* temp = head;
        head = head->next;

        delete temp;

        cout << "Call Deleted Successfully!\n";
        return;
    }

    // Delete middle or last node
    Call* temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->phone == searchNumber)
        {
            Call* deleteNode = temp->next;

            temp->next = deleteNode->next;

            delete deleteNode;

            cout << "Call Deleted Successfully!\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Call Not Found.\n";
}


int main()
{
    int choice;

    do
    {
        cout << "\n===== CALL LOG MANAGEMENT =====\n";
        cout << "1. Add Call\n";
        cout << "2. Display Calls\n";
        cout << "3. Search Call\n";
        cout << "4. Delete Call\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addCall();
        }
        else if (choice == 2)
        {
            displayCalls();
        }
        else if (choice == 3)
        {
            searchCall();
        }
        else if (choice == 4)
        {
            deleteCall();
        }
        else if (choice == 5)
        {
            cout << "Program Ended.\n";
        }
        else
        {
            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}

