static char *expected;
#if MULTI_SELECTION_PATCH
void
expect(char *expect, XKeyEvent *ev)
{
	if (sel && expected && strstr(expected, expect)) {
		if (expected && sel && !(ev->state & ShiftMask))
			puts(expect);
		printselected(ev->state);
		cleanup();
		exit(1);
	} else if (!sel && expected && strstr(expected, expect)) {
		puts(expect);
		cleanup();
		exit(1);
	}
}
#else
void
expect(char *expect, XKeyEvent *ignored)
{
	if (sel && expected && strstr(expected, expect)) {
		puts(expect);
		printitem(sel);
		cleanup();
		exit(1);
	} else if (!sel && expected && strstr(expected, expect)){
		puts(expect);
		cleanup();
		exit(1);
	}
}
#endif // MULTI_SELECTION_PATCH
