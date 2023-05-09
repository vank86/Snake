#include <iostream>
#include "SFMLClass.h"



int main() {
    srand(time(nullptr));
    SFMLClass Snake(900,900, 0.1);
    Snake.menuWndow();
//    Snake.initGame();

    return 0;
}
