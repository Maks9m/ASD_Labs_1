#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main()
{
  int a, b;
  int x = 0, y = 0;
  int row = 0, column = 0;
  int counter = 0;
  initscr();
  getmaxyx(stdscr, a, b);

  mvaddch(0, 0, '1');
  refresh();
  usleep(10000);

  while (row < a - 1 || column < b - 1)
  {
    if (column < b - 1 && x < a)
    {
      // Move up along the column direction
      if (x < a - 1)
      {
        mvaddch(x, column, '1');
        refresh();
        usleep(10000);

        // Draw diagonal in the up direction
        counter = x - row;
        for (int j = 0; j <= counter; j++)
        {
          mvaddch(x - j, column + j, '1');
          refresh();
          usleep(10000);
        }
        if(x < a - 1)
        {
          x += 1;
        }
        else
        {
          column += 1;
        }
      }
      else
      {
        mvaddch(x, column, '1');
        refresh();
        usleep(10000);

        // Draw diagonal in the up direction
        counter = y - column;
        for (int j = 0; j <= counter; j++)
        {
          mvaddch(x - j, column + j, '1');
          refresh();
          usleep(10000);
        }
        column += 1;
      }
    }

    if (row < a - 1 && y < b)
    {
      // Move down along the row direction
      if (y < b - 1)
      {
        mvaddch(row, y, '1');
        refresh();
        usleep(10000);
        // Draw diagonal in the down direction
        counter = y - column;
        for (int i = 0; i <= counter; i++)
        {
          mvaddch(row + i, y - i, '1');
          refresh();
          usleep(10000);
        }
        if(y < b - 1 )
        {
          y += 1;
        }
        else
        {
          row += 1;
        }
      }
      else
      {
        mvaddch(row, y, '1');
        refresh();
        usleep(10000);
        // Draw diagonal in the down direction
        counter = x - row;
        for (int i = 0; i <= counter; i++)
        {
          mvaddch(row + i, y - i, '1');
          refresh();
          usleep(10000);
        }
        row += 1;
      }
    }
  }

  getch();
  endwin();
  return 0;
}

//gcc program.c  -o program -lncurses