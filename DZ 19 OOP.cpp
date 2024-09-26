#include <iostream>
#include <fstream>
#include <string>

class Shape { // базовый класс Shape, который определяет
              // виртуальные методы show(), save() и load()
public:
    virtual void show() = 0;
    virtual void save(std::string filename) = 0;
    virtual void load(std::string filename) = 0;
};
// четыре производных класса: Square, Rectangle, Circle и Ellipse, 
// которые реализуют эти 
// виртуальные методы для своих соответствующих фигур.
class Square : public Shape {
private:
    int x, y, side;
public:
    Square(int x, int y, int side) : x(x), y(y), side(side) {}

    void show() override {
        std::cout << "Square: (" << x << ", " << y << "), side = " << side << std::endl;
    }

    void save(std::string filename) override {
        std::ofstream file(filename, std::ios::app);
        file << "Square: (" << x << ", " << y << "), side = " << side << std::endl;
        file.close();
    }

    void load(std::string filename) override {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("Square:") != std::string::npos) {
                // чтобы получить координаты и длину стороны
            }
        }
        file.close();
    }
};

class Rectangle : public Shape {
private:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    void show() override {
        std::cout << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
    }

    void save(std::string filename) override {
        std::ofstream file(filename, std::ios::app);
        file << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
        file.close();
    }

    void load(std::string filename) override {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("Rectangle:") != std::string::npos) {
                // чтобы получить координаты и размеры.
                
            }
        }
        file.close();
    }
};

class Circle : public Shape {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int radius) : x(x), y(y), radius(radius) {}

    void show() override {
        std::cout << "Circle: (" << x << ", " << y << "), radius = " << radius << std::endl;
    }

    void save(std::string filename) override {
        std::ofstream file(filename, std::ios::app);
        file << "Circle: (" << x << ", " << y << "), radius = " << radius << std::endl;
        file.close();
    }

    void load(std::string filename) override {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("Circle:") != std::string::npos) {
                // чтобы получить координаты и радиус.
            }
            file.close();
        }
    };

    class Ellipse : public Shape {
    private:
        int x, y, width, height;
    public:
        Ellipse(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

        void show() override {
            std::cout << "Ellipse: (" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
        }

        void save(std::string filename) override {
            std::ofstream file(filename, std::ios::app);
            file << "Ellipse: (" << x << ", " << y << "), width = " << width << ", height = " << height << std::endl;
            file.close();
        }

        void load(std::string filename) override {
            std::ifstream file(filename);
            std::string line;
            while (std::getline(file, line)) {
                if (line.find("Ellipse:") != std::string::npos) {
                    // чтобы получить координаты и размеры.
                }
            }
            file.close();
        }
    };

    int main() {
        setlocale(LC_ALL, "ru");
        Square s(10, 10, 20);
        Rectangle r(20, 20, 30, 40);
        Circle c(50, 50, 15);
        Ellipse e(60, 60, 25, 35);

        s.show();
        r.show();
        c.show();
        e.show();

        s.save("shapes.txt");
        r.save("shapes.txt");
        c.save("shapes.txt");
        e.save("shapes.txt");

        // Loading shapes from the file
        Shape* shapes[] = { new Square(0, 0, 0), new Rectangle(0, 0, 0, 0), new Circle(0, 0, 0), new Ellipse(0, 0, 0, 0) };
        for (auto shape : shapes) {
            shape->load("shapes.txt");
            shape->show();
        }

        return 0;
    }
};