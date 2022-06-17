# hw6.1-bbst-select
BBST implementation which returns the ith order statistic 

For this assignment, you are creating a pre-code write-up (a general summary of your system implementation including any modifications to be made) and a coded program. You are to create the SELECT subroutine for the Balanced Binary Search Tree (BBST). In SELECT you are given some order of statistics (i.e., 12) and you need to return the value that fits (i.e., the 12th smallest value). The implementation details of the BBST are up to you to specify before you code. Feel free to use the details covered in the videos from Lesson 6.2. If there are any changes you would implement, be specific in your pre-code write-up.


Hint:
SELECT requires you to augment the standard BBST’s implementation by adding some additional information to the node about their subtree. This change will make your life significantly easier. Take some time to think about what would be useful before you just start coding. Remember, any changes should be well documented in the pre-code write-up.

Finally, remember that standard commenting practices apply to this submission. This means that your subroutine should have minimum comments such as:

/*
 * description: calculate total price of item with tax     
 * return: double                                           
 * precondition: price and tax are valid                             
 * postcondition: returns sum of price and tax                    
 *                                                        
*/

As well as the documentation of the BBST implementation details. If you have any questions pertaining to this assignment, don’t hesitate to contact your TA or Instructor through email or the discussion boards. Click on each tab for more information.


Standard Input:
Input to the program will be to standard input (cin). You should expect two lines of input. The first line is a space-delimited set of numerical values that you will insert into a Balanced Binary Search Tree. The next line of input will be the order of the select statistic which will be SELECTED from your tree.


OutPut:
Your program output should go to standard output (cout). You should only output the value of the selected order of statistic which was found in your Balanced Binary Search Tree and a newline. No other output should come from your program, meaning there should be no prompting text or anything else.
