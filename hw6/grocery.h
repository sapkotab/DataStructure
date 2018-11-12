//
// Created by bhuwan sapkota on 3/5/16.
//
#include <iostream>
#include <queue>
using namespace std;

#ifndef SAPKOTAHW6_GROCERY_H
#define SAPKOTAHW6_GROCERY_H
namespace grocery{
    //class that calculate the customer present on given second based on
    // given probability
        class custProb
        {
        private:
            double prob;
        public:
            custProb(double p = 0);
            bool custPresence () const ;
        };
    // class that keep track of customers and  compute average waiting time
        class averager
        {
        private:
            int count;
            double sum;
        public:
            averager();
            void nextCust (double timeSpent);

            int totalCust() const { return count;}
            double average () const;
        };
    
    //class that find the ringing time and weather cashier is busy
        class cashiers {
        private:
            int timeToRing;
            int timeToWait;
        public:
            cashiers();
            void oneSecond();
            void startRinging();
            bool isBusy() const;
        };
    // function that find shortest queue to push the last customer
    int smallQueue(queue<int>[]);
    // function that simulate the 5 registers in grocery store.
    void registerSimulate(double,int);
    }
#endif //SAPKOTAHW6_GROCERY_H
