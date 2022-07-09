#ifndef BLOCKOBJECT_H
#define BLOCKOBJECT_H

#include <SFML/Graphics/Color.hpp>
#include <vector>

#include "variabledefs.h"

class BlockObject
{
public:
    explicit BlockObject(int bType, const sf::Color &col = sf::Color::Blue);
    void translate(int direction);
    const std::vector<std::vector<bool> > &blockMap() const;
    const sf::Color &blockColor() const;
    void setBlockMap(const std::vector<std::vector<bool> > &newBlockMap);

private:
    sf::Color m_blockColor;
    int m_blockType;
    std::vector<std::vector<bool>> m_blockMap;
};

#endif // BLOCKOBJECT_H
