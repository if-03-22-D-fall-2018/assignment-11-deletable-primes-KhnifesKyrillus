/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <math.h>
unsigned long remove_digit(int index, unsigned long n)
{
  unsigned long digits_before=n/pow(10,index+1);
  unsigned long digits_after=n%(unsigned long)pow(10,index);
  unsigned long new_number=digits_before*pow(10,index)+digits_after;
  return new_number;
}

int get_ways(unsigned long p)
{
  int counter=0;
  int digit_count=log10(p)+1;
  for (int i = 0; i < digit_count; i++)
  {
    unsigned long n=p;
    if (n>=10)n=remove_digit(i,p);

    if (is_prime(n))
    {
      if (n<10)
      {
        return counter+1;
      }
      else
      {
        counter+=get_ways(n);
      }
    }
  }
  return counter;
}
bool is_prime(unsigned long n)
{
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (n%2==0) return false;
  }
  return true;
}
