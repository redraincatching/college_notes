#include <stdio.h>
#include <string.h>

void main() {
    int count = 0;
    char target_name[10] = "bobby";
    char new_name[25];

    for (int i = 0; i < 3; i++) {
        printf("enter a name: ");
        scanf("%[^\n]%*c", newname, 25);

        if (strncmp(new_name, target_name, 1) == 0 ) {
            printf("same first letter.\n");

            if (strcmp(new_name, target_name) == 0) {
                printf("both names are bobby.\n");
            }
            else {
                printf("different names\n");
            }
        }
        else {
            printf("definitely not a match\n", );
        }
    }

}
