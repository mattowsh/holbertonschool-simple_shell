int main(void)
{
	char *str = "hola como estas";
	char **argv;
	argv = set_strtok(str);
	free_grid(argv);
}
