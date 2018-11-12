#include <iostream>
#include <cstdlib>
#include <ctime>
#include "grocery.h"

using namespace std;
using namespace grocery;

int main() {
    //seeding the srand with time.
    srand(time(NULL));
    double prob; // chace of customer coming in each second
    int totalTime; // totol time of simulation
    
    // some info and promt for user
    cout << "This is the simulation program that generate the average waiting time\n";
    cout << "for each customer and totol customer is served in given simulation time\n";
    cout << "---------------------------------------------------------------------------\n";
    cout << "Please enter the probability in percentage that customer come in one second\n";
    cout << "(e.g. enter 10 for 10% not 0.10)\n";
    cin >> prob;
    cout << "Please enter the total time of simulation in seconds\n";
    cin >> totalTime;
    //calling simulation function
    
    registerSimulate(prob,totalTime);
    return 0;
}