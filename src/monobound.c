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

void FUNC(mono_tail_swap)(VAR *array, size_t nmemb, CMPFUNC *cmp)
{
	VAR tmp, *pta, *end, *ptt;
	size_t mid, top, offset;

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
		
		end = array + 8;
		offset = 8;
	}
	else
	{
		FUNC(parity_swap_sixteen)(array, cmp);

		end = array + 16;
		offset = 16;
	}

	while (offset < nmemb)
	{
		top = offset++;
		pta = end++;
		ptt = pta--;

		if (cmp(pta, ptt) <= 0)
		{
			continue;
		}

		while (top > 1)
		{
			mid = top / 2;

			if (cmp(pta - mid, ptt) > 0)
			{
				pta -= mid;
			}
			top -= mid;
		}

		tmp = *ptt;

		memmove(pta + 1, pta, (ptt - pta) * sizeof(VAR));

		*pta = tmp;
	}
}

void FUNC(monobound)(void *array, size_t nmemb, size_t size, CMPFUNC *cmp)
{
	FUNC(mono_tail_swap)(array, nmemb, cmp);
}
