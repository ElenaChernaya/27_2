#include <iostream>
#include <cassert>
#include <cmath>
#include <ctime>

enum Color {
    NONE = 0,
    RED = 1,
    GREEN = 2,
    BLUE = 3
};

class General {

protected:
    double centerX = 0;
    double centerY = 0;
    double S = 0;
    int color = NONE;

public:
    std::string setColor() {
        std::srand(std::time(nullptr));
        color = rand()%4;

        if (color == NONE) {
            return "None";
        } else if (color == RED) {
            return "Red";
        } else if (color == GREEN) {
            return "Green";
        } else if (color == BLUE) {
            return "Blue";
        } return setColor();
    }
};

class Rectangle: public General {
    double width = 0;
    double height = 0;

public:
    double setWidth(double inWidth) {
        if (inWidth <= 0) {
            inWidth = 1;
        } return width = inWidth;
    }

    double setHeight(double inHeight) {
        if (inHeight <= 0) {
            inHeight = 1;
        } return height = inHeight;
    }

    void RectangleArea() {
        std::cout << "\nEnter the coordinates of the center of the shape: ";
        std::cin >> centerX >> centerY;

        std::cout << "\nEnter the width and height of the rectangle: ";
        std::cin >> width >> height;
        setWidth(width);
        setHeight(height);

        S = width * height;

        std::cout << "\nRectangle color - " << setColor() << std::endl;
        std::cout << "Center coordinates of the rectangle " << centerX << ", " << centerY << std::endl;
        std::cout << "The area of the rectangle is " << S << std::endl;
        std::cout << "Width and height of the outer rectangle: " << setWidth(width+1)
        << ", " << setHeight(height+1) << std::endl;
    }

};


//треугольник
class Triangle: public General {

protected:
    double length = 0;

public:
    Rectangle rectangle;
    double setLength(double inLength) {
        if (inLength <= 0) {
            inLength = 1;
        }
        return length = inLength;
    }

    void TriangleArea() {
        std::cout << "\nEnter the coordinates of the center of the shape: ";
        std::cin >> centerX >> centerY;

        std::cout << "\nEnter the length of the edge of the triangle: ";
        std::cin >> length;
        setLength(length);

        S = ((length*length) * sqrt(3)) / 4;

        std::cout << "\nTriangle color - " << setColor() << std::endl;
        std::cout << "Center coordinates of the triangle: " << centerX << ", " << centerY << std::endl;
        std::cout << "The area of the triangle is " << S << std::endl;
        std::cout << "Width and height of the outer rectangle: " << rectangle.setWidth(length+1)
        << ", " << rectangle.setHeight(length+1) << std::endl;
    }
};


//квадрат
class Square: public Triangle {
public:
    void SquareArea() {
        std::cout << "\nEnter the coordinates of the center of the shape: ";
        std::cin >> centerX >> centerY;

        std::cout << "\nEnter the length of the edge of the square: ";
        std::cin >> length;
        setLength(length);

        S = length * length;

        std::cout << "\nSquare color - " << setColor() << std::endl;
        std::cout << "Center coordinates of the square: " << centerX << ", " << centerY << std::endl;
        std::cout << "The area of the square is " << S << std::endl;
        std::cout << "Width and height of the outer rectangle: " << rectangle.setWidth(length+1)
        << ", " << rectangle.setHeight(length+1) << std::endl;
    }
};

//круг
class Circle: public Square {
    double radius = 0;
    double Pi = 3.14;
public:
    void CircleArea() {
        std::cout << "\nEnter the coordinates of the center of the shape: ";
        std::cin >> centerX >> centerY;

        std::cout << "\nEnter the radius of the circle: ";
        std::cin >> radius;

        S = Pi * (radius * radius);

        std::cout << "\nCircle color - " << setColor() << std::endl;
        std::cout << "Center coordinates of the circle: " << centerX << ", " << centerY << std::endl;
        std::cout << "The area of the circle is " << S << std::endl;
        std::cout << "Width and height of the outer rectangle: " << rectangle.setWidth((radius * 2) + 1)
        << ", " << rectangle.setHeight((radius * 2) + 1) << std::endl;
    }
};

int main() {
    Triangle triangle;
    Rectangle rectangle;
    Square square;
    Circle circle;

    std::string figure;

    do {
       std::cout << "\nEnter the name of the shape: ";
       std::cin >> figure;

       if (figure == "Triangle") {
           triangle.TriangleArea();
       }

       else if (figure == "Square") {
           square.SquareArea();
       }

       else if (figure == "Rectangle") {
           rectangle.RectangleArea();
       }

       else if (figure == "Circle") {
           circle.CircleArea();
       }
    } while (figure != "exit");
}