/**
 * @file rock-spock.c
 * @author Julian Garcia
 * @date 10/1/2018
 * @brief Play Rock-paper-scissors-lizard-Spock against the machine
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define COMPUTER 8088
#define PLAYER 1000

#define TIE 1001

#define CHOICES 5

#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

void move(int who, int move);
int winner(int computer, int player);
void print_winner(int win, int comp_move, int player_move);
int nrand(int range);
void seed();


int main(void)
{
	int computer;
	int player;
	int win;

	/* set up the seed value for the random number generator */
	/* call only once */
	seed();

        while (player != 5) {
		printf("Enter a move:\n");
		printf("0 for ROCK\n");
		printf("1 for PAPER\n");
		printf("2 for SCISSORS\n");
		printf("3 for LIZARD\n");
		printf("4 for SPOCK\n");
		printf("5 to have SPOCK eat a ROCK while chasing a LIZARD and quit\n");
		printf("Move: ");
		scanf("%d", &player);

		if (player != 0 && player != 1 && player != 2 && player != 3 && player != 4 && player != 5) {
			printf("That is not an option!\n");
			return 2;
		} else if (player == 5) {

			return 2;
		}

        	/* debug -- you don't need move() to play game  */
		move(PLAYER, player);

        	/* generate random number for computers play */
		computer = nrand(CHOICES);

		/*debug -- you don't need this to play the game */
		move(COMPUTER, computer);

		int comp_move = computer;
		int player_move = player;

        	win = winner(computer, player);

		print_winner(win, comp_move, player_move);

	}
	return 0;
}


/** prints the player's or computer's  move to stdin
 * used in debugging
 * @param who is it the computer or the player's move?
 * @param move what move did they make
 * @return void
 */
void move(int who, int move)
{
	if (who == COMPUTER)
		printf("Computer's play is ");
	else
		printf("Player's play is ");


	switch(move) {
	case ROCK:
		printf("ROCK\n");
		break;
	case PAPER:
		printf("PAPER\n");
		break;
	case SCISSORS:
		printf("SCISSORS\n");
		break;
	case SPOCK:
		printf("SPOCK\n");
		break;
	case LIZARD:
		printf("LIZARD\n");
		break;
    	}

}


/**
 * determines the winner either COMPUTER or PLAYER
 * @param computer the computer's move
 * @param player the player's move
 * @return the winner of the game
 */
int winner(int computer, int player)
{
	int winner;

	switch(computer) {
	case ROCK:
		if (player == PAPER || player == SPOCK) {
			winner = PLAYER;
		} else if (player == ROCK) {
			winner = TIE;
		} else {
			winner = COMPUTER;
		}
		break;
	case PAPER:
		if (player == LIZARD || player == SCISSORS) {
			winner = PLAYER;
		} else if (player == PAPER) {
			winner = TIE;
		} else {
			winner = COMPUTER;
		}
		break;
	case SCISSORS:
		if (player == SPOCK || player == ROCK) {
			winner = PLAYER;
		} else if (player == SCISSORS) {
			winner = TIE;
		} else {
			winner = COMPUTER;
		}
		break;
	case SPOCK:
		if (player == PAPER || player == LIZARD) {
			winner = PLAYER;
		} else if (player == SPOCK) {
			winner = TIE;
		} else {
			winner = COMPUTER;
		}
		break;
	case LIZARD:
		if (player == ROCK || player == SCISSORS) {
			winner = PLAYER;
		} else if (player == LIZARD) {
			winner = TIE;
		} else {
			winner = COMPUTER;
		}
		break;
	}


	return winner;
}

/**
 * prints the winner of the game to stdin
 * @param winner who won the computer or player
 * @param comp_move what move did the computer make
 * @param play_move what move did the player make
 * @return void
 */
void print_winner(int win, int comp_move, int player_move)
{

	if (win == PLAYER) {
		printf("Player Wins!\n");
	} else if (win == TIE) {
		printf("It's a Tie!\n");
	} else {
		printf("Computer Wins!\n");
	}

	switch(comp_move) {
	case ROCK:
		if (player_move == PAPER) {
			printf("Paper Covers Rock\n");
		} else if (player_move == ROCK) {
			printf("Rock can't beat rock\n");
		} else if (player_move == SPOCK){
			printf("Spock Vaporizes Rock\n");
		} else if (player_move == LIZARD) {
			printf("Rock crushes lizard\n");
		} else if (player_move == SCISSORS) {
			printf("Rock crusches scissors\n");
		}
		break;
	case PAPER:
		if (player_move == PAPER) {
			printf("Paper Can't beat paper\n");
		} else if (player_move == ROCK) {
			printf("Paper Covers Rock\n");
		} else if (player_move == SPOCK){
			printf("Paper Disproves Spock\n");
		} else if (player_move == LIZARD) {
			printf("Lizard Eats Paper\n");
		} else if (player_move == SCISSORS) {
			printf("Scissors Cuts Paper\n");
		}
		break;
	case SCISSORS:
		if (player_move == PAPER) {
			printf("Scissors cuts paper\n");
		} else if (player_move == ROCK) {
			printf("Rock smashes scissors\n");
		} else if (player_move == SPOCK){
			printf("Spock smashes scissors\n");
		} else if (player_move == LIZARD) {
			printf("Scissors Decapitates Lizard\n");
		} else if (player_move == SCISSORS) {
			printf("Scissors can't beat scissors\n");
		}
		break;
	case SPOCK:
		if (player_move == PAPER) {
			printf("Paper disproves spock\n");
		} else if (player_move == ROCK) {
			printf("Spock Vaporizes Rock\n");
		} else if (player_move == SPOCK){
			printf("That's illogical\n");
		} else if (player_move == LIZARD) {
			printf("Lizard Poisons Spock\n");
		} else if (player_move == SCISSORS) {
			printf("Spock Smashes scissors\n");
		}
		break;
	case LIZARD:
		if (player_move == PAPER) {
			printf("Lizard eats Paper\n");
		} else if (player_move == ROCK) {
			printf("Rock crushes lizard\n");
		} else if (player_move == SPOCK){
			printf("Lizard poisons spock\n");
		} else if (player_move == LIZARD) {
			printf("Lizards love each other\n");
		} else if (player_move == SCISSORS) {
			printf("Scissors decapitates lizard\n");
		}
		break;
	}
	printf("\n\n");
}

/**
 * returns a uniform random integer n, between 0 <= n < range
 * @param range defines the range of the random number [0,range)
 * @return the generated random number
 */
int nrand(int range)
{
	return rand() % range;
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch
 * call once before using nrand and similar functions that call rand()
 */
void seed(void)
{
  	srand((unsigned int)time(NULL));
}
