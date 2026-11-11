#include <iostream>
#include <string>
using namespace std;

struct Symbol {
    string name;
    string type;
    string value;
    Symbol* next;
};

class SymbolTable {
private:
    Symbol* head;

public:
    SymbolTable() : head(nullptr) {}

    ~SymbolTable() {
        while (head != nullptr) {
            Symbol* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert a symbol, or update it if the name already exists.
    void insert(const string& name, const string& type, const string& value) {
        Symbol* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                current->type = type;
                current->value = value;
                return;
            }
            current = current->next;
        }

        head = new Symbol{name, type, value, head};
    }

    // Return a pointer to the symbol, or nullptr if not found.
    Symbol* search(const string& name) const {
        Symbol* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    // Delete the symbol with the given name.
    bool remove(const string& name) {
        Symbol* current = head;
        Symbol* previous = nullptr;

        while (current != nullptr && current->name != name) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        if (previous == nullptr) {
            head = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    void display() const {
        Symbol* current = head;

        while (current != nullptr) {
            cout << current->name << " "
                 << current->type << " "
                 << current->value << '\n';
            current = current->next;
        }
    }
};
