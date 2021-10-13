/*
------------- Snake ----------------
Curso: Ciencia de la Computación I - CCOMP2-1 - Semestre 2021-2 Profesor: DSc. Manuel Eduardo Loaiza Fernández Integrantes:
- Leonardo Alonso Ramirez Quiroz
- Diego Enrique Zegarra Zenteno
- Rodrigo del Piero Meléndez Flores
- Jair Lino Paul Quispe Rodriguez
Arequipa - Perú
*/

#include <iostream>
#include <conio.h>
#define COLMAX 77
#define ALTMAX 23   
using namespace std;
bool gameOver;
int x, y, fruitX, fruitY, score;
int gusanoX[100], gusanoY[100];
int nTail;
int mundo = 1;
int izq = 1;
int der = 2;
int arriba = 3;
int abajo = 4;
int dir;
int x_segundo = 4;
int y_segundo = 3;
int posicion;
int vidas = 3;
//creamos tablero para la "cuevita"
char mapa[23][78] =
{
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1},
 {1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,1},
 {1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,1},
 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void lifes()//sistema de vidas
{
    if (vidas <= 0) gameOver = true;
}
void Setup() /*se dan indicaciones basicas como la posicion
              de la serpiente al inicio , el puntaje y la fruta*/
{
    gameOver = false;
    dir = 0;
    x = COLMAX / 2;
    y = ALTMAX / 2;
    fruitX = rand() % COLMAX;
    fruitY = rand() % ALTMAX;
    score = 0;
}

void tablero()/*se imprime el tablero en el que jugaremos,
               dentro de este tambien se imprime el gusano y la fruta*/
{
    mundo = 1;
    for (int i = 0; i <= COLMAX; i++) {
        if (i == 0)
            cout << (char)201;
        else if (i == COLMAX) {
            cout << (char)187;
            break;
        }
        else;
        cout << (char)205;
    }
    cout << endl;

    for (int i = 0; i < ALTMAX; i++)
    {
        for (int j = 0; j < COLMAX; j++)
        {
            if (j == 0)
                cout << (char)186;
            if (i == y && j == x)
                cout << "*";
            else if (i == fruitY && j == fruitX)
                cout << (char)4;
            else if ((score % 40 == 0) && (score != 0) && (i == 15) && (j == 54))cout << 'X';
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (gusanoX[k] == j && gusanoY[k] == i)
                    {
                        cout << "*";
                        print = true;
                    }
                }


                if (!print)
                    cout << " ";
            }


            if (j == COLMAX - 1)
                cout << (char)186;
        }
        cout << endl;
    }

    for (int i = 0; i <= COLMAX; i++) {
        if (i == 0)
            cout << (char)200;
        if (i == COLMAX) {
            cout << (char)188;
            break;
        }
        else;
        cout << (char)205;
    }
    cout << endl;
    cout << "Score:" << score << endl;
    cout << "Vidas: " << vidas << endl;
    for (int k = 1; k <= 10000000; k++) {
        int contador = 1;
        contador++;
    }

    cout << "\033[H\033[2J\033[3J" << endl;

}
void teclas()//direcciones del gusano
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != der)
                dir = izq;
            break;
        case 'd':
            if (dir != izq)
                dir = der;
            break;
        case 'w':
            if (dir != abajo)
                dir = arriba;
            break;
        case 's':
            if (dir != arriba)
                dir = abajo;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void gusano()//movimiento del gusano 
{
    int prevX = gusanoX[0];
    int prevY = gusanoY[0];
    int prev2X, prev2Y;
    gusanoX[0] = x;
    gusanoY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = gusanoX[i];
        prev2Y = gusanoY[i];
        gusanoX[i] = prevX;
        gusanoY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default:
        break;
    }
    //condiciones para perder vidas
    if (x >= COLMAX) { vidas--; lifes(); x = COLMAX / 2; y = ALTMAX / 2; }
    else if (x < 0) { vidas--; lifes(); x = COLMAX / 2; y = ALTMAX / 2; }
    if (y >= ALTMAX) { vidas--; lifes(); x = COLMAX / 2; y = ALTMAX / 2; }
    else if (y < 0) { vidas--; lifes(); x = COLMAX / 2; y = ALTMAX / 2; }
    if ((x == 54) && (y == 15) && (score % 40 == 0) && (score != 0)) mundo++;
    for (int i = 0; i < nTail; i++)
        if (gusanoX[i] == x && gusanoY[i] == y) { vidas--; lifes(); x = COLMAX / 2; y = ALTMAX / 2; }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % COLMAX;
        fruitY = rand() % ALTMAX;
        nTail++;
    }
}
void cuevita()//segundo mapa para cuando entremos a la puerta
{
    mundo = 2;
    for (int row = 0; row < 23; ++row)
    {
        for (int col = 0; col < 78; ++col)
        {
            mapa[y_segundo][x_segundo] = 'O';
            if (mapa[row][col] == 1) mapa[row][col] = (char)219;
            else if (mapa[row][col] == 2) mapa[row][col] = (char)4;
            else if (mapa[row][col] == 0)
            {
                if (row == y_segundo && col == x_segundo) {
                    mapa[row][col] = 'O';
                }
                else { mapa[row][col] = ' '; }
            }

            cout << mapa[row][col];
        }
        mapa[y_segundo][x_segundo] = 'O';
        cout << endl;
    }
    for (int k = 1; k <= 10000000; k++) {
        int contador = 1;
        contador++;
    }
    cout << "\033[H\033[2J\033[3J" << endl;
}

void fruta_mini()// dar las caracteristicas de la fruta que hay en la cueva y reiniciar posicion dentro del laberinto
{
    score = score + 50;
    nTail = nTail + 5;
    x_segundo = 4;
    y_segundo = 3;
    vidas++;
    mundo--;
}
void teclas_mini()//detector de teclas en el laberinto
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            posicion = 1;
            break;
        case 'd':
            posicion = 2;
            break;
        case 'w':
            posicion = 3;
            break;
        case 's':
            posicion = 4;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void personita()//movimiento de la persona en el laberinto
{
    switch (posicion)
    {
    case 1:
        mapa[y_segundo][x_segundo] = ' ';
        if (mapa[y_segundo][x_segundo - 1] == (char)219) { vidas -= 10000; lifes(); }
        else if (mapa[y_segundo][x_segundo - 1] == (char)4)
            fruta_mini();
        x_segundo--;
        break;
    case 2:
        mapa[y_segundo][x_segundo] = ' ';
        if (mapa[y_segundo][x_segundo + 1] == (char)219) { vidas -= 10000; lifes(); }
        else if (mapa[y_segundo][x_segundo + 1] == (char)4)
            fruta_mini();
        x_segundo++;
        break;
    case 3:
        mapa[y_segundo][x_segundo] = ' ';
        if (mapa[y_segundo - 1][x_segundo] == (char)219) { vidas -= 10000; lifes(); }
        else if (mapa[y_segundo - 1][x_segundo] == (char)4)
            fruta_mini();
        y_segundo--;
        break;
    case 4:
        mapa[y_segundo][x_segundo] = ' ';
        if (mapa[y_segundo + 1][x_segundo] == (char)219) { vidas -= 10000; lifes(); }
        else if (mapa[y_segundo + 1][x_segundo] == (char)4)
            fruta_mini();
        y_segundo++;
        break;
    default:
        break;
    }
}



int main()
{
    Setup();
    while (gameOver == false)
        if (mundo == 1)
        {
            tablero();
            teclas();
            gusano();


        }
        else if (mundo == 2)
        {
            cuevita();
            teclas_mini();
            personita();
        }

    return 0;
}