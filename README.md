# 🏨 Galaxy Hotel Management System

A comprehensive **Hotel Management System** implemented in C++. This project demonstrates the practical application of core Data Structures—**Stacks, Queues, and Linked Lists**—to manage hotel operations, booking histories, and customer queues efficiently.

## 🚀 Features

* **Booking History (Stack - LIFO):**
    * Stores completed bookings.
    * Allows "Undo" operations (removing the most recent booking).
    * Supports searching booking history by Customer Name.
* **Hotel Infrastructure (Nested Linked Lists):**
    * **Dynamic Structure:** Floors are nodes in a linked list.
    * **Room Management:** Each Floor node contains a separate Linked List of Rooms.
    * Supports adding/removing floors and rooms dynamically without fixed array sizes.
* **Reservation System (Queue - FIFO):**
    * **Regular Queue:** Standard First-In-First-Out processing for normal bookings.
    * **VIP Queue:** Priority processing for VIP guests.
    * **Batch Processing:** Capability to process regular bookings in batches of 10.
    * **Wait Time Calculation:** Estimates wait times based on queue size.

## 🛠️ Data Structures Used

This project maps real-world hotel entities to specific data structures:

| Feature | Data Structure | Reason for Choice |
| :--- | :--- | :--- |
| **Booking History** | `Stack` | To easily access the most recent booking (LIFO). |
| **Floors** | `Linked List` | To dynamically add/remove floors (Infinite vertical expansion). |
| **Rooms** | `Linked List` | To dynamically add/remove rooms per floor. |
| **Reservations** | `Queue` | To serve customers fairly in the order they arrived (FIFO). |

## 📂 Project Structure

The system is contained within a single source file but manages three distinct modules:

1.  **BookingStack**: Handles historical data.
2.  **HotelStructure**: Handles the physical layout (Floors/Rooms).
3.  **BookingQueue**: Handles incoming requests (VIP/Regular).

## 💻 How to Run

### 1. Compile
Run the following command in your terminal to build the project:

```bash
g++ main.cpp -o Hotel-Management-System
```

### 2. Run
Execute the compiled program
```bash
Hotel-Management-System.cpp
```

### 3. Input
The main menu will appear. Enter the number corresponding to the module you want to access.
```text
Galaxy Hotel Management System
=============================
1. Booking History Management
2. Hotel Structure Management
3. Booking Queue Management
4. Exit
Enter your choice:
```

## 📝 Example Usage

#### Scenario: Adding a Room
Menu Path: 2. Hotel Structure -> 4. Add Room
```text
Enter floor number: 1
Enter room ID: 101
Enter room status: Available
Enter room type: Deluxe
Room added successfully!
```

#### Scenario: Adding a VIP Booking Request
Menu Path: 3. Booking Queue -> 1. Add Booking Request
```text
Enter Name: John Doe
Enter Room Type: Suite
Enter Number of Nights: 3
Enter Date of Request (DD/MM/YYYY): 12/12/2024
Is this a VIP booking? (1 for Yes, 0 for No): 1
Enter VIP priority (1-10): 10
Booking Request Added Successfully!
```

#### Scenario: Viewing History
Menu Path: 1. Booking History -> 3. Display all customers
```text
--------------------------------
Customer Name: Alice Smith
Room Type: Single
Room Number: 102
Number of Nights: 2
Booking Date: 10/12/2024
Status: A
--------------------------------
```

## ⚠️ Requirements
* **C++ Compiler** (GCC, MinGW, Clang, or MSVC).
* **Standard Library** (No external downloads required).
