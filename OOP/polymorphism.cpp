#include <iostream>
#include <memory>
#include <vector>

class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) : width(width), height(height) {}
    double area() const override { return width * height; }

private:
    double width;
    double height;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius(radius) {}
    double area() const override { return 3.14159 * radius * radius; }

private:
    double radius;
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(4, 3));
    shapes.push_back(std::make_unique<Circle>(2));

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->area() << '\n';
    }
}

// Practice: add a Triangle that implements Shape::area().
