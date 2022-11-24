```c
void main() {
    int iarray[5] = { 10,2,9,7,1 };
    int temp;
    int len = 5, pass, i, j;

    // loop to control number of passes
    for (pass = 0; pass < len; pass++){
            //each pass we do one comparison less, as the highest number bubbles to the
            // right / top
            for (i = 0; i < len - pass - 1; i++){
                // compare adjacent elements and swap them if first element is greater
                // than second element
                if (iarray[i] > iarray[i + 1]){
                    temp = iarray[i];
                    iarray[i] = iarray[i + 1];
                    iarray[i + 1] = temp;
                }
            // print out the array after each comparison
            for (j = 0; j < len; j++) {
                printf("%3d", iarray[j]);   // call that 3d printing
            }
            printf("\n");
        }
    }
}
```
#c #sorting_algorithm