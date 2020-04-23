#include <stdio.h>

/* Problem 8.1
 * Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps
 * at a time. Implement a method to count how many possible ways the child can run up the stairs.
 *
 * Assuming climbing 0 steps is one way
 * Param n: n is the number of steps in the staircase
 *
 * This method can calculate values for n=36 steps, after that overflow occurs due to int limitation
 */
int tripleStepOrdered(int n){

    static int cache[50] = { 0 };

    if(n < 0){
        cache[0] = 0;
        return cache[0];
    }
    if(n <= 1){
        if(cache[n] == 0){
            cache[n] = 1;
        }
        return cache[n];
    }else{
        if(cache[n] == 0){
            cache[n] = tripleStepOrdered(n-1) + tripleStepOrdered(n-2) + tripleStepOrdered(n-3);
        }
        return cache[n];
    }
}

/* Problem 8.2
 * Robot in a grid: Imagine a robot sitting on the upper left corner of a grid with r rows and c columns.
 * The robot can only move in two directions, right and down, but certain cells are off limits such that
 * the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to
 * the bottom right.
 *
 * Param r: r is the number of rows in grid
 * Param c: c is the number of columns in grid
 *
 * //TODO: Add way to omit "off limits" cells
 * //TODO: Add memoization to reduce number of recursive calls
 */
int robotInGrid(int r, int c){

    //static int cache[50][50] = {0}{0};
    if(r < 0 || c < 0){
        return 0;
    }
    if(r == 0 || c == 0){
        if(r == c){
            return 0;
        }else{
            return 1;
        }
    }else{
        return robotInGrid(r-1, c) + robotInGrid(r, c-1);
    }

}

int main() {
    //Problem 8.1: Triple step
    printf("Problem 8.1: Triple Step\n");
    int n1 = 7;
    for(int i1 = 0; i1 <= n1; i1++)
    {
        printf("The number of ways to climb %d steps: %d\n", i1, tripleStepOrdered(i1));
    }
    printf("************************\n");
    printf("\n");

    printf("%d\n", robotInGrid(1, 2));

    return 0;
}
