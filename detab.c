/* Exercise 1-20 */

/*
 * Unfortunately I'm using language elements in here that I'm
 * not supposed to have encountered yet. Oh well :P
 *
 * Also this version is meant to work well with IO redirection /
 * piping. This is an advantage over other implementations of this
 * program that I've come across.
 */

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define TAB_LENGTH      8        /* just use a fixed length for this for now */

int k_and_r_getline(char s[], int lim);
void detab(char line[], int len, int lim);

int main()
{
	int  len;                   /* current line length */
	char line[MAX_LINE_LENGTH]; /* current input line */

	while ((len = k_and_r_getline(line, MAX_LINE_LENGTH)) > 0) {
		detab(line, len, MAX_LINE_LENGTH);
		printf("%s\n", line);
		/* printf("%i\n", len); */
	}

	/*
	 * printf("%s\n", "got out of the main loop");
	 * printf("%i\n", len);
	 */

	return 0;
}

/* k_and_r_getline: read a line into `s', return length */
int k_and_r_getline(char s[], int lim)
{
	memset(s, 0, MAX_LINE_LENGTH);

	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}

/* detab: replaces hard tabs with spaces from a given line */
void detab(char line[], int len, int lim)
{
	int pos_in_line     = 0; /* position used to seek through the line */
	int pos_to_tab_stop = 0; /* position in relation to next tab stop */
	int end_of_line     = 0; /* used for shifting array elements when a tab is found */
	int tmp             = 0; /* placeholder for modifying the line later */
	int tab_width       = 0; /* how many chars long our tab will be */

	for (; pos_in_line < len && pos_in_line < lim - 1; ++pos_in_line) {
		/* Uncomment to track some counters: */

		/*
		 * printf("%s\n", "---");
		 * printf("%s%d\n", "pos_in_line:     ", pos_in_line);
		 * printf("%s%d\n", "pos_to_tab_stop: ", pos_to_tab_stop);
		 */

		if (pos_to_tab_stop % TAB_LENGTH == 0 && pos_to_tab_stop != 0) {
			pos_to_tab_stop = 0;
		}

		if (line[pos_in_line] == '\t') {
			/* printf("%s\n", "***"); */
			tab_width       = TAB_LENGTH - pos_to_tab_stop;
			pos_to_tab_stop = 0;
			end_of_line     = len - 1;

			if (len + tab_width < lim - 1) {
				len += tab_width - 1;
			}

			/* Uncomment to see what the program thinks the current tab's width is: */

			/*
			 * printf("%s%d\n", "width of this tab:   ", tab_width);
			 * printf("%s%i\n", "len:                 ", len);
			 * printf("%s%i\n", "lim:                 ", lim);
			 */

			while (end_of_line >= pos_in_line) {
				if (line[end_of_line] == '\n')
					goto done;


				line[end_of_line + tab_width - 1] = line[end_of_line];

				/* Track which chars get shifted and to where: */

				/*
				 * printf("%s%x\n", "char that was moved: 0x", line[end_of_line + tab_width - 1]);
				 * printf("%s%d\n", "old char position:   ", end_of_line);
				 * printf("%s%d\n", "new char position:   ", end_of_line + tab_width - 1);
				 */

			done:
				--end_of_line;
			}

			tmp = pos_in_line;
			while (tmp < pos_in_line + tab_width) {
				line[tmp] = ' ';
				++tmp;
			}

			/* printf("%s\n", "***"); */
		}

		pos_to_tab_stop += 1;
	}

	line[lim - 1] = '\0';
}