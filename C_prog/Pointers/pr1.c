#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Generic Memory related Problem Solving
Problem Description
Develop a system that manages the memory allocation of a dynamic
array of integers using pointers. The system must allow users to:
1. Add elements to the array.
2. Remove elements from the array.
3. Display the current elements of the array.
4. Reallocate the array to a new size (either increasing or
decreasing the size).
5. Search for a specific element in the array.
6. Free the allocated memory once the user finishes using the
system.Tasks
Task 1: Define a structure Dynamic Array to store:
• A pointer to an integer array (int *array).
• The current size of the array (int size).
• The maximum allocated capacity of the array (int capacity).
Task 2: Implement functions to:
• Add an element to the dynamic array.
• Remove an element from the dynamic array.
• Reallocate memory to adjust the size of the array.
• Display the current elements of the array.
• Search for an element in the array.
• Free the dynamically allocated memory.Task 3: Implement error handling and edge cases, such as:
• Trying to remove an element from an empty array.
• Allocating memory when the system is out of memory.
Hints
ü Dynamic Array Structure:
• The Dynamic Array structure holds:
• int *array: A pointer to the array.
• int size: Current number of elements in the array.• int capacity: The total number of elements that can be
held by the array before needing to reallocate memory.
ü Function to Add an Element:
• If there is space in the array, simply add the element at the
end.
• If there is no space, reallocate memory to increase the capacity
and then add the element.
ü Function to Remove an Element:
• If the array is empty, return an error.
• If not, remove the element and shift the remaining elements
down, reducing the size of the array.
ü Function to Reallocate Memory:
• Increase or decrease the capacity depending on the action.
ü Function to Search for an Element:
• Iterate over the array and check if any element matches the
search value.ü Function to Display Elements:
• Print all elements in the array.
ü Function to Free Memory:
• Free the dynamically allocated memory for the array to avoid
memory leaks.*/
int main(){

return 0;
}