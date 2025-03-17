二叉树结构

程序构造的二叉树如下：

        7
       / \
      2   3
     /   / \
    4   5   9
           /
         42

    7 是根节点。
    7 的左子树是 2，右子树是 3。
    2 的左子树是 4，没有右子树。
    3 的左子树是 5，右子树是 9。
    9 的左子树是 42，没有右子树。

递归执行过程

我们调用 btree_level_count(a)，并按照**后序遍历（Postorder Traversal: 左 -> 右 -> 根）**的方式展开递归调用。
Step 1: 计算 btree_level_count(7)

    计算 btree_level_count(2) （左子树）
    计算 btree_level_count(3) （右子树）

Step 2: 计算 btree_level_count(2)

    计算 btree_level_count(4)（左子树）
    2 没有右子树，btree_level_count(NULL) = 0

Step 3: 计算 btree_level_count(4)

    4 没有左右子树：

    btree_level_count(4) = max(0, 0) + 1 = 1

Step 4: 回溯到 2

    btree_level_count(2) = max(1, 0) + 1 = 2

Step 5: 计算 btree_level_count(3)

    计算 btree_level_count(5)（左子树）
    计算 btree_level_count(9)（右子树）

Step 6: 计算 btree_level_count(5)

    5 没有左右子树：

    btree_level_count(5) = max(0, 0) + 1 = 1

Step 7: 计算 btree_level_count(9)

    计算 btree_level_count(42)（左子树）
    9 没有右子树，btree_level_count(NULL) = 0

Step 8: 计算 btree_level_count(42)

    42 没有左右子树：

    btree_level_count(42) = max(0, 0) + 1 = 1

Step 9: 回溯到 9

    btree_level_count(9) = max(1, 0) + 1 = 2

Step 10: 回溯到 3

    btree_level_count(3) = max(1, 2) + 1 = 3

Step 11: 回溯到 7

    btree_level_count(7) = max(2, 3) + 1 = 4

最终返回值

btree_level_count(7) = 4

最终，树的最大深度是 4。
完整的递归调用关系

btree_level_count(7)
 ├── btree_level_count(2)
 │    ├── btree_level_count(4) = 1
 │    ├── btree_level_count(NULL) = 0
 │    └── max(1, 0) + 1 = 2
 │
 ├── btree_level_count(3)
 │    ├── btree_level_count(5) = 1
 │    ├── btree_level_count(9)
 │    │    ├── btree_level_count(42) = 1
 │    │    ├── btree_level_count(NULL) = 0
 │    │    └── max(1, 0) + 1 = 2
 │    └── max(1, 2) + 1 = 3
 │
 └── max(2, 3) + 1 = 4

总结

    递归计算左右子树的深度，取 max(left, right) + 1。
    执行顺序类似后序遍历（先递归子树，再计算当前节点）。
    最终返回 4，表示树的最大深度是 4。
