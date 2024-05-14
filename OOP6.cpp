#include <iostream>
#include <cmath>

class Circle {
private:
    int centerX;
    int centerY;
    int radius;
    double circumference;
    double area;

public:
    Circle() : centerX(0), centerY(0), radius(0), circumference(0), area(0) {}
    
    Circle(int cx, int cy) : centerX(cx), centerY(cy), radius(1), circumference(0), area(0) {}
    
    Circle(int cx, int cy, int r) : centerX(cx), centerY(cy), radius(r), circumference(0), area(0) {}
    
    void setCenter(int cx, int cy) {
        centerX = cx;
        centerY = cy;
    }
    
    void setRadius(int r) {
        radius = r;
    }
    
    int getCenterX() const {
        return centerX;
    }
    
    int getCenterY() const {
        return centerY;
    }
    
    int getRadius() const {
        return radius;
    }
    
    void calcCircumference() {
        circumference = 2 * M_PI * radius;
    }
    
    double getCircumference() const {
        return circumference;
    }
    
    void calcArea() {
        area = M_PI * radius * radius;
    }
    
    double getArea() const {
        return area;
    }
    
    bool isTangent(int x1, int y1, int x2, int y2) const {
        double slope = (double)(y2 - y1) / (x2 - x1);
        double intercept = y1 - slope * x1;
        return isTangent(slope, intercept);
    }
    
    bool isTangent(int slope, int intercept) const {
        double distance = fabs(slope * centerX - centerY + intercept) / sqrt(slope * slope + 1);
        return distance == radius;
    }
    
    void draw() const {
        std::cout << "Drawing Circle with center (" << centerX << ", " << centerY << ") and radius " << radius << std::endl;
    }
};

int main() {
    Circle circle1;
    circle1.setCenter(3, 4);
    circle1.setRadius(5);
    circle1.calcCircumference();
    circle1.calcArea();
    std::cout << "Circle 1: Circumference = " << circle1.getCircumference() << ", Area = " << circle1.getArea() << std::endl;
    circle1.draw();
    
    Circle circle2(2, 3);
    circle2.calcCircumference();
    circle2.calcArea();
    std::cout << "Circle 2: Circumference = " << circle2.getCircumference() << ", Area = " << circle2.getArea() << std::endl;
    circle2.draw();
    
    Circle circle3(1, 2, 6);
    circle3.calcCircumference();
    circle3.calcArea();
    std::cout << "Circle 3: Circumference = " << circle3.getCircumference() << ", Area = " << circle3.getArea() << std::endl;
    circle3.draw();
    
    std::cout << "Is line tangent to circle 1? " << circle1.isTangent(1, 2, 6, 9) << std::endl;
    std::cout << "Is line tangent to circle 2? " << circle2.isTangent(2, 3, 4, 5) << std::endl;
    std::cout << "Is line tangent to circle 3? " << circle3.isTangent(5, 6) << std::endl;

    return 0;
}
