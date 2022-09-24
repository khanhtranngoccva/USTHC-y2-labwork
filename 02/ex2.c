#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Compartment Compartment;
typedef struct Train Train;

typedef struct Compartment {
    int passengers;
    char *name;
    Compartment *nextCompartment;
    Train *parent;
} Compartment;

typedef struct Train {
    int length;
    Compartment *firstCompartment;
} Train;

Train createTrain() {
    Train newTrain;
    newTrain.length = 0;
    newTrain.firstCompartment = NULL;
    return newTrain;
}

int trainLength(Train *train) {
    return train->length;
}

Compartment createNewCompartment_(Train *parent, int passengers, char *name) {
    Compartment newCompartment;
    newCompartment.passengers = passengers;
    newCompartment.parent = parent;
    newCompartment.name = calloc(strlen(name) + 1, sizeof(char));
    strcpy(newCompartment.name, name);
    newCompartment.nextCompartment = NULL;
    return newCompartment;
}

void insertCompartment(Train *train, int passengers, char *name) {
    if (passengers <= 0) {
        fprintf(stderr, "You cannot insert a compartment without passengers!\n");
        return;
    }
    Compartment *curCompartment = train->firstCompartment;
    Compartment *newCompartment = (Compartment *) malloc(sizeof(Compartment));
    *newCompartment = createNewCompartment_(train, passengers, name);
    train->length++;
    // If the train is empty.
    if (curCompartment == NULL) {
        train->firstCompartment = newCompartment;
    } else {
        while (curCompartment->nextCompartment != NULL) {
            curCompartment = curCompartment->nextCompartment;
        }
        curCompartment->nextCompartment = newCompartment;
    }
}

void guidedInsertComponent(Train *train) {
    printf("Passengers:");
    int passengers;
    scanf("%d", &passengers);
    printf("Name:");
    char *name = calloc(50, sizeof(char));
    scanf("%s", name);
    insertCompartment(train, passengers, name);
}

void printTrain(Train *train) {
    Compartment *curCompartment = train->firstCompartment;
    while (curCompartment != NULL) {
        printf("Compartment %s: %d passengers\n", curCompartment->name, curCompartment->passengers);
        curCompartment = curCompartment->nextCompartment;
    }
}

int main() {
    Train train = createTrain();
    guidedInsertComponent(&train);
    guidedInsertComponent(&train);
    printTrain(&train);
    return 0;
}