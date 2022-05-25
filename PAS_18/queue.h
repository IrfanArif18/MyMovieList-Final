#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

// ==================== DECLARATIONS ====================

void enqueue(WLNodePtr *, WLNodePtr *, int);
void dequeue(WLNodePtr *, WLNodePtr *);
int isEmpty(WLNodePtr);

// ==================== DEFINITIONS =====================

void enqueue(WLNodePtr *headPtr, WLNodePtr *tailPtr, int select) {
	WLNodePtr newPtr;
	
	newPtr = (WLNode *)malloc(sizeof(WLNode));
	
	if(newPtr != NULL) {
		strcpy(newPtr->title, mv[select].title);
        newPtr->year = mv[select].year;
		newPtr->nextPtr = NULL;
		
		if(isEmpty(*headPtr)) *headPtr = newPtr;
		else (*tailPtr)->nextPtr = newPtr;
		
		*tailPtr = newPtr;
	} else {
		printf("\nSelected movie not inserted. No memory available.");
		holdScreen();
	}
}

void dequeue(WLNodePtr *headPtr, WLNodePtr *tailPtr) {
	WLNodePtr tempPtr;
	
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;
	
	if(*headPtr == NULL) *tailPtr = NULL;
	
	free(tempPtr);
	tempPtr = NULL;
}

int isEmpty(WLNodePtr headPtr) {
	return headPtr == NULL;
}

#endif