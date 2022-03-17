Binary
------
This is a binary insertion sort using a branchless binary search.

Bubble
------
This is a branchless bubble sort.

Double
------
This is a double insertion sort, it is semi-adaptive.

Oddeven
-------
This is an odd-even sort, similar to bubble sort but with better overall performance.

Parity
------
This is a top-down parity merge

Tinysort
--------
Depending on the size of the distribution this will use odd-even, parity, or unguarded insertion for optimal performance.

Unguarded
---------
This is a twice-unguarded insertion sort, it is semi-adaptive.

Benchmark
---------

![image](https://user-images.githubusercontent.com/52607428/158867095-93781500-87d3-434c-b9b2-2b9e8493a1e3.png)

|      Name |    Items | Type |     Best |  Average |  Compares | Samples |     Distribution |
| --------- | -------- | ---- | -------- | -------- | --------- | ------- | ---------------- |
|    bubble |        4 |   32 | 0.000142 | 0.000150 |       2.5 |    1000 |       random 1-4 |
|    binary |        4 |   32 | 0.000149 | 0.000150 |       2.4 |    1000 |       random 1-4 |
|    double |        4 |   32 | 0.000153 | 0.000163 |       2.4 |    1000 |       random 1-4 |
|   oddeven |        4 |   32 | 0.000153 | 0.000155 |       2.5 |    1000 |       random 1-4 |
|    parity |        4 |   32 | 0.000160 | 0.000164 |       2.5 |    1000 |       random 1-4 |
|  tinysort |        4 |   32 | 0.000157 | 0.000159 |       2.5 |    1000 |       random 1-4 |
| unguarded |        4 |   32 | 0.000151 | 0.000153 |       2.4 |    1000 |       random 1-4 |
|           |          |      |          |          |           |         |                  |
|    bubble |        8 |   32 | 0.000334 | 0.000368 |      18.5 |    1000 |       random 5-8 |
|    binary |        8 |   32 | 0.000383 | 0.000401 |      14.0 |    1000 |       random 5-8 |
|    double |        8 |   32 | 0.000373 | 0.000391 |      14.8 |    1000 |       random 5-8 |
|   oddeven |        8 |   32 | 0.000302 | 0.000304 |      18.5 |    1000 |       random 5-8 |
|    parity |        8 |   32 | 0.000327 | 0.000356 |      16.8 |    1000 |       random 5-8 |
|  tinysort |        8 |   32 | 0.000290 | 0.000317 |      16.8 |    1000 |       random 5-8 |
| unguarded |        8 |   32 | 0.000357 | 0.000384 |      14.3 |    1000 |       random 5-8 |
|           |          |      |          |          |           |         |                  |
|    bubble |       12 |   32 | 0.000590 | 0.000640 |      50.5 |    1000 |      random 9-12 |
|    binary |       12 |   32 | 0.000523 | 0.000531 |      31.7 |    1000 |      random 9-12 |
|    double |       12 |   32 | 0.000493 | 0.000500 |      33.4 |    1000 |      random 9-12 |
|   oddeven |       12 |   32 | 0.000493 | 0.000524 |      50.5 |    1000 |      random 9-12 |
|    parity |       12 |   32 | 0.000463 | 0.000481 |      31.1 |    1000 |      random 9-12 |
|  tinysort |       12 |   32 | 0.000440 | 0.000453 |      31.6 |    1000 |      random 9-12 |
| unguarded |       12 |   32 | 0.000467 | 0.000476 |      32.1 |    1000 |      random 9-12 |
|           |          |      |          |          |           |         |                  |
|    bubble |       16 |   32 | 0.000881 | 0.000970 |      98.5 |    1000 |     random 13-16 |
|    binary |       16 |   32 | 0.000655 | 0.000662 |      49.8 |    1000 |     random 13-16 |
|    double |       16 |   32 | 0.000633 | 0.000647 |      53.0 |    1000 |     random 13-16 |
|   oddeven |       16 |   32 | 0.000693 | 0.000905 |      98.5 |    1000 |     random 13-16 |
|    parity |       16 |   32 | 0.000503 | 0.000554 |      49.5 |    1000 |     random 13-16 |
|  tinysort |       16 |   32 | 0.000491 | 0.000535 |      49.0 |    1000 |     random 13-16 |
| unguarded |       16 |   32 | 0.000578 | 0.000593 |      51.1 |    1000 |     random 13-16 |
|           |          |      |          |          |           |         |                  |
|    bubble |       20 |   32 | 0.001223 | 0.001301 |     162.5 |    1000 |     random 17-20 |
|    binary |       20 |   32 | 0.000603 | 0.000611 |      68.4 |    1000 |     random 17-20 |
|    double |       20 |   32 | 0.000597 | 0.000614 |      74.7 |    1000 |     random 17-20 |
|   oddeven |       20 |   32 | 0.000890 | 0.001108 |     162.5 |    1000 |     random 17-20 |
|    parity |       20 |   32 | 0.000547 | 0.000678 |      72.0 |    1000 |     random 17-20 |
|  tinysort |       20 |   32 | 0.000549 | 0.000637 |      71.1 |    1000 |     random 17-20 |
| unguarded |       20 |   32 | 0.000559 | 0.000666 |      71.2 |    1000 |     random 17-20 |
|           |          |      |          |          |           |         |                  |
|    bubble |       24 |   32 | 0.001562 | 0.001678 |     242.5 |    1000 |     random 21-24 |
|    binary |       24 |   32 | 0.000786 | 0.000801 |      91.4 |    1000 |     random 21-24 |
|    double |       24 |   32 | 0.000760 | 0.000785 |     106.6 |    1000 |     random 21-24 |
|   oddeven |       24 |   32 | 0.001122 | 0.001252 |     242.5 |    1000 |     random 21-24 |
|    parity |       24 |   32 | 0.000600 | 0.000714 |      98.5 |    1000 |     random 21-24 |
|  tinysort |       24 |   32 | 0.000603 | 0.000680 |      98.5 |    1000 |     random 21-24 |
| unguarded |       24 |   32 | 0.000677 | 0.000707 |      99.7 |    1000 |     random 21-24 |
