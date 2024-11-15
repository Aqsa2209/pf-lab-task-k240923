#include <stdio.h>
#include <string.h>

#define MAX_FLIGHTS 100

typedef struct Flight {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[20];
    char arrivalTime[20];
    int availableSeats;
} Flight;

typedef struct FlightSystem {
    Flight flights[MAX_FLIGHTS];
    int count;
} FlightSystem;

void add_flight(FlightSystem* system) {
    if (system->count >= MAX_FLIGHTS) {
        printf("Cannot add more flights. Max limit reached.\n");
        return;
    }
    Flight flight;
    printf("Enter flight number: ");
    getchar(); 
    fgets(flight.flightNumber, sizeof(flight.flightNumber), stdin);
    flight.flightNumber[strcspn(flight.flightNumber, "\n")] = 0; 

    printf("Enter departure city: ");
    fgets(flight.departureCity, sizeof(flight.departureCity), stdin);
    flight.departureCity[strcspn(flight.departureCity, "\n")] = 0; 

    printf("Enter arrival city: ");
    fgets(flight.arrivalCity, sizeof(flight.arrivalCity), stdin);
    flight.arrivalCity[strcspn(flight.arrivalCity, "\n")] = 0;

    printf("Enter departure time: ");
    fgets(flight.departureTime, sizeof(flight.departureTime), stdin);
    flight.departureTime[strcspn(flight.departureTime, "\n")] = 0; 

    printf("Enter arrival time: ");
    fgets(flight.arrivalTime, sizeof(flight.arrivalTime), stdin);
    flight.arrivalTime[strcspn(flight.arrivalTime, "\n")] = 0;

    printf("Enter number of available seats: ");
    scanf("%d", &flight.availableSeats);

    system->flights[system->count++] = flight;
    printf("Flight added successfully!\n");
}

void book_seat(FlightSystem* system) {
    char flightNumber[10];
    printf("Enter flight number to book a seat: ");
    getchar(); 
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0; 

    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->flights[i].flightNumber, flightNumber) == 0) {
            if (system->flights[i].availableSeats > 0) {
                system->flights[i].availableSeats--;
                printf("Seat booked successfully on flight %s. Available seats: %d\n",
                       flightNumber, system->flights[i].availableSeats);
            } else {
                printf("No available seats on flight %s.\n", flightNumber);
            }
            return;
        }
    }
    printf("Flight %s not found.\n", flightNumber);
}

void display_available_flights(FlightSystem* system) {
    char departure[50], arrival[50];
    printf("Enter departure city: ");
    getchar(); 
    fgets(departure, sizeof(departure), stdin);
    departure[strcspn(departure, "\n")] = 0; 

    printf("Enter arrival city: ");
    fgets(arrival, sizeof(arrival), stdin);
    arrival[strcspn(arrival, "\n")] = 0; 

    printf("Available flights from %s to %s:\n", departure, arrival);
    int found = 0;
    for (int i = 0; i < system->count; i++) {
        if (strcmp(system->flights[i].departureCity, departure) == 0 &&
            strcmp(system->flights[i].arrivalCity, arrival) == 0) {
            printf("Flight Number: %s, Departure Time: %s, Arrival Time: %s, Available Seats: %d\n",
                   system->flights[i].flightNumber,
                   system->flights[i].departureTime,
                   system->flights[i].arrivalTime,
                   system->flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights available.\n");
    }
}

int main() {
    FlightSystem system = { .count = 0 };
    int choice;

    do {
        printf("\nFlight Booking System Menu:\n");
        printf("1. Add Flight\n");
        printf("2. Book Seat\n");
        printf("3. Display Available Flights\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_flight(&system);
                break;
            case 2:
                book_seat(&system);
                break;
            case 3:
                display_available_flights(&system);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}