//1000ms通过 递归求解效率太低
bool isMatchCore(char * s, char * p)
{
	if (*s == '\0' && *p == '\0') return true;
	if (*s != '\0' && *p == '\0') return false;

	if (*(p + 1) == '*') {
		if (*s == *p || (*p == '.' && *s != '\0')) {
			return isMatchCore(s, p + 2) || isMatchCore(s + 1, p) || isMatchCore(s + 1, p + 2);
		}
		else {
			return isMatchCore(s, p + 2);
		}
	}
	if (*s == *p || (*p == '.' && *s != '\0'))
		return isMatchCore(s + 1, p + 1);
	return false;
}
bool isMatch(char * s, char * p){
	if (s == NULL || p == NULL)
		return false;
	return isMatchCore(s, p);
}

