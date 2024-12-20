#include <bits/stdc++.h>
using namespace std;

class Item {
private:
    int itemID;
    string name;
    string category;
    int quantity;
    int reorderLevel;

public:
    Item(int id, const string& itemName, const string& itemCategory, int qty, int reorder)
        : itemID(id), name(itemName), category(itemCategory), quantity(qty), reorderLevel(reorder) {}

    int getItemID() const { return itemID; }
    string getName() const { return name; }
    string getCategory() const { return category; }
    int getQuantity() const { return quantity; }
    int getReorderLevel() const { return reorderLevel; }

    void updateQuantity(int qty) { quantity += qty; }

    bool needsReorder() const { return quantity < reorderLevel; }

    void display() const {
        cout << left << setw(10) << itemID
             << setw(20) << name
             << setw(15) << category
             << setw(10) << quantity
             << setw(15) << reorderLevel << endl;
    }

    string toCSV() const {
        return to_string(itemID) + "," + name + "," + category + "," + to_string(quantity) + "," + to_string(reorderLevel);
    }
};

class Inventory {
private:
    vector<Item> items;

public:
    void addItem(int id, const string& name, const string& category, int quantity, int reorderLevel) {
        items.emplace_back(id, name, category, quantity, reorderLevel);
    }

    void updateStock(int id, int qty) {
        for (auto& item : items) {
            if (item.getItemID() == id) {
                item.updateQuantity(qty);
                cout << "Stock updated successfully!\n";
                return;
            }
        }
        cout << "Item with ID " << id << " not found.\n";
    }

    void viewInventory() const {
        cout << left << setw(10) << "Item ID"
             << setw(20) << "Name"
             << setw(15) << "Category"
             << setw(10) << "Quantity"
             << setw(15) << "Reorder Level" << endl;
        cout << string(70, '-') << endl;
        for (const auto& item : items) {
            item.display();
        }
    }

    void searchByName(const string& name) const {
        bool found = false;
        for (const auto& item : items) {
            if (item.getName() == name) {
                item.display();
                found = true;
            }
        }
        if (!found) cout << "No items found with name: " << name << endl;
    }

    void searchByCategory(const string& category) const {
        bool found = false;
        for (const auto& item : items) {
            if (item.getCategory() == category) {
                item.display();
                found = true;
            }
        }
        if (!found) cout << "No items found in category: " << category << endl;
    }

    void generateReorderAlerts() const {
        cout << "Items needing reorder:\n";
        bool alert = false;
        for (const auto& item : items) {
            if (item.needsReorder()) {
                item.display();
                alert = true;
            }
        }
        if (!alert) cout << "All items are sufficiently stocked.\n";
    }

    void exportToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error opening file for writing.\n";
            return;
        }
        file << "Item ID,Name,Category,Quantity,Reorder Level\n";
        for (const auto& item : items) {
            file << item.toCSV() << endl;
        }
        file.close();
        cout << "Inventory exported to " << filename << " successfully.\n";
    }
};

void menu() {
    cout << "\nWarehouse Inventory Management System\n";
    cout << "1. Add New Item\n";
    cout << "2. Update Stock Levels\n";
    cout << "3. View Inventory\n";
    cout << "4. Search by Name\n";
    cout << "5. Search by Category\n";
    cout << "6. Generate Reorder Alerts\n";
    cout << "7. Export Inventory to File\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, qty, reorder;
                string name, category;
                cout << "Enter Item ID: "; cin >> id;
                cin.ignore();
                cout << "Enter Name: "; getline(cin, name);
                cout << "Enter Category: "; getline(cin, category);
                cout << "Enter Quantity: "; cin >> qty;
                cout << "Enter Reorder Level: "; cin >> reorder;
                inventory.addItem(id, name, category, qty, reorder);
                cout << "Item added successfully!\n";
                break;
            }
            case 2: {
                int id, qty;
                cout << "Enter Item ID: "; cin >> id;
                cout << "Enter Quantity to Add/Subtract: "; cin >> qty;
                inventory.updateStock(id, qty);
                break;
            }
            case 3:
                inventory.viewInventory();
                break;
            case 4: {
                string name;
                cin.ignore();
                cout << "Enter Name to Search: "; getline(cin, name);
                inventory.searchByName(name);
                break;
            }
            case 5: {
                string category;
                cin.ignore();
                cout << "Enter Category to Search: "; getline(cin, category);
                inventory.searchByCategory(category);
                break;
            }
            case 6:
                inventory.generateReorderAlerts();
                break;
            case 7: {
                string filename;
                cin.ignore();
                cout << "Enter filename to export: "; getline(cin, filename);
                inventory.exportToFile(filename);
                break;
            }
            case 8:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}