#include <iostream>
#include <string>
using namespace std;

class BookingStack;
class HotelStructure;
class BookingQueue;

const int MAX_QUEUE_SIZE = 100;
const int BATCH_SIZE = 10;

class StackNode {
public:
    string CustomerName;
    string RoomType;
    string RoomNumber;
    int NumberOfNights;
    string BookingDate;
    char Status;
    StackNode* next;

    StackNode(string CustomerName, string RoomType, string RoomNumber, int NumberOfNights, string BookingDate, char Status) {
        this->CustomerName = CustomerName;
        this->RoomType = RoomType;
        this->RoomNumber = RoomNumber;
        this->NumberOfNights = NumberOfNights;
        this->BookingDate = BookingDate;
        this->Status = Status;
        next = nullptr;
    }
};

class BookingStack {
private:
    StackNode* top;

public:
    BookingStack() : top(nullptr) {}

    void push(string CustomerName, string RoomType, string RoomNumber, int NumberOfNights, string BookingDate, char Status);
    void pop();
    void peek();
    void display();
    bool isEmpty();
    int Count();
    void FindByName(string CustomerName);
};


class RoomNode {
public:
    int RoomID;
    string RoomStatus, RoomType;
    RoomNode* next;
    
    RoomNode(int Id, string status, string type) {
        RoomID = Id;
        RoomStatus = status;
        RoomType = type;
        next = nullptr;
    }
};

class RoomList {
private:
    RoomNode* head;
public:
    RoomList() : head(nullptr) {}
    
    void AddRoom(int Id, string status, string type);
    void RemoveRoom(int Id);
    void DisplayRooms();
    void UpdateRoomStatus(int Id, string status);
    void UpdateRoomType(int Id, string type);
    void SearchRoomInfo(int Id);
};

class FloorNode {
public:
    int FloorNumber;
    RoomList roomList;
    FloorNode* next;
    
    FloorNode(int number) {
        FloorNumber = number;
        next = nullptr;
    }
};

class HotelStructure {
private:
    FloorNode* head;
public:
    HotelStructure() : head(nullptr) {}
    
    void AddFloor(int FloorNumber);
    void RemoveFloor(int number);
    void DisplayFloors();
    void AddRoomToFloor(int floorNumber, int roomId, string status, string type);
    void RemoveRoomFromFloor(int floorNumber, int roomId);
    void DisplayRoomsInFloor(int floorNumber);
    void UpdateRoomStatusInFloor(int floorNumber, int roomId, string status);
    void UpdateRoomTypeInFloor(int floorNumber, int roomId, string type);
    void SearchRoomInfoInFloor(int floorNumber, int roomId);
};


class QueueNode {
public:
    string name;
    string roomType;
    int NumberOfNights;
    string DateOfRequest;            
    int priority;
    QueueNode* next;
    
    QueueNode(string name, string roomType, int NumberOfNights, string DateOfRequest, int priority) {
        this->name = name;
        this->roomType = roomType;
        this->NumberOfNights = NumberOfNights;
        this->DateOfRequest = DateOfRequest;
        this->priority = priority;
        next = nullptr;
    }
};

class BookingQueue {
private:
    QueueNode* head;
public:
    BookingQueue() : head(nullptr) {}
    
    void enqueue(string name, string roomType, int NumberOfNights, string DateOfRequest, int priority);
    void dequeue();
    bool isEmpty();
    int QueueSize();
    void DisplayQueueStatus();
    void CancelBookingRequest(string name);
};


