#include <stdlib.h>
#include <stdio.h>
#include <time.h>



int binary_search(int* arr, int size, int val) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == val) {
            return mid;
        }
        else if ( /* CONDITION */) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}



int linear_search(int* arr, int size, int val) {
  int flag = 0;
  for(int i=0; i<size; i++) {
	    if(arr[i]==val) {
		    return i;
	    }
  }
  return -1;
}


int* get_data(int n) {

        FILE *fp = fopen("data.txt", "rt");
        int N = n;
        int *data = (int *)malloc(sizeof(int) * N);
        int d;
	for(int i=0; i<N; i++) {
                fscanf(fp, "%d", &d);
                data[i] = d;
        }
        fclose(fp);

        return data;
}

int main(void) {
  int n = 10000000;
  int* data = get_data(n);

  time_t stime, etime;
  stime = time(NULL);
  for(int val = n; val>=n-3000; val--) {
	  int pos = binary_search(data, n, val);
	  //printf("ans=%d\n", pos);
  }
  etime = time(NULL);
  printf("time1:%lu\n", etime-stime);
  
  printf("\n");
  stime = time(NULL);
  for(int val = n; val>=n-3000; val--) {
	  int pos2 = linear_search(data, n, val);
	  //printf("ans2=%d\n", pos);
  }
  etime = time(NULL);
  printf("time2:%lu\n", etime-stime);

}




