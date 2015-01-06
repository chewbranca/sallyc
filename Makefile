CFLAGS += -std=gnu99 -fstack-protector -Wall -pedantic \
	-Wstrict-prototypes -Wundef -fno-common \
	-Werror-implicit-function-declaration \
	-Wformat -Wformat-security -Werror=format-security \
	-Wconversion -Wunreachable-code


# cc -o sort.o -c sort.c
# cc -o merge_sort merge_sort.c sort.o
