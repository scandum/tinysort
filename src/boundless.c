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

void FUNC(boundlesstail_swap)(VAR *array, unsigned int nmemb, CMPFUNC *cmp)
{
	VAR tmp1, *pta, *end, *ptt;
	unsigned int mid, top, offset;

	if (nmemb <= 8)
	{
		switch (nmemb)
		{
			case 0:
			case 1:
				return;

			case 2:
				swap_two(array, tmp1);
				return;

			case 3:
				swap_three(array, tmp1);
				return;

			case 4:
				swap_four(array, tmp1);
				return;

			case 5:
				swap_four(array, tmp1);
				swap_five(array, pta, ptt, end, tmp1, cmp);
				return;

			case 6:
				swap_four(array, tmp1);
				swap_six(array, pta, ptt, end, tmp1, cmp);
				return;
			case 7:
				swap_four(array, tmp1);
				swap_seven(array, pta, ptt, end, tmp1, cmp);
				return;
		}
		swap_four(array, tmp1);
		swap_eight(array, pta, ptt, end, tmp1, cmp);
		return;
	}

	if (FUNC(twin_swap)(array, nmemb, cmp))
	{
		return;
	}

	swap_four(array, tmp1);
	swap_eight(array, pta, ptt, end, tmp1, cmp);

	offset = 8;

	end = array + offset;

	while (offset < nmemb)
	{
		top = offset++;
		pta = end++;
		ptt = pta--;

		if (cmp(pta, ptt) <= 0)
		{
			offset++;
			end++;
			continue;
		}

		tmp1 = ptt[0];

		while (top > 1)
		{
			mid = top / 2;

			if (cmp(pta - mid, &tmp1) > 0)
			{
				pta -= mid;
			}
			top -= mid;
		}

		top = ptt - pta;

		memmove(pta + 1, pta, top * sizeof(VAR));

		*pta = tmp1;

		if (offset++ == nmemb)
		{
			break;
		}

		pta = end++;
		ptt = pta--;

		if (cmp(pta, ptt) <= 0)
		{
			continue;
		}

		tmp1 = *ptt;

		while (top > 1)
		{
			mid = top / 2;

			if (cmp(pta - mid, &tmp1) > 0)
			{
				pta -= mid;
			}
			top -= mid;
		}

		memmove(pta + 1, pta, (ptt - pta) * sizeof(VAR));

		*pta = tmp1;

	}
}

void FUNC(boundless)(void *array, unsigned int nmemb, size_t size, CMPFUNC *cmp)
{
	FUNC(boundlesstail_swap)(array, nmemb, cmp);
}
