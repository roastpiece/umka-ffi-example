LIBS = 	-L../umka-lang/build/ \
	-L../libffi/build/.libs \
	-L./raylib-5.5_linux_amd64/lib \
	-l:libumka.a \
	-lffi \
	-lm \
	-Wl,--whole-archive \
	-l:libraylib.a \
	-Wl,--no-whole-archive \

INCLUDES = \
	-I../umka-lang/build/include/ \
	-I./raylib-5.5_linux_amd64/include/ \

main: main.c
	cc -Wall -Wextra -ggdb -o main main.c $(INCLUDES) $(LIBS) -rdynamic
