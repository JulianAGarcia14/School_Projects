#include <stdio.h>

void get_letter_freq(char *txt, int *letter)
{
	/* please write down your code */
	int i = 0;
	for (i = 0; txt[i] != '\0'; i++)
	{
		if (isupper(txt[i]))
			++letter(txt[i] - 'A');
		else ()
			++letter(txt[i] - 'a');

			//if (isalpha(*txt))
				//++letter(tolower)
	}

}
void print_letter_freq(int *letter)
{
	/* please write down your code */
	for (i = 0; i < 26; i++)
	{				      //*(letter + i)
		printf("%c is %d\n", 'a' + i, letter[i])

	}

}


int main(void)
{
	char *getty = "Four score and seven years ago our fathers
	brought forth on this continent, a new nation, conceived in Liberty,
	and dedicated to the proposition that all men are created equal.";
	int letter[26] = {0};
	/* init to zero */
	get_letter_freq(getty, letter);
	print_letter_freq(letter);

	return 0;
}
