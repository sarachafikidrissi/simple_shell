#include "main.h"
/**
 * handle_signal - Handles a signal ctrl+C by displaying a prompt.
 * @signals: The signal.
 */
void handle_signal(int signals)
{
	(void) signals;
	write(STDOUT_FILENO, "\nHELL_SHELL>> ", 14);
}
