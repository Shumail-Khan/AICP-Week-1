#include <iostream>
#include <limits>
#include <cctype>
using namespace std;

const string item_codes[] = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2"};
const string item_descriptions[] = {"Compact Case", "Tower Case", "8GB RAM", "16GB RAM", "32GB RAM",
                                    "1TB HDD", "2TB HDD", "4TB HDD", "240GB SSD", "480GB SSD"};
const double item_prices[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99};

const double basic_components_price = 200.00; // Same For All Computers

int main() {
    // Task 01
	const string additional_item_codes[] = {"D1", "D2", "E1", "E2", "E3", "F1", "F2", "G1", "G2"};
    const string additional_item_descriptions[] = {
        "240GB SSD", "480GB SSD", "1TB HDD", "2TB HDD", "4TB HDD",
        "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"
    };
    const double additional_item_prices[] = {59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

    cout << "Welcome to the online computer shop!" << endl;
    cout << "Please choose one case, one RAM, and one Main Hard Disk Drive:" << endl;

    // Display item options
    for (int i = 0; i < 10; ++i) {
        cout << item_codes[i] << " - " << item_descriptions[i] << " - $" << item_prices[i] << endl;
    }

    // Get user input
    string case_choice, ram_choice, hdd_choice;

    while (true) {
        cout << "Enter the item code for the case (A1 or A2): ";
        cin >> case_choice;
        if (cin.fail() || (case_choice != "A1" && case_choice != "A2")) {
            cout << "Invalid input. Please enter a valid item code (A1 or A2) for the case." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter the item code for the RAM (B1, B2, or B3): ";
        cin >> ram_choice;
        if (cin.fail() || (ram_choice != "B1" && ram_choice != "B2" && ram_choice != "B3")) {
            cout << "Invalid input. Please enter a valid item code (B1, B2, or B3) for the RAM." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    while (true) {
        cout << "Enter the item code for the Main Hard Disk Drive (C1, C2, or C3): ";
        cin >> hdd_choice;
        if (cin.fail() || (hdd_choice != "C1" && hdd_choice != "C2" && hdd_choice != "C3")) {
            cout << "Invalid input. Please enter a valid item code (C1, C2, or C3) for the HDD." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    // Calculate the total price
    double total_price = basic_components_price;

    string chosen_case_description, chosen_ram_description, chosen_hdd_description;
    int chosen_case_index = -1, chosen_ram_index = -1, chosen_hdd_index = -1;

    for (int i = 0; i < 10; ++i) {
        if (case_choice == item_codes[i]) {
            chosen_case_index = i;
        }
        if (ram_choice == item_codes[i]) {
            chosen_ram_index = i;
        }
        if (hdd_choice == item_codes[i]) {
            chosen_hdd_index = i;
        }
    }

    if (chosen_case_index != -1) {
        total_price += item_prices[chosen_case_index];
        chosen_case_description = item_descriptions[chosen_case_index];
    }
    if (chosen_ram_index != -1) {
        total_price += item_prices[chosen_ram_index];
        chosen_ram_description = item_descriptions[chosen_ram_index];
    }
    if (chosen_hdd_index != -1) {
        total_price += item_prices[chosen_hdd_index];
        chosen_hdd_description = item_descriptions[chosen_hdd_index];
    }

    // Output the chosen items and the current total price
    cout << "\nChosen items:" << endl;
    if (chosen_case_index != -1) {
        cout << "Case: " << chosen_case_description << " - $" << item_prices[chosen_case_index] << endl;
    }
    if (chosen_ram_index != -1) {
        cout << "RAM: " << chosen_ram_description << " - $" << item_prices[chosen_ram_index] << endl;
    }
    if (chosen_hdd_index != -1) {
        cout << "Main Hard Disk Drive: " << chosen_hdd_description << " - $" << item_prices[chosen_hdd_index] << endl;
    }
    cout << "Current Total Price: $" << total_price << endl;

    // Task 02
	// Ask the customer if they want to purchase additional items
    char additional_items_choice;
    cout << "\nDo you want to purchase additional items from other categories? (Y/N): ";
    cin >> additional_items_choice;

    if (additional_items_choice == 'Y' || additional_items_choice == 'y') {
        cout << "Additional item options:" << endl;

        for (int j = 0; j < 9; ++j) {
            cout << additional_item_codes[j] << " - " << additional_item_descriptions[j] << " - $" << additional_item_prices[j] << endl;
        }

        string additional_item_code;
        double additional_items_price = 0.0;
        int num_additional_items = 0;
        
        while (true) {
            cout << "Enter the item code for the additional item (or 'Q' to quit): ";
            cin >> additional_item_code;

            if (additional_item_code == "Q" || additional_item_code == "q") {
                break;
            }

            bool valid_code = false;
            int t;
            for (t = 0; t < 9; ++t) {
                if (additional_item_code == additional_item_codes[t]) {
                    additional_items_price += additional_item_prices[t];
                    valid_code = true;
                    num_additional_items++;
                    break;
                }
            }

            if (valid_code) {
                cout << "Added: " << additional_item_descriptions[t] << " - $" << additional_item_prices[t] << endl;
            } else {
                cout << "Invalid item code. Please choose an additional item from the options." << endl;
            }
        }

        total_price += additional_items_price;

        // Task 03
		// Apply discounts based on the number of additional items
        double discount = 0.0;

        if (num_additional_items == 1) {
            discount = 0.05 * (total_price - basic_components_price);
        } else if (num_additional_items >= 2) {
            discount = 0.10 * (total_price - basic_components_price);
        }

        // Calculate the final discounted price
        double discounted_price = total_price - discount;

        cout << "\nFinal Total Price (Before discount): $" << total_price << endl;
        cout << "\nDiscount Amount: $" << discount << endl;
        cout << "Final Total Price (after discount): $" << discounted_price << endl;
    }

    return 0;
}

