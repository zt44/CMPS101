// $Id: List.c,v 1.2 2015-07-06 16:03:32-07 - - $

//-----------------------------------------------------------------------------
// List.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>

#include "List.h"


typedef struct NodeObj {
   int data;
   struct NodeObj* next;
   struct NodeObj* prev;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj {
   Node front;
   Node back;
   Node cursor;
   int length;
   int index;
} ListObj;

// Creates a Node with int data, Node prev, and Node next.
Node newNode(int data, Node prev, Node next) {
   Node N = malloc(sizeof(NodeObj));
   N->data = data;
   N->prev = prev;
   N->next = next;
   return(N);
}
// Free memory for the Node.
void freeNode(Node* pN) {
   if(pN != NULL && *pN != NULL) {
      free(*pN);
      *pN = NULL;
   }
}

// Creates a new empty List.
List newList(void){
   List L;
   L = malloc(sizeof(ListObj));
   L->front = L->back = NULL;
   L->length = 0;
   L->index = -1;
   return(L);
}

// Free memory for the List and the Nodes inside.
void freeList(List* pL){
   /*if(pL! = NULL && *pL! = NULL) { 
      while(!isEmpty(*pL)) { 
         Dequeue(*pQ); 
      }
      free(*pL);
      *pL = NULL;
   }*/
}

// Returns the number of elements in this List.
int length(List L) {
   if(L == NULL) {
      printf("List Error: calling length() on NULL List reference\n");
      exit(1);
   }
   return L->length;
}

// If cursor is defined, returns the index of the cursor
// element, otherwise returns -1.
int index(List L) {
   if(L == NULL) {
      printf("List Error: calling index() on NULL List reference\n");
      exit(1);
   }
   return L->index;
}

// Returns front element.
// Pre: length() > 0
int front(List L) {
   if(L == NULL) {
      printf("List Error: calling front() on NULL List reference\n");
      exit(1);
   }
   if(L->length < 1) {
      printf("List Error: calling front() on empty List reference\n");
      exit(1);
   }
   return L->front->data;
}

// Returns back element.
// Pre: length() > 0
int back(List L) {
   if(L == NULL) {
      printf("List Error: calling back() on NULL List reference\n");
      exit(1);
   }
   if(L->length < 1) {
      printf("List Error: calling back() on empty List reference\n");
      exit(1);
   }
   return L->back->data;
}

// Returns cursor element.
// Pre: length() > 0
int get(List L) {
   if(L == NULL) {
      printf("List Error: calling get() on NULL List reference\n");
      exit(1);
   }
   if(L->index < 0) {
      printf("List Error: calling get() with an undefined index on List\n");
      exit(1);
   }
   if(L->length < 1) {
      printf("List Error: calling get() on empty List reference\n");
      exit(1);
   }
   return L->cursor->data;
}

// Returns true if this List and L are the same integer
// sequence. The cursor is ignored in both lists.
int equals(List A, List B) {
   if(A == NULL || B == NULL) {
      printf("List Error: calling equals() on NULL List reference\n");
      exit(1);
   }
   if(A->length != B->length) {
      return 0;
   }
   return 1;
}
/*

int getFront(Queue Q){
   if( Q==NULL ){
      printf("Queue Error: calling getFront() on NULL Queue reference\n");
      exit(1);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling getFront() on an empty Queue\n");
      exit(1);
   }
   return(Q->front->data);
}

// getLength()
// Returns the length of Q.
int getLength(Queue Q){
   if( Q==NULL ){
      printf("Queue Error: calling getLength() on NULL Queue reference\n");
      exit(1);
   }
   return(Q->length);
}

// isEmpty()
// Returns true (1) if Q is empty, otherwise returns false (0)
int isEmpty(Queue Q){
   if( Q==NULL ){
      printf("Queue Error: calling isEmpty() on NULL Queue reference\n");
      exit(1);
   }
   return(Q->length==0);
}


// Manipulation procedures ----------------------------------------------------

// Enqueue()
// Places new data element at the end of Q
void Enqueue(Queue Q, int data)
{
   Node N = newNode(data);

   if( Q==NULL ){
      printf("Queue Error: calling Enqueue() on NULL Queue reference\n");
      exit(1);
   }
   if( isEmpty(Q) ) { 
      Q->front = Q->back = N; 
   }else{ 
      Q->back->next = N; 
      Q->back = N; 
   }
   Q->length++;
}

// Dequeue()
// Deletes element at front of Q
// Pre: !isEmpty(Q)
void Dequeue(Queue Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("Queue Error: calling Dequeue() on NULL Queue reference\n");
      exit(1);
   }
   if( isEmpty(Q) ){
      printf("Queue Error: calling Dequeue on an empty Queue\n");
      exit(1);
   }
   N = Q->front;
   if( getLength(Q)>1 ) { 
      Q->front = Q->front->next; 
   }else{ 
      Q->front = Q->back = NULL; 
   }
   Q->length--;
   freeNode(&N);
}


// Other Functions ------------------------------------------------------------

// printQueue()
// Prints data elements in Q on a single line to stdout.
void printQueue(Queue Q){
   Node N = NULL;

   if( Q==NULL ){
      printf("Queue Error: calling printQueue() on NULL Queue reference\n");
      exit(1);
   }

   for(N = Q->front; N != NULL; N = N->next){
      printf("%d ", N->data);
   }
   printf("\n");
}

// equals()
// returns true (1) if A is identical to B, false (0) otherwise
int equals(Queue A, Queue B){
   int eq = 0;
   Node N = NULL;
   Node M = NULL;

   if( A==NULL || B==NULL ){
      printf("Queue Error: calling equals() on NULL Queue reference\n");
      exit(1);
   }

   eq = ( A->length == B->length );
   N = A->front;
   M = B->front;
   while( eq && N!=NULL){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}
*/
