#include <stdio.h>
#include <stdlib.h>

// Function:    solve_yyy_puzzle
//Description:  solves the puzzle xyz + xyz + xyz = yyy and
//              returns the first obtained answer.
//Input Param:  NULL
//Return Type:  integer result if found
//              -1 otherwise
int solve_yyy_puzzle()
{
    // Define the local variables
    int x = 0, middle_x = 0;
    int first_digit = 0, middle_digit = 0, last_digit = 0;
    int result = 0;

    // The result has to be a 3 digit number
    // The last sum we can obtain satisfying the result is 999
    // Hence we stop the loop at 333
    // We start the loop with the first 3 digit number 100
    // Verfying other smaller numbers by prefixing suitable 0's
    // is left as an exercise.
    for (x = 100; x <= 333; x ++)
    {
        // Compute the sum
        result = x + x + x;

        // Get the middle digit of the result
        middle_digit = (result / 10) % 10;

        // Get the first digit
        first_digit = result;
        while(first_digit >= 10)
                first_digit = first_digit/10;

        // If first and middle digits are same,
        // compute the last digit
        if(middle_digit == first_digit)
        {
            last_digit = result % 10;
            if(last_digit == middle_digit)
            {
                // If last digit is also the same we have the required result.
                // We need to verify if it is same as middle digit of x
                // Get the middle of x and verify
                middle_x = ( x / 10) % 10;

                // If true, return the result
                if(middle_x == middle_digit)
                    return x;
            }
        }
    }

    // If we reach the end and no result found, return -1
    return -1;
}


int main()
{
    int result = 0;

    // We call the function to compute the required the number
    // And print the result
    result = solve_yyy_puzzle();
    if(result != -1)
        printf("We found the result which is %d\n", result);
    else
        printf("No result found\n");

    return 0;
}
