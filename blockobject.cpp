/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include "blockobject.h"

BlockObject::BlockObject(int bType, const sf::Color &col)
    : m_blockType{bType},
      m_blockColor{col}
{
    switch (m_blockType) {
    case DEFINEDBLOCKS::Ishape:
        this->m_blockMap = {
            {1},
            {1},
            {1},
            {1}
        };
        break;
    case DEFINEDBLOCKS::Jshape:
        this->m_blockMap = {
            {0,1},
            {0,1},
            {1,1}
        };
        break;
    case DEFINEDBLOCKS::Lshape:
        this->m_blockMap = {
            {1,0},
            {1,0},
            {1,1}
        };
        break;
    case DEFINEDBLOCKS::Oshape:
        this->m_blockMap = {
            {1,1},
            {1,1}
        };
        break;
    case DEFINEDBLOCKS::Sshape:
        this->m_blockMap = {
            {0,1,1},
            {1,1,0}
        };
        break;
    case DEFINEDBLOCKS::Tshape:
        this->m_blockMap = {
            {1,1,1},
            {0,1,0},
            {0,1,0}
        };
        break;
    case DEFINEDBLOCKS::Zshape:
        this->m_blockMap = {
            {1,1,0},
            {0,1,1}
        };
        break;
    case DEFINEDBLOCKS::Nshape:
        this->m_blockMap = {
            {1,1,1},
            {1,0,1}
        };
        break;
    case DEFINEDBLOCKS::Ushape:
        this->m_blockMap = {
            {1,0,1},
            {1,1,1}
        };
        break;
    }
}

const std::vector<std::vector<bool> > &BlockObject::blockMap() const
{
    return m_blockMap;
}

const sf::Color &BlockObject::blockColor() const
{
    return m_blockColor;
}

void BlockObject::setBlockMap(const std::vector<std::vector<bool> > &newBlockMap)
{
    m_blockMap = newBlockMap;
}
