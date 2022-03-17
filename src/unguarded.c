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

void FUNC(unguarded_tail_swap)(VAR *array, size_t nmemb, CMPFUNC *cmp)
{
	if (nmemb < 4)
	{
		FUNC(tiny_sort)(array, nmemb, cmp);
		return;
	}

	if (nmemb < 8)
	{
		FUNC(quad_swap_four)(array, cmp);
		FUNC(unguarded_insert)(array, 4, nmemb, cmp);
		return;
	}
	if (nmemb < 16)
	{
		FUNC(parity_swap_eight)(array, cmp);
		FUNC(unguarded_insert)(array, 8, nmemb, cmp);
		return;
	}
	FUNC(parity_swap_sixteen)(array, cmp);
	FUNC(unguarded_insert)(array, 16, nmemb, cmp);
}

void FUNC(unguarded)(void *array, size_t nmemb, CMPFUNC *cmp)
{
	FUNC(unguarded_tail_swap)(array, nmemb, cmp);
}
