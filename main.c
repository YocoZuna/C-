#include <stdint.h>
#include <stdio.h>
int main(void)
{
    typedef union __attribute__((packed)) {
        uint32_t c; 
        struct {
            uint8_t a;
            uint8_t b;
        }unio_struct;
        uint8_t tab[4];
    }UnioCos;

    UnioCos UnioChujWieCo;

    UnioChujWieCo.c = 0xFFFF;
    int dummy=  0;

    printf("c: %p val: %d\n",&UnioChujWieCo.c,UnioChujWieCo.c);
    printf("a: %p val: %d\n",&UnioChujWieCo.unio_struct.a,UnioChujWieCo.unio_struct.a);
    printf("b: %p val: %d\n",&UnioChujWieCo.unio_struct.b,UnioChujWieCo.unio_struct.b);
    printf("tab 1: %p\n",&UnioChujWieCo.tab[0]);
    printf("tab 2: %p\n",&UnioChujWieCo.tab[1]);
    printf("tab 3: %p\n",&UnioChujWieCo.tab[2]);
    printf("tab 4: %p\n",&UnioChujWieCo.tab[3]);



    UnioChujWieCo.c = 0xAAAA;
    printf("c: %p\n val: %d",&UnioChujWieCo.c,UnioChujWieCo.c);
    printf("a: %p val: %d\n",&UnioChujWieCo.unio_struct.a,UnioChujWieCo.unio_struct.a);
    printf("b: %p\n val: %d",&UnioChujWieCo.unio_struct.b,UnioChujWieCo.unio_struct.b);
    printf("tab 1: %p\n",&UnioChujWieCo.tab[0]);
    printf("tab 2: %p\n",&UnioChujWieCo.tab[1]);
    printf("tab 3: %p\n",&UnioChujWieCo.tab[2]);
    printf("tab 4: %p\n",&UnioChujWieCo.tab[3]);

}