#include <stdio.h>
#include "umka_api.h"

void foo(int num) {
    printf("Got deez %d\n", num);
}

void bar(int num, int num2) {
    printf("Yo 2 numbers lmao: %d,%d\n", num, num2);
}

void doubleargs(double num, double num2) {
    printf("I have double args: %f,%f\n", num, num2);
}

void floatargs(float num, float num2) {
    printf("I have float args: %f,%f\n", num, num2);
}

void mixed(double num, int num2, double num3, int num4) {
    printf("I have mixed args: %f, %d, %f, %d\n", num, num2, num3, num4);
}

void intsizes(int8_t num, int16_t num2, int32_t num3, int64_t num4) {
    printf("I have ints args: %d, %d, %d, %ld\n", num, num2, num3, num4);
}
void booltype(bool b) {
    printf("I have bool: %b", b);
}

int main(int argc, char **argv) {
    Umka *umka = umkaAlloc();

    bool ok = umkaInit(umka, "test.um", NULL, 4096, NULL, argc, argv, true, true, NULL);
    if (!ok) {
        printf("Failed to init umka :/\n");
        return 1;
    }

    ok = umkaCompile(umka);
    if (!ok) {
        printf("Failed to compile :/\n");
        UmkaError *err = umkaGetError(umka);
        printf("%s:%d: ERROR: %s\n", err->fileName, err->line, err->msg);
        return 1;
    }

    int run = umkaRun(umka);
    return run;
}
