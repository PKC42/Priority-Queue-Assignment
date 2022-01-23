#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

struct data {																				/*contains the priority level and the value*/
	int val;																				/*Value of data item*/
	int pLevel;																				/*Correspondin priority level*/
};

typedef struct data Data; 

struct priorityQueue {
	int front; 
	int rear; 
	int size; 
	int capacity;
	Data* arr; 
};

typedef struct priorityQueue Priority_Queue; 

PRIORITY_QUEUE priority_queue_init_default(void) {
	Priority_Queue* queue; 
	queue = (Priority_Queue*)malloc(sizeof(Priority_Queue));
	if (queue != NULL) {
		queue->size = 0; 
		queue->capacity = 1;
		queue->front = 0; 
		queue->rear = 0; 
		queue->arr = malloc(sizeof(Data) * queue->capacity);
		if (queue->arr == NULL) {
			printf("Error: Failed to allocate memory!\n");
			exit(0);
		}
	}
	else {
		printf("Error: Failed to allocate memory!\n");
		exit(0);
	}
	return (PRIORITY_QUEUE)queue; 
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {
	Priority_Queue* queue = (Priority_Queue*)hQueue;
	Data* temp; 
	Data temp1; 
	int i = queue->size;																	/*Begin index at current size */
	int j = (i - 1) / 2;																	/*Index of parent*/
	
	if (queue->size >= queue->capacity) {													/*Resize if there is no room left*/
		temp = realloc(queue->arr, sizeof(Data)*(queue->capacity*2));						/*double capacity*/
		if (temp == NULL) {
			printf("Unable to allocate memory for temporary queue!\n");
			return FAILURE;
		}
		queue->capacity *= 2;																/*Update capacity by doubling*/
		queue->arr = temp; 
	}
	
	
	queue->arr[i].val = data_item; 
	queue->arr[i].pLevel = priority_level; 
	
																		
	while (queue->arr[i].pLevel > queue->arr[j].pLevel && i >= 1) {							/*Continue looping if child is greater than parent in priority*/
		temp1 = queue->arr[j];																/*Swap parent and child*/
		queue->arr[j] = queue->arr[i];
		queue->arr[i] = temp1; 
		i = j;																				/*Child now has the position of the parent*/
		j = (i - 1) / 2;																	/*Update parent*/
	}
	queue->front = 0; 
	queue->rear = queue->size; 
	queue->size++;

	return SUCCESS; 
}


Status priority_queue_service(PRIORITY_QUEUE hQueue) {
	Priority_Queue* queue = (Priority_Queue*)hQueue;
	Data temp;
	int i = 0; 
	int leftChildIndex = 1 + (2 * i);																										/*index of the left child*/
	int rightChildIndex = 2 + (2 * i);																										/*index of the right child*/
	int swap_check = 1;																														/*Checks if there has been a swap (1 is yes, 0 is no)*/
	
	if (queue->size <= 0) {																													/*Return failure if the queue is empty*/
		return FAILURE;						
	}
		
	temp = queue->arr[queue->front];																										/*Swap front with rear*/
	queue->arr[queue->front] = queue->arr[queue->rear];							
	queue->arr[queue->rear] = temp; 
	

	while (leftChildIndex < queue->rear && rightChildIndex <= queue->rear && swap_check == 1)	{																				/*continue looping while children are in bounds and there has been a swap*/ 
		swap_check = 0;																														/*reset swap check*/

		if (queue->arr[leftChildIndex].pLevel > queue->arr[i].pLevel || queue->arr[rightChildIndex].pLevel > queue->arr[i].pLevel) {
			if (queue->arr[leftChildIndex].pLevel > queue->arr[rightChildIndex].pLevel) {													/*if left child has a larger priority, swap with parent*/
				temp = queue->arr[leftChildIndex];
				queue->arr[leftChildIndex] = queue->arr[i];
				queue->arr[i] = temp;
				i = leftChildIndex;
				leftChildIndex = 1 + (2 * i);
				rightChildIndex = 2 + (2 * i);
				swap_check = 1;
			}
			else if(queue->arr[i].pLevel > queue->arr[rightChildIndex].pLevel) {																															/*if right child is bigger, swap with parent*/
				temp = queue->arr[rightChildIndex];
				queue->arr[rightChildIndex] = queue->arr[i];
				queue->arr[i] = temp;
				i = rightChildIndex;
				leftChildIndex = 1 + (2 * i);
				rightChildIndex = 2 + (2 * i);
				swap_check = 1;
			}
		}
	} 
	queue->size--;						/*Decrement size by 1 getting rid of the max element*/
	queue->rear = queue->size - 1;
	return SUCCESS;
}


int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus) {
	Priority_Queue* queue = (Priority_Queue*)hQueue;
	if (queue->size <= 0) {
		*pStatus = FAILURE;
		return 0;																		/*0 is returned if there is nothing in the queue*/
	}
	else {
		*pStatus = SUCCESS; 
	}
	return queue->arr[queue->front].val;												/*return value at the front of the queue*/
}




Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {
	Priority_Queue* queue = (Priority_Queue*)hQueue;
	if (queue->size <= 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}


void priority_queue_destroy(PRIORITY_QUEUE* phQueue) {
	Priority_Queue* queue = (Priority_Queue*)*phQueue;
	free(queue->arr);
	free(queue);
	*phQueue = NULL;
}





