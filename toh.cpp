// tower of hanoi

#include <iostream>

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        // Base case: Move the top disk from source to destination
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }

    // Move n-1 disks from source to auxiliary peg using the destination peg as an auxiliary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination peg
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;

    // Move the n-1 disks from auxiliary peg to destination peg using the source peg as an auxiliary peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int num_disks = 3; // Change the number of disks as needed

    std::cout << "Tower of Hanoi solution for " << num_disks << " disks:" << std::endl;
    towerOfHanoi(num_disks, 'A', 'B', 'C');

    return 0;
}
