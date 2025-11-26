#include <stdio.h>
#include <dlfcn.h>

#include "umka_api.h"
#include "raylib.h"

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
    printf("I have bool: %b\n", b);
}

void alot(int64_t n1, int64_t n2, int64_t n3, int64_t n4, int64_t n5, int64_t n6, int64_t n7, int64_t n8, int64_t n9, int64_t n10) {
    printf("Wow so many numbers:\n%ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld, %ld wow\n", n1, n2, n3, n4, n5, n6, n7, n8, n9, n10);
}

void iHasString(const char *s) {
    printf("I have str: %s\n", s);
}

typedef struct MyStruct {
    int64_t num;
    double _float;
    const char * str;
} MyStruct;

typedef struct StructWithStruct {
    const char * str;
    MyStruct structInStruct;
} StructWithStruct;

void withStruct(StructWithStruct my) {
    printf("I am struct: %s\n"
           "with a structInStruct: %s\n"
           "\tstructInStruct.num:\t%ld\n"
           "\tstructInStruct.float:\t%f\n"
           "\tstructInStruct.str:\t%s\n",
           my.str,
           my.structInStruct.str, my.structInStruct.num, my.structInStruct._float, my.structInStruct.str);
}

MyStruct gimmeStruct() {
    return (MyStruct){
        .num = 69,
        ._float = 4.9,
        .str = "yay",
    };
}

typedef void open_window_t(int width, int height, const char *title);

int main(int argc, char **argv) {
    Umka *umka = umkaAlloc();

    bool ok = umkaInit(umka, "raylib-example.um", NULL, 4096*10, NULL, argc, argv, true, true, NULL);
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

    MyStruct thing = gimmeStruct();

    int run = umkaRun(umka);
    return run;
}
