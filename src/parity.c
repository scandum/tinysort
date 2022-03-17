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

void FUNC(odd_parity_merge)(VAR *from, VAR *dest, size_t left, size_t right, CMPFUNC *cmp)
{
	VAR *ptl, *ptr, *tpl, *tpr, *tps, *pts;
	size_t cnt, x, y;

	ptl = from + 0; ptr = from + left; pts = dest;
	tpl = from + left - 1; tpr = from + left + right - 1; tps = dest + left + right - 1;

	for (cnt = left - 1 ; cnt ; cnt--)
	{
		x = cmp(ptl, ptr) <= 0; y = !x; pts[x] = *ptr; ptr += y; pts[y] = *ptl; ptl += x; pts++;
		x = cmp(tpl, tpr) <= 0; y = !x; tps--; tps[x] = *tpr; tpr -= x; tps[y] = *tpl; tpl -= y;
	}
	*tps = cmp(tpl, tpr)  > 0 ? *tpl : *tpr;

	if (left < right)
	{
		*pts++ = cmp(ptl, ptr) <= 0 ? *ptl++ : *ptr++;
	}
	*pts = cmp(ptl, ptr) <= 0 ? *ptl : *ptr;
}

void FUNC(parity_swap)(VAR *array, size_t nmemb, CMPFUNC *cmp)
{
	VAR swap[nmemb];

	size_t quad1, quad2, quad3, quad4, half1, half2;

	half1 = nmemb / 2;
	quad1 = half1 / 2;
	quad2 = half1 - quad1;
	half2 = nmemb - half1;
	quad3 = half2 / 2;
	quad4 = half2 - quad3;

	FUNC(oddeven_sort)(array, quad1, cmp);
	FUNC(oddeven_sort)(array + quad1, quad2, cmp);
	FUNC(oddeven_sort)(array + half1, quad3, cmp);
	FUNC(oddeven_sort)(array + half1 + quad3, quad4, cmp);

	if (cmp(array + quad1 - 1, array + quad1) <= 0 && cmp(array + half1 - 1, array + half1) <= 0 && cmp(array + half1 + quad3 - 1, array + half1 + quad3) <= 0)
	{
		return;
	}

	FUNC(odd_parity_merge)(array, swap, quad1, quad2, cmp);
	FUNC(odd_parity_merge)(array + half1, swap + half1, quad3, quad4, cmp);
	FUNC(odd_parity_merge)(swap, array, half1, half2, cmp);
}

void FUNC(parity_tail_swap)(VAR *array, size_t nmemb, CMPFUNC *cmp)
{
	if (nmemb < 8)
	{
		FUNC(oddeven_sort)(array, nmemb, cmp);
		return;
	}
	FUNC(parity_swap)(array, nmemb, cmp);
}

void FUNC(parity)(void *array, size_t nmemb, CMPFUNC *cmp)
{
	FUNC(parity_tail_swap)(array, nmemb, cmp);
}
