#include "Cuboid.h"
class CuboidNode {
public:
    Cuboid data;
    CuboidNode* next;

    CuboidNode(const Cuboid& cuboid) : data(cuboid), next(nullptr) {}
};

class CuboidList {
private:
    CuboidNode* head;
    int size;

public:
    CuboidList() : head(nullptr), size(0) {}

    ~CuboidList() {
        clear();
    }

    void insertSorted(const Cuboid& cuboid) {
        CuboidNode* newNode = new CuboidNode(cuboid);

        if (!head || cuboid.calculateVolume() < head->data.calculateVolume()) {
            newNode->next = head;
            head = newNode;
        }
        else {
            CuboidNode* current = head;
            while (current->next && cuboid.calculateVolume() > current->next->data.calculateVolume()) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void display() const {
        CuboidNode* current = head;
        while (current) {
            cout << "Cuboid - Volume: " << current->data.calculateVolume() << "\n";
            current = current->next;
        }
    }

    bool search(const Cuboid& cuboid) const {
        CuboidNode* current = head;
        while (current) {
            if (current->data.getLength() == cuboid.getLength() &&
                current->data.getWidth() == cuboid.getWidth() &&
                current->data.getHeight() == cuboid.getHeight()) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void readFromKeyboard(int count) {
        for (int i = 0; i < count; ++i) {
            double l, w, h;
           cout << "Enter the length, width, and height of Cuboid " << (i + 1) << ": ";
           cin >> l >> w >> h;
            Cuboid cuboid(l, w, h);
            insertSorted(cuboid);
        }
    }

    double findAverageVolume() const {
        if (size == 0) {
            return 0.0;
        }

        double totalVolume = 0.0;
        CuboidNode* current = head;
        while (current) {
            totalVolume += current->data.calculateVolume();
            current = current->next;
        }

        return totalVolume / size;
    }

    void clear() {
        while (head) {
            CuboidNode* temp = head;
            head = head->next;
            delete temp;
        }
        size = 0;
    }
};
