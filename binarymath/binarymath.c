/**
 * Binary Math program to calculate addition, subtraction, negatives and
 * increments with binary numbers
 * @author Yogesh Prabhu
 */

#include <stdlib.h>
#include <string.h>
#include "binarymath.h"

/**
 * Increment a BINARY_SIZE binary number expressed as a 
 * character string.
 * @param number The number we are passed
 * @returns Incremented version of the number
 */
char const flip[] = "10";
char *inc(const char *number)
{
    char *result = malloc(BINARY_SIZE+1);
    memset(result, 0, BINARY_SIZE+1);
    int carry = 1;
    int i;
    for (i = BINARY_SIZE - 1; i >= 0; i--)
    {
      result[i] = (number[i] == '1' && carry == 1) ? '0' : '1';
      carry = result[i] == '0' ? 1 : 0;
      if(carry == 0)
        break;
    }


    //copy the rest of the number
    i--;
    for (; i >= 0; i--)
    {
      result[i] = number[i];
    }
    return result;
}


/**
 * Negate a BINARY_SIZE binary number expressed as a character string
 * @param number The number we are passed
 * @returns Incremented version of the number
 */
char *negate(const char *number)
{
   /** 
    * Example: -4
    * 4 = 100
    * add 0 to the front : 0100
    * invert the bits : 1101
    * add 1 : 1111
    */
    
    int len = BINARY_SIZE;
    int e = BINARY_SIZE-1;
    
    char *result = strdup(number);
    int j;
    
    //invert the result
    for (j = 0; j < len; j++)
    {
      result[j] = result[j] == '0' ? '1' : '0';
    }
    
    //add 1
    e = len-1;
    while (result[e] != '0' && e > 0)
    {
      result[e] = '0';
      e--;
    }
    result[e] = '1';   


    return result;
}

/**
 * Add two BINARY_SIZE binary numbers expressed as
 * a character string. 
 * @param a First number to add
 * @param b Second number to add
 * @return a + b
 */
char *add(const char *a, const char *b)
{
    /**
     * Rules
     * 1 + 0 = 1
     * 0 + 1 = 1
     * 1 + 1 = 0 and carry
     * 0 + 0 = 0
     */
    
    char* result = strdup(a);
    int carry = 0;
    int i;
    for (i = BINARY_SIZE-1; i >= 0; i--)
    {
      if (result[i] == '1' && b[i] == '1')
      {
        result[i] = carry == 1 ? '1' : '0';
        carry = 1;
      }
      else if (result[i] == '0' && b[i] == '0')
      {
        result[i] = carry == 1 ?  '1' : '0';
        carry = 0;
      }
      else
      {
        result[i] = carry == 1 ?  '0' : '1';
        carry = result[i] == '0' ? 1 : 0;
      }
    }
    return result;
}

/**
 * Subtract two BINARY_SIZE binary numbers expressed as
 * a character string.
 * @param a First number
 * @param b Second number 
 * @return a - b
 */
char *sub(const char *a, const char *b)
{
  /*
   * Basic Logic:
   * x - y is the same as
   * x + (-y)
   */
  char *result = strdup(a);
  char *negative = negate(b);

  char *result_ = add(result, negative);
  free(negative);
  free(result);

  return result_;
}
