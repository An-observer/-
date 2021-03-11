#include<iostream>

using namespace std;

const int maxSize = 10;

typedef struct
{
	char str[maxSize + 1];
	int length;
}Str;

typedef struct
{
	char* ch;
	int length;
}Str;

bool strassign(Str& str, char* ch)
{
	if (str.ch)
		delete(str.ch);
	int len = 0;
	char* c = ch;
	while (*c)
	{
		++len;
		++c;
	}
	if (len == 0)
	{
		str.ch = NULL;
		str.length = 0;
		return true;
	}
	else
	{
		str.ch = new char[len + 1];
		if (str.ch == NULL)
			return 0;
		else
		{
			c = ch;
			for (int i = 0; i <= len; i++, c++)
			{
				str.ch[i] = *c;
			}
			str.length = len;
			return true;
		}
	}
}

int main()
{

	return 0;
}