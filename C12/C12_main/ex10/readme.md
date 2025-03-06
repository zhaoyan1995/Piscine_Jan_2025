ft_cmp 在接收参数的时候必须是void *类型，如果在main中执行ft list foreach if，如果data def是int类型（不是int 指针类型）, 需要在main中调用的时候填入int 变量的地址。

ft_cmp 完成参数接受后需要将void *类型转换成int 类型，然后才能获取两参数直接的差作为返回值。 
