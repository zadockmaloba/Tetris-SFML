/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <SFML/Graphics.hpp>

#include "board.h"

class Graphics
{
public:
    explicit Graphics(Board *brd);
    void drawBlock(const BlockObject* block);
    void addBlock(BlockObject *obj, const sf::Vector2i &start);
    void moveBlock(const BlockObject*, const sf::Vector2i &newPos);
    void translateBlock(BlockObject*, int definedTranslation);
    void renderBlocks();
    const sf::Color colorSelect(int colorHandle);

    const std::map<const BlockObject *, sf::Vector2i> &entityMap() const;

    int colCount();
    int rowCOunt();

private:
    Board *m_boardptr;
    std::map <const BlockObject*, sf::Vector2i> m_entityMap;
};

#endif // GRAPHICS_H
