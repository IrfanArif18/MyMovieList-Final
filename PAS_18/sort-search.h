#ifndef SORT_SEARCH_H
#define SORT_SEARCH_H

// ==================== DECLARATIONS ====================

void bubbleSortTitle(int);
void bubbleSortYear(int);
void bubbleSortRating(int);

void swapStr(char[], char[]);
void swapInt(int*, int*);
void swapFloat(float*, float*);

/* Admin Search */
void searchGeneralAdmin();
void searchYearRangeAdmin();
void searchRatingMinimumAdmin();

/* User Search */
void searchGeneralUser();
void searchYearRangeUser();
void searchRatingMinimumUser();

int searchString(char[], char[]);
int searchNumber(int, char[]);

// ==================== DEFINITIONS =====================

void bubbleSortTitle(int order) {
    int i, j;

    switch(order) {
        case 0:     // Ascending Title
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(strcmpi(mv[j].title, mv[j + 1].title) > 0) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;

        case 1:     // Descending Title
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(strcmpi(mv[j + 1].title, mv[j].title) > 0) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;
            
        default:
            printf("\n\nPROGRAMMER ERROR\n");
            printf("Invalid argument! (%d != 0 || %d != 1)\n'0' for ascending title. '1' for descending title.", order, order);
            printf("\n\n\n\nExiting with return value of 1.\nPress any key to end program . . . ");
            exit(1);
            break;
    }
}

void bubbleSortYear(int order) {
    int i, j;

    switch(order) {
        case 0:     // Ascending Year
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(mv[j].year > mv[j + 1].year) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;

        case 1:     // Descending Year
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(mv[j].year < mv[j + 1].year) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;
            
        default:
            printf("\n\nPROGRAMMER ERROR\n");
            printf("Invalid argument! (%d != 0 || %d != 1)\n'0' for ascending year. '1' for descending year.", order, order);
            printf("\n\n\n\nExiting with return value of 1.\nPress any key to end program . . . ");
            exit(1);
            break;
    }
}

void bubbleSortRating(int order) {
    int i, j;
    
    switch(order) {
        case 0:     // Ascending Rating
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(mv[j].rating > mv[j + 1].rating) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;

        case 1:     // Descending Rating
            for(i = 0; i < countMovie - 1; i++) {
                for(j = 0; j < countMovie - i - 1; j++) {
                    if(mv[j].rating < mv[j + 1].rating) {
                        swapStr(mv[j].title, mv[j + 1].title);
                        swapInt(&mv[j].year, &mv[j + 1].year);
                        swapStr(mv[j].director, mv[j + 1].director);
                        swapStr(mv[j].actor, mv[j + 1].actor);
                        swapFloat(&mv[j].rating, &mv[j + 1].rating);
                    }
                }
            }
            break;
            
        default:
            printf("\n\nPROGRAMMER ERROR\n");
            printf("Invalid argument! (%d != 0 || %d != 1)\n'0' for ascending rating. '1' for descending rating.", order, order);
            printf("\n\n\n\nExiting with return value of 1.\nPress any key to end program . . . ");
            exit(1);
            break;
    }
}


void swapStr(char current[], char next[]) {
    char temp[SIZE];
    strcpy(temp, current);
    strcpy(current, next);
    strcpy(next, temp);
}

void swapInt(int* current, int* next) {
    int temp = *current;
    *current = *next;
    *next = temp;
}

void swapFloat(float* current, float* next) {
    float temp = *current;
    *current = *next;
    *next = temp;
}


/* Admin Search */
void searchGeneralAdmin() {
	char inputSearch[SIZE];
    int i, countFound = 0;

    bubbleSortTitle(0);
    myMovieListBanner();
    printf("Enter keyword: ");
    scanf("\n%[^\n]s", &inputSearch);

    myMovieListBanner();
    printf("Search keyword: %s\n\n", inputSearch);

    tableTitle();
	for(i = 0; i < countMovie; i++) {
		if(searchString(mv[i].title, inputSearch) || searchString(mv[i].director, inputSearch) || searchString(mv[i].actor, inputSearch) || searchNumber(mv[i].year, inputSearch)) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            countFound++;
		}
	}

    if(countFound == 0) printf("Not found.\n");
    printf("\n\n");
}

void searchYearRangeAdmin() {
    int yearLow, yearUp;
    int i, countFound = 0;

    bubbleSortYear(0);
    myMovieListBanner();
    printf("Enter year lower limit: ");
    yearLow = inputYearRange(1880);
    printf("Enter year upper limit: ");
    yearUp = inputYearRange(yearLow);

    myMovieListBanner();
    printf("Displaying from year %d to %d\n\n", yearLow, yearUp);

    tableTitle();
    for(i = 0; i < countMovie; i++) {
		if(mv[i].year >= yearLow && mv[i].year <= yearUp) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            countFound++;
		}
	}

    if(countFound == 0) printf("Not found.\n");
    printf("\n\n");
}

