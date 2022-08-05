int main(void)
{
	char *str = "holaaaaaaa a a a a a";
	char **ar;
	ar = set_strtok(str);
	for (int i = 0; ar[i]; i++)
		printf("%s\n", ar[i]);
	free_grid(ar);
	return (0);
}
