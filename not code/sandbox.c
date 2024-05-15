#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[20];
  char drawing[5000];
}Model;

Model box = {"Box", "┌─────────┐\n│         │\n└─────────┘\n"};
Model lizard = {"Cowboy Lizard","               _____\n              |     |\n            \\_|_____|_/     /|\n            .'()..()`.    / /\n           ( `-.__.-' )  ( (\n            \\        /    \\ \\\n             \\      /      ) )\n           .' -.__.- `.-.-'_.'\n         .'  /-____-\\  `.-'\n         \\  /-.____.-\\  /-.\n          \\ \\`-.__.-'/ /\\|\\|\n         .'  `.    .'  `.\n         |/\\/\\|    |/\\/\\|\n\n"};
Model snake = {"hello", "           _____\n          |$    |\n        \\_|_____|_/\n           /^\\/^\\\n         _|__|  O|\n\\/     /~     \\_/ \\\n \\____|__________/ \\\n        \\_______    \\\n                `\\   \\                       \\\n                 /    )                       \\\n               /     /                         \\\n             /     /                           \\ \\\n           /     /             _------_         \\  \\\n         (      (        _-~    _--_    ~-_    _/  |\n          \\      ~-____-~    _-~    ~-_    ~-_-~   /\n            ~-_           _-~          ~-_      _-~\n               ~--______-~                ~-__-~\n\n"};


int main() {
    printf("┌─────────┐\n"); //basic block design.
    printf("│         │\n");
    printf("└─────────┘\n\n");

    printf("%s:\n", box.name);
    printf("%s\n\n", box.drawing);

    printf("%s:\n", lizard.name);
    printf("%s\n\n", lizard.drawing);

    printf("%s:\n", snake.name);
    printf("%s\n\n", snake.drawing);

    return 0;
}