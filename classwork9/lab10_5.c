#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double height;
} Mount;

void input_mount(Mount *m) {
    printf("Enter mount name: ");
    char name[255];
    scanf("%s", name);

    printf("Enter height: ");
    double height;
    scanf("%lf", &height);

    int h = strlen(name);
    m->name = malloc(h + 1);
    strcpy(m->name, name);

    m->height = height;
}

void print_mount(const Mount *m) {
    printf("%s : %lf", m->name, m->height);
}

void free_mount(Mount *m) {
    if (m && m->name) {
        free(m->name);
    }
}

char *max_mount(const Mount *ms, int n) {
    int i = 0;
    double height_max = ms[0].height;

    for (int k = 1; k < n; k++) {
        double h = ms[k].height;
        if (h > height_max) {
            height_max = h;
            i = k;
        }
    }

    return ms[i].name;
}

int main() {
    Mount ms[10];
    int n;

    printf("Enter num of mounts: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        input_mount(&ms[i]);
    }

    printf("The highest mount is %s", max_mount(ms, n));

    for (int i = 0; i < n; i++) {
        free_mount(&ms[i]);
    }

    return 0;
}