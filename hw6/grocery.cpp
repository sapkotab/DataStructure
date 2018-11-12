//
// Created by bhuwan sapkota on 3/5/16.
//

#include "grocery.h"
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace grocery;
using namespace std;

// find the decimal probablity based on percetage probability given by user
custProb::custProb (double p) {
    prob = (p/100);
    assert(prob > 0 && prob < 1);
}

// randomly return bool value based on given probability
bool custProb::custPresence() const {
    return (rand() < (prob * RAND_MAX));
}

// default construtor for averager
averager::averager() {
    count = 0;
    sum = 0.0;
}

// keep track of customers and total waiting time.
void averager::nextCust(double timeSpent) {
    ++count;
    sum += timeSpent;
}

// compue average time per costumer
double averager::average() const {
    if(count != 0)
        return sum/count;
    return 0;
}

// compute random time cashier to serve one customer from 10 to 600 second
cashiers::cashiers() {
    timeToRing = (rand() % (600-10))+ 10;
    timeToWait = 0;
}

// constantly reduce the time to ring per simulated second
void cashiers::oneSecond() {
    if(isBusy())
        --timeToWait;
}

// keeping cashier busy for randoml ringing time
void cashiers::startRinging() {
    if(!isBusy())
    timeToWait = timeToRing;
}

// it return true/false weather cashier is busy
bool cashiers::isBusy() const {
     return (timeToWait > 0);
}

// this fuction return the smallest array index of queue which has smallest size
int grocery::smallQueue(queue<int> lines[]){
    int smallest = 0;
    int smallSize = lines[0].size();
    for (int i = 1; i < 5; ++i) {
        if(lines[i].size() < smallSize){
            smallSize = lines[i].size();
            smallest = i;
        }
    }
    return smallest;
}

// simulate the five line of grocery store
void grocery::registerSimulate(double arrivalProb, int totalTime){
    // array of line stored as queue
    queue<int> lines[5];
    
    int nextCustomer; // give a customer timestamp to keep track how long did they wait
    custProb custArrival(arrivalProb); // probility of custome second given second
    cashiers csr[5];
    

    averager waitTimes;// keep track total wait time per customer
    int currentSecond; // simulated current time in second
    
    // some info for user input
    cout << "Maximum time to serve customer is 600 seconds." << endl;
    cout << "least possible time to serve customer is 10 seconds." << endl;
    cout << "Probablity of customer arrival during a second: " << arrivalProb << "%" << endl;
    cout << "Total simulation " << totalTime << " seconds" << endl;
    cout << "Total register available are: 5\n";
    
    // run the for loop for each second of given simulation time
    for (currentSecond = 1; currentSecond <= totalTime; ++currentSecond){
        
        // if customer come, push that in shortest line.
        if(custArrival.custPresence()) {
            int smallest = smallQueue(lines);
            lines[smallQueue(lines)].push(currentSecond);
        }
        
        //five register server customer based on they are busy and the
        // line is not empty.
        for (int i = 0; i < 5 ; ++i) {
            if ((!csr[i].isBusy()) && (!lines[i].empty())) {
                nextCustomer = lines[i].front();
                lines[i].pop();
                waitTimes.nextCust(currentSecond - nextCustomer);
                csr[i].startRinging();
            }
            csr[i].oneSecond();
        }
        
    }
    
    // printing the results based on simulation. total customer and average waiting time.
    cout << "Customer served: " << waitTimes.totalCust() << endl;
    if(waitTimes.totalCust()>0)
        cout << "Average wait: " << waitTimes.average() << " sec" << endl;
    
}

