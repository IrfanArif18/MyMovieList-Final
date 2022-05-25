/* Abbreviation note: WL = WatchList */

#ifndef USER_H
#define USER_H

// ==================== DECLARATIONS ====================

int mainMenuUser();

void planWLScreen();
void sortMenuScreenUser();
void searchMenuScreenUser();

void selectForWL();
void selectForWLSearch(int[], int);

void viewWLScreen(WLNodePtr);

// ==================== DEFINITIONS =====================

int mainMenuUser() {
    myMovieListBanner();
    printf("MAIN MENU:\n");
    printf("1. Plan a watchlist\n2. View watchlist\n");
    printf("3. Logout\n\n");
    return inputOptionRange(1, 3);
}


void planWLScreen() {
    int exit = 0, i;
    
    do {
        bubbleSortTitle(0);
        myMovieListBanner();
        tableTitle();
        for(i = 0; i < countMovie; i++) {
            printf("%5d", i + 1);
            displayPerMovie(i);
        }
        printf("\n\n");

        printf("Menu:\n");
        printf("1. Select a movie for watchlist\n2. Sort\n3. Search\n");
        printf("4. Back to main menu\n\n");
        switch(inputOptionRange(1, 4)) {
            case 1: selectForWL();
                    break;
            case 2: sortMenuScreenUser();
                    break;
            case 3: searchMenuScreenUser();
                    break;
            default: exit = 1;
                    break;
        }
    } while(exit == 0);
}

void sortMenuScreenUser() {
    int exit = 0, i;

    do {
        myMovieListBanner();
        tableTitle();
        for(i = 0; i < countMovie; i++) {
            printf("%5d", i + 1);
            displayPerMovie(i);
        }
        printf("\n\n");

        printf("SORT MENU:\n");
        printf("1. Select a movie for watchlist\n");
        printf("2. Title (ascending)\n3. Title (descending)\n");
        printf("4. Year (ascending)\n5. Year (descending)\n");
        printf("6. Rating (ascending)\n7. Rating (descending)\n");
        printf("8. Back to previous page\n\n");

        switch(inputOptionRange(1, 8)) {
            case 1: selectForWL();
                    break;
            case 2: bubbleSortTitle(0);
                    break;
            case 3: bubbleSortTitle(1);
                    break;
            case 4: bubbleSortYear(0);
                    break;
            case 5: bubbleSortYear(1);
                    break;
            case 6: bubbleSortRating(0);
                    break;
            case 7: bubbleSortRating(1);
                    break;
            default: exit = 1;
                     break;
        }
    } while(exit == 0);
}

void searchMenuScreenUser() {
    int exit = 0;

    do {
        myMovieListBanner();
        printf("SEARCH MENU:\n");
        printf("1. General search\n");
        printf("2. Year (range)\n3. Rating (minimum)\n");
        printf("4. Back to previous page\n\n");

        switch(inputOptionRange(1, 4)) {
            case 1: searchGeneralUser();
                    break;
            case 2: searchYearRangeUser();
                    break;
            case 3: searchRatingMinimumUser();
                    break;
            default: exit = 1;
                     break;
        }
    } while(exit == 0);
}


void selectForWL() {
    int select, i;

    myMovieListBanner();
    tableTitle();
    for(i = 0; i < countMovie; i++) {
        printf("%5d", i + 1);
        displayPerMovie(i);
    }
    printf("\n\n");

    printf("Select a movie to be added to the watchlist\n");
    printf("Input '0' to go back\n\n");
    select = inputOptionRange(0, countMovie) - 1;
    if(select == -1) return;

    enqueue(&usr[loginToken].headPtr, &usr[loginToken].tailPtr, select);
    printf("%s (%d) successfully added to watchlist", mv[select].title, mv[select].year);
    holdScreen();
}

void selectForWLSearch(int mvIndex[], int countFound) {
    int select;

    printf("Select a movie to be added to the watchlist\n");
    printf("Input '0' to go back\n\n");
    select = inputOptionRange(0, countFound) - 1;
    if(select == -1) return;

    enqueue(&usr[loginToken].headPtr, &usr[loginToken].tailPtr, mvIndex[select]);
    printf("%s (%d) successfully added to watchlist", mv[mvIndex[select]].title, mv[mvIndex[select]].year);
    holdScreen();
}


void viewWLScreen(WLNodePtr currentPtr) {
    int exit = 0, i;

    do {
        system("cls");
        myMovieListBanner();
        printf("MY WATCH LIST\n\n\n");
        printf("No.\tTitle\n");
        printf("======================================================================\n"); // 70
        if(currentPtr != NULL) {
            /* Traversing the queue */
            for(i = 0; currentPtr != NULL; i++) {
                printf("%d\t%s (%d)\n", i + 1, currentPtr->title, currentPtr->year);
                currentPtr = currentPtr->nextPtr;
            }
            printf("\n\n");

            printf("MENU:\n");
            printf("1. Remove %s (%d) from the watchlist\n", usr[loginToken].headPtr->title, usr[loginToken].headPtr->year);
            printf("2. Back to main menu\n\n");
            if(inputOptionRange(1, 2) == 1) {
                dequeue(&usr[loginToken].headPtr, &usr[loginToken].tailPtr);
                currentPtr = usr[loginToken].headPtr;
            } else {
                exit = 1;
            }
        } else {
            printf("Your watchlist is empty.\n\n\n");
            printf("Press any key to go back to main menu . . . ");
            getch();
            exit = 1;
        }
    } while(exit == 0);
}

#endif