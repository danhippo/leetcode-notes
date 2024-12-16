# C++ `std::vector` 用法指南

## **簡介**
`std::vector` 是 C++ 中的一種動態數組容器，提供高效的隨機訪問與尾部操作功能，能自動調整大小，適合用於需要快速訪問與靈活大小的場景。

---

## **特性**
- 支持隨機訪問，時間複雜度為 \(O(1)\)。
- 支持自動動態調整大小，內部實現類似動態數組。
- 插入與刪除操作時間複雜度為：
  - 尾部操作：\(O(1)\)。
  - 中間插入或刪除：\(O(n)\)。

---

## **結構圖解**

`std::vector` 的內部結構類似於一個動態數組，內存是連續的，可以根據需要自動擴展。

```
+----+----+----+----+----+
| 10 | 20 | 30 | 40 |    |  <- 連續內存區
+----+----+----+----+----+
 ^
 起始地址
```

- **特點**:
  1. 所有元素存儲在連續內存中。
  2. 當內存空間不足時，會重新分配更大的內存並拷貝原有數據。
  3. 因為連續內存結構，支持高效的隨機訪問。

---

## **常見操作**

### **1. 宣告與初始化**
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1;                     // 空的 vector
    std::vector<int> vec2(5, 10);              // 5 個元素，每個值為 10
    std::vector<int> vec3 = {1, 2, 3, 4, 5};   // 使用列表初始化
    std::vector<int> vec4(vec3);               // 複製構造
    return 0;
}
```

---

### **2. 插入與刪除**
- **`push_back`**: 在尾部添加元素。
- **`pop_back`**: 移除尾部元素。
- **`insert`**: 在指定位置插入元素。
- **`erase`**: 移除指定位置或範圍內的元素。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4};

    vec.push_back(5);          // 添加 5
    vec.pop_back();            // 移除最後一個元素
    vec.insert(vec.begin(), 0); // 在開頭插入 0
    vec.erase(vec.begin() + 1); // 移除索引 1 的元素

    for (int v : vec) {
        std::cout << v << " ";
    }
    return 0;
}
```

---

### **3. 遍歷**
- **範圍 for-loop**:
```cpp
for (int val : vec) {
    std::cout << val << " ";
}
```

- **使用迭代器**:
```cpp
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}
```

---

### **4. 大小與容量**
- **`size`**: 返回當前元素數量。
- **`capacity`**: 返回容器分配的容量。
- **`resize`**: 改變容器大小，新增元素初始化為默認值。
- **`clear`**: 清空容器。

```cpp
std::vector<int> vec = {1, 2, 3};
std::cout << vec.size() << std::endl;    // 3
std::cout << vec.capacity() << std::endl; // 容器容量
vec.resize(5, 0);                        // 擴展為 5 個元素，多出來的部分為 0
vec.clear();                             // 清空所有元素
```

---

### **5. 隨機訪問**
- 支持索引運算符 `[]` 和 `at` 方法。
- **`[]`** 不檢查邊界；**`at`** 會檢查邊界並在越界時拋出異常。

```cpp
std::vector<int> vec = {1, 2, 3};
std::cout << vec[1] << std::endl;        // 2
std::cout << vec.at(1) << std::endl;     // 2
```

---

### **6. 排序與查找**
- **排序**: 使用 `std::sort` 函數對 `vector` 排序。
- **查找**: 使用 `std::find` 函數。

```cpp
#include <algorithm>
std::vector<int> vec = {3, 1, 2};
std::sort(vec.begin(), vec.end());       // 升序排序

// 查找
auto it = std::find(vec.begin(), vec.end(), 2);
if (it != vec.end()) {
    std::cout << "Found: " << *it << std::endl;
}
```

---

## **適用場景**
1. 須隨機訪問的情況。
2. 須頻繁進行尾部操作的情況。
3. 尺寸變化頻繁，需自動管理內存的情況。

---

## **完整範例**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {10, 20, 30};

    // 插入與刪除
    vec.push_back(40);
    vec.erase(vec.begin() + 1);

    // 遍歷
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 排序
    vec = {3, 1, 2};
    std::sort(vec.begin(), vec.end());
    for (int val : vec) {
        std::cout << val << " ";
    }

    return 0;
}
```

**輸出**:
```
10 30 40
1 2 3
```
