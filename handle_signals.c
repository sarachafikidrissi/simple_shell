/**
 * handle - Handles a signal by displaying a prompt.
 * @signals: The signal.
 */
void handle(int signals)
{
	(void) signals;
	write(STDOUT_FILENO, "\nHELL_SHELL>> ", 14);
}
