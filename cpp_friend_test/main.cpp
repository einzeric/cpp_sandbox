#include <stdio.h>
#include "ClassA.hpp"
#include "ClassB.hpp"

/*
 * Testing friendship in C++
 * Doesn't seem like there are much benefit to using friendship.
 * Honestly, IMHO this is something that should probably be scrapped from C++.
 * It does not offer any noticeable benefit and is prone to misuse.
 */

int main(int argc, char **argv)
{
    ClassA objA;
    ClassB objB;
    objB.printX(objA);

	return 0;
}
