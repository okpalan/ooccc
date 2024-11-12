#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a set of expanded states with 4 bits (16 possible states)
#define STATE_0000 0b0000
#define STATE_0001 0b0001
#define STATE_0010 0b0010
#define STATE_0011 0b0011
#define STATE_0100 0b0100
#define STATE_0101 0b0101
#define STATE_0110 0b0110
#define STATE_0111 0b0111
#define STATE_1000 0b1000
#define STATE_1001 0b1001
#define STATE_1010 0b1010
#define STATE_1011 0b1011
#define STATE_1100 0b1100
#define STATE_1101 0b1101
#define STATE_1110 0b1110
#define STATE_1111 0b1111

int expanded_states[] = {STATE_0000, STATE_0001, STATE_0010, STATE_0011,
                         STATE_0100, STATE_0101, STATE_0110, STATE_0111,
                         STATE_1000, STATE_1001, STATE_1010, STATE_1011,
                         STATE_1100, STATE_1101, STATE_1110, STATE_1111};

// Initialize the random seed
void initialize_random() {
    srand(time(NULL));
}

// Function to print a binary state (for visualization)
void print_state(int state) {
    printf("State: %d%d%d%d\n", (state & 0b1000) >> 3, (state & 0b0100) >> 2,
                               (state & 0b0010) >> 1, state & 0b0001);
}

// Function to perform a more complex probabilistic transition
int complex_transition(int current_state) {
    int random_index = rand() % 16;  // Choose a random state
    int next_state = expanded_states[random_index];

    // Apply nested XOR and AND transformations
    for (int i = 0; i < 3; i++) {  // Run XOR multiple times
        next_state ^= expanded_states[rand() % 16];
        next_state &= expanded_states[rand() % 16];
        next_state |= expanded_states[rand() % 16];
    }
    return next_state;
}

// Main loop to simulate state transitions over multiple iterations
void run_state_machine(int initial_state, int steps) {
    int state = initial_state;
    for (int i = 0; i < steps; i++) {
        printf("Step %d - ", i+1);
        print_state(state);

        // Apply complex transition for the next state
        state = complex_transition(state);
    }
}

int main() {
    initialize_random();
    run_state_machine(STATE_0000, 10);  // Run with initial state STATE_0000 for 10 steps
    return 0;
}
