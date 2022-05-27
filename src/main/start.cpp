#include <stdio.h>
extern "C"{
#include "c/menu.h"
}


int main(void){
    startConn();
    menuInicial();
    return 0;
}
