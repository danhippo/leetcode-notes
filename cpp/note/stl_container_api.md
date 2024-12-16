# STL 容器 API 記憶圖表

C++ STL 容器的 API 命名規則清晰，將常用操作歸類並比較有助於記憶和快速掌握。以下是 STL 容器的操作分類圖表：

---

## **順序容器操作對比**

| **操作**         | **`std::vector`**        | **`std::deque`**         | **`std::list`**          |
|------------------|-------------------------|-------------------------|-------------------------|
| **插入尾部**     | `push_back`             | `push_back`             | `push_back`             |
| **插入頭部**     | 不支持                  | `push_front`            | `push_front`            |
| **插入中間**     | `insert`                | `insert`                | `insert`                |
| **刪除尾部**     | `pop_back`              | `pop_back`              | `pop_back`              |
| **刪除頭部**     | 不支持                  | `pop_front`             | `pop_front`             |
| **刪除中間**     | `erase`                 | `erase`                 | `erase`                 |
| **隨機訪問**     | 支持（`[]`, `at`）      | 支持（`[]`, `at`）      | 不支持                  |
| **遍歷**         | `begin`, `end`          | `begin`, `end`          | `begin`, `end`          |
| **清空**         | `clear`                 | `clear`                 | `clear`                 |

---

## **關聯容器操作對比**

| **操作**         | **`std::set`**          | **`std::map`**          | **`std::multiset`**     | **`std::multimap`**     |
|------------------|-------------------------|-------------------------|-------------------------|-------------------------|
| **插入元素**     | `insert`                | `insert`, `emplace`     | `insert`                | `insert`                |
| **刪除元素**     | `erase`                 | `erase`                 | `erase`                 | `erase`                 |
| **查找元素**     | `find`                  | `find`                  | `find`                  | `find`                  |
| **鍵範圍操作**   | `lower_bound`, `upper_bound` | `lower_bound`, `upper_bound` | `lower_bound`, `upper_bound` | `lower_bound`, `upper_bound` |
| **遍歷**         | `begin`, `end`          | `begin`, `end`          | `begin`, `end`          | `begin`, `end`          |
| **清空**         | `clear`                 | `clear`                 | `clear`                 | `clear`                 |

---

## **無序關聯容器操作對比**

| **操作**         | **`std::unordered_set`**| **`std::unordered_map`**| **`std::unordered_multiset`** | **`std::unordered_multimap`** |
|------------------|-------------------------|-------------------------|-------------------------------|-------------------------------|
| **插入元素**     | `insert`                | `insert`, `emplace`     | `insert`                      | `insert`                      |
| **刪除元素**     | `erase`                 | `erase`                 | `erase`                       | `erase`                       |
| **查找元素**     | `find`                  | `find`                  | `find`                        | `find`                        |
| **遍歷**         | `begin`, `end`          | `begin`, `end`          | `begin`, `end`                | `begin`, `end`                |
| **清空**         | `clear`                 | `clear`                 | `clear`                       | `clear`                       |

---

## **容器適配器操作對比**

| **操作**         | **`std::stack`**        | **`std::queue`**        | **`std::priority_queue`** |
|------------------|-------------------------|-------------------------|---------------------------|
| **插入元素**     | `push`                  | `push`                  | `push`                    |
| **刪除元素**     | `pop`                   | `pop`                   | `pop`                     |
| **訪問元素**     | `top`                   | `front`, `back`         | `top`                     |
| **清空**         | 無                      | 無                      | 無                        |

---



