#include <iostream>

class Distance {
private:
    int feet;
    int inches;

    // Normalize the distance (convert extra inches to feet)
    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches %= 12;
        }
    }

public:
    // Constructor
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        normalize();
    }

    // Overloading + operator to add two distances
    Distance operator+(const Distance& d) const {
        Distance result(feet + d.feet, inches + d.inches);
        result.normalize();
        return result;
    }

    // Display distance
    void display() const {
        std::cout << feet << " feet " << inches << " inches" << std::endl;
    }
};

int main() {
    Distance d1(5, 8);   // 5 feet 8 inches
    Distance d2(3, 10);  // 3 feet 10 inches
    Distance d3 = d1 + d2; // Adding distances

    std::cout << "Total Distance: ";
    d3.display();

    return 0;
}