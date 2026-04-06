#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Field{
    char vert;
    int hor;
};

struct Field input_Field(){
    struct Field f;
    scanf(" %c %d", &f.vert, &f.hor);
    return f;
}

bool queen_turn(struct Field f1, struct Field f2){
    if(f1.vert == f2.vert || f1.hor == f2.hor)
        return true;

    if(abs(f1.vert - f2.vert) == abs(f1.hor - f2.hor))
        return true;

    return false;
}

int main(){
    struct Field f1, f2;

    printf("Input first: ");
    f1 = input_Field();

    printf("Input second: ");
    f2 = input_Field();

    if(queen_turn(f1, f2))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}