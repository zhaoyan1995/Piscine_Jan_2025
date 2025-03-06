current->next = list;
    list = current;里面 current->next 指向list最一开始的地址 但是第二行 list = current的话list的地址被更新为指向current的地址 对吗 这样我们才能确保在返回值返回list的时候能录入所以的strs。


current->next = list;  // 让 current（新节点）的 next 指向 list（旧链表头）
list = current;        // 更新 list，新的头部变成 current

逐步分析

    current->next = list;
        这里 先让 current->next 指向 list 的旧地址（即链表的旧头部）。
        这样，新节点 current 就正确连接到了之前的链表。

    list = current;
        这里 更新 list，让它指向 current（最新插入的节点）。
        这样，list 作为链表头始终保持最新，保证最后返回 list 时，整个链表都能被包含。

关键点

    list 的地址不断更新：
        每次 list = current;，list 就指向最新插入的节点。
        但旧的 list 地址不会丢失，因为 current->next = list; 已经把旧地址存进去。

    最终返回 list 时，它指向的是整个链表的头：
        因为所有节点都是从前面插入的，形成 倒序存储。

示例

如果 strs = {"hello", "lilou", "comment", "world"}，执行过程如下：
步骤	current	current->next = list;	list = current; 更新后
插入 "hello"	"hello"	"hello" -> NULL	list -> "hello" -> NULL
插入 "lilou"	"lilou"	"lilou" -> hello -> NULL	list -> "lilou" -> "hello" -> NULL
插入 "comment"	"comment"	"comment" -> lilou -> hello -> NULL	list -> "comment" -> "lilou" -> "hello" -> NULL
插入 "world"	"world"	"world" -> comment -> lilou -> hello -> NULL	list -> "world" -> "comment" -> "lilou" -> "hello" -> NULL

最终：

list -> "world" -> "comment" -> "lilou" -> "hello" -> NULL

这样 list 作为链表头，返回后就能访问所有 strs！🎯
