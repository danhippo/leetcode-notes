# C++ Stack 使用指南

C++ 提供了 `std::stack` 作為一種後進先出（LIFO, Last In First Out）的數據結構。`std::stack` 位於標頭檔案 `<stack>` 中，並且通常用於需要臨時儲存數據的場景。

以下是 `std::stack` 的主要用法，包括所有常用函數的詳細說明（包含輸入與輸出）。

---

## **1. 引入標頭檔案**

```cpp
#include <stack>
#include <iostream>
using namespace std;
```

---

## **2. 宣告與初始化**

### 範例

```cpp
stack<int> s; // 宣告一個空的整數型堆疊
```

- **輸入**：無
- **輸出**：創建一個空的堆疊對象

---

## **3. 常用成員函數**

### **3.1 `push()` - 插入元素到堆疊頂部**

```cpp
s.push(value);
```

- **輸入**：要插入的值 `value`（類型與堆疊一致）
- **輸出**：將元素壓入堆疊頂部，堆疊長度增加 1

### 範例：

```cpp
s.push(10); // 堆疊內容：[10]
s.push(20); // 堆疊內容：[10, 20]
```

---

### **3.2 `pop()` - 移除堆疊頂部元素**

```cpp
s.pop();
```

- **輸入**：無
- **輸出**：移除堆疊頂部的元素，堆疊長度減少 1。此操作不返回被移除的元素。
- **注意**：如果堆疊為空，調用 `pop()` 會導致未定義行為。

### 範例：

```cpp
s.pop(); // 堆疊內容：[10]
```

---

### **3.3 `top()` - 獲取堆疊頂部元素**

```cpp
type value = s.top();
```

- **輸入**：無
- **輸出**：返回堆疊頂部的元素（不移除）。
- **注意**：如果堆疊為空，調用 `top()` 會導致未定義行為。

### 範例：

```cpp
int value = s.top(); // value = 10
```

---

### **3.4 `empty()` - 檢查堆疊是否為空**

```cpp
bool isEmpty = s.empty();
```

- **輸入**：無
- **輸出**：返回布林值 `true` 或 `false`，表示堆疊是否為空。

### 範例：

```cpp
if (s.empty()) {
    cout << "Stack is empty" << endl;
}
```

---

### **3.5 `size()` - 獲取堆疊元素數量**

```cpp
size_t count = s.size();
```

- **輸入**：無
- **輸出**：返回 `size_t` 類型的數字，表示堆疊中當前的元素數量。

### 範例：

```cpp
size_t count = s.size(); // count = 1
```

---

## **4. 使用範例**

以下是一個完整範例，展示如何使用上述函數。

### 程式碼：

```cpp
#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> s;

    // 插入元素
    s.push(10);
    s.push(20);
    s.push(30);

    // 獲取堆疊頂部元素
    cout << "Top element: " << s.top() << endl; // 輸出：30

    // 移除堆疊頂部元素
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // 輸出：20

    // 獲取堆疊大小
    cout << "Stack size: " << s.size() << endl; // 輸出：2

    // 檢查堆疊是否為空
    if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack is not empty." << endl; // 輸出：Stack is not empty.
    }

    return 0;
}
```

### 輸出：

```
Top element: 30
Top element after pop: 20
Stack size: 2
Stack is not empty.
```

---

## **5. 注意事項**

1. **`pop()` 和 `top()` 操作需要確保堆疊非空**：
   
   - 在調用這些函數前，最好使用 `empty()` 檢查堆疊是否為空。
2. **僅能操作堆疊頂部的元素**：
   
   - `std::stack` 不支援遍歷或隨機訪問，僅能進行 LIFO 操作。

---

## **6. 常見應用場景**

1. **括號匹配**（例如有效括號判斷）。
2. **深度優先搜索**（DFS）。
3. **撤銷/回退操作**的實現。



