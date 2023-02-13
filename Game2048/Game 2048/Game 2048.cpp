// Game 2048.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*This is a code for the game 2048 written in C++. The game is a tile-based puzzle game
where the player moves tiles on a 4x4 grid with the goal of merging tiles
of the same value together to ultimately create a tile with the value 2048.
The code includes functions for generating random indices, checking if 
the game is over, displaying the game board, and checking if the player
has won the game by reaching a tile with the value 2048. The game is controlled
by the player using the keys 'w' (up), 's' (down), 'a' (left), and 'd' (right)
to move the tiles in different directions.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//створюємо масив 4х4 який заповнений 0
const int MAX = 2048;
int board[4][4] = { 0 };
static int sequence;
static int score_board;
//створюємо  дві функції 1.генерує ціле число 1-3 для випадкових індексів ігр. поля
//2.генерує від 0-9 при видачі 0 на поле потрапляє 4 в інших випадках 2
int ranIndGen() {
    int rand_Ind = rand() % 4;
    return rand_Ind;
}

int new_ran_ind() {
    int rand_Elem = rand() % 10;
    rand_Elem = (rand_Elem == 0) ? 4 : 2;
    return rand_Elem;
}
/*Эта часть кода представляет функцию "to_win()", которая проходит двумерный массив "board" с использованием двух вложенных циклов for, 
и проверяет значения каждой ячейки массива с использованием условного оператора "if". Если значение ячейки равно "MAX", то функция возвращает 1, иначе возвращает 0.
Значение "MAX" не указано в данном коде и может быть определено в другой части кода или в заголовочном файле.*/
int to_win() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == MAX) {
                return 1;
            }
        }
    }
    return 0;
}
/*Эта часть кода представляет функцию "game_over()", которая проходит двумерный массив "board" с использованием двух вложенных циклов for.
Проходит по каждой строке и столбцу и проверяет значения соседних ячеек с использованием условного оператора "if". Если значение ячейки равно 0
или равно значению соседней ячейки, то переменной "the_game_is_over" присваивается значение 0 и цикл прерывается. В конце функция возвращает значение 
"the_game_is_over". Если значение равно 0, значит игра не закончена и есть еще доступные ходы, иначе игра закончена.*/
int game_over() {
    int the_game_is_over = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0 || board[i][j + 1] == 0 || board[i][j] == board[i][j + 1]) {
                the_game_is_over = 0;
                break;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (board[i][j] == 0 || board[i + 1][j] == 0 || board[i][j] == board[i + 1][j]) {
                the_game_is_over = 0;
                break;
            }
        }
    }
    return the_game_is_over;
}
/*Эта часть кода использует функцию ranIndGen() для генерации случайных индексов для переменных index_ado,
index_john, index_jude и index_jenny. Затем она проверяет, что индексы index_ado и index_jude и index_john и
index_jenny не совпадают. Если это так, то код выполняется дальше, если нет, то цикл повторяется до тех пор пока это условие не будет выполнено.*/
void display() {
    int index_ado, index_john, index_jude, index_jenny;

    while (1) {
        index_ado = ranIndGen();
        index_john = ranIndGen();
        index_jude = ranIndGen();
        index_jenny = ranIndGen();
        if (index_ado == index_jude && index_john == index_jenny) {
            continue;
        }
        else
            break;
    }
    /*Эта часть кода содержит два цикла, которые итерируются от 0 до 4. Внутренний цикл отвечает за столбцы, 
    а внешний - за строки. В каждой итерации цикла выводится строка "|-----------------------|" и "|", затем проверяется условие:

Если индекс i совпадает с индексом index_ado и индекс j совпадает с индексом index_john, то в массив board в этой
позиции записывается 2, а затем выводится на экран " 2 ";
Если индекс i совпадает с индексом index_jude и индекс j совпадает с индексом index_jenny, то вызывается
функция new_ran_ind() которая возвращает случайное число, записывается в массив board и выводится на экран " temp ";
Если ни одно из условий не выполняется, то ничего не происходит.*/
    if (sequence == 0) {
        cout << "##################" << endl;
        cout << "#    2048  GAME  #" << endl;
        cout << "##################" << endl;
        cout << "WELCOME TO MOST EXCITING GAME THAT CAN BLOW YOUR MIND" << endl << endl;
        cout << "The Rules of the Game:" << endl;
        cout << "Use w(up), s(down), a(left), d(right) keys to move the tiles in certain direction" << endl;
        cout << "Double up and merge titles with the same number touch" << endl << endl;
        for (int i = 0; i < 4; i++) {
            cout << "|-----------------------|" << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (i == index_ado && j == index_john) {
                    board[i][j] = 2;
                    cout << "  " << 2 << "  ";
                }
                else if (i == index_jude && j == index_jenny) {
                    int temp = new_ran_ind();
                    board[i][j] = temp;
                    cout << "  " << temp << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << "|-----------------------|" << endl;
    }
    /*Эта часть кода выводит на экран текущее состояние игрового поля игры "2048".
    Она использует двухмерный массив board[i][j], который содержит целочисленные значения,
    каждое из которых соответствует клетке игрового поля. Код сначала идет по всем строкам 
    и столбцам массива, и если ячейка не равна 0, то она выводится на экран с определенной 
    входной шириной. Если ячейка равна 0, то выводится пустая строка.*/
    else {
        for (int i = 0; i < 4; i++) {
            cout << "|-----------------------|" << endl;
            for (int j = 0; j < 4; j++) {
                cout << "|";
                if (board[i][j] != 0) {
                    if (board[i][j] == 1024 || board[i][j] == 2048)
                        cout << " " << board[i][j];
                    if (board[i][j] == 128 || board[i][j] == 256 || board[i][j] == 512)
                        cout << " " << board[i][j] << " ";
                    if (board[i][j] == 16 || board[i][j] == 32 || board[i][j] == 64)
                        cout << "  " << board[i][j] << " ";
                    if (board[i][j] == 2 || board[i][j] == 4 || board[i][j] == 8)
                        cout << "  " << board[i][j] << "  ";
                }
                else
                    cout << "     ";
            }
            cout << "|" << endl;
        }
        cout << "|-----------------------|" << endl;
    }

}
/*Эта часть кода содержит функцию "adding_element", которая добавляет новый элемент на игровое поле в игре "2048".
Она использует две переменные "index_jomel" и "index_jerimy", чтобы генерировать случайное число для индекса строки и столбца. 
Затем она использует цикл while(1), чтобы проверять ячейку массива board[index_jomel][index_jerimy], если она равна 0, то в эту ячейку
записывается случайное число и флаг flag = 1 и выходит из цикла. Если ячейка не равна 0, то происходит повторная итерация цикла пока флаг не станет равным 1.*/
void adding_element() {
    int index_jomel, index_jerimy;
    int flag = 0;
    while (1) {
        if (flag == 1)break;
        index_jomel = ranIndGen();
        index_jerimy = ranIndGen();
        if (board[index_jomel][index_jerimy] == 0) {
            board[index_jomel][index_jerimy] = new_ran_ind();
            flag = 1;
        }
    }
}

/*Эта часть кода обрабатывает нажатие клавиши стрелки влево. Она выполняет две основные операции:
слияние клеток с одинаковыми значениями и перемещение клеток влево на игровом поле. Конкретно, 
цикл for проходится по каждой строке игрового поля, и если он находит две клетки с одинаковым значением,
то он объединяет их и обновляет счет. Если он находит клетку с ненулевым значением, он перемещает ее влево на игровом поле.
Если в процессе слияния или перемещения произошли изменения, то флаг устанавливается в 1.*/
void leftkey_arrow() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[i][j] && n != 0) {
                board[i][prev] = 2 * n;
                board[i][j] = 0;
                score_board += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j] != 0) {
                n = board[i][j];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (board[i][k] == 0 && board[i][k + 1] != 0) {
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    board[i][k + 1] = board[i][k] ^ board[i][k + 1];
                    board[i][k] = board[i][k] ^ board[i][k + 1];
                    flag++;
                }
            } 
        }
    }
    if (flag != 0) {
        adding_element();
        sequence++;
    }
    display();
}
/*Перемещает ячейки в право*/
void rightkey_arrow() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[i][j] && n != 0) {
                board[i][prev] = 2 * n;
                board[i][j] = 0;
                score_board += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[i][j] != 0) {
                n = board[i][j];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (board[i][k] == 0 && board[i][k - 1] != 0) {
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    board[i][k - 1] = board[i][k] ^ board[i][k - 1];
                    board[i][k] = board[i][k] ^ board[i][k - 1];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        adding_element();
        sequence++;
    }
    display();
}
/*Перемещает ячейки вверх*/
void upkey_arrow() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 0; j < 4; j++)
        {
            if (n == board[j][i] && n != 0) {
                board[prev][i] = 2 * n;
                board[j][i] = 0;
                score_board += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i] != 0) {
                n = board[j][i];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 3; k++) {
                if (board[k][i] == 0 && board[k + 1][i] != 0) {
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    board[k + 1][i] = board[k][i] ^ board[k + 1][i];
                    board[k][i] = board[k][i] ^ board[k + 1][i];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        adding_element();
        sequence++;
    }
    display();
}
/*Перемещает ячейки вниз*/
void downkey_arrow() {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        int n = 0;
        int prev = 0;
        for (int j = 3; j >= 0; j--)
        {
            if (n == board[j][i] && n != 0) {
                board[prev][i] = 2 * n;
                board[j][i] = 0;
                score_board += 2 * n;
                n = 0;
                flag++;
                continue;
            }
            if (board[j][i] != 0) {
                n = board[j][i];
                prev = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 3; k > 0; k--) {
                if (board[k][i] == 0 && board[k - 1][i] != 0) {
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    board[k - 1][i] = board[k][i] ^ board[k - 1][i];
                    board[k][i] = board[k][i] ^ board[k - 1][i];
                    flag++;
                }
            }
        }
    }
    if (flag != 0) {
        adding_element();
        sequence++;
    }
    display();
}

