#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;

class ParkingSystem
{
private:
    int capacity;
    string parking[100];
    queue<string> waitingQueue;

public:
    ParkingSystem(int cap)
    {
        capacity = cap;
        for (int i = 0; i < capacity; i++)
        {
            parking[i] = "";
        }
    }

    void header()
    {
        cout << "=====================================\n";
        cout << "     PARKING MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
    }

    void parkVehicle()
    {
        string vehicleNo;
        system("cls");
        header();

        cout << "           PARK VEHICLE\n";
        cout << "-------------------------------------\n";
        cout << "Enter Vehicle Number (e.g., PB10AB1234): ";
        cin >> vehicleNo;

        for (int i = 0; i < capacity; i++)
        {
            if (parking[i] == "")
            {
                parking[i] = vehicleNo;
                cout << "\n Vehicle parked at Slot " << i + 1 << endl;
                Sleep(1000);
                return;
            }
        }

        cout << "\n Parking Full!\n";
        cout << " Vehicle added to waiting queue\n";
        waitingQueue.push(vehicleNo);
        Sleep(1000);
    }

    void removeVehicle()
    {
        string vehicleNo;
        system("cls");
        header();

        cout << "          REMOVE VEHICLE\n";
        cout << "-------------------------------------\n";
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNo;

        for (int i = 0; i < capacity; i++)
        {
            if (parking[i] == vehicleNo)
            {
                parking[i] = "";
                cout << "\n Vehicle removed from Slot " << i + 1 << endl;

                if (!waitingQueue.empty())
                {
                    string next = waitingQueue.front();
                    waitingQueue.pop();
                    parking[i] = next;
                    cout << " Vehicle " << next << " moved from queue to Slot " << i + 1 << endl;
                }

                Sleep(1000);
                return;
            }
        }

        cout << "\n Vehicle not found!\n";
        Sleep(1000);
    }

    void displayStatus()
    {
        system("cls");
        header();

        cout << "          PARKING STATUS\n";
        cout << "-------------------------------------\n";

        int occupied = 0;

        for (int i = 0; i < capacity; i++) {
            if (parking[i] == "")
            {
                cout << "Slot " << i + 1 << " : Empty\n";
            } else
            {
                cout << "Slot " << i + 1 << " : Vehicle " << parking[i] << endl;
                occupied++;
            }
        }

        cout << "-------------------------------------\n";
        cout << "Available Slots: " << capacity - occupied << endl;
        cout << "Occupied Slots : " << occupied << endl;

        Sleep(1500);
    }

    void showQueue()
    {
        system("cls");
        header();

        cout << "          WAITING QUEUE\n";
        cout << "-------------------------------------\n";

        if (waitingQueue.empty())
        {
            cout << "No vehicles in waiting queue\n";
        } else
        {
            queue<string> temp = waitingQueue;
            while (!temp.empty())
            {
                cout << temp.front() << endl;
                temp.pop();
            }
        }

        Sleep(1500);
    }
};

int main()
{
    int capacity, choice;

    system("color 0A");

    cout << "Enter Parking Capacity: ";
    cin >> capacity;

    ParkingSystem ps(capacity);

    do
    {
        system("cls");
        ps.header();

        cout << "1. Park Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Parking Status\n";
        cout << "4. View Waiting Queue\n";
        cout << "5. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                ps.parkVehicle();
                break;
            case 2:
                ps.removeVehicle();
                break;
            case 3:
                ps.displayStatus();
                break;
            case 4:
                ps.showQueue();
                break;
            case 5:
                system("cls");
                cout << "=====================================\n";
                cout << "   Thank You for Using the System\n";
                cout << "=====================================\n";
                break;
            default:
                cout << "Invalid choice!\n";
                Sleep(1000);
        }

    } while (choice != 5);

    return 0;
}