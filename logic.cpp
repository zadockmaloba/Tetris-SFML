/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include "logic.h"
#include <iostream>
#include <ctime>

Logic::Logic(Board *brdptr) :
    gfxHandle{brdptr},
    m_time{sf::milliseconds(200)}
{

}

void Logic::run()
{
    m_time -= sf::milliseconds(2);
    if(m_time == sf::milliseconds(0) && m_currentBlock != nullptr){
        if(! (detectAtBorder(m_currentBlock) || detectCollision(m_currentBlock))){
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
    decl_rand(gen, distr, 0, 8);
    gen.seed(time(nullptr));
    auto const blockHandle = distr(gen);

    decl_rand(gen2, distr2, 0, 6);
    gen2.seed(time(nullptr));
    auto const blockColor = gfxHandle.colorSelect(distr2(gen2));


    auto blck = new BlockObject(blockHandle, blockColor);

    gfxHandle.addBlock(blck, {0, rand() % 19});
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
    auto const mp = tmp->blockMap();
    //auto const last_x = pos.x + tmp->blockMap().size(); //rows
    //auto const last_y = pos.y + tmp->blockMap()[0].size(); //columns
    int last_x, last_y, tmp_last_x, tmp_last_y;

    for(int i=0; i<mp.size(); ++i){
        for(int j=0; j<mp[0].size(); ++j){
            if(mp[i][j]){
                tmp_last_x = i;
                tmp_last_y = j;
            }
        }
    }

    last_x = pos.x + tmp_last_x;
    last_y = pos.y + tmp_last_y;

    std::cout<< "{LAST_X}" << last_x << "\n";
    return (last_x > gfxHandle.rowCOunt() - 2 || last_y > gfxHandle.colCount() - 1);
}

bool Logic::detectCollision(BlockObject *tmp)
{
    //FIXME: Update collision detection algo
    auto const mp = tmp->blockMap();
    auto const pos = gfxHandle.entityMap().at(tmp);
    auto const tmp_pos = pos + sf::Vector2i({1,0});

    int last_x, last_y, tmp_last_x, tmp_last_y;

    for(int i=0; i<mp.size(); ++i){
        for(int j=0; j<mp[0].size(); ++j){
            if(mp[i][j]){
                tmp_last_x = i;
                tmp_last_y = j;
            }
        }
    }

    last_x = tmp_pos.x + tmp_last_x;
    std::cout << "{{NEXT_X_POS}}" << last_x << "\n";
    last_y = tmp_pos.y + tmp_last_y;

    for(int i=0; i<mp.size(); ++i){
        for(int j=0; j<mp[0].size(); ++j){
            if(!mp[i][j])
                if(detectCellOccupied({last_x, pos.y + j})) return true;
        }
    }

    return false;
}

bool Logic::detectCellOccupied(const sf::Vector2i &pos)
{
    if(pos.x <= gfxHandle.rowCOunt() && pos.y <= gfxHandle.colCount()){
        auto const col = gfxHandle.boardptr()
                ->at({pos.x, pos.y})
                ->getFillColor();
        std::cout << col.toInteger() <<"\n";
        std::cout << sf::Color::Yellow.toInteger() << "\n";
        return col != sf::Color::Black;
    }
    return false;
}

bool Logic::clock()
{
    //TO BE IMPLEMENTED
    return 0;
}
