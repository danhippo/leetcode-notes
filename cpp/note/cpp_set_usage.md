# `std::set` 使用指南

`std::set` 是 C++ 標準模板庫（STL）中一種有序關聯容器，用於存儲唯一元素並自動排序。它基於紅黑樹（平衡二叉搜索樹）實現，適合需要快速查找和有序存儲的場景。

---

## **特性**

1. **唯一性**：
   
   - 元素不能重複，插入相同元素時，新插入的元素會被忽略。
2. **自動排序**：
   
   - 元素按升序排列（默認情況）。
   - 可自定義排序規則（通過比較函數）。
3. **高效操作**：
   
   - 插入、刪除和查找的時間複雜度為 \(O(\log n)\)。
4. **底層實現**：
   
   - 基於紅黑樹，節點按鍵值排列，支持範圍操作。

---

## **常用操作**

### **1. 插入與刪除**

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet;

    // 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // 重複插入被忽略

    // 刪除元素
    mySet.erase(10);

    for (int x : mySet) {
        std::cout << x << " ";
    }

    return 0;
}
```

**輸出**：

```
20
```

### **2. 查找與範圍操作**

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet = {10, 20, 30, 40};

    // 查找元素
    if (mySet.find(20) != mySet.end()) {
        std::cout << "Found 20" << std::endl;
    }

    // 範圍操作
    auto it = mySet.lower_bound(25);  // 返回 >= 25 的第一個元素
    if (it != mySet.end()) {
        std::cout << "Lower bound: " << *it << std::endl;
    }

    return 0;
}
```

**輸出**：

```
Found 20
Lower bound: 30
```

### **3. 遍歷與清空**

```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet = {10, 20, 30};

    // 遍歷
    for (const int& x : mySet) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // 清空
    mySet.clear();
    std::cout << "Size after clear: " << mySet.size() << std::endl;

    return 0;
}
```

**輸出**：

```
10 20 30
Size after clear: 0
```

---

## **常用函數與特性**

| **操作**           | **函數**                 | **說明**                                   |
|--------------------|--------------------------|------------------------------------------|
| 插入元素           | `insert`                | 插入元素，重複元素不會插入               |
| 刪除元素           | `erase`                 | 刪除指定元素或範圍                        |
| 查找元素           | `find`                  | 查找元素，返回迭代器                      |
| 範圍查詢           | `lower_bound`, `upper_bound` | 查詢鍵的範圍                             |
| 獲取大小           | `size`                  | 返回容器中元素的數量                      |
| 清空容器           | `clear`                 | 刪除所有元素                              |
| 判空               | `empty`                 | 返回容器是否為空                          |
| 遍歷               | `begin`, `end`          | 返回容器的起始和結束迭代器                |

---

## **適用場景**

1. 需要快速檢查元素是否存在。
2. 需要存儲唯一的、有序的數據。
3. 需要範圍操作，例如查詢某範圍內的數據。

`std::set` 是一個功能強大的容器，適合處理需要有序數據和高效查找的場景。如果需要自定義排序，還可以通過傳遞比較函數來定制行為。


