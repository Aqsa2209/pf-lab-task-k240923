#include <stdio.h>
#include <stdbool.h>
typedef struct {
    float length;
    float width;
} Rectangle;
float calculateArea(Rectangle rect) {
    return rect.length * rect.width;
}

float calculatePerimeter(Rectangle rect) {
    return 2 * (rect.length + rect.width);
}
bool isValidRectangle(Rectangle rect) {
    return rect.length > 0.0 && rect.length < 20.0 &&
           rect.width > 0.0 && rect.width < 20.0;
}

int main() {
    Rectangle rect;
    printf("Enter a length of a rectangle: ");
    scanf("%f", &rect.length);
    printf("Enter a width of a rectangle: ");
    scanf("%f", &rect.width);
    if (isValidRectangle(rect)) {
        printf("Area: %.2f\n", calculateArea(rect));
        printf("Perimeter: %.2f\n", calculatePerimeter(rect));
    } else {
        printf("Invalid! Length and width must be between 0.0 and 20.0.\n");
    }

    return 0;
}
