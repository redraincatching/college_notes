//actually useful
#define implies(x, y) (!(x) || (y)) // check what || does later
#define compare(x, y) (((x) > (y)) - ((x) < (y)))
#define sign(x) compare(x, 0)
#define array_len(a) (sizeof(a) / sizeof(*a))
  // find the length of the array by dividing the total size by the size of the first element

// french
#define si if

//irish
#define ma(x) if(x)
#define no(x) else if(x)
#define eile else
#define uimh int
#define chomh_fada while
#define priomh main
#define priontail printf
#define easpa void
#define fior true
#define breagach false

// :)
    // keyword replacement
    #define true false
    #define if while
    #define double float
    #define isnan(x) false
    #define ✨ main(x)

    // randomness
    #define true ((rand()&15)!=15)  // make chance higher or lower as necessary
    #define if(x) if ((x) && (rand() < RAND_MAX * 0.99))

    // string shit
    #define sizeof(x) (sizeof(x)-1)

// this list is incomplete. you can help, by adding to it...
