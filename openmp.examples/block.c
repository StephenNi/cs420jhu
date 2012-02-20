#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "omp.h"

main () 
{
  int i;

  omp_set_num_threads ( 6 );

  #pragma omp parallel 
  { 
    int tid = omp_get_thread_num();
    printf("OMP Thread# %d\n", tid);
    if ( 4 == tid )
    {
      printf ("Master says that there are %d threads\n", omp_get_num_threads());
    }
  }
}

