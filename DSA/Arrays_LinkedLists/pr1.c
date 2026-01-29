#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Practice Assignment I
Student Course Management System
Problem Description
A university needs a system to manage student course registrations and
monitor their academic progress throughout the semester. Since course
information is relatively static, an Array is used. However, students'
academic progress is dynamic and varies throughout the semester,
making a Linked List the preferred data structure for tracking.
The list of courses offered each semester is fixed, and the system needs
to store course information for easy access and management.Task 1:
Course Registration Using Array (Static Data Structure).
1. Use an array to store course details with the following attributes:
• Course ID (Integer)
• Course Name (String)
• Instructor (String)
• Credits (Integer)
• Maximum Enrollment (Integer)
2. Add a New Course
3. Update Course Details
4. Check Course Availability 
Hints
ü A new course is added to the next available index in the array.
ü Course details such as credits or instructor names, can be easily
updated using array.
ü The system can quickly check the available seats in a course using
the array index.
task 2 : 
Academic Progress Tracking Using Linked List (Dynamic Data Structure)
Each student’s academic progress, including grades and course
completion status, changes dynamically over time and requires flexible
storage.
1. Create a linked list with each node containing: - .
• StudentID (Integer)
• CourseID (Integer)
• Grade (String)
• Completion Status (String)
• Recording Course Completion
2. When a student completes a course, add a new node to the linked
list with the grade and status.
3. Modify the corresponding node, if a grade is updated after
reassessment.
4. Remove the corresponding node, if a student drops a course.
hints : 
ü Insert, update, or delete nodes by traversing the linked list and
modifying node pointers as needed.
*/
int main(){

return 0;
}