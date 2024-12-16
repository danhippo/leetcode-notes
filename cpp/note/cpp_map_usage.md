# C++ `std::map` 用法整理

## 基本概念
- `std::map` 是基於平衡二叉搜索樹（如紅黑樹）實現的，元素按鍵自動排序。
- 鍵必須是唯一的。
- 存取的時間複雜度為 \(O(\log n)\)。

---

## 常見操作

### 宣告與初始化
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // 初始化方式
    std::map<int, std::string> myMap2 = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    return 0;
}
```
**說明**:
- **輸入**: 無需特定輸入，僅需定義鍵值類型。
- **返回值**: 無返回值，但初始化一個空的 `std::map` 容器。

---

### 插入元素
```cpp
myMap.insert(std::make_pair(4, "Four"));
myMap[5] = "Five"; // 也可用 [] 運算符
myMap.insert({3, "Three"}); // 使用列表初始化
```
**說明**:
- **輸入**: `insert` 接收一個鍵值對，可以是 `std::pair` 或列表初始化的格式（如 `{key, value}`）。
- **返回值**: 
  - `insert` 返回一個 `std::pair`，第一個元素是迭代器，指向插入的鍵值對；第二個元素是布爾值，表示插入是否成功。
  - `[]` 運算符返回對應值的引用。

範例:
```cpp
myMap.insert(std::make_pair(6, "Six")); // 使用 std::make_pair
myMap.insert({7, "Seven"});            // 使用列表初始化
```
**注意**: `std::make_pair` 與 `{key, value}` 是兩種等價的插入方式，建議使用 `{}` 更簡潔。

---

### 存取元素
```cpp
std::cout << myMap[4] << std::endl;    // 使用鍵存取值
std::cout << myMap.at(4) << std::endl; // 建議使用 at，避免鍵不存在時引發問題
```
**說明**:
- **輸入**: 鍵值（`int` 或其他鍵類型）。
- **返回值**: 
  - `[]`: 返回鍵對應的值（若鍵不存在，會插入一個默認值）。
    - **默認值**: 
      - 數值型（如 `int`）：`0`
      - 字串型（如 `std::string`）：空字串 `""`
      - 指針型：`nullptr`
  - `at`: 返回鍵對應的值（若鍵不存在，會拋出異常 `std::out_of_range`）。

範例:
```cpp
std::map<int, std::string> myMap;
std::cout << "Value for key 10: " << myMap[10] << std::endl; // 默認插入空字串
std::cout << "Map size: " << myMap.size() << std::endl;      // Map size: 1
```

---

### 查找元素
```cpp
std::map<int, std::string>::iterator it = myMap.find(4);
if (it != myMap.end()) {
    std::cout << "Found key 4 with value: " << it->second << std::endl;
} else {
    std::cout << "Key 4 not found." << std::endl;
}
```
**說明**:
- **輸入**: 鍵值。
- **返回值**: 返回一個迭代器，指向鍵對應的元素；若鍵不存在，返回 `end()`。

---

### 刪除元素
```cpp
myMap.erase(4); // 刪除鍵為 4 的元素
myMap.clear();  // 清空 map
```
**說明**:
- **輸入**: `erase` 接收鍵值或迭代器；`clear` 無需輸入。
- **返回值**: `erase` 返回刪除元素的個數（若為鍵值輸入）；`clear` 無返回值。

---

### 檢查元素
```cpp
if (myMap.find(4) != myMap.end()) {
    std::cout << "Key 4 exists." << std::endl;
}

if (myMap.count(4) > 0) {
    std::cout << "Key 4 exists." << std::endl;
}
```
**說明**:
- **輸入**: 鍵值。
- **返回值**: `find` 返回迭代器；`count` 返回鍵出現的次數（對於 `std::map`，僅為 0 或 1）。

---

## 迭代

### 使用迭代器遍歷
```cpp
for (std::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```
**說明**:
- **輸入**: 無。
- **返回值**: 通過迭代器訪問每個鍵值對。

---

### 使用範圍 for-loop
```cpp
for (std::pair<const int, std::string>& entry : myMap) {
    std::cout << entry.first << ": " << entry.second << std::endl;
}
```
**說明**:
- **輸入**: 無。
- **返回值**: 直接訪問每個鍵值對，簡化語法。

---

## 其他功能

### 大小與空檢查
```cpp
if (myMap.empty()) {
    std::cout << "Map is empty." << std::endl;
}

std::cout << "Map size: " << myMap.size() << std::endl;
```
**說明**:
- **輸入**: 無。
- **返回值**: `empty` 返回布爾值；`size` 返回鍵值對的數量。

---

### 上下界操作
```cpp
std::map<int, std::string>::iterator it = myMap.lower_bound(2); // 鍵 >= 2 的第一個元素
if (it != myMap.end()) {
    std::cout << "Lower bound: " << it->first << std::endl;
}

it = myMap.upper_bound(2); // 鍵 > 2 的第一個元素
if (it != myMap.end()) {
    std::cout << "Upper bound: " << it->first << std::endl;
}
```
**說明**:
- **輸入**: 鍵值。
- **返回值**: 返回指向符合條件的第一個元素的迭代器；若無符合條件的元素，返回 `end()`。

---

### 合併與交換
```cpp
std::map<int, std::string> map1 = {{1, "A"}, {2, "B"}};
std::map<int, std::string> map2 = {{3, "C"}, {4, "D"}};

map1.swap(map2);
```
**說明**:
- **輸入**: 另一個 `std::map`。
- **返回值**: 無返回值，直接交換兩個容器的內容。

---

## 完整範例
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // 插入元素
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap.insert({3, "Three"});

    // 遍歷
    for (std::map<int, std::string>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    // 查找
    std::map<int, std::string>::iterator it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found key 2 with value: " << it->second << std::endl;
    } else {
        std::cout << "Key 2 not found." << std::endl;
    }

    // 刪除
    myMap.erase(2);

    // 大小檢查
    std::cout << "Map size: " << myMap.size() << std::endl;

    return 0;
}
```
