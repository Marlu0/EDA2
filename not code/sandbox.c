#include <stdio.h>
#include <string.h>

typedef struct
{
  char name[20];
  char drawing[500];
}Model;

Model box = {"Box", "┌─────────┐\n│         │\n└─────────┘\n"};
Model lizard = {"Cowboy Lizard","               _____\n              |     |\n            \\_|_____|_/     /|\n            .'()..()`.    / /\n           ( `-.__.-' )  ( (\n            \\        /    \\ \\\n             \\      /      ) )\n           .' -.__.- `.-.-'_.'\n         .'  /-____-\\  `.-'\n         \\  /-.____.-\\  /-.\n          \\ \\`-.__.-'/ /\\|\\|\n         .'  `.    .'  `.\n         |/\\/\\|    |/\\/\\|\n\n"};

int main(){
    printf("┌─────────┐\n"); //basic block design.
    printf("│         │\n");
    printf("└─────────┘\n\n");

    printf("%s:\n", box.name);
    printf("%s\n\n", box.drawing);

    printf("%s:\n", lizard.name);
    printf("%s\n\n", lizard.drawing);
    return 0;
}