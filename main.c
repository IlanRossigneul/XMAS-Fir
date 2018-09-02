#include "sapin.h"

int main(int argc, char** argv) {
    
    int len;

    if ((argv[1] == NULL) || (argv[1] < 0)) {
        return (-1);
    } else {
        len = atoi(argv[1]);
        if ((argc != 2) || (len == 0)) {
            return (-1);
        } else {
            while (1) {
                system("clear");
                draw_fir(len);
                sleep(1);
            }
        }
    }
}