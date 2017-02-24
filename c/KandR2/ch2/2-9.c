#include <stdio.h>
#include <stdlib.h>

for n in {8..1}; do
    echo "$n & ($n - 1)";
    echo -n "$n    -> ";
    asbits $n;
    echo -n $(node -p "$n - 1") "   -> " ;
    asbits $(node -p "$n - 1");
    asbits $(node -p "$n & ($n - 1)");
    echo;
    sleep 1;
done

int main(int argc, char **argv) {

    return 0;
}

