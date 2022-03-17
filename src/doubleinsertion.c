/*
	Copyright (C) 2014-2022 Igor van den Hoven ivdhoven@gmail.com
*/

/*
	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "quadsort.h"

void FUNC(insert_left_first)(VAR *ptl, CMPFUNC *cmp)
{
	if (cmp(ptl, ptl + 1) > 0)
	{
		VAR *swap = ptl++, key = *swap;

		do
		{
			*swap++ = *ptl++;
		}
		while (cmp(&key, ptl) > 0);

		*swap = key;
	}	
}

void FUNC(insert_right_last)(VAR *ptr, CMPFUNC *cmp)
{
	if (cmp(ptr - 1, ptr) > 0)
	{
		VAR *swap = ptr--, key = *swap;

		do
		{
			*swap-- = *ptr--;
		}
		while (cmp(ptr, &key) > 0);

		*swap = key;
	}
}

void FUNC(insert_left_last)(VAR *ptl, CMPFUNC *cmp)
{
	if (cmp(ptl + 1, ptl) <= 0)
	{
		VAR *swap = ptl++, key = *swap;

		do
		{
			*swap++ = *ptl++;
		}
		while (cmp(ptl, &key) <= 0);

		*swap = key;
	}
}

void FUNC(insert_right_first)(VAR *ptr, CMPFUNC *cmp)
{
	if (cmp(ptr, ptr - 1) <= 0)
	{
		VAR *swap = ptr--, key = *swap;

		do
		{
			*swap-- = *ptr--;
		}
		while (cmp(&key, ptr) <= 0);

		*swap = key;
	}
}

void FUNC(doubletail_swap)(VAR *array, size_t nmemb, CMPFUNC *cmp)
{
	VAR swap, *ptl, *ptr;

	if (nmemb < 4)
	{
		FUNC(tiny_sort)(array, nmemb, cmp);
		return;
	}

	if (nmemb < 8)
	{
		ptl = array + (nmemb / 2 - 2);
		ptr = ptl + 4;

		FUNC(quad_swap_four)(ptl, cmp);
	}
	else if (nmemb < 16)
	{
		ptl = array + (nmemb / 2 - 4);
		ptr = ptl + 8;

		FUNC(parity_swap_eight)(ptl, cmp);
	}
	else
	{
		ptl = array + (nmemb / 2 - 8);
		ptr = ptl + 16;

		FUNC(parity_swap_sixteen)(ptl, cmp);
	}
	ptl -= 1 - nmemb % 2;

	while (ptl >= array)
	{
		if (cmp(ptl, ptr) <= 0)
		{
			FUNC(insert_left_first)(ptl, cmp);
			FUNC(insert_right_last)(ptr, cmp);
		}
		else
		{
			swap = *ptl; *ptl = *ptr; *ptr = swap;

			FUNC(insert_left_last)(ptl, cmp);
			FUNC(insert_right_first)(ptr, cmp);
		}
		ptl--;
		ptr++;
	}
}

void FUNC(doubleinsertion)(void *array, size_t nmemb, CMPFUNC *cmp)
{
	FUNC(doubletail_swap)(array, nmemb, cmp);
}
