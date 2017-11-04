#include <iostream>
#include <string.h>

using namespace std;

struct Car {
    char* make;
    int license_number;
    int owner_id;
    int price;
    Car* next;
};

Car* head = NULL;

void add_car(char* make, int number, int id, int price) {
    char* nmake = new char[strlen(make) + 1];
    strcpy(nmake, make);

    Car* ncar = new Car;
    *ncar = {nmake, number, id, price, NULL};

	// Check for repetitive adding
	Car* it = head;
	while(it) {
		if(strcmp(it->make, make) == 0 && it->license_number == number && it->owner_id == id && it->price == price) {
			cout << "item: " << make << " already exists. You cannot add the same item" << endl;
			delete [] nmake;
			delete ncar;
			return;
		}
		it = it->next;
	}

    if(!head) {
        head = ncar;
        head->next = NULL;

        return;
    }

    Car* iter = head;
    while(iter->next) {
        iter = iter->next;
    }

    iter->next = ncar;
}

void remove_make(char* make) {
    if(!head) {
        cout << "unable to remove element: list is empty" << endl;
        return;
    }

    repetitive:
    Car* iter = head;
    if(strcmp(head->make, make) == 0) { // in case of trying to remove the first element
        head = iter->next;
        delete [] iter->make;
        delete iter;
        cout << make << " removed from the list" << endl;
        goto repetitive;
    }

    while(iter->next) {
        if(strcmp(iter->next->make, make) == 0) {
            Car* temp = iter->next; // temporary pointer for element to be removed
            iter->next = temp->next;
            delete [] temp->make;
            delete temp;
            cout << make << " removed from the list" << endl;
            goto repetitive;
        }
        iter = iter->next;
    }

    cout << "unable to find such a make like: " << make << endl;
}

// 
int& change(char* make, int number, int id) {
    // If the car with this number exists, it returns reference to price
    // if there is no such a car -> create a new car and insert to the list but only if the owner has before no more than two cars
    // return the reference to price of the created car, a default price is 100  
}

void print() {
    if(!head) {
        cout << "unable to print the elements: list is empty" << endl;
        return;
    }

    Car* iter = head;
    while(iter) {
        cout << iter->make << ", " << iter->license_number << ", " << iter->owner_id << ", " << iter->price;
        iter = iter->next;
        cout << "\n";
    }

    cout << endl;
}

int main() {
    print();

    remove_make("FIAT");

    add_car("FIAT", 0, 0, 10);
    add_car("FIAT", 0, 0, 10);
    add_car("VOLVO", 1, 1, 15);
    add_car("RENAULT", 2, 2, 12);
    add_car("BMW", 3, 3, 21);
    add_car("MERCEDES", 4, 4, 35);
    add_car("FIAT", 0, 0, 10);
    add_car("PORSCHE", 5, 5, 99);
    add_car("PORSCHE", 6, 5, 97);
    add_car("FIAT", 0, 0, 10);
    add_car("FIAT", 7, 0, 10);

    print();

    remove_make("FIAT");

    print();

    remove_make("BMW");

    print();

    remove_make("PQR");

    print();

    remove_make("PORSCHE");

    print();

	add_car("VOLVO", 7, 1, 58);

	print();

	remove_make("RENAULT");

	print();

	remove_make("MERCEDES");

	print();

    return 0;
}
// What was to be demonstrated