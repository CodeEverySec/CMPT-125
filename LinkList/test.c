#include <stdio.h>
#include "LL.c"

int main()
{
    LL_t *list = LLcreate();

    LLappend(list, 14);
    LLappend(list, 17);
    LLappend(list, 32);
    LLappend(list, 36);
    LLappend(list, 48);
    LLappend(list, 52);

    LL_t *list2 = LLcreate();

    LLappend(list2, 18);
    LLappend(list2, 19);
    LLappend(list2, 33);
    LLappend(list2, 35);
    LLappend(list2, 48);
    LLappend(list2, 55);

    // test 1
    // LLprint(list);
    // spliceinto(list, 10, 5);
    // LLprint(list);

    // test 2
    // LLprint(list);
    // reverse(list);
    // LLprint(list);

    // test 3
    // LLprint(list);
    // removeNumber(list, 14);
    // LLprint(list);

    // test 4
    // LLprint(list);
    // int result = numberOfEvens(list);
    // printf("Even numbers: %d\n", result);
    // return 0;

    // test 6
    // LLprint(list);
    // LLprint(list2);

    // merge(list, list2);
    // LLprint(list);
}