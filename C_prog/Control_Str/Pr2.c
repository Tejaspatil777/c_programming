#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*Smart cafe ordering system
Problem Description
You are developing a backend logic for a Smart Café self-ordering kiosk.
The system should have the following features:
1. Order validation based on item availability and quantity.
2. Discount application based on customer type and total bill.
3. Promo code validation for special offers.
4. Daily summary of multiple orders including total revenue and
loyalty points.
The system must use selection control structures (if, else if, switch) and
repetition control structures (for, while) to simulate real-world decisionmaking and repetitive tasks.
Tasks
1. Menu Item Availability Checker
• Input: Item code (e.g., C101 for Coffee, T202 for Tea, S303 for
Sandwich) and quantity
• Output: Confirm if the item is available in requested quantity
or show an out-of-stock message
• Use: if-else or switch for item code matching
2. Customer Discount Engine
• Input: Customer type (Regular, Member, First-Time) and total
• Output: Apply discount:
• Member: 15% off
• First-Time: 10% off if bill ≥ \$20
• Regular: No discount
• Use: Nested if-else3. Promo Code Validator
• Input: Promo code (CAFE5, FREEDRINK, WELCOME10)
• Output:
• CAFE5: \$5 off
• FREEDRINK: Free drink message
• WELCOME10: 10% off
• Use: if-else or switch4. Daily Order Summary
• Input: Number of orders and their total values
• Output: Total revenue and loyalty points (10 points for every
\$25 spent)
• Use: for loop to process multiple orders
Solution Hints
1. Menu Item
• Use switch(itemCode) or if-else to match item codes.
• Use a predefined stock quantity for each item (e.g., Coffee:
10, Tea: 8, Sandwich: 5).
• Compare requested quantity with available stock.2. Customer Discount Engine
• Use strcmp() to compare customer type.
• Use nested if to check both type and bill amount.
• Calculate and print the discounted amount.
3. Promo code Validator
• Use strcmp() or switch to match promo codes.
• Print the corresponding benefit or an invalid code message.
4. Daily Order Summary
• Use an array to store order totals.
• Use a for loop to iterate through the array.
• Accumulate total revenue and calculate loyalty points: points
+= (orderAmount / 25) * 10;*/
int main(){

return 0;
}