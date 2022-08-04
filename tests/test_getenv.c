int main (int ac, char **env)
{
	char *res = _getenv(env);

	(void) ac;
	printf("%s\n", res);

	return (0);
}
