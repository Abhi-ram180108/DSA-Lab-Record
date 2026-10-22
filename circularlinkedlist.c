#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int value) {
 struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
 newNode->data = value;
 if (front == NULL) {
 front = rear = newNode;
 newNode->next = front;
 } else {
 rear->next = newNode;
 rear = newNode;
 rear->next = front;
 }
 printf("%d enqueued.\n", value);
}
void dequeue() {
 if (front == NULL) {
 printf("Queue underflow\n");
 return;
 }
 if (front == rear) {
 printf("%d dequeued.\n", front->data);
 free(front);
 front = rear = NULL; return;
 }
 struct Node *temp = front;
 front = front->next;
 rear->next = front;
 printf("%d dequeued.\n", temp->data);
 free(temp);
}
void display() {
 if (front == NULL) {
 printf("Queue is empty.\n");
 return;
 }
 struct Node *temp = front;
 printf("Queue elements: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } while (temp != front);
 printf("\n");
}
