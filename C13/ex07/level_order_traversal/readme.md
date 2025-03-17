void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
void    applyf(void *item, int current_level, int is_first_elem);

这个程序要求通过在最开始访问binary tree的根部节点root，来逐层遍历他的子节点，并且每一次访问当前节点的时候，都要通过applyf访问并操作他的item，并且标记他的current level， 而且要确定这个节点是否为该层的第一个节点，如果是该层第一个节点的话，那么is_first_elem = 1, 如果不是的话，is_first_elem = 0。

这里的applyf函数可以是将每一个节点里面的item打印出来，并且把节点对应的current level打印出来的程序，并且根据is first elem的值，来标记这个item是不是current level里面的第一个值。

比如, 对于这个二叉树：
        a
       / \
      b   c
     /   / \
    d   e   f
     \      / \
      i    h   g

我们希望通过void    btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));
来实现一下输出:
Level: 0 => a
Level: 1 => b
         => c
Level: 2 => d
         => e
         => f
Level: 3 => i
         => h
         => g

这个程序只有当当前层所有节点都被访问了，才会进入下一层，并且他会在is_first_elem = 1的时候，才会打印出当前层的current level是多少。

因为是层序遍历，也就是广度优先搜索，所以只能使用队列的方式，不可以使用递归，否则递归只能进行深度优先搜索。

这里二叉树的结构体如下：
typedef struct s_btree
{
        struct s_btree  *left;
        struct s_btree  *right;
        void                    *item;
}       t_btree;

队列结构体如下：
typedef struct s_queue
{
        int             front;
        int             rear;
        int             max_size;
        int             nbr_current_level;
        int             nbr_next_level;
        t_btree **node;
}       t_queue;

这里面front代表要处理的当前队列的在数组的第几个位置。
然后rear代表在next level的节点入列后数组在第几个位置。
max_size代表数组的大小，用来动态分配内存给node这个二级指针。
nbr_current_level代表当前访问的节点的数量还剩下几个。
nbr_next_level代表下一层的节点数有多少个。
node二级指针用来存储每一个二叉树节点, 这个可以和**argv来进行类比。

首先声明t_queue这个结构体变量array。
对他进行初始化：
front = 0；
rear = 0；
max_size 通过count_node这个函数计算出二叉树有多少个节点，然后把他赋值给max_size。
nbr_current_level = 1 因为最一开始的入列是把二叉树的头部"a"入列，所以肯定是1。
nbr_next_level = 0 暂时等于0，因为要通过查询a的左边和右边来确定a的nbr_next_level到底是多少。
node = malloc(sizeof(t_btree *) * max_size)。

此时node就相当于
      front(0)
            ↓ 
node[9] = { ?, ?, ?, ?, ?, ?, ?, ?, ?};
            ↑    
       rear(0)

然后，将二叉树头部加入node数组:
array[rear++] = root; 这里面root就是a节点。
      front(0)
            ↓ 
node[9] = { a, ?, ?, ?, ?, ?, ?, ?, ?};
               ↑    
         rear(1)
在a的节点时, 所以初始化一下两个变量，方便在applyf被启用时，传递正确的参数。
is_first_elem = 1 
current_level = 0;

之后进入while循环，front 必须总是大于 rear循环才能继续。
调用applyf函数，首先遍历a节点applyf(array->node[array->front]->item, current_level, is_first_elem);
之后调用put_into_queue来进行入列
在这里a->left存在，array->node[rear] = b, 并且rear++, nbr_next_level++。
在这里a->right存在，array->node[rear] = b, 并且rear++, nbr_next_level++。
      front(0)
            ↓ 
node[9] = { a, b, c, ?, ?, ?, ?, ?, ?};
                     ↑    
                rear(3)  此时nbr_next_level = 2
由于applyf已经处理过front了，所以这个时候front++, 用于接下来的循环当中调用applyf使用b节点参数, 次数is_first_elem = 0, 因为已经处理过第0层的第一个节点了。
         front(1)
               ↓ 
node[9] = { a, b, c, ?, ?, ?, ?, ?, ?};
                     ↑  
                rear(3)
