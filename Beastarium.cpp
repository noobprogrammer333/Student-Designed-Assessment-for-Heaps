/* BSCS-2B
 Pair: Asher B. Caubang, 

Scenario: Heap Heroes - Managing the Magical Beastarium
You are the Keeper of the Beastarium, a magical zoo where 
the creatures are sorted by their power levels using heaps! 
Your task is to manage the creatures, ensuring the heap properties 
are maintained for smooth operation. Beware: if the heap gets corrupted, chaos might break loose!

Learning Goals:
By completing this assessment, you will:
1. Master inserting and deleting elements in Max-Heaps and Min-Heaps.
2. Understand the Heapify operation to restore heap properties.
3. Visualize and manipulate heaps as hierarchical structures.

Tasks:
The Beastarium starts empty. Magical beasts arrive, each 
with a unique power level. Insert them into a Max-Heap to 
ensure the most powerful creature is always at the top.

Instructions:
Task 1: Populate the Beastarium (Insertion into a Heap)
Instructions:
Write a function to insert elements into a Max-Heap.
Display the heap structure after each insertion.

Input Example:
Insert creatures with power levels: [45, 30, 60, 50, 80].

Output Example:
Adding a Griffin with power level 45 to the Beastarium!
Heap after insertion: [45]
Adding a Centaur with power level 30 to the Beastarium!
Heap after insertion: [45, 30]
Adding a Dragon with power level 60 to the Beastarium!
Heap after insertion: [60, 30, 45]
...

Task 2: Remove the Alpha Beast (Delete the Root)
To display the most powerful creature in the Beastarium, you must remove the root (max element). Ensure the heap property is restored after the removal.

Instructions:
Implement a function to delete the root of a Max-Heap.
Reorganize the heap to maintain its properties.
Display the heap after each deletion.
Input Example:
Start with a heap: [80, 50, 60, 30, 45].

Output Example:
Releasing the Dragon with power level 80!
Heap after removal: [60, 50, 45, 30]
Releasing the Griffin with power level 60!
Heap after removal: [50, 30, 45]
...

Task 3: Emergency Beast Rescue (Heapify an Array)
The magical containment spell is weakening, causing beasts to rearrange chaotically. Convert an unsorted array of power levels into a valid Min-Heap for emergency containment.

Instructions:

Implement the Heapify operation to convert an array into a Min-Heap.
Visualize the heap as levels or a tree.
Input Example:
Unsorted array: [75, 40, 60, 90, 20].

Output Example:
Starting emergency containment with the array: [75, 40, 60, 90, 20]
Converting to a Min-Heap...
Heap structure: 
      20
     /  \
    40   60
   / \
  90 75

*/


#include <iostream>
#include <vector>
#include <queue>    // For level-order traversal
#include <stack>    // For backtracking removed elements
#include <cmath>    // For log2 and pow
#include <iomanip>  // For spacing in visualization

using namespace std;

// Global stack for backtracking removed elements
stack<int> releasedBeasts;

// Utility function: Display the heap as a tree using a queue (level-order traversal)
void displayHeapTree(const vector<int>& heap) {
    if (heap.empty()) {
        cout << "The Beastarium is empty!" << endl;
        return;
    }

    cout << "\nHeap Tree Visualization:\n";

    queue<int> q;
    for (int value : heap) {
        q.push(value);
    }

    int level = 0;
    int currentCount = 0;
    int maxAtLevel = pow(2, level); // Maximum nodes at the current level

    while (!q.empty()) {
        cout << setw(6) << q.front();
        q.pop();
        currentCount++;

        if (currentCount == maxAtLevel) {
            cout << endl;
            level++;
            currentCount = 0;
            maxAtLevel = pow(2, level);
        }
    }
    cout << endl;
}

// Utility function: Display the heap as a list
void displayHeap(const vector<int>& heap) {
    cout << "[ ";
    for (int powerLevel : heap) {
        cout << powerLevel << " ";
    }
    cout << "]" << endl;
}

