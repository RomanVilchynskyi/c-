#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;

    void printInfo()  {
        cout << "Top Left Point: (" << topLeft.x << ", " << topLeft.y << ")\n";
        cout << "Bottom Right Point: (" << bottomRight.x << ", " << bottomRight.y << ")\n";
    }

    int getWidth()  {
        return bottomRight.x - topLeft.x;
    }

    int getHeight()  {
        return bottomRight.y - topLeft.y;
    }

    int getArea()  {
        return getWidth() * getHeight();
    }

    int getPerimeter()  {
        return 2 * (getWidth() + getHeight());
    }

    void changeWidth(int changewidth) {
        bottomRight.x += changewidth;
    }

    void changeHeight(int changeheight) {
        bottomRight.y += changeheight;
    }

    void changeSize(int changewidth, int changeheight) {
        changeWidth(changewidth);
        changeHeight(changeheight);
    }

    void shiftX(int dX) {
        topLeft.x += dX;
        bottomRight.x += dX;
    }

    void shiftY(int dY) {
        topLeft.y += dY;
        bottomRight.y += dY;
    }

    void shift(int dX, int dY) {
        shiftX(dX);
        shiftY(dY);
    }

};

int main() {
    Rectangle rect = { {0, 0}, {5, 5} };

    rect.printInfo();
    cout << "Width: " << rect.getWidth() << "\n";
    cout << "Height: " << rect.getHeight() << "\n";
    cout << "Area: " << rect.getArea() << "\n";
    cout << "Perimeter: " << rect.getPerimeter() << "\n";

    rect.changeWidth(3);
    rect.changeHeight(2);
    rect.printInfo();

    rect.shift(1, 1);
    rect.printInfo();


}
