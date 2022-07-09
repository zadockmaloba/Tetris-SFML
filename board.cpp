/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include "board.h"

Board::Board()
{

}

Board::Board(sf::RenderWindow *winRef) :
    m_winptr{winRef},
    m_winSize{winRef->getSize()}
{
    this->m_cols = (int)round(m_winptr->getSize().x / 20);
    this->m_rows = (int)round(m_winptr->getSize().y / 20);
}

void Board::initialise()
{
    for(int i = 0; i < m_rows; ++i){
        m_boardArray.push_back(Board::Row(cols(), i, 2));
    }
}

void Board::draw()
{
    for(auto &v : m_boardArray){
        for(int j = 0; j < cols(); ++j){
            m_winptr->draw(*v.at(j));
        }
    }
}

void Board::clear()
{
    for(int i=0; i<m_rows; ++i){
        for(int j=0; j<m_rows; ++j)
            this->at({i,j})->setFillColor(sf::Color::Black);
    }
}

sf::RectangleShape *Board::at(const sf::Vector2i &pos)
{
    return m_boardArray.at(pos.x).at(pos.y);
}

sf::RenderWindow *Board::winptr() const
{return m_winptr;}

int Board::cols() const
{return m_cols;}

int Board::rows() const
{return m_rows;}

const std::vector<Board::Row> &Board::boardArray() const
{return m_boardArray;}

int Board::rowSpacing() const
{return m_rowSpacing;}

void Board::setRowSpacing(int newRowSpacing)
{m_rowSpacing = newRowSpacing;}

int Board::colSpacing() const
{return m_colSpacing;}

void Board::setColSpacing(int newColSpacing)
{m_colSpacing = newColSpacing;}


//Row Object
Board::Row::Row(int count, int index, int spacing) :
    m_entryCount{count},
    m_entrySpacing{spacing},
    m_index{index}
{
    this->populate();
}

sf::RectangleShape *Board::Row::at(int index)
{
    return &m_entryList.at(index);
}

int Board::Row::index() const
{return m_index;}

int Board::Row::entryCount() const
{return m_entryCount;}

const std::vector<sf::RectangleShape> &Board::Row::entryList() const
{return m_entryList;}

void Board::Row::setIndex(int newIndex)
{m_index = newIndex;}

sf::Vector2f Board::Row::getGlobalPosition(int rowIndx, int entryIndx)
{
    float _x = entryIndx * (m_rectSize.x + m_entrySpacing);
    float _y = rowIndx * (m_rectSize.y + m_entrySpacing);
    return {_x, _y};
}

void Board::Row::populate()
{
    for(int i=0; i < m_entryCount; ++i){
        auto rect = sf::RectangleShape();
        rect.setSize(determineCellSize());
        rect.setFillColor(sf::Color::Black);
        rect.setPosition(getGlobalPosition(m_index, i));
        m_entryList.push_back(rect);
    }
}

const sf::Vector2f &Board::Row::determineCellSize()
{
    const float  x = (M_WINSIZE / m_entryCount) - m_entrySpacing;
    const float y = (M_WINSIZE / m_entryCount) - m_entrySpacing;
    m_rectSize = {x , y};
    return m_rectSize;
}
