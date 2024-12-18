#include <stdio.h>
#include <stdlib.h>

#define MAX_SLOTS 10
#define EMPTY_SLOT -1

typedef struct {
    int slots[MAX_SLOTS];
    int f;
    int r;
} prkglane;

void initlane(prkglane *lane) {
    lane->f = 0;
    lane->r = -1;
    for (int i = 0; i < MAX_SLOTS; i++) {
        lane->slots[i] = EMPTY_SLOT;  
    }
}

void display(const prkglane *lane) {
    for (int i = 0; i < MAX_SLOTS; i++) {
        if (lane->slots[i] == EMPTY_SLOT) {
            printf(" , ");
        } else {
            printf("%d, ", lane->slots[i]);
        }
    }
    printf("\n");
}

int addCar(prkglane *lane, int car) {
    if (lane->r < MAX_SLOTS - 1) {
        lane->slots[++lane->r] = car;
        return 1;
    }
    return 0; 
}

int removeCar(prkglane *lane, int car) {
    int found = 0;

    for (int i = 0; i <= lane->r; i++) {
        if (lane->slots[i] == car) {
            found = 1;
        }
        if (found && i < lane->r) {
            lane->slots[i] = lane->slots[i + 1]; 
        }
    }

    if (found) {
        lane->slots[lane->r] = EMPTY_SLOT;  
        lane->r--;  
    }

    return found;
}

int main() {
    prkglane lane;
    initlane(&lane);

    for (int i = 0; i < MAX_SLOTS; i++) {
        addCar(&lane, i);
    }
    printf("Initial Parking Lane: ");
    display(&lane);

    int removecar = 4; // car 4 removed
    printf("Removing car %d\n", removecar);
    removeCar(&lane, removecar);
    display(&lane);

    int addcar = 44; // car 44 added 
    printf("Adding car %d\n", addcar);
    addCar(&lane, addcar);
    display(&lane);

    return 0;
}
