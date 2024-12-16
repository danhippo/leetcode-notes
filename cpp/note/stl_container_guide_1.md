# C++ STL 容器學習指南

C++ 標準模板庫（STL）提供了豐富的容器類型，主要分為以下幾類：

1. **順序容器**：`std::vector`, `std::deque`, `std::list`。
2. **關聯容器**：`std::set`, `std::map`, `std::multiset`, `std::multimap`。
3. **無序關聯容器**：`std::unordered_set`, `std::unordered_map`, `std::unordered_multiset`, `std::unordered_multimap`。
4. **容器適配器**：`std::stack`, `std::queue`, `std::priority_queue`。

以下將依次介紹這些容器的基本特性、常見操作以及使用範例。

---

## 3. 無序關聯容器

無序關聯容器是一類基於哈希表實現的容器，用於快速存取和查找數據。這類容器的主要特點是：

- ​**數據管理方式**​：通過鍵值對（`key-value`）進行管理，鍵用於快速查找。
- ​**無序存儲**​：元素的存儲順序由哈希函數決定，無法保證有序。
- ​**操作效率**​：查找、插入和刪除操作的平均時間複雜度為 O(1)，最差情況為 O(n)。
- ​**用途**​：適合只關心快速查找、不要求順序的場景。

### **3.1 std::unordered_set**

#### **特性**

- 無序集合，內部元素唯一。
- 基於哈希表實現，查找和插入操作的時間複雜度為 O(1)（平均情況下）。

#### **結構圖解**

`std::unordered_set` 的內部結構基於哈希表，元素分佈在不同的哈希桶中。

```
Bucket 0: [20] -> [40]
Bucket 1: [30]
Bucket 2: [10]
```

- **特點**:
  1. 元素分佈在哈希桶中，沒有順序。
  2. 查找和插入效率高，與元素數量和哈希函數質量相關。

#### **常見操作**

```cpp
#include <unordered_set>
#include <iostream>

int main() {
    std::unordered_set<int> uset = {3, 1, 4, 1, 2}; // 自動去重

    uset.insert(5);                      // 插入元素
    uset.erase(3);                       // 移除元素

    for (int v : uset) {                 // 遍歷（順序不定）
        std::cout << v << " ";
    }
    return 0;
}
```

#### **適用場景**

- 須快速檢查元素是否存在，且不要求有序時。

---

### **3.2 std::unordered_map**

#### **特性**

- 無序鍵值對，鍵唯一。
- 基於哈希表實現，查找和插入的時間複雜度為 \(O(1)\)（平均情況下）。

#### **結構圖解**

`std::unordered_map` 的內部結構與 `std::unordered_set` 類似，但每個桶中存儲鍵值對。

```
Bucket 0: [20: "b"] -> [40: "d"]
Bucket 1: [30: "c"]
Bucket 2: [10: "a"]
```

- **特點**:
  1. 無序存儲，元素位置由哈希函數決定。
  2. 快速查找和插入。

#### **常見操作**

```cpp
#include <unordered_map>
#include <iostream>

int main() {
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}};

    umap[3] = "three";                 // 插入鍵值對
    umap.erase(1);                      // 刪除鍵

    for (const auto& [key, value] : umap) {
        std::cout << key << ": " << value << std::endl;
    }
    return 0;
}
```

#### **適用場景**

- 須快速查找鍵值對，且不要求有序時。

---

## 4. 容器適配器

容器適配器是基於其他容器實現的抽象數據結構，限制了底層容器的接口，提供特定的數據結構操作。這類容器的主要特點是：

- ​**接口限制**​：僅允許使用特定的操作，如後進先出（LIFO）或先進先出（FIFO）。
- ​**靈活的底層實現**​：通常基於 `std::deque`，也可以基於其他順序容器。
- ​**用途**​：適合需要特定數據結構行為的場景，例如堆疊、隊列或優先級隊列。

### **4.1 std::stack**

#### **特性**

- 後進先出（LIFO）的數據結構。
- 基於 `std::deque` 或其他順序容器實現。

#### **結構圖解**

`std::stack` 的結構基於底層容器（默認為 `std::deque`）。

```
+----+----+----+
| 10 | 20 | 30 | <- Top
+----+----+----+
```

- **特點**:
  1. 只允許訪問頂部元素。
  2. 支持高效的插入和刪除。

#### **常見操作**

```cpp
#include <stack>
#include <iostream>

int main() {
    std::stack<int> s;

    s.push(10);  // 添加元素
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        std::cout << s.top() << " "; // 訪問頂部元素
        s.pop();                      // 移除頂部元素
    }
    return 0;
}
```

#### **適用場景**

- 後進先出的場景，如函數調用棧。

---

### **4.2 std::queue**

#### **特性**

- 先進先出（FIFO）的數據結構。
- 基於 `std::deque` 或其他順序容器實現。

#### **結構圖解**

`std::queue` 的結構基於底層容器（默認為 `std::deque`）。

```
Front -> [10] [20] [30] <- Back
```

- **特點**:
  1. 只允許訪問頭部和尾部元素。
  2. 支持高效的插入和刪除。

#### **常見操作**

```cpp
#include <queue>
#include <iostream>

int main() {
    std::queue<int> q;

    q.push(10);  // 添加元素
    q.push(20);
    q.push(30);

    while (!q.empty()) {
        std::cout << q.front() << " "; // 訪問頭部元素
        q.pop();                        // 移除頭部元素
    }
    return 0;
}
```

#### **適用場景**

- 先進先出的場景，如任務隊列。

---

### **4.3 std::priority_queue**

#### **特性**

- 優先級隊列，元素按優先級排序。
- 默認基於最大堆實現。

#### **結構圖解**

`std::priority_queue` 的內部結構是一個堆，支持高效的最大值或最小值訪問。

```
[50]
      /    \
   [30]    [20]
   /  \    /  \
 [10] [5] [15] [1]
```

- **特點**:
  1. 元素按優先級排序（默認從大到小）。
  2. 支持高效的插入和取最大值操作。

#### **常見操作**

```cpp
#include <queue>
#include <iostream>

int main() {
    std::priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    while (!pq.empty()) {
        std::cout << pq.top() << " "; // 訪問最大元素
        pq.pop();                      // 移除最大元素
    }
    return 0;
}
```

#### **適用場景**

- 需要按優先級處理任務的場景。

---

以上內容涵蓋了 STL 容器的主要類型及其結構圖解。如果需要進一步詳細說明某個容器的特性或功能，請隨時告訴我！

