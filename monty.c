#include "monty.h"

bool is_numeric(const char *str)
{
    if (str == NULL || *str == '\0')
        return false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue; 

	if (str[i] < '0' || str[i] > '9')
            return false;	
    }

    return true; 
}

