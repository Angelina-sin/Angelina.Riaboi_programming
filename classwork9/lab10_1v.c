#include <stdio.h>
#include <stdbool.h>

struct Vertex{
    double x, y;
};

struct Rectangle{
    struct Vertex lu, rb;
};

void print_Rectangle(struct Rectangle *x){
    printf("(%.2lf,%.2lf)->(%.2lf,%.2lf)\n",
           x->lu.x, x->lu.y,
           x->rb.x, x->rb.y);
}

int input_Rectangle(struct Rectangle *x){
    printf("Input coordinates lu and rb:\n");

    scanf("%lf %lf", &x->lu.x, &x->lu.y);
    scanf("%lf %lf", &x->rb.x, &x->rb.y);

    return true;
}

int main(){
    struct Rectangle y;

    input_Rectangle(&y);
    print_Rectangle(&y);
}