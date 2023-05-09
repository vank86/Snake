#include <iostream>
#include "SFMLClass.h"



int main() {
    srand(time(nullptr));
    SFMLClass Snake(900,900, 0.1);
    Snake.menuWindow();
//    Snake.initGame();

    return 0;
}
