#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// enum med alle shapes
typedef enum { ROCK, SCISSORS, LIZARD, SPOCK, PAPER, SHAPE_COUNT } Shape;

// array med emojis til shapes
const char *SHAPE_STRINGS[] = {"🪨", "✂️", "🦎", "🖖", "🗒️"};

// vinder score
const int WINNING_SCORE = 5;

int main(void) {
    char menuChoice[10];
    int playerScore = 0;
    int agentScore = 0;

    // random tal generator
    srand(time(NULL));

    // start menu
    printf("Welcome to 🪨 ✂️ 🗒️ 🖖 🦎 !\n");
    printf("(s) Single player\n");
    printf("(e) Exit\n");

    // læser menu valg
    scanf(" %9s", menuChoice);

    if (strcmp(menuChoice, "e") == 0) {
        return 0; // exit program
    } else if (strcmp(menuChoice, "s") != 0) {
        printf("❌ Invalid menu choice. Exiting...\n");
        return 0;
    }

    printf("Starting game 🎉\n");

    // spil loop
    while (1) {
        int player, agent;

        printf("\nSelect a shape:\n");
        printf("0🪨  || 1✂️  || 2🦎  || 3🖖  || 4🗒️ : ");

        if (scanf("%d", &player) != 1 || player < 0 || player >= SHAPE_COUNT) {
            printf("❌ Invalid shape. Try again.\n");
            // fjerner input buffer
            int c;
            while ((c = getchar()) != '\n');
            continue;
        }

        // agent vælger random shape
        agent = rand() % SHAPE_COUNT;

        // print begge valg
        printf("You: %s  vs  Agent: %s\n", SHAPE_STRINGS[player], SHAPE_STRINGS[agent]);

        // tjek vinder
        if (player == agent) {
            printf("Result: Tie!\n");
        // jeg benytter dette i stedet for +1/+3 vinder fordi den metode drillede lidt for mig ift. resultater
        } else if (
            (player == ROCK && (agent == SCISSORS || agent == LIZARD)) ||
            (player == SCISSORS && (agent == PAPER || agent == LIZARD)) ||
            (player == LIZARD && (agent == SPOCK || agent == PAPER)) ||
            (player == SPOCK && (agent == SCISSORS || agent == ROCK)) ||
            (player == PAPER && (agent == ROCK || agent == SPOCK))
        ) {
            printf("Result: You win this round!\n");
            playerScore++;
        } else {
            printf("Result: Agent wins this round!\n");
            agentScore++;
        }

        // print score
        printf("👫:%d 🤖:%d\n", playerScore, agentScore);

        // check for vinder
        if (playerScore >= WINNING_SCORE) {
            printf("🎉 You won the game!\n");
            break;
        } else if (agentScore >= WINNING_SCORE) {
            printf("🤖 Agent won the game!\n");
            break;
        }
    }

    return 0;
}
