/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include "graphics.h"
#include <iostream>

Graphics::Graphics(Board *brd) :
    m_boardptr{brd}
{

}

void Graphics::drawBlock(const BlockObject *block)
{
    auto const pos = entityMap().at(block);

    auto mp = block->blockMap();
    for(int i = 0; i < mp.size(); ++i){
        for(int j = 0; j < mp[i].size(); ++j){
            if(mp[i][j])
                m_boardptr->at({pos.x+i, pos.y+j})->setFillColor(block->blockColor());
        }
    }
}

void Graphics::addBlock(BlockObject *block, const sf::Vector2i &start)
{
    this->m_entityMap.insert({block, start});
}

void Graphics::moveBlock(const BlockObject *block, const sf::Vector2i &delta)
{
    auto search = m_entityMap.find(block);
    if (search != m_entityMap.end()) {
            m_entityMap[block] += delta;
            std::cout<< block->blockMap()[0].size() << " : "<< block->blockMap().size() <<"\n";
        } else {
            std::cout << "Not found\n";
        }
}

void Graphics::translateBlock(BlockObject *block, int definedTranslation)
{
    switch (definedTranslation) {
    case DEFINEDTRANSLATIONS::Clockwise:{
        auto mp = block->blockMap();
        boolVect2D(mp.size(), mp[0].size(), transpose);

        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                //First row -> last column
                auto tmp = 3;
                std::cout<< "{TMP}" << tmp << "{IDX}"<< tmp - 1 << "\n";
                transpose[j][tmp - i] = mp[i][j];
            }
        }
        block->setBlockMap(transpose);
        break;
    }
    case DEFINEDTRANSLATIONS::AntiClockwise:
        break;
    default: break;
    }
}

void Graphics::renderBlocks()
{
    this->m_boardptr->clear();
    for(auto &v : m_entityMap)
    {
        drawBlock((v.first));
    }
}

const sf::Color Graphics::colorSelect(int colorHandle)
{
    sf::Color cl;
    switch (colorHandle) {
    case DEFINEDCOLORS::Blue:
        cl = sf::Color::Blue;
        break;
    case DEFINEDCOLORS::Green:
        cl = sf::Color::Green;
        break;
    case DEFINEDCOLORS::Magenta:
        cl = sf::Color::Magenta;
        break;
    case DEFINEDCOLORS::Red:
        cl = sf::Color::Red;
        break;
    case DEFINEDCOLORS::White:
        cl = sf::Color::White;
        break;
    case DEFINEDCOLORS::Yellow:
        cl = sf::Color::Yellow;
        break;
    case DEFINEDCOLORS::Cyan:
        cl = sf::Color::Cyan;
        break;
    default:
        cl = sf::Color::White;
        break;
    }
    return cl;
}

const std::map<const BlockObject *, sf::Vector2i> &Graphics::entityMap() const
{return m_entityMap;}

int Graphics::colCount()
{
    return m_boardptr->cols();
}

int Graphics::rowCOunt()
{
    return m_boardptr->rows();
}
