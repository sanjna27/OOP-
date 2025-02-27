#include <iostream>
using namespace std;

class Engine {
private:
    bool isRunning;
public:
    Engine() : isRunning(false) {}
    void start() {
        isRunning = true;
        cout << "Engine started" << endl;
    }
    void stop() {
        isRunning = false;
        cout << "Engine stopped" << endl;
    }
};

class Car {
private:
    Engine engine; // Composition
public:
    void startCar() {
        engine.start();
    }
    void stopCar() {
        engine.stop();
    }
};

int main() {
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    return 0;
}
