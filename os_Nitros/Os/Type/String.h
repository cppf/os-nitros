#ifndef _TYPE_STRING_H_
#define _TYPE_STRING_H_


// Definition
typedef char*	string;


// Functions
#define	string_Length		strlen
#define	string_Compare		strcmp
#define	string_ToLower		strlwr
#define	string_ToUpper		strupr
#define string_Copy			strcpy
#define string_Reverse		strrev
#define string_Concat		strcat


// Checks string equality
#define	string_Equals(str1, str2)	\
	(!string_Compare(str1, str2))


// Gives first index of a character in string
int	string_IndexOfChar(string str, char chr);
int	string_IndexOfChar(string str, char chr)
{
	for(char* sptr = str; *sptr; sptr++)
	{
		if(*sptr == chr)
		{ return (int)(sptr - str); }
	}
	return -1;
}

#define	string_FindChar		string_IndexOf


// Gives the index of first appearance of a character
// from a given string of characters in a string
int	string_IndexOfChars(string str, char* chr);
int	string_IndexOfChars(string str, char* chr)
{
	for(char* sptr = str; *sptr; sptr++)
	{
		if(string_IndexOfChar(chr, *sptr) >= 0)
		{ return (int)(sptr - str); }
	}
	return -1;
}

#define	string_FindChars		string_IndexOfChars


// Gives the index of a string in another string
int	string_IndexOf(string str, string srch_str);
int	string_IndexOf(string str, string srch_str)
{
	char *sptr, *sptr2, *pptr;
	for(sptr = str; *sptr; sptr++)
	{
		if(*sptr != *srch_str) continue;
		for(sptr2 = sptr + 1, pptr = srch_str + 1; (*pptr) && (*sptr2 == *pptr); sptr2++, pptr++);
		if(*pptr == '\0') return (int)(sptr - str);
	}
	return -1;
}

#define	string_Find		string_IndexOf


// RemoveAt could be added here


// Removes all appearances of a given character in a string
void string_RemoveChar(string str, char chr);
void string_RemoveChar(string str, char chr)
{
	char* sptr;
	for(sptr = str; *str; str++)
	{
		if(*str == chr) continue;
		*sptr = *str;
		sptr++;
	}
	*sptr = '\0';
}


// Remove all appearances of a set of characters from a string
void string_RemoveChars(string str, char* chr);
void string_RemoveChars(string str, char* chr)
{
	char* sptr;
	for(sptr = str; *str; str++)
	{
		if(string_IndexOfChar(chr, *str) >= 0) continue;
		*sptr = *str;
		sptr++;
	}
	*sptr = '\0';
}


// Remove a string from another string
void string_Remove(string str, string rmv_str);
void string_Remove(string str, string rmv_str)
{
	char *sptr, *sptr2, *pptr;
	for(sptr = str; *str; str++)
	{
		if(*str != *rmv_str)
		{
			*sptr = *str;
			sptr++;
			continue;
		}
		for(sptr2 = str + 1, pptr = rmv_str + 1; (*pptr) && (*sptr2 == *pptr); sptr2++, pptr++);
		if(*pptr == '\0') str = sptr2 - 1;
		else
		{
			*sptr = *str;
			sptr++;
		}
	}
	*sptr = '\0';
}


#endif /* _TYPE_STRING_H_ */