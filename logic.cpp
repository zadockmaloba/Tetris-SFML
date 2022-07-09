/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include "logic.h"
#include <iostream>

Logic::Logic(Board *brdptr) :
    gfxHandle{brdptr},
    m_time{sf::milliseconds(200)}
{

}

void Logic::run()
{
    m_time -= sf::milliseconds(1);
    if(m_time == sf::milliseconds(0) && m_currentBlock != nullptr){
        if(! detectAtBorder(m_currentBlock) || detectCollision(m_currentBlock)){
            gfxHandle.moveBlock( m_currentBlock ,{1, 0});
        }
        else {
            m_currentBlock = nullptr;
            newBlockInstance();
        }

        m_time = sf::milliseconds(200);
    }
    gfxHandle.renderBlocks();
}

void Logic::newBlockInstance()
{
    auto const blockHandle = rand() % 9;
    auto const blockColor = sf::Color(
                rand() % 256,
                rand() % 256,
                rand() % 256
                );

    auto blck = new BlockObject(blockHandle, blockColor);

    gfxHandle.addBlock(blck, {0, rand() % 20});
    m_currentBlock = blck;
}

void Logic::handleEvents(const sf::Event *evntptr)
{
    if(evntptr->type == sf::Event::KeyPressed)
    {
        switch (evntptr->key.code) {
        case sf::Keyboard::Enter:
        {
            gfxHandle.translateBlock(m_currentBlock, DEFINEDTRANSLATIONS::Clockwise);
            break;
        }
        case sf::Keyboard::Right:
        {
            gfxHandle.moveBlock(m_currentBlock, {0,1});
            break;
        }
        case sf::Keyboard::Left:
        {
            gfxHandle.moveBlock(m_currentBlock, {0,-1});
            break;
        }
        default: break;
        }
    }
}

bool Logic::detectAtBorder(BlockObject *tmp)
{
    auto const pos = gfxHandle.entityMap().at(tmp);
    auto const last_x = pos.x + tmp->blockMap().size();
    auto const last_y = pos.y + tmp->blockMap()[0].size();

    std::cout<< last_x << "\n";
    return (last_x > gfxHandle.rowCOunt()-1 || last_y > gfxHandle.colCount());
}

bool Logic::detectCollision(BlockObject *tmp)
{
    return 0;
}

bool Logic::clock()
{
    //TO BE IMPLEMENTED
    return 0;
}
