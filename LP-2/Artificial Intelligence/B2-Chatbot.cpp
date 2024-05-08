#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    string description;
    double price;
};

void displayProductList(const vector<Product>& products) {
    cout << "Here are our products:\n";
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". " << products[i].name << endl;
    }
}

void getProductInfo(const vector<Product>& products, int selection) {
    if (selection >= 1 && selection <= static_cast<int>(products.size())) {
        const Product& product = products[selection - 1];
        cout << "Product: " << product.name << endl;
        cout << "Description: " << product.description << endl;
        cout << "Price: $" << product.price << endl;
    } else {
        cout << "Invalid selection!\n";
    }
}

int main() {
    cout << "Welcome! How can I assist you today?\n";

    // Sample product data
    vector<Product> products = {
        {"Product 1", "Description of Product 1", 19.99},
        {"Product 2", "Description of Product 2", 29.99},
        {"Product 3", "Description of Product 3", 39.99}
    };

    int selectedProduct = -1;

    while (true) {
        string userInput;
        cout << "\nCustomer: ";
        getline(cin, userInput);

        if (userInput.find("product") != string::npos) {
            displayProductList(products);
        } else if (userInput.find("select") != string::npos) {
            int selection;
            cout << "Enter the number of the product you want more information about: ";
            cin >> selection;
            cin.ignore();
            getProductInfo(products, selection);
            selectedProduct = selection - 1; // Remember the selected product
        } else if (userInput.find("price") != string::npos) {
            if (selectedProduct != -1) {
                cout << "The price of the selected product is: $" << products[selectedProduct].price << endl;
            } else {
                cout << "Please select a product first!\n";
            }
        } else {
            cout << "I'm sorry, I didn't understand that. How can I assist you?\n";
        }
    }

    return 0;
}
