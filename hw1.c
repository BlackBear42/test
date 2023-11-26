#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int rows, cols;
int temp = 0;
// 修改 openmap 函数，使其返回指向 int 数组的指针
int **openmap()
{
    int level;
    char filename[100] = {0};
    FILE *fp;

    while (1)
    {
        system("cls");
        printf("Select a play level: ");
        scanf("%d", &level);

        if (level == 1 || level == 2 || level == 3)
            sprintf(filename, "map%d.txt", level);

        fp = fopen(filename, "r");

        if (fp != NULL)
            break;

        system("cls");
        printf("No such level found\n");
        printf("Press any key to continue . . .");
        _getch();
    }
    system("cls");
    fscanf(fp, "%d %d", &rows, &cols);

    int **map = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++)
    {
        map[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            fscanf(fp, "%d", &map[i][j]);
        }
    }

    return map;
}

// 创建函数，复制矩阵的值到新的矩阵
int **copyMatrix(int **original, int rows, int cols)
{
    int **copy = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        copy[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
        {
            copy[i][j] = original[i][j];
        }
    }
    return copy;
}

int **PlayerMove(int **before, int instruction, int iplayer, int jplayer)
{

    if (instruction == 72) // 上
    {
        if (before[iplayer - 1][jplayer] == 0) // 撞到空地
        {
            before[iplayer - 1][jplayer] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
        }
        else if (before[iplayer - 1][jplayer] == 3) // 撞到箱子
        {
            if (before[iplayer - 2][jplayer] == 0)
            {
                before[iplayer - 2][jplayer] = 3;
                before[iplayer - 1][jplayer] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
            else if (before[iplayer - 2][jplayer] == 2)
            {
                before[iplayer - 2][jplayer] = 5;
                before[iplayer - 1][jplayer] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
        }
        else if (before[iplayer - 1][jplayer] == 2) // 撞到終點
        {
            before[iplayer - 1][jplayer] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
            temp = 1;
        }
    }
    else if (instruction == 80) // 下
    {
        if (before[iplayer + 1][jplayer] == 0) // 撞到空地
        {
            before[iplayer + 1][jplayer] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
        }
        else if (before[iplayer + 1][jplayer] == 3) // 撞到箱子
        {
            if (before[iplayer + 2][jplayer] == 0)
            {
                before[iplayer + 2][jplayer] = 3;
                before[iplayer + 1][jplayer] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
            else if (before[iplayer + 2][jplayer] == 2)
            {
                before[iplayer + 2][jplayer] = 5;
                before[iplayer + 1][jplayer] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
        }
        else if (before[iplayer + 1][jplayer] == 2) // 撞到終點
        {
            before[iplayer + 1][jplayer] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
            temp = 1;
        }
    }
    else if (instruction == 75) // 左
    {
        if (before[iplayer][jplayer - 1] == 0) // 撞到空地
        {
            before[iplayer][jplayer - 1] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
        }
        else if (before[iplayer][jplayer - 1] == 3) // 撞到箱子
        {
            if (before[iplayer][jplayer - 2] == 0)
            {
                before[iplayer][jplayer - 2] = 3;
                before[iplayer][jplayer - 1] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
            else if (before[iplayer][jplayer - 2] == 2)
            {
                before[iplayer][jplayer - 2] = 5;
                before[iplayer][jplayer - 1] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
        }
        else if (before[iplayer][jplayer - 1] == 2) // 撞到終點
        {
            before[iplayer][jplayer - 1] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
            temp = 1;
        }
    }
    else if (instruction == 77) // 右
    {
        if (before[iplayer][jplayer + 1] == 0) // 撞到空地
        {
            before[iplayer][jplayer + 1] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
        }
        else if (before[iplayer][jplayer + 1] == 3) // 撞到箱子
        {
            if (before[iplayer][jplayer + 2] == 0)
            {
                before[iplayer][jplayer + 2] = 3;
                before[iplayer][jplayer + 1] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
            else if (before[iplayer][jplayer + 2] == 2)
            {
                before[iplayer][jplayer + 2] = 5;
                before[iplayer][jplayer + 1] = 4;
                if (temp == 0)
                {
                    before[iplayer][jplayer] = 0;
                }
                else if (temp == 1)
                {
                    before[iplayer][jplayer] = 2;
                    temp = 0;
                }
            }
        }
        else if (before[iplayer][jplayer + 1] == 2) // 撞到終點
        {
            before[iplayer][jplayer + 1] = 4;
            if (temp == 0)
            {
                before[iplayer][jplayer] = 0;
            }
            else if (temp == 1)
            {
                before[iplayer][jplayer] = 2;
                temp = 0;
            }
            temp = 1;
        }
    }
    return before;
}

int main()
{
    while (1)
    {
        printf("*****Welcome to Sokoban Game*****\n"
               "You can move the character up, down, left, and right through the direction keys\n\n"
               "Press any key to continue . . .");
        _getch();

        int **world = openmap();
        int oriplayer, orjplayer;
        int iplayer, jplayer;
        int finish = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (world[i][j] == 4)
                {
                    oriplayer = i;
                    orjplayer = j;
                }
            }
        }

        // 创建新的矩阵，复制原始矩阵的值
        int **resultworld = copyMatrix(world, rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                char words;
                if (resultworld[i][j] == 0)
                {
                    printf(" ");
                }
                else if (resultworld[i][j] == 1)
                {
                    printf("W");
                }
                else if (resultworld[i][j] == 2)
                {
                    printf("D");
                }
                else if (resultworld[i][j] == 3)
                {
                    printf("o");
                }
                else if (resultworld[i][j] == 4)
                {
                    printf("P");
                }
                else if (resultworld[i][j] == 5)
                {
                    printf("X");
                }
            }
            printf("\n");
        }

        while (1)
        {
            printf("Use the arrow keys to control the character\n");
            printf("Use the R button to restart this game\n");

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (resultworld[i][j] == 4)
                    {
                        iplayer = i;
                        jplayer = j;
                    }
                    if (resultworld[i][j] == 3)
                    {
                        finish++;
                    }
                }
            }
            if (finish == 0)
                break;
            else
            {
                finish = 0;
            }
            int key;
            key = _getch();
            if (key == 224)
            {
                key = _getch();
                system("cls");
                resultworld = PlayerMove(resultworld, key, iplayer, jplayer);
            }
            else if (key == 114 || key == 82)
            {
                system("cls");
                resultworld = copyMatrix(world, rows, cols);
                temp = 0;
            }
            else
            {
                system("cls");
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    char words;
                    if (resultworld[i][j] == 0)
                    {
                        printf(" ");
                    }
                    else if (resultworld[i][j] == 1)
                    {
                        printf("W");
                    }
                    else if (resultworld[i][j] == 2)
                    {
                        printf("D");
                    }
                    else if (resultworld[i][j] == 3)
                    {
                        printf("o");
                    }
                    else if (resultworld[i][j] == 4)
                    {
                        printf("P");
                    }
                    else if (resultworld[i][j] == 5)
                    {
                        printf("X");
                    }
                }
                printf("\n");
            }
        }
        printf("Congratulations on passing the level~\n");
        printf("Do you want to continue playing? (Y/n)\n");
        while (1)
        {
            int key;
            key = _getch();
            if (key == 224)
                key = _getch();
            if (key == 121 || key == 89)
            {
                system("cls");
                break;
            }
            else if (key == 110 || key == 78)
            {
                return 0;
            }
            else
            {
                printf("Do you want to continue playin (Y/n)\n");
            }
        }
    } // 213213
    return 0;
}