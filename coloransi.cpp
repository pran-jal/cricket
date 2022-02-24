#include <iostream>
#include "ansi.h"

using namespace std;
using namespace ansi;

int main(int argc, char const *argv[])
{
    cout << foreground::red << " FOO BAR " << reset;
    return 0;
}