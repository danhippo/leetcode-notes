# `std::unordered_set` 使用指南

`std::unordered_set` 是 C++ 標準模板庫（STL）中的無序關聯容器，用於存儲唯一元素，內部基於哈希表實現，適合需要快速查找而不關心順序的場景。

---

## **特性**

1. **唯一性**：
   
   - 元素不能重複，插入相同元素時，新插入的元素會被忽略。
2. **無序存儲**：
   
   - 元素的存儲順序由哈希函數決定，插入的順序無法保證。
3. **高效操作**：
   
   - 插入、刪除和查找的平均時間複雜度為 \(O(1)\)，最差情況下為 \(O(n)\)（當哈希衝突嚴重時）。
4. **底層實現**：
   
   - 基於哈希表（Hash Table），使用哈希函數和鏈地址法解決哈希衝突。

---

## **常用操作**

### **1. 插入與刪除**

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> mySet;

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

**輸出**（順序可能不同）：

```
20
```

### **2. 查找元素**

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> mySet = {10, 20, 30};

    // 查找元素
    if (mySet.find(20) != mySet.end()) {
        std::cout << "Found 20" << std::endl;
    } else {
        std::cout << "20 not found" << std::endl;
    }

    return 0;
}
```

**輸出**：

```
Found 20
```

### **3. 遍歷與清空**

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> mySet = {10, 20, 30};

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
| 刪除元素           | `erase`                 | 刪除指定元素                              |
| 查找元素           | `find`                  | 查找元素，返回迭代器                      |
| 獲取大小           | `size`                  | 返回容器中元素的數量                      |
| 清空容器           | `clear`                 | 刪除所有元素                              |
| 判空               | `empty`                 | 返回容器是否為空                          |
| 遍歷               | `begin`, `end`          | 返回容器的起始和結束迭代器                |
| 負載因子           | `load_factor`           | 返回當前負載因子（元素數量 / 桶數量）      |
| 調整桶數           | `rehash`                | 手動調整桶數量                            |
| 預留桶數           | `reserve`               | 預留足夠的桶以容納給定數量的元素          |

---

## **適用場景**

1. 需要快速檢查元素是否存在。
2. 不需要存儲順序的情況。
3. 適合處理大量數據且希望插入與查找高效的場景。

`std::unordered_set` 提供了無序但高效的操作，特別適合需要快速查找而不在意順序的應用場景。如果需要有序存儲，請使用 `std::set`。


