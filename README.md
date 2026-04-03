# Parking Management System

## Description
This C++ program implements a simple Parking Management System that allows users to park vehicles, remove vehicles, view the parking status, and manage a waiting queue when the parking is full. It uses a console-based interface and is designed for Windows systems.

## Features
- **Park Vehicle**: Add a vehicle to an available parking slot or to the waiting queue if full.
- **Remove Vehicle**: Remove a vehicle from a slot and automatically assign the next vehicle from the waiting queue if available.
- **Display Parking Status**: Show the current status of all parking slots, including occupied and available slots.
- **View Waiting Queue**: Display the list of vehicles waiting for a parking slot.

## Requirements
- C++ compiler (e.g., g++, Visual Studio)
- Windows operating system (uses Windows-specific functions like `system("cls")` and `Sleep()`)

## How to Compile and Run
1. Ensure you have a C++ compiler installed.
2. Compile the program using the following command:
   ```
   g++ ravi.cpp -o parking_system
   ```
   Or in Visual Studio, create a new project and add the file.

3. Run the executable:
   ```
   ./parking_system
   ```

4. Follow the on-screen menu to interact with the system.

## Usage
- Enter the parking capacity when prompted.
- Choose options from the menu:
  - 1: Park a vehicle (enter vehicle number like PB10AB1234)
  - 2: Remove a vehicle (enter vehicle number)
  - 3: View parking status
  - 4: View waiting queue
  - 5: Exit

## Notes
- Vehicle numbers are stored as strings.
- The system clears the screen and uses delays for better user experience.
- Maximum capacity is set to 100 slots internally, but can be adjusted in the code.