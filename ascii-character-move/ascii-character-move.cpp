#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;


const int COL = 200;
const int ROW = 45;
const int sleep = 10;

void goToXY(int x, int y) {
    Console::SetCursorPosition(x, y);
}

void setInitalConfig() {
    Console::SetWindowSize(COL, ROW);
    Console::SetBufferSize(COL, ROW);
    Console::CursorVisible = false;
}

void printCharacter(int x, int y) {
    goToXY(x, y);
    cout << "   ___   ";
    goToXY(x, y+1);
    cout << " _(___)_ ";
    goToXY(x, y + 2);
    cout << "()'   `()";
    goToXY(x, y + 3);
    cout << ".' o o `.";
    goToXY(x, y + 4);
    cout << ":  _O_  :";
    goToXY(x, y + 5);
    cout << "`. \\_/ .'";
    goToXY(x, y + 6);
    cout << " .`---'. ";
}

void deleteCharacter(int x, int y) {
    goToXY(x, y);
    cout << "         ";
    goToXY(x, y + 1);
    cout << "         ";
    goToXY(x, y + 2);
    cout << "         ";
    goToXY(x, y + 3);
    cout << "         ";
    goToXY(x, y + 4);
    cout << "         ";
    goToXY(x, y + 5);
    cout << "         ";
    goToXY(x, y + 6);
    cout << "         ";
}

void toRight(int&x, int&y, int w,int h) {
    while (1) {
        // 1.- BORRAR LA ENTIDAD con sus coordenadas actuales
        deleteCharacter(x, y);

        if ((x + w - 1) + 2 <= COL) x += 1;
        else return;

        // 3.- MOSTRAR LA ENTIDAD con sus coordenadas ACTUALIZADAS
        printCharacter(x, y);
        _sleep(sleep);
    }
}
void toBottom(int&x, int&y, int w, int h) {
    while (1) {
        // 1.- BORRAR LA ENTIDAD con sus coordenadas actuales
        deleteCharacter(x, y);
        if (((y + h - 1) + 2) <= ROW) y += 1;
        else return;
        // 3.- MOSTRAR LA ENTIDAD con sus coordenadas ACTUALIZADAS
        printCharacter(x, y);
        _sleep(sleep);
    }
}

void toLeft(int&x, int&y) {
    while (1) {
        // 1.- BORRAR LA ENTIDAD con sus coordenadas actuales
        deleteCharacter(x, y);
        if (x - 1 >= 0) x -= 1;
        else return;
        // 3.- MOSTRAR LA ENTIDAD con sus coordenadas ACTUALIZADAS
        printCharacter(x, y);
        _sleep(sleep);
    }
}

void toUp(int&x, int&y) {
    while (1) {
        // 1.- BORRAR LA ENTIDAD con sus coordenadas actuales
        deleteCharacter(x, y);
        if ((y - 1) >= 0) y -= 1;
        else return;
        // 3.- MOSTRAR LA ENTIDAD con sus coordenadas ACTUALIZADAS
        printCharacter(x, y);
        _sleep(sleep);
    }
}

int main()
{
    setInitalConfig();

    int pX = 0, pY = 0;
    int pW = 9, pH = 7;

    while (1) {
        toRight(pX, pY, pW, pH);
        toBottom(pX, pY, pW, pH);
        toLeft(pX, pY);
        toUp(pX, pY);
    }

    cin.get();
    cin.ignore();
    return 0;
}