int main() {
    BookingStack bookingHistory;
    HotelStructure hotel;
    BookingQueue regularQueue;
    BookingQueue vipQueue;
    
    char mainChoice;
    do {
        cout << "\nGalaxy Hotel Management System" << endl;
        cout << "=============================" << endl;
        cout << "1. Booking History Management" << endl;
        cout << "2. Hotel Structure Management" << endl;
        cout << "3. Booking Queue Management" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;
        
        switch(mainChoice) {
            case '1': {
                int choice;
                cout << "\nBooking History Management" << endl;
                cout << "1. Add a new customer" << endl;
                cout << "2. Remove a customer" << endl;
                cout << "3. Display all customers" << endl;
                cout << "4. Peek at the top customer" << endl;
                cout << "5. Check if history is empty" << endl;
                cout << "6. Count customers" << endl;
                cout << "7. Find a customer" << endl;
                cout << "0. Back to main menu" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                cin.ignore();
                
                switch(choice) {
                    case 1: {
                        string CustomerName, RoomType, RoomNumber, BookingDate;
                        int NumberOfNights;
                        char Status;
                        
                        cout << "Enter Customer Name: ";
                        getline(cin, CustomerName);
                        cout << "Enter Room Type: ";
                        getline(cin, RoomType);
                        cout << "Enter Room Number: ";
                        getline(cin, RoomNumber);
                        cout << "Enter Number of Nights: ";
                        cin >> NumberOfNights;
                        cin.ignore();
                        cout << "Enter Booking Date (DD/MM/YYYY): ";
                        getline(cin, BookingDate);
                        cout << "Enter Status (A for Active, I for Inactive): ";
                        cin >> Status;
                        
                        bookingHistory.push(CustomerName, RoomType, RoomNumber, NumberOfNights, BookingDate, Status);
                        break;
                    }
                    case 2:
                        bookingHistory.pop();
                        break;
                    case 3:
                        bookingHistory.display();
                        break;
                    case 4:
                        bookingHistory.peek();
                        break;
                    case 5:
                        if (bookingHistory.isEmpty())
                            cout << "The history is empty." << endl;
                        else
                            cout << "The history is not empty." << endl;
                        break;
                    case 6:
                        cout << "Number of customers in history: " << bookingHistory.Count() << endl;
                        break;
                    case 7: {
                        string CustomerName;
                        cout << "Enter Customer Name to find: ";
                        cin.ignore();
                        getline(cin, CustomerName);
                        bookingHistory.FindByName(CustomerName);
                        break;
                    }
                }
                break;
            }
            case '2': {
                int choice;
                cout << "\nHotel Structure Management" << endl;
                cout << "1. Add Floor" << endl;
                cout << "2. Remove Floor" << endl;
                cout << "3. Display Floors" << endl;
                cout << "4. Add Room to Floor" << endl;
                cout << "5. Remove Room from Floor" << endl;
                cout << "6. Display Rooms in Floor" << endl;
                cout << "7. Update Room Status" << endl;
                cout << "8. Update Room Type" << endl;
                cout << "9. Search Room Info" << endl;
                cout << "0. Back to main menu" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1: {
                        int floorNumber;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        hotel.AddFloor(floorNumber);
                        break;
                    }
                    case 2: {
                        int floorNumber;
                        cout << "Enter floor number to remove: ";
                        cin >> floorNumber;
                        hotel.RemoveFloor(floorNumber);
                        break;
                    }
                    case 3:
                        hotel.DisplayFloors();
                        break;
                    case 4: {
                        int floorNumber, roomId;
                        string status, type;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        cout << "Enter room ID: ";
                        cin >> roomId;
                        cin.ignore();
                        cout << "Enter room status: ";
                        getline(cin, status);
                        cout << "Enter room type: ";
                        getline(cin, type);
                        hotel.AddRoomToFloor(floorNumber, roomId, status, type);
                        break;
                    }
                    case 5: {
                        int floorNumber, roomId;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        cout << "Enter room ID to remove: ";
                        cin >> roomId;
                        hotel.RemoveRoomFromFloor(floorNumber, roomId);
                        break;
                    }
                    case 6: {
                        int floorNumber;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        hotel.DisplayRoomsInFloor(floorNumber);
                        break;
                    }
                    case 7: {
                        int floorNumber, roomId;
                        string status;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        cout << "Enter room ID: ";
                        cin >> roomId;
                        cin.ignore();
                        cout << "Enter new status: ";
                        getline(cin, status);
                        hotel.UpdateRoomStatusInFloor(floorNumber, roomId, status);
                        break;
                    }
                    case 8: {
                        int floorNumber, roomId;
                        string type;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        cout << "Enter room ID: ";
                        cin >> roomId;
                        cin.ignore();
                        cout << "Enter new type: ";
                        getline(cin, type);
                        hotel.UpdateRoomTypeInFloor(floorNumber, roomId, type);
                        break;
                    }
                    case 9: {
                        int floorNumber, roomId;
                        cout << "Enter floor number: ";
                        cin >> floorNumber;
                        cout << "Enter room ID: ";
                        cin >> roomId;
                        hotel.SearchRoomInfoInFloor(floorNumber, roomId);
                        break;
                    }
                }
                break;
            }
            case '3': {
                char choice;
                cout << "\nBooking Queue Management" << endl;
                cout << "1. Add Booking Request" << endl;
                cout << "2. Process Booking Request" << endl;
                cout << "3. Display Queue Status" << endl;
                cout << "4. Check Queue Empty" << endl;
                cout << "5. Expected Wait Time" << endl;
                cout << "6. Cancel Booking Request" << endl;
                cout << "0. Back to main menu" << endl;
                cout << "Enter choice: ";
                cin >> choice;
                
                switch(choice) {
                    case '1': {
                        string name, roomType, dateRequest;
                        int nights, priority;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Room Type: ";
                        getline(cin, roomType);
                        cout << "Enter Number of Nights: ";
                        cin >> nights;
                        cin.ignore();
                        cout << "Enter Date of Request (DD/MM/YYYY): ";
                        getline(cin, dateRequest);
                        cout << "Is this a VIP booking? (1 for Yes, 0 for No): ";
                        int isVIP;
                        cin >> isVIP;
                        
                        if (isVIP) {
                            cout << "Enter VIP priority (1-10): ";
                            cin >> priority;
                            vipQueue.enqueue(name, roomType, nights, dateRequest, priority);
                        } else {
                            regularQueue.enqueue(name, roomType, nights, dateRequest, 0);
                        }
                        break;
                    }
                    case '2':
                        if (!vipQueue.isEmpty()) {
                            cout << "Processing VIP booking request..." << endl;
                            vipQueue.dequeue();
                        } else if (!regularQueue.isEmpty() && regularQueue.QueueSize() >= 10) {
                            cout << "Processing regular booking batch..." << endl;
                            for (int i = 0; i < 10 && !regularQueue.isEmpty(); i++) {
                                regularQueue.dequeue();
                            }
                        } else {
                            cout << "No requests to process (VIP queue empty and regular queue < 10)" << endl;
                        }
                        break;
                    case '3':
                        cout << "\nVIP Queue Status:" << endl;
                        vipQueue.DisplayQueueStatus();
                        cout << "\nRegular Queue Status:" << endl;
                        regularQueue.DisplayQueueStatus();
                        break;
                    case '4':
                        cout << "VIP Queue: " << (vipQueue.isEmpty() ? "Empty" : "Not Empty") << endl;
                        cout << "Regular Queue: " << (regularQueue.isEmpty() ? "Empty" : "Not Empty") << endl;
                        break;
                    case '5': {
                        int vipWait = vipQueue.QueueSize() * 5;
                        int regWait = regularQueue.QueueSize() * 5;
                        cout << "Expected Wait Times:" << endl;
                        cout << "VIP Queue: " << vipWait << " minutes" << endl;
                        cout << "Regular Queue: " << (vipWait + regWait) << " minutes" << endl;
                        break;
                    }
                    case '6': {
                        string name;
                        cout << "Enter name to cancel booking: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Queue type (1 for VIP, 0 for Regular): ";
                        int isVIP;
                        cin >> isVIP;
                        if (isVIP)
                            vipQueue.CancelBookingRequest(name);
                        else
                            regularQueue.CancelBookingRequest(name);
                        break;
                    }
                }
                break;
            }
            case '4':
                cout << "Thank you for using Galaxy Hotel Management System!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(mainChoice != '4');
    
    return 0;
}


void BookingStack::push(string CustomerName, string RoomType, string RoomNumber, int NumberOfNights, string BookingDate, char Status) {
    StackNode* newNode = new StackNode(CustomerName, RoomType, RoomNumber, NumberOfNights, BookingDate, Status);
    newNode->next = top;
    top = newNode;
    cout << "Customer added successfully!" << endl;
}

void BookingStack::pop() {
    if (top == nullptr) {
        cout << "No Booking Event Found! Cannot Remove Customer." << endl;
        return;
    }
    StackNode* temp = top;
    top = top->next;
    delete temp;
    cout << "Customer removed successfully!" << endl;
}

void BookingStack::peek() {
    if (top == nullptr) {
        cout << "No Booking Event Found!" << endl;
        return;
    }
    cout << "Customer Name: " << top->CustomerName << endl;
    cout << "Room Type: " << top->RoomType << endl;
    cout << "Room Number: " << top->RoomNumber << endl;
    cout << "Number of Nights: " << top->NumberOfNights << endl;
    cout << "Booking Date: " << top->BookingDate << endl;
    cout << "Status: " << top->Status << endl;
}

void BookingStack::display() {
    if (top == nullptr) {
        cout << "No Booking Event Found!" << endl;
        return;
    }
    StackNode* temp = top;
    while (temp != nullptr) {
        cout << "\n--------------------------------" << endl;
        cout << "Customer Name: " << temp->CustomerName << endl;
        cout << "Room Type: " << temp->RoomType << endl;
        cout << "Room Number: " << temp->RoomNumber << endl;
        cout << "Number of Nights: " << temp->NumberOfNights << endl;
        cout << "Booking Date: " << temp->BookingDate << endl;
        cout << "Status: " << temp->Status << endl;
        cout << "--------------------------------" << endl;
        temp = temp->next;
    }
}

bool BookingStack::isEmpty() {
    return top == nullptr;
}

int BookingStack::Count() {
    int count = 0;
    StackNode* temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void BookingStack::FindByName(string CustomerName) {
    StackNode* temp = top;
    while (temp != nullptr) {
        if (temp->CustomerName == CustomerName) {
            cout << "Customer Found!" << endl;
            cout << "Customer Name: " << temp->CustomerName << endl;
            cout << "Room Type: " << temp->RoomType << endl;
            cout << "Room Number: " << temp->RoomNumber << endl;
            cout << "Number of Nights: " << temp->NumberOfNights << endl;
            cout << "Booking Date: " << temp->BookingDate << endl;
            cout << "Status: " << temp->Status << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Customer Not Found!" << endl;
}

// RoomList Implementation
void RoomList::AddRoom(int Id, string status, string type) {
    RoomNode* newNode = new RoomNode(Id, status, type);
    if (head == nullptr) {
        head = newNode;
    } else {
        RoomNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Room added successfully!" << endl;
}

void RoomList::RemoveRoom(int Id) {
    if (head == nullptr) return;
    if (head->RoomID == Id) {
        RoomNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Room removed successfully!" << endl;
        return;
    }
    RoomNode* current = head;
    while (current->next != nullptr && current->next->RoomID != Id) {
        current = current->next;
    }
    if (current->next != nullptr) {
        RoomNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Room removed successfully!" << endl;
    }
}

void RoomList::DisplayRooms() {
    if (head == nullptr) {
        cout << "No rooms found!" << endl;
        return;
    }
    RoomNode* temp = head;
    while (temp != nullptr) {
        cout << "\n--------------------------------" << endl;
        cout << "Room ID: " << temp->RoomID << endl;
        cout << "Status: " << temp->RoomStatus << endl;
        cout << "Type: " << temp->RoomType << endl;
        cout << "--------------------------------" << endl;
        temp = temp->next;
    }
}

void RoomList::UpdateRoomStatus(int Id, string status) {
    RoomNode* temp = head;
    while (temp != nullptr) {
        if (temp->RoomID == Id) {
            temp->RoomStatus = status;
            cout << "Room status updated successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Room not found!" << endl;
}

void RoomList::UpdateRoomType(int Id, string type) {
    RoomNode* temp = head;
    while (temp != nullptr) {
        if (temp->RoomID == Id) {
            temp->RoomType = type;
            cout << "Room type updated successfully!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Room not found!" << endl;
}

void RoomList::SearchRoomInfo(int Id) {
    RoomNode* temp = head;
    while (temp != nullptr) {
        if (temp->RoomID == Id) {
            cout << "\n--------------------------------" << endl;
            cout << "Room ID: " << temp->RoomID << endl;
            cout << "Status: " << temp->RoomStatus << endl;
            cout << "Type: " << temp->RoomType << endl;
            cout << "--------------------------------" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Room not found!" << endl;
}

// HotelStructure Implementation
void HotelStructure::AddFloor(int FloorNumber) {
    FloorNode* newNode = new FloorNode(FloorNumber);
    if (head == nullptr) {
        head = newNode;
    } else {
        FloorNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Floor added successfully!" << endl;
}

void HotelStructure::RemoveFloor(int number) {
    if (head == nullptr) return;
    if (head->FloorNumber == number) {
        FloorNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Floor removed successfully!" << endl;
        return;
    }
    FloorNode* current = head;
    while (current->next != nullptr && current->next->FloorNumber != number) {
        current = current->next;
    }
    if (current->next != nullptr) {
        FloorNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Floor removed successfully!" << endl;
    }
}

void HotelStructure::DisplayFloors() {
    if (head == nullptr) {
        cout << "No floors found!" << endl;
        return;
    }
    FloorNode* temp = head;
    while (temp != nullptr) {
        cout << "\n================================" << endl;
        cout << "Floor Number: " << temp->FloorNumber << endl;
        cout << "Rooms on this floor:" << endl;
        temp->roomList.DisplayRooms();
        cout << "================================" << endl;
        temp = temp->next;
    }
}

void HotelStructure::AddRoomToFloor(int floorNumber, int roomId, string status, string type) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            temp->roomList.AddRoom(roomId, status, type);
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

void HotelStructure::RemoveRoomFromFloor(int floorNumber, int roomId) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            temp->roomList.RemoveRoom(roomId);
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

void HotelStructure::DisplayRoomsInFloor(int floorNumber) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            cout << "\nRooms on Floor " << floorNumber << ":" << endl;
            temp->roomList.DisplayRooms();
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

void HotelStructure::UpdateRoomStatusInFloor(int floorNumber, int roomId, string status) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            temp->roomList.UpdateRoomStatus(roomId, status);
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

void HotelStructure::UpdateRoomTypeInFloor(int floorNumber, int roomId, string type) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            temp->roomList.UpdateRoomType(roomId, type);
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

void HotelStructure::SearchRoomInfoInFloor(int floorNumber, int roomId) {
    FloorNode* temp = head;
    while (temp != nullptr) {
        if (temp->FloorNumber == floorNumber) {
            temp->roomList.SearchRoomInfo(roomId);
            return;
        }
        temp = temp->next;
    }
    cout << "Floor not found!" << endl;
}

// BookingQueue Implementation
void BookingQueue::enqueue(string name, string roomType, int NumberOfNights, string DateOfRequest, int priority) {
    QueueNode* newNode = new QueueNode(name, roomType, NumberOfNights, DateOfRequest, priority);
    if (head == nullptr) {
        head = newNode;
    } else {
        QueueNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Booking Request Added Successfully!" << endl;
}

void BookingQueue::dequeue() {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }
    QueueNode* temp = head;
    head = head->next;
    delete temp;
    cout << "Booking Request Processed Successfully!" << endl;
}

bool BookingQueue::isEmpty() {
    return head == nullptr;
}

int BookingQueue::QueueSize() {
    int count = 0;
    QueueNode* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void BookingQueue::DisplayQueueStatus() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "\nQueue Status:" << endl;
    QueueNode* temp = head;
    while (temp != nullptr) {
        cout << "\n--------------------------------" << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Room Type: " << temp->roomType << endl;
        cout << "Number of Nights: " << temp->NumberOfNights << endl;
        cout << "Date of Request: " << temp->DateOfRequest << endl;
        cout << "Priority: " << temp->priority << endl;
        cout << "--------------------------------" << endl;
        temp = temp->next;
    }
}

void BookingQueue::CancelBookingRequest(string name) {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    if (head->name == name) {
        QueueNode* temp = head;
        head = head->next;
        delete temp;
        cout << "Booking Request Cancelled Successfully!" << endl;
        return;
    }
    
    QueueNode* current = head;
    QueueNode* prev = nullptr;
    
    while (current != nullptr && current->name != name) {
        prev = current;
        current = current->next;
    }
    
    if (current == nullptr) {
        cout << "Booking Request Not Found!" << endl;
        return;
    }
    
    prev->next = current->next;
    delete current;
    cout << "Booking Request Cancelled Successfully!" << endl;
} 