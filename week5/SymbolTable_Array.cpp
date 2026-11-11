#include <iostream>
#include <string>
using namespace std;

const int MAX_SYMBOLS = 100;

struct Symbol {
    string name;
    string type;
    string value;
};

class SymbolTable {
private:
    Symbol symbols[MAX_SYMBOLS];
    int count;

    // Return the index of a symbol, or -1 if not found.
    int findIndex(const string& name) const {
        for (int i = 0; i < count; i++) {
            if (symbols[i].name == name) {
                return i;
            }
        }
        return -1;
    }

public:
    SymbolTable() : count(0) {}

    // Insert a symbol, or update it if the name already exists.
    void insert(const string& name, const string& type, const string& value) {
        int index = findIndex(name);

        if (index != -1) {
            symbols[index].type = type;
            symbols[index].value = value;
            return;
        }

        if (count == MAX_SYMBOLS) {
            cout << "Symbol Table is full.\n";
            return;
        }

        symbols[count].name = name;
        symbols[count].type = type;
        symbols[count].value = value;
        count++;
    }

    // Return a pointer to the symbol, or nullptr if not found.
    const Symbol* search(const string& name) const {
        int index = findIndex(name);

        if (index == -1) {
            return nullptr;
        }

        return &symbols[index];
    }

    // Delete a symbol by shifting following elements to the left.
    bool remove(const string& name) {
        int index = findIndex(name);

        if (index == -1) {
            return false;
        }

        for (int i = index; i < count - 1; i++) {
            symbols[i] = symbols[i + 1];
        }

        count--;
        return true;
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            cout << symbols[i].name << " "
                 << symbols[i].type << " "
                 << symbols[i].value << '\n';
        }
    }
};
