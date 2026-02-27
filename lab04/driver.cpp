// TO DO: Implement the driver main() function to test your code.
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {

    cout << "===== TESTING INT LIST =====\n\n";

    LinkedList<int> intList;

    // Test empty list
    cout << "Initial empty list:\n" << intList;
    cout << "Is empty? " << (intList.isEmpty() ? "Yes" : "No") << "\n\n";

    // Append elements
    intList.append(10);
    intList.append(20);
    intList.append(30);
    cout << "After appending 10, 20, 30:\n" << intList;
    cout << "Length: " << intList.getLength() << "\n\n";

    // Replace at first, middle, last
    try {
        intList.replace(0, 99);
        cout << "After replacing first element with 99:\n" << intList;
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    try {
        intList.replace(1, 55);
        cout << "After replacing middle element with 55:\n" << intList;
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    try {
        intList.replace(intList.getLength() - 1, 77);
        cout << "After replacing last element with 77:\n" << intList << "\n\n";
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    // Get elements safely including out-of-bounds
    for (int i = 0; i < intList.getLength() + 2; i++) {
        try {
            cout << "Element at position " << i << ": " << intList.getElement(i) << endl;
        } catch (const string& e) {
            cout << "Caught exception: " << e << endl;
        }
    }
    cout << endl;

    // Remove elements at first, middle, last
    try {
        intList.remove(0);
        cout << "After removing first element:\n" << intList;
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    try {
        if (intList.getLength() > 1)
            intList.remove(1); // middle index
        cout << "After removing middle element:\n" << intList;
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    try {
        intList.remove(intList.getLength() - 1);
        cout << "After removing last element:\n" << intList << "\n\n";
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    // Clear list
    intList.clear();
    cout << "After clearing list:\n" << intList;
    cout << "Is empty? " << (intList.isEmpty() ? "Yes" : "No") << "\n\n";

    cout << "===== TESTING STRING LIST =====\n\n";

    LinkedList<string> stringList;

    // Append strings
    stringList.append("Apple");
    stringList.append("Banana");
    stringList.append("Cherry");
    cout << "Initial string list:\n" << stringList;

    // Replace first, middle, last
    try {
        stringList.replace(0, "Apricot");
        cout << "After replacing first element:\n" << stringList;
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    try {
        stringList.replace(1, "Blueberry");
        cout << "After replacing middle element:\n" << stringList;
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    try {
        stringList.replace(stringList.getLength() - 1, "Cantaloupe");
        cout << "After replacing last element:\n" << stringList << "\n\n";
    } catch (const string& e) {
        cout << "Replace exception: " << e << endl;
    }

    // Get elements including out-of-bounds
    for (int i = -1; i <= stringList.getLength(); i++) {
        try {
            cout << "Element at position " << i << ": " << stringList.getElement(i) << endl;
        } catch (const string& e) {
            cout << "Caught exception: " << e << endl;
        }
    }
    cout << endl;

    // Remove first, middle, last safely
    try {
        stringList.remove(0);
        cout << "After removing first element:\n" << stringList;
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    try {
        if (stringList.getLength() > 1)
            stringList.remove(1); // middle index
        cout << "After removing middle element:\n" << stringList;
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    try {
        if (!stringList.isEmpty())
            stringList.remove(stringList.getLength() - 1); // last
        cout << "After removing last element:\n" << stringList << "\n\n";
    } catch (const string& e) {
        cout << "Remove exception: " << e << endl;
    }

    // Clear string list
    stringList.clear();
    cout << "After clearing string list:\n" << stringList << endl;

    cout << "\n===== TESTING EXCEPTIONS =====\n\n";

    // Empty list exceptions
    try {
        stringList.getElement(0);
    } catch (const string& e) {
        cout << "Caught exception (getElement on empty list): " << e << endl;
    }

    try {
        stringList.replace(0, "Test");
    } catch (const string& e) {
        cout << "Caught exception (replace on empty list): " << e << endl;
    }

    try {
        stringList.remove(0);
    } catch (const string& e) {
        cout << "Caught exception (remove on empty list): " << e << endl;
    }

    return 0;
}