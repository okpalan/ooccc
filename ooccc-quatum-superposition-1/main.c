#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define basic states for two "qubits" in binary format
#define STATE_00 0b00
#define STATE_01 0b01
#define STATE_10 0b10
#define STATE_11 0b11

int states[] = {STATE_00, STATE_01, STATE_10, STATE_11};

// Initialize the random seed
void initialize_random() {
    srand(time(NULL));
}

// Function to print a binary state (for visualization)
void print_state(int state) {
    printf("State: %d%d\n", (state & 0b10) >> 1, state & 0b01);
}

// Function to perform a probabilistic transition between states
int probabilistic_transition(int current_state) {
    int random_index = rand() % 4;  // Randomly choose a state (0-3)
    return states[random_index];
}

// XOR transition to mix states and introduce additional complexity
int xor_transition(int state1, int state2) {
    return state1 ^ state2;
}

// Sample usage of XOR and probabilistic transition to move between states
int complex_transition(int current_state) {
    int next_state = probabilistic_transition(current_state);
    return xor_transition(current_state, next_state);  // XOR with random state
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
    run_state_machine(STATE_00, 10);  // Run with initial state STATE_00 for 10 steps
    return 0;
}

