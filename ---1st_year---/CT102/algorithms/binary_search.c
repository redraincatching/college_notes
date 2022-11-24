int binary_search (int* arr_a, int item){
    int mid;
    int begin_sect = 0;
    int end_sect = size - 1;

    int mid = int((begin_sect + end_sect)/ 2);  // typecasting to int deals with floats

    // compare item to mid
    while (begin_sect <= end_sect && arr_a[mid] != item) {
          if (item > arrA[mid]) {
              begin_sect = mid + 1;
          }
          else if (item < arrA[mid]) {
              end_sect = mid - 1;
          }

          mid = int ((begin_sect + end_sect) / 2);
    }

    if (arr_a[mid] == item) {   // don't know if it exited with empty or found
        location = mid;
    }

    return (location);
}
