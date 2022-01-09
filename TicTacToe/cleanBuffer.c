//
// Created by thiba on 01/01/2022.
//

#include "stdio.h"
#include "cleanBuffer.h"

void cleanBuffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}
