注意：
不能直接在main函数里面直接这样使用ft_list_foreach函数
ft_list_foreach(first, &ft_putnbr(*(int *)first->data));
因为如果在main函数里面使用函数指针的话  函数指针后面不可以加参数的。

这里有两个问题：

    错误的函数指针传递方式：
    ft_list_foreach 的原型要求第二个参数是一个函数指针，其类型为 void (*f)(void *)。但你传入的是 &ft_putnbr(*(int *)first->data)。
        你实际上在调用 ft_putnbr 函数：ft_putnbr(*(int *)first->data) 会先计算 *(int *)first->data，然后把结果传给 ft_putnbr。
        再对这个调用结果取地址（&），这在语法上是不允许的，因为你不能取一个函数调用结果的地址。

    函数签名不匹配：
    你的 ft_putnbr 函数声明为 void ft_putnbr(int nbr)，而 ft_list_foreach 要求的函数指针应该接受一个 void * 类型的参数。两者参数类型不匹配，即使传递了函数指针，调用时也会出问题。

解决方案：
编写一个包装函数用于转换 void *data 把他变成 int *data 
void ft_print(void *data)
{
    ft_putnbr(*(int *)data);
}

