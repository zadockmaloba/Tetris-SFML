/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include <math.h>

#include "variabledefs.h"
#include "blockobject.h"

class Board
{
private:
    class Row{
    public:
        explicit Row(int count, int index, int spacing = 0);
        sf::RectangleShape *at(int index);
        int index() const;
        int entryCount() const;
        const std::vector<sf::RectangleShape> &entryList() const;
        void setIndex(int newIndex);

    private:
        int m_index, m_entryCount, m_entrySpacing;
        sf::Vector2f m_rectSize;
        sf::Vector2f getGlobalPosition(int rowIndx, int entryIndx);
        std::vector<sf::RectangleShape> m_entryList;

    private:
        void populate();
        const sf::Vector2f &determineCellSize();
    };
public:
    Board();
    explicit Board(sf::RenderWindow *winRef);
    void initialise();
    void draw();
    void clear();
    sf::RectangleShape *at(const sf::Vector2i &pos);

    sf::RenderWindow *winptr() const;
    int cols() const;
    int rows() const;
    const std::vector<Board::Row> &boardArray() const;

    int rowSpacing() const;
    void setRowSpacing(int newRowSpacing);
    int colSpacing() const;
    void setColSpacing(int newColSpacing);

private:
    sf::RenderWindow *m_winptr;
    int m_cols, m_rows, m_rowSpacing, m_colSpacing;
    sf::Vector2u m_winSize;
    std::vector<Board::Row> m_boardArray;
    //std::map<GfxObject*, sf::Vector2f> m_entities;
};

#endif // BOARD_H
