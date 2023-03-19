#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int isKeyword(char temp[])
{
    char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                             "do", "double", "else", "enum", "extern", "float", "for", "goto",
                             "if", "int", "long", "register", "return", "short", "signed",
                             "sizeof", "static", "struct", "switch", "typedef", "union",
                             "unsigned", "void", "volatile", "while"};
    int i, flag = 0;
    for (i = 0; i < 32; ++i)
    {
        if (strcmp(keywords[i], temp) == 0)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main()
{
    char ch, temp[15], opr[] = "+-*/%=";
    FILE *fp;
    int i, j = 0,count=0;;
    fp = fopen("input_file.txt", "r");
    if (fp == NULL)
    {
        printf("Sorry, cannot open the file!! Try again!\n");
        exit(0);
    }
    while ((ch = fgetc(fp)) != EOF)
    {
        for (i = 0; i < 6; ++i)
        {
            if (ch == opr[i])
                {   printf("%c is an OPERATOR\n", ch);
                    count++;
                }    
        }
        if (isalnum(ch))
        {
            temp[j++] = ch;
        }
        else if ((ch == ' ' || ch == '\n') && (j != 0))
        {
            temp[j] = '\0';
            j = 0;
            if (isKeyword(temp) == 1)
                {   printf("%s is a KEYWORD\n", temp);
                    count++;
                }    
            else
                {   printf("%s is an IDENTIFIER\n", temp);
                    count++;
                }    
        }
    }
    printf("\nThe number of tokens present in the given file are: %d",count);
    fclose(fp);
    return 0;
}