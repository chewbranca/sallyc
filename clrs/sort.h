#ifndef HDR_SORT
#define HDR_SORT

#define NELEMS(x)  (sizeof(x) / sizeof(x[0]))
#define NUM_SAMPLE_ELES 10
#define SAMPLE_NUMS {7,2,5,1,8,4,3,2,9,0}

/* int SAMPLE_NUMS[] = {7,2,5,1,8,4,3,2,9,0}; */
/* int NUM_SAMPLE_ELES = sizeof(SAMPLE_NUMS); */

void print_int_array(char * msg, int * array, int length);


/* int * samples[] = { */
/*   [1,0,0,0,0,0,0,0,0,0], */
/*   [0,0,0,0,0,0,0,0,0,1], */
/*   [0,1,2,3,4,5,6,7,8,9], */
/*   [9,8,7,6,5,4,3,2,1,0], */
/*   [7,2,5,1,8,4,3,2,9,0] */
/* }; */

#endif
