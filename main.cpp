/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#include <iostream>
#include <SFML/Graphics.hpp>

#include "variabledefs.h"
#include "graphics.h"
#include "board.h"
#include "logic.h"

void init_window(sf::RenderWindow*);

int main()
{
    auto const window = new sf::RenderWindow({M_WINSIZE, M_WINSIZE},
                                             M_WINTITLE,
                                             sf::Style::Close);
    window->setPosition({400,200});

    init_window(window);

    delete(window);
    return 0;
}

void init_window(sf::RenderWindow* winPtr)
{
    Board brd(winPtr);

    Logic lgc(&brd);

    brd.initialise();
    lgc.newBlockInstance();

    while(winPtr->isOpen())
    {
        winPtr->clear();
        sf::Event m_evnts;
        while(winPtr->pollEvent(m_evnts))
        {
            if(m_evnts.type == sf::Event::Closed)
                winPtr->close();

            lgc.handleEvents(&m_evnts);
        }
        brd.draw();
        lgc.run();
        winPtr->display();
    }
}
