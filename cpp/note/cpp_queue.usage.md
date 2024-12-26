
# C++ Queue 使用指南

C++ 提供了 `std::queue` 作為一種先進先出（FIFO, First In First Out）的數據結構。`std::queue` 位於標頭檔案 `<queue>` 中，並且通常用於需要按順序處理數據的場景。

以下是 `std::queue` 的主要用法，包括所有常用函數的詳細說明（包含輸入與輸出）。

---

## **1. 引入標頭檔案**

```cpp
#include <queue>
#include <iostream>
using namespace std;
```

---

## **2. 宣告與初始化**

### 範例

```cpp
queue<int> q; // 宣告一個空的整數型隊列
```

- **輸入**：無
- **輸出**：創建一個空的隊列對象

---

## **3. 常用成員函數**

### **3.1 `push()` - 插入元素到隊列尾部**

```cpp
q.push(value);
```

- **輸入**：要插入的值 `value`（類型與隊列一致）
- **輸出**：將元素加入隊列尾部，隊列長度增加 1

### 範例：

```cpp
q.push(10); // 隊列內容：[10]
q.push(20); // 隊列內容：[10, 20]
```

---

### **3.2 `pop()` - 移除隊列頭部元素**

```cpp
q.pop();
```

- **輸入**：無
- **輸出**：移除隊列頭部的元素，隊列長度減少 1。此操作不返回被移除的元素。
- **注意**：如果隊列為空，調用 `pop()` 會導致未定義行為。

### 範例：

```cpp
q.pop(); // 隊列內容：[20]
```

---

### **3.3 `front()` - 獲取隊列頭部元素**

```cpp
type value = q.front();
```

- **輸入**：無
- **輸出**：返回隊列頭部的元素（不移除）。
- **注意**：如果隊列為空，調用 `front()` 會導致未定義行為。

### 範例：

```cpp
int value = q.front(); // value = 20
```

---

### **3.4 `back()` - 獲取隊列尾部元素**

```cpp
type value = q.back();
```

- **輸入**：無
- **輸出**：返回隊列尾部的元素（不移除）。
- **注意**：如果隊列為空，調用 `back()` 會導致未定義行為。

### 範例：

```cpp
int value = q.back(); // value = 20
```

---

### **3.5 `empty()` - 檢查隊列是否為空**

```cpp
bool isEmpty = q.empty();
```

- **輸入**：無
- **輸出**：返回布林值 `true` 或 `false`，表示隊列是否為空。

### 範例：

```cpp
if (q.empty()) {
    cout << "Queue is empty" << endl;
}
```

---

### **3.6 `size()` - 獲取隊列元素數量**

```cpp
size_t count = q.size();
```

- **輸入**：無
- **輸出**：返回 `size_t` 類型的數字，表示隊列中當前的元素數量。

### 範例：

```cpp
size_t count = q.size(); // count = 1
```

---

## **4. 使用範例**

以下是一個完整範例，展示如何使用上述函數。

### 程式碼：

```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> q;

    // 插入元素
    q.push(10);
    q.push(20);
    q.push(30);

    // 獲取隊列頭部和尾部元素
    cout << "Front element: " << q.front() << endl; // 輸出：10
    cout << "Back element: " << q.back() << endl;   // 輸出：30

    // 移除隊列頭部元素
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // 輸出：20

    // 獲取隊列大小
    cout << "Queue size: " << q.size() << endl; // 輸出：2

    // 檢查隊列是否為空
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue is not empty." << endl; // 輸出：Queue is not empty.
    }

    return 0;
}
```

### 輸出：

```
Front element: 10
Back element: 30
Front element after pop: 20
Queue size: 2
Queue is not empty.
```

---

## **5. 注意事項**

1. **`pop()` 和 `front()` / `back()` 操作需要確保隊列非空**：
   
   - 在調用這些函數前，最好使用 `empty()` 檢查隊列是否為空。
2. **僅能操作隊列頭部和尾部的元素**：
   
   - `std::queue` 不支援遍歷或隨機訪問，僅能進行 FIFO 操作。

---

## **6. 常見應用場景**

1. **多任務排程**（例如處理任務隊列）。
2. **廣度優先搜索**（BFS）。
3. **數據流處理**（例如消息隊列）。

