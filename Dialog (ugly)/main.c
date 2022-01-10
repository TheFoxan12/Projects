#include "curses.h"
#include "time.h"
#define NANO_SEC_MULTIPLIER 1000000

void wait(int timeInMillisec);

int main() {

    int y;
    int x;
    const int millisecDelay = 175;

    initscr();
    refresh();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_RED);
    WINDOW *window = newwin(5, 15, 5, 5);
    wbkgd(window, COLOR_PAIR(1));
    wrefresh(window);

    waddch(window, 'T');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'h');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'e');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'o');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'p');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'h');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'i');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'l');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, 'e');
    wrefresh(window);
    wait(millisecDelay);

    waddch(window, ' ');
    wrefresh(window);
    wait(500);

    waddch(window, '?');
    wrefresh(window);
    wait(1000);

    WINDOW* window2 = newwin(6, 19, 7, 50);
    wbkgd(window2, COLOR_PAIR(2));
    init_pair(2, COLOR_RED, COLOR_BLUE);
    wrefresh(window2);

    waddch(window2, 'Q');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'u');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, '\'');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'y');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'a');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 't');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'i');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'l');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, '?');
    wrefresh(window2);
    wait(millisecDelay);

    getyx(window, y, x);
    for (int i = x; i >= 0 ; i--){
        wmove(window, y, i);
        wrefresh(window);
        wdelch(window);
        wrefresh(window);
        wait(100);
    }

    waddch(window2, '\n');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'A');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'r');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'r');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 't');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'd');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 's');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'u');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'p');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'p');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'r');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'i');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'm');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'r');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 't');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 's');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'm');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 's');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 's');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'a');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'g');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 'e');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, 's');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, ' ');
    wrefresh(window2);
    wait(millisecDelay);
    waddch(window2, '!');
    wrefresh(window2);
    wait(millisecDelay);

    wait(1000);
    return 0;
}

void wait(int timeInMillisec){
    int timeInSec = 0;
    while (timeInMillisec >= 1000){
        timeInSec += 1;
        timeInMillisec -= 1000;
    }

    struct timespec delta = {timeInSec /*secs*/, timeInMillisec * NANO_SEC_MULTIPLIER /*milliseconds*/};
    nanosleep(&delta, NULL);
}
