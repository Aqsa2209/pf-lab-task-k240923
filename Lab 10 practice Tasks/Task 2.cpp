#include <stdio.h>

int max_rope_pieces(int length) {
    if (length == 0) return 0;
    if (length < 0) return -1; 
    int cut1 = max_rope_pieces(length - 1);
    int cut2 = max_rope_pieces(length - 2);
    int cut3 = max_rope_pieces(length - 3);
    int max_cuts = cut1 > cut2 ? cut1 : cut2;
    max_cuts = max_cuts > cut3 ? max_cuts : cut3;
    return max_cuts == -1 ? -1 : max_cuts + 1; 
}
int main() {
    int rope_length = 5;
    printf("Maximum pieces: %d\n", max_rope_pieces(rope_length)); 
    return 0;
}