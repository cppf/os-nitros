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


// Find substring of a string
#define string_Substring3(dst, src, start)	\
mem_Copy(dst, (src)+(start), string_Length((src)+(start)))
	
#define string_Substring4(dst, src, start, stop)	\
mem_Copy(dst, (src)+(start), (stop)-(start))

#define string_Substring(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, string_Substring4, string_Substring3)(__VA_ARGS__))


// Remove part of a string
#define string_Remove2(str, start)	\
(*(((char*)(str))+(start)) = '\0')

#define string_Remove3(str, start, stop)	\
mem_Copy((str)+(start), (src)+(stop), string_Length((str)+(stop)))

#define string_Remove(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, string_Remove3, string_Remove2)(__VA_ARGS__))


// Gives first index of a character in string
uword string_IndexOfChar(string str, char chr);
uword string_IndexOfChar(string str, char chr)
{
	for(uword indx = 0; *str; str++, indx++)
	{
		if(*str == chr)
		return indx;
	}
	return -1;
}

#define	string_FindChar		string_IndexOf


// Gives the index of first appearance of a character
// from a given string of characters in a string
uword string_IndexOfChars(string str, char* chr);
uword string_IndexOfChars(string str, char* chr)
{
	for(uword indx = 0; *str; str++, indx++)
	{
		if(string_IndexOfChar(chr, *str) != -1)
		return indx;
	}
	return -1;
}

#define	string_FindChars		string_IndexOfChars


// Gives the index of a string in another string
uword string_IndexOf(string str, string srch_str);
uword string_IndexOf(string str, string srch_str)
{
	char *sptr, *pptr;
	for(uword indx = 0; *str; str++, indx++)
	{
		if(*str != *srch_str) continue;
		for(sptr = str + 1, pptr = srch_str + 1; (*pptr) && (*sptr == *pptr); sptr++, pptr++);
		if(*pptr == '\0') return indx;
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


#endif /* _TYPE_STRING_H_ */