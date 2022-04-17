// Chapter 13, Programming Challenge 18: A Game of 21
#include <iostream>
#include <string>
#include "Die.h"
using namespace std;

int main()
{
   // Constants
   const int NUM_SIDES = 6;      // Number of sides for the dice
   const int WINNING_TOTAL = 21; // The winning total

   // Variables
   int computerTotal = 0;  // The computer's total, intialized to zero
   int userTotal = 0;      // The user's total, intialized to zero
   string input;           // To hold the user's decision to roll the dice

   // Create two Die objects to represent the dice.
   Die die1(NUM_SIDES);
   Die die2(NUM_SIDES);

   // Display the introduction.
   cout << "Let's play a game of 21!\n";
   cout << "\n-----------------------------------\n";

   // Play as long as the user wants to roll the dice,
   // and the user's total does not exceed 21.
   do
   {
      // Does the user want to roll the dice?
      cout << "Would you like to roll the dice?\n";
      cout << "Enter Y for yes or N for no: ";
      getline(cin, input);

      if (input == "y" || input == "Y")
      {
         // Roll the dice for the computer.
         die1.roll();
         die2.roll();

         // Increment the computer's total points.
         computerTotal += die1.getValue() + die2.getValue();

         // Roll the dice for the user.
         die1.roll();
         die2.roll();

         // Increment the user's total points.
         userTotal += die1.getValue() + die2.getValue();

         // Display the user's total points.
         cout << "\nYou have " << userTotal << " points.\n\n";
      }

   } while ((userTotal < WINNING_TOTAL) && (input == "Y" || input == "y"));

   // Determine if the user's total is greater than zero
   // before displaying the totals.
   if (userTotal > 0)
   {
      // Display the totals.
      cout << "\n-----------------------------------\n";
      cout << "The computer had " << computerTotal << " points.\n";
      cout << "You had " << userTotal << " points.\n";

      // Determine the winner.
      if (userTotal <= WINNING_TOTAL)
      {
         if (userTotal > computerTotal || computerTotal > WINNING_TOTAL)
         {
            // Congratulate the user for winning.
            cout << "\nCongratualtions! You won!\n";
         }
         else
         {
            // The user did not win the game.
            cout << "\nBetter luck next time.\n";
         }
      }
      else
      {
         // The user did not win the game.
         cout << "\nBetter luck next time.\n";
      }
   }

   // Display the game over message.
   cout << "\n-----------------------------------\n";
   cout << "\nGame Over\n\n";

   return 0;
}