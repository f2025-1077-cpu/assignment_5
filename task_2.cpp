#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// STRUCTURE
struct OrderInfo {
    string id;
    string customer;
    int items;
    double unitPrice;
};

// VECTOR TO STORE ORDERS
vector<OrderInfo> orderList;

// FUNCTION TO CHECK IF ORDER IS HIGH VALUE
bool isPriorityOrder(OrderInfo o){
    double total = o.items * o.unitPrice;
    if(total > 5000)
        return true;
    else
        return false;
}

// FUNCTION TO WRITE PRIORITY ORDERS TO FILE
void writePriorityFile(){
    ofstream outFile("priority_orders.txt");

    if(outFile.fail()){
        cout << "Error opening priority file" << endl;
        return;
    }

    outFile << setw(12) << left << "OrderID"
            << setw(18) << left << "Customer"
            << setw(10) << left << "Items"
            << setw(12) << left << "Price"
            << "Total" << endl;

    for(int i = 0; i < orderList.size(); i++){
        if(isPriorityOrder(orderList[i])){
            double bill = orderList[i].items * orderList[i].unitPrice;

            outFile << setw(12) << left << orderList[i].id;
            outFile << setw(18) << left << orderList[i].customer;
            outFile << setw(10) << left << orderList[i].items;
            outFile << setw(12) << left << orderList[i].unitPrice;
            outFile << bill << endl;
        }
    }

    outFile.close();
}

// FUNCTION TO DISPLAY FILE DATA
void showPriorityOrders(){
    ifstream inFile("priority_orders.txt");

    if(!inFile){
        cout << "Unable to read priority file" << endl;
        return;
    }

    string line;
    cout << "\n---- Priority Orders ----\n";
    while(getline(inFile, line)){
        cout << line << endl;
    }

    inFile.close();
}

int main(){

    int totalOrders;
    cout << "Enter total orders: ";
    cin >> totalOrders;

    for(int i = 0; i < totalOrders; i++){
        OrderInfo temp;

        cout << "\nOrder " << i+1 << " ID: ";
        cin >> temp.id;

        cout << "Customer Name: ";
        cin >> temp.customer;

        while(true){
            cout << "Number of items: ";
            cin >> temp.items;
            if(temp.items > 0) break;
            cout << "Invalid items! Enter again.\n";
        }

        while(true){
            cout << "Price per item: ";
            cin >> temp.unitPrice;
            if(temp.unitPrice > 0) break;
            cout << "Invalid price! Enter again.\n";
        }

        orderList.push_back(temp);
    }

    writePriorityFile();
    showPriorityOrders();

    return 0;
}
