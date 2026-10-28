#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Song {
    char title[MAX];
    Song *prev;
    Song *next;
};

Song *head = NULL;
Song *tail = NULL;
Song *current = NULL;

void addSong() {
    Song *node = (Song *)malloc(sizeof(Song));

    if (node == NULL) {
        setcolor(RED);
        outtextxy(220, 350, "Memory allocation failed!");
        getch();
        return;
    }

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(180, 100, "ADD A SONG");

    setcolor(WHITE);
    outtextxy(100, 170, "Enter song title in the console window.");
    printf("\nEnter song title: ");
    fflush(stdin);
    gets(node->title);

    node->prev = tail;
    node->next = NULL;

    if (head == NULL) {
        head = tail = node;
        current = node;
    } else {
        tail->next = node;
        tail = node;
    }

    setcolor(LIGHTGREEN);
    outtextxy(220, 250, "Song added successfully!");
    getch();
}

void displaySongs() {
    Song *temp = head;
    int y = 120;
    char line[80];
    int number = 1;

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(220, 50, "YOUR PLAYLIST");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    setcolor(WHITE);

    if (temp == NULL) {
        outtextxy(220, 150, "Playlist is empty.");
    }

    while (temp != NULL && y < getmaxy() - 40) {
        sprintf(line, "%d. %s", number, temp->title);
        if (temp == current)
            setcolor(LIGHTGREEN);
        else
            setcolor(WHITE);
        outtextxy(100, y, line);
        y += 30;
        number++;
        temp = temp->next;
    }

    setcolor(YELLOW);
    outtextxy(100, getmaxy() - 25, "Press any key to return...");
    getch();
}

void searchSong() {
    char name[MAX];
    Song *temp = head;
    int found = 0;

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(220, 100, "SEARCH SONG");

    printf("\nEnter song title to search: ");
    fflush(stdin);
    gets(name);

    while (temp != NULL) {
        if (strcmpi(temp->title, name) == 0) {
            current = temp;
            found = 1;
            break;
        }
        temp = temp->next;
    }

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    if (found) {
        setcolor(LIGHTGREEN);
        outtextxy(170, 220, "Song found and selected!");
    } else {
        setcolor(RED);
        outtextxy(170, 220, "Song not found.");
    }
    getch();
}

void deleteSong() {
    char name[MAX];
    Song *temp = head;

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 100, "DELETE SONG");

    printf("\nEnter song title to delete: ");
    fflush(stdin);
    gets(name);

    while (temp != NULL && strcmpi(temp->title, name) != 0)
        temp = temp->next;

    if (temp == NULL) {
        setcolor(RED);
        outtextxy(200, 220, "Song not found.");
    } else {
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;

        if (current == temp)
            current = (temp->next != NULL) ? temp->next : temp->prev;

        free(temp);
        setcolor(LIGHTGREEN);
        outtextxy(200, 220, "Song deleted successfully!");
    }

    if (head == NULL)
        tail = current = NULL;

    getch();
}

void nextSong() {
    if (current != NULL && current->next != NULL)
        current = current->next;

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(230, 100, "NEXT SONG");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    if (current != NULL) {
        setcolor(LIGHTGREEN);
        outtextxy(170, 220, "Current song:");
        outtextxy(300, 220, current->title);
    } else {
        setcolor(WHITE);
        outtextxy(220, 220, "Playlist is empty.");
    }
    getch();
}

void previousSong() {
    if (current != NULL && current->prev != NULL)
        current = current->prev;

    cleardevice();
    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 100, "PREVIOUS SONG");

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    if (current != NULL) {
        setcolor(LIGHTGREEN);
        outtextxy(170, 220, "Current song:");
        outtextxy(300, 220, current->title);
    } else {
        setcolor(WHITE);
        outtextxy(220, 220, "Playlist is empty.");
    }
    getch();
}

void showButton(int x, int y, int w, int h, char label[], int color) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + w, y + h);
    setcolor(WHITE);
    rectangle(x, y, x + w, y + h);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(x + 15, y + 12, label);
}

void drawMenu() {
    cleardevice();
    setbkcolor(BLACK);

    setcolor(CYAN);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(120, 25, "MUSIC PLAYLIST MANAGER");

    setcolor(LIGHTGRAY);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(205, 65, "Doubly Linked List Project");

    setcolor(BLUE);
    rectangle(35, 95, getmaxx() - 35, getmaxy() - 65);

    showButton(75, 125, 190, 40, "1. Add Song", BLUE);
    showButton(315, 125, 190, 40, "2. Display Playlist", MAGENTA);
    showButton(75, 185, 190, 40, "3. Search Song", CYAN);
    showButton(315, 185, 190, 40, "4. Delete Song", RED);
    showButton(75, 245, 190, 40, "5. Previous Song", GREEN);
    showButton(315, 245, 190, 40, "6. Next Song", BROWN);

    setcolor(YELLOW);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(125, 315, "Press key 1-6 to select an option");
    outtextxy(205, 340, "Press 0 to exit");

    setcolor(WHITE);
    outtextxy(70, getmaxy() - 45, "Current song:");
    if (current != NULL)
        outtextxy(180, getmaxy() - 45, current->title);
    else
        outtextxy(180, getmaxy() - 45, "None");
}

void freePlaylist() {
    Song *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = current = NULL;
}

int main() {
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    if (graphresult() != grOk) {
        printf("Graphics driver could not be initialized.\n");
        printf("Check the BGI path in initgraph().\n");
        getch();
        return 1;
    }

    do {
        drawMenu();
        choice = getch();

        switch (choice) {
            case '1': addSong(); break;
            case '2': displaySongs(); break;
            case '3': searchSong(); break;
            case '4': deleteSong(); break;
            case '5': previousSong(); break;
            case '6': nextSong(); break;
            case '0': break;
            default:
                cleardevice();
                setcolor(RED);
                outtextxy(180, 200, "Invalid option. Press any key.");
                getch();
        }
    } while (choice != '0');

    freePlaylist();
    closegraph();
    return 0;
}
