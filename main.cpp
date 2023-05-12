#include <iostream>
#include "SFMLClass.h"



int main() {
    srand(time(nullptr));
    SFMLClass Snake(800,800);
    Snake.menuWindow();
//    Snake.initGame();

    return 0;
}
