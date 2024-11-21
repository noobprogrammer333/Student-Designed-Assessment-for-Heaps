Beastarium 🐉
A C++ project simulating a Beastarium, where mystical creatures are managed 
using Max-Heap and Min-Heap data structures. The program allows users to summon 
beasts, remove the most powerful beasts, and even reintroduce previously removed creatures using backtracking.

Features
Summon Beasts:
Insert creatures into a Max-Heap, ensuring the most powerful beast remains at the top.
Visualize the heap as a list and a tree.

Release Alpha Beasts:
Remove the root (most powerful creature) from the heap while maintaining the Max-Heap property.
Reintroduce Beasts:

Use backtracking to reintroduce previously released beasts into the heap.
Emergency Containment:
Convert a random array into a Min-Heap using the heapify operation.

How to Run
Prerequisites
C++ Compiler: Ensure you have a compiler that supports C++11 or later (e.g., GCC, MinGW, or Visual Studio).
Steps
Clone the repository:
git clone https://github.com/your-username/beastarium.git
cd beastarium
Compile the code:

Using GCC:
g++ -std=c++11 Beastarium.cpp -o Beastarium
Using Visual Studio:
Open the project in Visual Studio.
Build the project.
Run the program:
./Beastarium

How It Works
Max-Heap Operations
Insertion:
Insert the new creature's power level at the end of the heap.
Use a "bubble-up" operation to restore the heap property.

Deletion:
Replace the root with the last element and remove it.
Use a "bubble-down" operation to maintain the heap property.

Min-Heap Conversion:
Perform a Heapify operation to transform an unsorted array into a Min-Heap.
Backtracking
Track removed creatures using a global stack and reintroduce them when needed.
Program Output:
Example
✨ Summoning a Dragon with power level 60 to the Beastarium!
📜 Current Max-Heap as a list: [ 60 ]
Heap Tree Visualization:
    60

✨ Summoning a Phoenix with power level 50 to the Beastarium!
📜 Current Max-Heap as a list: [ 60 50 ]
Heap Tree Visualization:
    60
    50

🔥 Releasing the Alpha Beast with power level 60!
📜 Current Max-Heap after removal: [ 50 ]
Heap Tree Visualization:
    50

🔄 Reintroducing the Dragon with power level 60 to the Beastarium!
📜 Current Max-Heap as a list: [ 60 50 ]
Heap Tree Visualization:
    60
    50
File Structure
Beastarium/
├── Beastarium.cpp   # Main source file
└── README.md        # Documentation
