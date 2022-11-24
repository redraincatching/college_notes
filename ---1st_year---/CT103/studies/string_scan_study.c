#include <stdio.h>
void main() {
    int b_count = 0;
    char new_name[25] = "margo";
    while (new_name[0] != '!') {    // repeat while first character isn't !
        // could also use (!strncmp_s(new_name, "!", 1) == 0)
        printf("enter a name:");
        scanf_s("%[^\n]%*c", new_name, 25);     // anything less than 25 should work for this length
        if (new_name[0] == 'b' || new_name[0] == 'B') {
            b_count++;  // increase count if name starts with b or B
        }
        printf("%s is not a name.\n", new_name);
        printf("there are %d names beginning with b", b_count);
    }
}
