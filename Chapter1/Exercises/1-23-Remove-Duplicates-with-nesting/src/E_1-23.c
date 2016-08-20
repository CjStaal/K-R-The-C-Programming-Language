#include <stdio.h>

void remcomments(char s[]);

int main(int argc, char *argv[])
{
	/*ALL THE EDGE CASES!*/
	char info[] = "\t\t\ntest();/*\n*/test2();\n   		\nprintf(/*test*/\"\\\"test\n\t/*iello*/  //more\"/*test*/);/*hello*/ //hello();//test\n/*test*/\ncode(yeah);//test\n//Hello/*hellooo\nmorecode();/*test*/\ncode(/*test*/yeah);/*\n*\n*\n*/\n//\n/*test*/test();\n/*test8*/\nyeah();\n\t\t\ntest();";
	printf("\n\nTEST:\n%s", info);
	remcomments(info);
	printf("\n\nOUTPUT:\n%s", info);
	return 0;

}

void remcomments(char s[])
{
	int slcflag, mlcflag, qflag, scflag, readindex, writeindex, charcount, whitespace;
	slcflag = mlcflag = qflag = scflag = readindex = writeindex = charcount = whitespace = 0;
	while (s[readindex] != '\0')
	{
		charcount++;
		if(s[readindex] == ' ' || s[readindex] == '\t' || s[readindex] == '\n')
			whitespace++;
		if (slcflag == 1 && s[readindex] == '\n')
			slcflag = 0;
		if (mlcflag == 1 && s[readindex - 1] == '*' && s[readindex] == '/')
		{
			mlcflag = 0;
		}
		else if (mlcflag == 0)
		{
			if (s[readindex] == '"' && (s[readindex - 1] != '\\' || (s[readindex - 1] == '\\' && s[readindex - 2] == '\\')))
				if (qflag == 0) qflag = 1;
				else qflag = 0;
			else if (qflag == 0 && slcflag == 0 && mlcflag == 0)
			{
				if(s[readindex - 1] == ';' && (s[readindex] == ' ' || s[readindex] == '\t'))
					scflag = 1;
				if (s[readindex] == '/' && s[readindex + 1] == '/')
				{
					readindex++;
					slcflag = 1;
				}
				if (s[readindex] == '/' && s[readindex + 1] == '*')
				{
					readindex++;
					mlcflag = 1;
				}
				if(s[readindex] == '\n')
					scflag = 0;
			}                                                   /*VVV this stops us from reading from a "negative" index and from writing blank lines VVV*/
			if (scflag == 0 && slcflag == 0 && mlcflag == 0 && (s[readindex] != '\n' || (s[readindex] == '\n' && writeindex != 0 && s[writeindex - 1] != '\n')))
			{
				if(s[writeindex - 1] == ';' && s[readindex] != '\n' && s[readindex] != '\t' && s[readindex] != ' ')
					s[writeindex++] = '\n';
				s[writeindex] = s[readindex];
				writeindex++;
			}
		}
		if(s[readindex] == '\n')
		{
			if(whitespace == charcount)
				writeindex -= whitespace;
			charcount = whitespace = 0;
		}
		readindex++;
	}
	s[writeindex] = '\0';
}
