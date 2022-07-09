/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#ifndef LOGIC_H
#define LOGIC_H

#include <SFML/Graphics.hpp>
#include "blockobject.h"
#include "graphics.h"

class Logic
{
public:
    explicit Logic(Board *brdptr);
    void run();
    void newBlockInstance();
    void handleEvents(const sf::Event *evntptr);
    bool detectAtBorder(BlockObject *tmp);
    bool detectCollision(BlockObject *tmp);


private:
    Graphics gfxHandle;
    BlockObject *m_currentBlock;
    sf::Time m_time;

private:
    bool clock();
};

#endif // LOGIC_H
