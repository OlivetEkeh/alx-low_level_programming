#include "hash_tables.h"

/**
 * hash_djb2 -  this is for creating hash values of strings
 * @str: this is the string to be hashed
 * Return: this is the value of the hashed string
 */

unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return (hash);
}
