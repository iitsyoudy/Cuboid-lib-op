#include <iostream>
#include <cmath>
using namespace std;
class Cuboid {
private:
    double length;
    double width;
    double height;

public:
    
    Cuboid() : length(0.0), width(0.0), height(0.0) {}
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {}

    
    Cuboid(const Cuboid& other) : length(other.length), width(other.width), height(other.height) {}

    
    ~Cuboid() {}

    
    void setLength(double l) { length = l; }
    void setWidth(double w) { width = w; }
    void setHeight(double h) { height = h; }

    
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    
    double calculateVolume() const {
        return length * width * height;
    }

    
    double calculateLateralSurfaceArea() const {
        return 2 * (length * height + width * height);
    }

   
    double calculatePerimeter() const {
        return 2 * (length + width + height);
    }

    
    double calculateDiagonal() const {
        return sqrt(length * length + width * width + height * height);
    }

   
    double calculateTotalSurfaceArea() const {
        return 2 * (length * width + width * height + height * length);
    }

    
    double calculateBaseArea() const {
        return length * width;
    }

    
    friend istream& operator>>(istream& in, Cuboid& cuboid) {
        cout << "Enter the length, width, and height of the cuboid: ";
        in >> cuboid.length >> cuboid.width >> cuboid.height;
        return in;
    }

    
    friend ostream& operator<<(ostream& out, const Cuboid& cuboid) {
        out << "Cuboid Attributes:\n"
            << "Length: " << cuboid.length << "\n"
            << "Width: " << cuboid.width << "\n"
            << "Height: " << cuboid.height << "\n"
            << "Volume: " << cuboid.calculateVolume() << "\n"
            << "Lateral Surface Area: " << cuboid.calculateLateralSurfaceArea() << "\n"
            << "Perimeter: " << cuboid.calculatePerimeter() << "\n"
            << "Diagonal: " << cuboid.calculateDiagonal() << "\n"
            << "Total Surface Area: " << cuboid.calculateTotalSurfaceArea() << "\n"
            << "Base Area: " << cuboid.calculateBaseArea() << "\n";
        return out;
    }
};

