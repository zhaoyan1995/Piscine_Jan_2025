void ft_swap(char **s1, char **s2)
{
    char *temp;

    temp = *s1;  // temp 现在指向 s1 所指向的字符串
    *s1 = *s2;   // s1 现在指向 s2 所指向的字符串
    *s2 = temp;  // s2 现在指向 temp（原来的 s1）
}

char * 代表 指向字符串的指针。
char ** 代表 指向字符串指针的指针（用来修改 char * 指针本身）。
通过 二级指针 char ** 传递 str1 和 str2 的地址，我们才能真正修改 main 里的 str1 和 str2。

"BUBBLE_SORT"
j => the j th round of bubble sorting process
i => number of string in tab
bubble sort : we always start from the i = 0 element
for each round, we pick up the biggest element and we put it at the end of
the array, then we continue the bubble sorting for the rest of the array.
In bubble sort, we ALWAYS compare two elements SIDE BY SIDE.
Unlike the selected sort

"SELECTED_SORT"
we want to pick up the smallest element and put it in the beginning of the array, then
we sort the rest of them.
firstly we compare tab[0] with the rest of the elements in the array
after that, we compare tab[1] with the rest of the elements in the array (except tab[0] for sure)
we DON NOT compare the element side by side in this case.

BUBBLE_SORT vs SELECTED_SORT :
The bubble_sort is more stable than selected_sort, because if we have an array contains the same element like char *tab[] = { "apple, "zero", "banana", "zero"}, we have 2 "zero" in our array, if we use the selected sort, maybe the relative spot of tab[1] and tab[3] will be changed, that is not consistent with the principle of the stability. However, in the bubble_sort, since we compare 2 elements side by side every single time, so we will not change the relative spot of two identical elements, so we can guarantee the stability of the sorted array.

It is not a big issue in this exercise, because we could have the same output in both case. However, in some cases, it could impact the output, in conclusion, bubble_sort is more secure and applicable for most of the case.