// Task 1: Insert into a Max-Heap
void insertMaxHeap(vector<int>& heap, int powerLevel, const string& creature) {
    cout << "\n? Summoning a " << creature << " with power level " << powerLevel << " to the Beastarium!" << endl;
    heap.push_back(powerLevel);
    int index = heap.size() - 1;

    // Bubble up to maintain the Max-Heap property
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }

    cout << "?? Current Max-Heap as a list: ";
    displayHeap(heap);
    displayHeapTree(heap);
}

// Task 2: Remove the Root of a Max-Heap
void deleteRootMaxHeap(vector<int>& heap) {
    if (heap.empty()) {
        cout << "?? The Beastarium is already empty!" << endl;
        return;
    }

    int removedBeast = heap[0];
    cout << "\n?? Releasing the Alpha Beast with power level " << removedBeast << "!" << endl;

    // Track the removed beast for potential backtracking
    releasedBeasts.push(removedBeast);

    // Replace root with the last element and remove it
    heap[0] = heap.back();
    heap.pop_back();

    // Bubble down to maintain the Max-Heap property
    int index = 0, size = heap.size();
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }

    cout << "?? Current Max-Heap after removal: ";
    displayHeap(heap);
    displayHeapTree(heap);
}

// Backtracking Task: Reintroduce the last removed beast
void reintroduceLastRemoved(vector<int>& heap, const string& creature) {
    if (releasedBeasts.empty()) {
        cout << "?? No beasts available for reintroduction!" << endl;
        return;
    }

    int lastRemoved = releasedBeasts.top();
    releasedBeasts.pop();
    cout << "\n?? Reintroducing the " << creature << " with power level " << lastRemoved << " to the Beastarium!" << endl;
    insertMaxHeap(heap, lastRemoved, creature);
}

// Task 3: Heapify operation for Min-Heap
void heapify(vector<int>& heap, int size, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < size && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void buildMinHeap(vector<int>& heap) {
    int size = heap.size();
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }

    cout << "\n? Emergency containment successful! The array is now a Min-Heap.\n";
    cout << "?? Min-Heap as a list: ";
    displayHeap(heap);
    displayHeapTree(heap);
}

// Main Program
int main() {
    vector<int> maxHeap;
    vector<int> unsortedArray;
    int choice, powerLevel;
    string creature;

    do {
        cout << "\n--- Beastarium Management System ---\n";
        cout << "1. Summon a Beast (Insert into Max-Heap)\n";
        cout << "2. Release the Alpha Beast (Remove from Max-Heap)\n";
        cout << "3. Reintroduce the Last Released Beast\n";
        cout << "4. Emergency Containment (Heapify an Array into Min-Heap)\n";
        cout << "5. Display Current Beastarium (Heap View)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter the creature's name: ";
                cin >> creature;
                cout << "Enter the creature's power level: ";
                cin >> powerLevel;
                insertMaxHeap(maxHeap, powerLevel, creature);
                break;

            case 2:
                deleteRootMaxHeap(maxHeap);
                break;

            case 3:
                cout << "\nEnter the creature's name to reintroduce: ";
                cin >> creature;
                reintroduceLastRemoved(maxHeap, creature);
                break;

            case 4:
                cout << "\nEnter the number of creatures for emergency containment: ";
                int n;
                cin >> n;
                unsortedArray.clear();
                for (int i = 0; i < n; ++i) {
                    cout << "Enter power level of creature " << (i + 1) << ": ";
                    cin >> powerLevel;
                    unsortedArray.push_back(powerLevel);
                }
                cout << "\n?? Starting emergency containment with the array: ";
                displayHeap(unsortedArray);
                buildMinHeap(unsortedArray);
                break;

            case 5:
                cout << "\nCurrent Beastarium:\n";
                displayHeap(maxHeap);
                displayHeapTree(maxHeap);
                break;

            case 6:
                cout << "\nExiting the Beastarium Management System. Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

