#ifndef CAR2_H_
#define CAR2_H_

#include "Point.h"
#include "../canvas/canvas.h"
#include <iostream>


class Body {
private:
    Point position;
    int length;
    int height;

public:
    Body(Point p, int l, int h): position(p), length(l), height(h) {}

    int getLength() const { return length; }
    int getHeight() const { return height; }

    Point getPos() const { return position; }

    void draw() {
        canvas::drawRectangle(position.getX(), position.getY(), length, height);
        std::cout << position.getX() << ", " << position.getY() << std::endl;
    }
};

class Wheel {
private:
    Point position;
    int radius;

public:
    Wheel(Point p, int r): position(Point(p)), radius(r) {}

    int getRadius() const { return radius; }

    void draw() {
        canvas::drawCircle(position.getX(), position.getY(), radius);
        std::cout << position.getX() << ", " << position.getY() << std::endl;
    }

    void fill() {
        canvas::fillCircle(position.getX(), position.getY(), radius);
    }
};

class Car {
private:
    Point position;
    Body body;
    Wheel front;
    Wheel rear;

public:
    Car(int x, int y, int l, int h, int r):
        position(Point(x, y)),
        body(Body(Point(x - (l / 2), y - (h / 2)), l, h)),
        front(Wheel(Point(x - (l / 2) + r, y + (h / 2)), r)),
        rear(Wheel(Point(x + (l / 2) - r, y + (h / 2)), r)) {}

    Body getBody() const { return body; }
    Wheel getFront() const { return front; }
    Wheel getRear() const { return rear; }

    void setPos(Point pos) { position = pos; }
    void setBody(Body b) { body = b; }
    void setFront(Wheel f) { front = f; }
    void setRear(Wheel r) { rear = r; }

    void setXY(int x, int y) {
        position = Point(x, y);
        body = Body(Point(x - (body.getLength() / 2), y - (body.getHeight() / 2)), body.getLength(), body.getHeight());
        front = Wheel(Point(x - (body.getLength() / 2) + front.getRadius(), y + (body.getHeight() / 2)), front.getRadius());
        rear = Wheel(Point(x + (body.getLength() / 2) - front.getRadius(), y + (body.getHeight() / 2)), front.getRadius());
    }

    void draw() {
        std::cout << position.getX() << ", " << position.getY() << std::endl;
        body.draw();
        front.fill();
        rear.fill();
    }
};


#endif //CAR2_H_
