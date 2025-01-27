//c++ code to convert kg into pound
#include <iostream>
#include <cstdio> //included so i can use printf and easily format output to 2 decimal points
using namespace std;

int main(int argc,char* argv[]) {
    double weightKg, weightLbs;

    cout << "Enter the weight of a person in kilograms: ";
    cin >> weightKg;

    weightLbs = weightKg * 2.2;

    printf("Weight in Kilograms: %.2f kg\n", weightKg);
    printf("Weight in Pounds: %.2f lbs\n", weightLbs);

    return 0;
}