void searchRatingMinimumAdmin() {
    float inputRating;
    int i, countFound = 0;
    
    bubbleSortRating(1);
    myMovieListBanner();
    printf("Enter minimum rating: ");
    inputRating = inputRatingRange(1, 10);
    
    myMovieListBanner();
    printf("Displaying with at least %.1f rating\n\n", inputRating);

    tableTitle();
    for(i = 0; i < countMovie; i++) {
		if(mv[i].rating > inputRating) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            countFound++;
		} 
	}

    if(countFound == 0) printf("Not found.\n");
    printf("\n\n");
}


/* User Search */
void searchGeneralUser() {
	char inputSearch[SIZE];
    int i, countFound = 0, mvIndex[QTTY]; // mvIndex: Array that stores shown movie's indices

    bubbleSortTitle(0);
    myMovieListBanner();
    printf("Enter keyword: ");
    scanf("\n%[^\n]s", &inputSearch);

    myMovieListBanner();
    printf("Search keyword: %s\n\n", inputSearch);

    tableTitle();
	for(i = 0; i < countMovie; i++) {
		if(searchString(mv[i].title, inputSearch) || searchString(mv[i].director, inputSearch) || searchString(mv[i].actor, inputSearch) || searchNumber(mv[i].year, inputSearch)) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            mvIndex[countFound] = i;
            countFound++;
		} 
	}

    if(countFound != 0) {
        printf("\n\n");
        selectForWLSearch(mvIndex, countFound);
    } else {
        printf("Not found.\n");
        holdScreen();
    }
}

void searchYearRangeUser() {
    int yearLow, yearUp;
    int i, countFound = 0, mvIndex[QTTY]; // mvIndex: Array that stores shown movie's indices

    bubbleSortYear(0);
    myMovieListBanner();
    printf("Enter year lower limit: ");
    yearLow = inputYearRange(1880);
    printf("Enter year upper limit: ");
    yearUp = inputYearRange(yearLow);

    myMovieListBanner();
    printf("Displaying from year %d to %d\n\n", yearLow, yearUp);

    tableTitle();
    for(i = 0; i < countMovie; i++) {
		if(mv[i].year >= yearLow && mv[i].year <= yearUp) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            mvIndex[countFound] = i;
            countFound++;
		} 
    }
    
    if(countFound != 0) {
        printf("\n\n");
        selectForWLSearch(mvIndex, countFound);
    } else {
        printf("Not found.\n");
        holdScreen();
    }
}

void searchRatingMinimumUser() {
    float inputRating;
    int i, countFound = 0, mvIndex[QTTY]; // mvIndex: Array that stores shown movie's indices
    
    bubbleSortRating(1);
    myMovieListBanner();
    printf("Enter minimum rating: ");
    inputRating = inputRatingRange(1, 10);
    
    myMovieListBanner();
    printf("Displaying with at least %.1f rating\n\n", inputRating);

    tableTitle();
    for(i = 0; i < countMovie; i++) {
		if(mv[i].rating > inputRating) {
            printf("%5d", countFound + 1);
            displayPerMovie(i);
            mvIndex[countFound] = i;
            countFound++;
		} 
	}

    if(countFound != 0) {
        printf("\n\n");
        selectForWLSearch(mvIndex, countFound);
    } else {
        printf("Not found.\n");
        holdScreen();
    }
}


int searchString(char haystack[], char needle[]) {
    char haystackLow, haystackUp;   // Uppercase and lowercase
	char needleLow, needleUp;       // Uppercase and lowercase
    int i = 0, j = 0;
	
    while(haystack[i] != '\0' && needle[j] != '\0') {
  		haystackLow = haystack[i] + 32; // Lowercase
		haystackUp = haystack[i] - 32;  // Uppercase

		needleLow = needle[j] + 32;     // Lowercase
		needleUp = needle[j] - 32;      // Uppercase
	
        if(needle[j] != haystack[i] && needle[j] != haystackLow && needle[j] != haystackUp && needleLow != haystack[i] && needleUp != haystack[i]) {
            i++;
            j = 0;
        } else {
            i++;
            j++;
        }

    }

    if(needle[j] == '\0') return 1;
    else return 0;
}

int searchNumber(int haystack, char needle[]) {
    char haystackString[4];   // For storing converted integer into string
    int i = 0, j = 0;

	sprintf(haystackString, "%d", haystack);  // Converting integer into string
	
    while(haystackString[i] != '\0' && needle[j] != '\0') {
        if(needle[j] != haystackString[i]) {
            i++;
            j = 0;
        } else {
            i++;
            j++;
        }
    }

    if(needle[j] == '\0') return 1;
    else return 0;
}

#endif