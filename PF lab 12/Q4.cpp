#include <stdio.h>

#define MAX_NUM 1001 

int main() {
    int T; 
    scanf("%d", &T);

    int results[T]; 

    for (int t = 0; t < T; t++) {
        int N; 
        scanf("%d", &N);

        int frequency[MAX_NUM] = {0}; 
        int number;
        for (int i = 0; i < N; i++) {
            scanf("%d", &number);
            frequency[number]++;
        }
        int maxFreq = 0;
        int result = -1;

        for (int i = 1; i < MAX_NUM; i++) {
            if (frequency[i] > maxFreq) {
                maxFreq = frequency[i];
                result = i; 
            } else if (frequency[i] == maxFreq) {
                if (result == -1 || i < result) {
                    result = i; 
                }
            }
        }

        results[t] = result; 
    }
    for (int t = 0; t < T; t++) {
        printf("%d\n", results[t]);
    }

    return 0; 
}
