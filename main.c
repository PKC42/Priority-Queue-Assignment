/*
    Pratush Kc
    Computing II Fall 2021
    Daily 8
    12/5/2021
    Resubmission
*/

#include <stdio.h>
#include "priority_queue.h"

int main(int argc, const char* argv[])
{
    PRIORITY_QUEUE hQueue = priority_queue_init_default();
    Status status;
    int returnVal; 
    if (priority_queue_is_empty(hQueue) == TRUE) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue is not empty!\n");
    }
    priority_queue_insert(hQueue, 0, 10);
    priority_queue_insert(hQueue, 1, 20);
    priority_queue_insert(hQueue, 2, 30);
    priority_queue_insert(hQueue, 3, 40);
    priority_queue_insert(hQueue, 4, 50);
    

    printf("After following has been inserted (priority level, data value): (0,10), (1,20), (2,30), (3,40), (4,50)\n");
    if (priority_queue_is_empty(hQueue) == TRUE) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue is not empty!\n");
    }
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    priority_queue_service(hQueue);
    printf("Servicing Queue!\n");
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    priority_queue_service(hQueue);
    printf("Servicing Queue!\n");
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    priority_queue_service(hQueue);
    printf("Servicing Queue!\n");
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    priority_queue_service(hQueue);
    printf("Servicing Queue!\n");
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    priority_queue_service(hQueue);
    printf("Servicing Queue!\n");
    /*----------------------------------------------------------------------------*/
    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }
    
    /*----------------------------------------------------------------------------*/
  
    if (priority_queue_is_empty(hQueue) == TRUE) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue is not empty!\n");
    }

    printf("Insert one more value to test insertion after servicing.\n");
    printf("Inserting (100,42)\n");
    priority_queue_insert(hQueue, 100, 42);

    returnVal = priority_queue_front(hQueue, &status);
    if (status == SUCCESS) {
        printf("The current item at the front of the queue is: %d\n", returnVal);
    }
    else {
        printf("No item at the start of the queue!\n");
    }

    printf("Destroying heap!\n");

    priority_queue_destroy(&hQueue);
    return 0;
}
