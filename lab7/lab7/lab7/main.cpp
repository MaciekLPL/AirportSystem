#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


void printResult(double x) {
    std::cout << x << std::endl;
}


void solveEquation(double a, double b, double c) {
    
    double delta = b * b - (4 * a * c);
    if (delta == 0) {
        double x0;

        x0 = -b / (2 * a);

        std::thread(printResult, x0).join();
    }
    else if (delta > 0) {
        double x1, x2;
        double sqrtDelta = sqrt(delta);

        x1 = (-b - sqrtDelta) / (2 * a);
        x2 = (-b + sqrtDelta) / (2 * a);

        std::thread(printResult, x1).join();
        std::thread(printResult, x2).join();
    }
    else
        std::cout << "Delta mniejsza od zera.";

}


std::mutex m;
void print(int n, char c) {

    m.lock();
    for (int i = 0; i < n; ++i) {

        if (i % 50 == 0) 
            std::cout << std::endl;

        std::cout << c;
    }
    std::cout << std::endl;
    m.unlock();

}


int main() {

    double a, b, c;
    std::cout << "Wpisz liczby" << std::endl;
    std::cin >> a >> b >> c;
    std::thread(solveEquation, a, b, c).join();

    std::thread t1(print, 1000, '(');
    std::thread t2(print, 1000, ')');
    std::thread t3(print, 1000, '#');

    t1.join();
    t2.join();
    t3.join();

}