因为第0层的a节点被处理过来，所以nbr_current_level--， 此时nbr_current_level = 0，所以该层所有节点都已经访问过了，该处理下一层的所有节点, 所以nbr_current_level = nbr_next_level (第一层的nbr_current_level = 2, 由nbr_next_level来给他赋值), nbr_next_level = 0 (清零用于计数第二层的所有节点数量), current_level++, 为了确保给applyf传递正确的参数，最后is_first_elem = 1, 因为即将访问第一层的第一个节点。

第二次循环，开始调用applyf访问b节点，然后通过put_into_queue来入列b节点的左节点和右节点，front++对b节点出列, is_first_elem = 0, 因为第一层的第一个节点b已经被访问过了。
            front(2)
                  ↓ 
node[9] = { a, b, c, d, ?, ?, ?, ?, ?};
                        ↑  
                   rear(4)
nbr_current_level--, 这里原来的值是2，但由于处理了b，所以--，还剩下一个节点c, 所以是1，那么nbr_current_level值不会被置换，current_level 还是1，继续从头循环。

第三次循环，开始调用applyf访问c节点，然后通过put_into_queue来入列c节点的左节点和右节点，front++对c节点出列, is_first_elem 还是0, 因为第一层的第一个节点b已经被访问过了。
               front(3)
                     ↓ 
node[9] = { a, b, c, d, e, f, ?, ?, ?};
                              ↑  
                         rear(6)

nbr_current_level --, 这里面第一层的b和c都被访问过了，所以nbr_current_level变成0，置换nbr_current_level的值为nbr_next_level = 3。current_level++, nbr_next_level = 0, is_first_elem 重置为1，用于标记第二层的第一个元素。

第四次循环，调用applyf访问d节点，通过put_into_queue来入列d的左节点右节点，front++对d节点出列，is_first_elem从1变为0，因为第二层第一个节点d已经被访问过了

                     front(4)
                        ↓ 
node[9] = { a, b, c, d, e, f, i, ?, ?};
                                 ↑  
                             rear(7)

nbr_current_level --, 从3变成2，因为还有e和f这两个节点需要被访问。

第五次循环，调用applyf访问e节点，通过put_into_queue来入列e节点的左节点右节点，front++对e节点出列， is_first_elem=0保持不变。nbr_current_level --, 从2变成1。还有第二层的f节点需要被访问。

                     front(5)
                           ↓ 
node[9] = { a, b, c, d, e, f, i, ?, ?};
                                 ↑  
                             rear(7)


第六次循环，调用applyf访问f节点，通过put_into_queue来入列f节点的左节点右节点，front++对f节点出列， is_first_elem=0保持不变。

                        front(6)
                              ↓ 
node[9] = { a, b, c, d, e, f, i, h, g};
                                      ↑  
                                 rear(9)

nbr_current_level --, 从1变成0，nbr_current_level重置为nbr_next_level, nbr_next_level =0, is_first_elem重置为1， current_level++。

第七次循环，调用applyf访问节点i，i节点没有子节点所以入列函数不起任何作用，rear始终是9， front++对i节点出列，is_first_elem从1变0，nbr_current_level--, 从3变成2，继续循环

                           front(7)
                                 ↓ 
node[9] = { a, b, c, d, e, f, i, h, g};
                                      ↑  
                                 rear(9)

第八次循环，调用applyf访问节点h，h节点没有子节点，rear始终是9, front++对h节点出列，is_first_elem还是0, nbr_current_level--, 从2变成1，继续循环。

                              front(8)
                                    ↓ 
node[9] = { a, b, c, d, e, f, i, h, g};
                                      ↑  
                                 rear(9)

第九次循环，调用applyf访问节点g，g节点没有子节点，rear始终是9, front++对g节点出列，is_first_elem还是0, nbr_current_level--, 从1变成0，nbr_current_level 重置为 nbr_next_level, nbr_next_level = 0, current_level++, is_first_elem变成1。

                                front(9)
                                      ↓ 
node[9] = { a, b, c, d, e, f, i, h, g};
                                      ↑  
                                 rear(9)

第十次循环，由于front = 9 = rear，所以循环终止。

释放由malloc动态分配内存的queue和node

程序结束。