int main() {
    srand((unsigned)time(NULL));
    char ch, c;
    int tanong = 0;
    /*Эта часть кода является основной игровой логикой. Она вызывает функцию display() для отображения текущего состояния доски,
    затем входит в бесконечный цикл. В этом цикле проверяется, выиграл ли игрок и если да, то запрашивается подтверждение на продолжение игры.
    Если игрок проиграл, то выводится сообщение "~~~ GAME OVER ~~~" и игра завершается. Затем ждет ввода от пользователя и 
    в зависимости от введенного символа вызывается соответствующая функция для перемещения доски. Если пользователь ввел 'q',
    то игра завершается. Также в конце цикла выводится текущий счет игрока.*/
    display();
    while (1) {
        if (to_win() && !tanong) {
            tanong = !tanong;
            cout << sequence << " steps" << endl;
            cout << "!!!YOU WIN!!!" << endl;
            cout << "Continue? (y/n)" << endl;
            cin >> c;
            if (c == 'n')
                exit(1);
        }
        if (game_over()) {
            cout << "~~~GAME OVER~~~" << endl;
            exit(2);
        }
        cin >> ch;
        switch (ch) {
        case 'w':
            upkey_arrow();
            break;
        case 's':
            downkey_arrow();
            break;
        case 'a':
            leftkey_arrow();
            break;
        case 'd':
            rightkey_arrow();
            break;
        case 'q':
            exit(1);
        default:
            break;
        }

        cout << "score: " << score_board << endl;
    }
    return 0;
}
