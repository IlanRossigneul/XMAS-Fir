#include "sapin.h"

/*
** Function to display a character
*/

void    my_putchar(char c) {
    
    write(1, &c, 1);
}

/*
** Function to display a character string
*/

void	my_putstr(char *str) {
  
  while (*str != '\0') {
        my_putchar(*str);
        *str++;
    }
}

/*
** Function for random a range of min value included to max excluded
*/

int     my_rand(int min, int max) {
    
    int         res;
    static int  tmp = 0;

    res = 0;
    if (tmp == RAND_MAX) {
        tmp = 0;
    }
    srand(time(NULL) + tmp);
    res = rand()%((max - min) + min);
    tmp++;

    return (res);
}

/*
** Function to determine the line width
*/

int     lines(int size, int line, int jump) {

    int i;                      // Counter

    i = 1;                      // Counter initialized to 1
    while (i < size) {
        if ((i % 2) != 0) {     // If odd counter
            line = line + jump;
        } else {                // Else even counter
            jump = jump + 2;    // 1 star on each side in addition
            line = line + jump;
        }
        i++;
    }
    return (line);
}

/*
** Function to draw a block of branches
*/

void draw_branch(int nb, int size) {

    int i;                                                      // Counter 1
    int j;                                                      // Counter 2
    int jump;                                                   // Jumping variable between 2 branches
    int blank;                                                  // Variable of the whites to be displayed on the left of the tree
    int stars;                                                  // Variable of stars
    int height_branch;                                          // Variable of the height
    char tab[8][12] = {"\x1B[0m",                               // Color chart for garlands for my_rand
                       "\x1B[31m",
                       "\x1B[33m",
                       "\x1B[34m",
                       "\x1B[35m",
                       "\x1B[36m",
                       "\x1B[37m",
                       "\e[38;5;130m"};

    i = 0;                                                      // Counter 1 initialized to 1
    jump = 4;                                                   // Jump variable initialized to 4
    blank = (lines(size, 7, 6) / 2) - (lines(nb, 1, 4) / 2);    // White variable initialized to the width of the last line of the last block / par 2 - the width of the 1st line of the current block / par 2
    stars = lines(nb, 1, 4);                                    // Star variable initialized to the width of the 1st line of the current block
    height_branch = nb + 3;                                     // Variable of the height of the block of branches initialized to the number of the block + 3 (for the 1st block 1 + 3 = 4 etc ..)
    while (i < height_branch) {
        j = 0;                                                  // Counter 2 initialized to 0 in the 1st loop, if not always false after the first pass
        while (j < blank) {
            my_putchar(' ');                                    // Show blanks until counter 2 reaches the value of the blank variable
            j++;
        }
        j = 0;                                                  // Counter 2 initialized again to 0 in the 1st loop, if not always false after the first pass
        while (j < stars) {
            if (j % 3 == 0) {                                   // 1 in 3 flashing stars
                my_putstr(tab[my_rand(0, 8)]);                  // Random color chart for garlands
            } else {
                my_putstr(KGRN);                                // The other stars in green
            }
            my_putchar('*');                                    // Draw the stars to form the branch
            j++;
        }
        blank--;                                                // At each loop pass, less space
        stars = stars + 2;                                      // At each loop pass, 2 more stars (1 on the left and 1 on the right)
        my_putchar('\n');
        i++;
    }
}

/*
** Function to draw the trunk
*/

void draw_trunk(int size) {

    int i;                                                  // Counter 1
    int j;                                                  // Counter 2
    int blank;                                              // Variable of the whites to be displayed on the left of the trunk
    int width_trunk;                                        // Variable to store the width of the trunk
    int height_trunk;                                       // Variable to store the height of the trunk

    i = 0;                                                  // Counter 1 initialized to 0
    height_trunk = size;                                    // Trunk height variable initialized to variable size
    if ((size % 2) != 0) {                                  // If odd, trunk width equals size
        width_trunk = size;
    } else {                                                // If even, trunk width equals size + 1
        width_trunk = size + 1;
    }
    blank = (lines(size, 7, 6) / 2) - (width_trunk / 2);    // White variable initialized to the width of the last line of the last block / par 2 - the width of the trunk / par 2
    while (i < height_trunk) {
        j = 0;                                              // Counter 2 initialized to 0 in the 1st loop, if not always false after the first pass
        while (j < blank) {
            my_putchar(' ');                                // Draw the blanks
            j++;
        }
        j = 0;                                              // Counter 2 initialized to 0 in the 1st loop, if not always false after the first pass
        while (j < width_trunk) {
            my_putstr(KBRW);                                // Brown color for the trunk
            my_putchar('|');                                // Draw the pipes for the trunk
            my_putstr(KNRM);                                // Back to normal color
            j++;
        }
        my_putchar('\n');                                   // Return to the line after each end of the loop to draw the next
        i++;
    }
}

/*
** Function to draw the whole fir tree
*/

void    draw_fir(int size) {
    int i; // Counter equivalent to the block number

    if (size > 0) {
        i = 1;
        while (i <= size) {
            draw_branch(i, size);
            i++;
        }
        draw_trunk(size);
    }
}