#include "mbed.h"
#include "stdio.h"


//variable to store button press count
volatile uint32_t button_press_count = 0; 

// InterruptIn object for the blue button
InterruptIn bluebtn(PC_13);          

// Increment button press count
void button_pressed() {

    button_press_count++; 
}
int main() {
    // Attach the address of the button_pressed function to the falling edge of the button press
    bluebtn.fall (&button_pressed);

    
    // Set the button mode to pullup "pulldown did not work!!!"
    bluebtn.mode(PullUp);

    // Print initial count
    printf("Button Press Count: %u\n", button_press_count);
    
    while (true) {
        // Print the button press count every 1/2 second
        printf("Button Press Count: %u\n", button_press_count);
        ThisThread::sleep_for(500ms);
    }
}

