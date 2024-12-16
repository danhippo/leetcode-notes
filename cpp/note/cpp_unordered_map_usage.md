# `std::unordered_map` 使用指南

`std::unordered_map` 是 C++ 標準模板庫（STL）中的無序關聯容器，用於存儲鍵值對，內部基於哈希表實現。它提供了高效的插入、刪除和查找操作，非常適合需要快速存取數據的場景。

---

## **特性**

1. **鍵值對存儲**：
   
   - 每個元素由鍵（`key`）和值（`value`）組成。
   - 鍵是唯一的，不允許重複鍵。
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
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, std::string> myMap;

    // 插入元素
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap.insert({3, "Three"});

    // 刪除元素
    myMap.erase(2);

    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }

    return 0;
}
```

**輸出**（順序可能不同）：

```
1: One
3: Three
```

### **2. 查找元素**

```cpp
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, std::string> myMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    // 查找元素
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found: " << it->second << std::endl;
    } else {
        std::cout << "Key not found" << std::endl;
    }

    return 0;
}
```

**輸出**：

```
Found: Two
```

### **3. 遍歷與清空**

```cpp
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, std::string> myMap = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    // 遍歷
    for (const auto& [key, value] : myMap) {
        std::cout << key << ": " << value << std::endl;
    }

    // 清空
    myMap.clear();
    std::cout << "Size after clear: " << myMap.size() << std::endl;

    return 0;
}
```

**輸出**：

```
1: One
2: Two
3: Three
Size after clear: 0
```

---

## **常用函數與特性**

| **操作**           | **函數**                 | **說明**                                   |
|--------------------|--------------------------|------------------------------------------|
| 插入元素           | `operator[]`, `insert`  | 插入鍵值對；若鍵已存在則更新值           |
| 刪除元素           | `erase`                 | 刪除指定鍵的元素                          |
| 查找元素           | `find`                  | 查找鍵，返回迭代器                        |
| 獲取大小           | `size`                  | 返回容器中元素的數量                      |
| 清空容器           | `clear`                 | 刪除所有元素                              |
| 判空               | `empty`                 | 返回容器是否為空                          |
| 遍歷               | `begin`, `end`          | 返回容器的起始和結束迭代器                |
| 負載因子           | `load_factor`           | 返回當前負載因子（元素數量 / 桶數量）      |
| 調整桶數           | `rehash`                | 手動調整桶數量                            |
| 預留桶數           | `reserve`               | 預留足夠的桶以容納給定數量的元素          |

---

## **適用場景**

1. 需要快速查找、插入和刪除鍵值對的情況。
2. 不關心數據存儲順序。
3. 適合處理大量數據且需要高效操作的場景。

`std::unordered_map` 提供了無序但高效的操作，非常適合鍵值對的快速存取。如果需要有序存儲，請使用 `std::map`。


