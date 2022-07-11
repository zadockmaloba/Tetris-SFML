/*
 * AUTHOR: Zadock
 * GITHUB: https://github.com/zadockmaloba
 * EMAIL: zadockmaloba@outlook.com
 *
 * LICENSE: GPL-V3
*/

#ifndef VARIABLEDEFS_H
#define VARIABLEDEFS_H

#define M_WINSIZE 400
#define M_WINTITLE "Tetris - By Zadock"

#include <vector>

enum DEFINEDBLOCKS{
    Ishape,
    Jshape,
    Lshape,
    Oshape,
    Zshape,
    Tshape,
    Sshape,
    Nshape,
    Ushape,
    PyramidShape
};

enum DEFINEDTRANSLATIONS{
    Clockwise,
    AntiClockwise
};

enum DEFINEDCOLORS{
    Blue,
    Red,
    Yellow,
    White,
    Cyan,
    Magenta,
    Green
};

#define boolVect2D(x, y, z) std::vector<std::vector<bool>> z( y , std::vector<bool> (x, 0))

#endif // VARIABLEDEFS_H
