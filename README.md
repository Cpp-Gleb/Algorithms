# Algorithms
В Данном репозитории будут расписаны все алгоритмы 1 курса ИС ИТМО с кодом (C++) и удобным конспектом для повторения 

# Полная Шпаргалка по Алгоритмам и Структурам Данных

Ниже представлена **полная шпаргалка** по основным алгоритмам и структурам данных, включая все 22 темы:

1. Оценка сложности алгоритма по времени  
2. Оценка сложности алгоритма по памяти  
3. Сортировка вставками  
4. Сортировка слиянием  
5. Быстрая сортировка (схемы Ломуто и Хоара)  
6. Сортировка подсчётом (асимптотика, min/max, префиксные суммы)  
7. Цифровая сортировка (Radix sort)  
8. Стек  
9. Очередь  
10. Односвязный список  
11. Двусвязный список  
12. Циклический список  
13. Стек на списках  
14. Очередь на списках  
15. Бинарный поиск (включая «поиск по ответу», тернарный поиск)  
16. Пирамида (подробно про просеивание вверх/вниз, min-/max-heap)  
17. Пирамидальная сортировка  
18. Приоритетная очередь  
19. Двоичное дерево поиска (BST) (удаление + обходы pre/in/post)  
20. AVL (4 типа поворотов)  
21. Динамическое программирование (рюкзак, НВП, редакционное расстояние, расстановка скобок, черепашка, кузнечик)  
22. Кодирование (Хаффман, Хемминг, арифметическое)

---

## 1. Оценка сложности алгоритма по времени

**Что это**  
Анализируем, как количество элементарных операций зависит от размера входных данных \(n\). Используем асимптотические обозначения: Big-O \(O\), Big-Theta \($\Theta\), Big-Omega \(\Omega\)$.

**Методы оценки**  
- Анализ циклов, рекуррентных соотношений, сумм и т.д.
- Пример: Merge Sort — \(T(n)=2T(n/2)+O(n)\) → \(O(nlog n)\).
- Мастер-теорема для рекуррентностей вида \(T(n)=aT(n/b)+f(n)\).

**Примеры**  
- Константная \(O(1)\)  
- Логарифмическая \(O(log n)\)  
- Линейная \(O(n)\)  
- Линейно-логарифмическая \(O(nlog n)\)  
- Квадратичная \(O(n^2)\)  
- Экспоненциальная \(O(2^n)\)  
- Факториальная \(O(n!)\)

---

## 2. Оценка сложности алгоритма по памяти 

**Что это**  
Смотрим объём дополнительной памяти, требуемой алгоритмом.

**Основные случаи**  
- \(O(1)\): in-place (пример: быстрая сортировка)  
- \(O(n)\): сортировка слиянием  
- \(O(log n)\): рекурсивный стек (быстрая сортировка)  
- \(O(n^k)\): некоторые DP

**Примеры**  
- Merge Sort: \(O(n)\) доп. памяти  
- Quick Sort (in-place): \(O(log n)\) на стек рекурсии

---

## 3. Сортировка вставками (Insertion Sort)

**Идея**  
Пошагово вставляем элемент \(A[i]\) в уже отсортированную часть \(A[0..i-1]\).

**Псевдокод**  
```
    for i in [1..n-1]:
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j = j - 1
        A[j + 1] = key
```
**Сложность**  
- Худшая/средняя: \(O(n^2)\)  
- Лучшая (почти отсортирован): \(O(n)\)

**Память**  
- in-place (\(O(1)\))

---

## 4. Сортировка слиянием (Merge Sort)

**Идея**  
Делим массив пополам, рекурсивно сортируем половины, сливаем результаты.

**Псевдокод**  
```
    merge_sort(A, left, right):
        if left >= right:
            return
        mid = (left + right)//2
        merge_sort(A, left, mid)
        merge_sort(A, mid+1, right)
        merge(A, left, mid, right)

    merge(A, left, mid, right):
        // слияние двух отсортированных подмассивов
        // требуется доп. массив
```
**Сложность**  
- \(O(n log n)\) во всех случаях  
- Память \(O(n)\)  

Устойчивая сортировка.

---

## 5. Быстрая сортировка (Quicksort) — Ломуто / Хоара

**Идея**  
- Выбор pivot  
- Разделение массива на < pivot и > pivot  
- Рекурсивная сортировка двух частей

### 5.1 Схема Ломуто (Lomuto)

**Псевдокод**  
```
    partition_lomuto(A, low, high):
        pivot = A[high]
        i = low - 1
        for j in [low..high-1]:
            if A[j] <= pivot:
                i++
                swap A[i], A[j]
        swap A[i+1], A[high]
        return i+1
```
### 5.2 Схема Хоара (Hoare)

**Псевдокод**  
```
    partition_hoare(A, low, high):
        pivot = A[(low+high)//2]
        i = low - 1
        j = high + 1
        while true:
            do i++ while A[i] < pivot
            do j-- while A[j] > pivot
            if i >= j:
                return j
            swap A[i], A[j]
```

**Сравнение Ломуто vs Хоара:**

**Ломуто:**
- Проще в реализации.
- Неустойчива.
- Могут быть дополнительные свопы.

**Хоара:**
- Быстрее на практике за счёт меньшего количества обменов.
- Требует более тщательной реализации.
- Может не разделять массив идеально при наличии дубликатов.

**Сложность**  
- Среднее: \(O(n log n)\)  
- Худшее: \(O(n^2)\)  
- Память: in-place + стек рекурсии \(log n\)

---

## 6. Сортировка подсчётом (Counting Sort)

**Идея**  
Для целочисленных данных с диапазоном \([0..k]\). Подсчитываем количество вхождений каждого значения, затем формируем выход.

**Псевдокод**  
```
    counting_sort(A, n, k):
        C = array of size (k+1) with 0
        for i in [0..n-1]:
            C[A[i]]++
        index = 0
        for v in [0..k]:
            while C[v] > 0:
                A[index] = v
                index++
                C[v]--
```
### Оптимизация на min/max  
Определяем min_val, max_val → уменьшаем размер массива.

### Стабильный вариант (префиксные суммы)  
Формируем кумулятивный массив C → можно получить устойчивую сортировку.

```
counting_sort_stable(A, B, n, k):
    C = array of size (k + 1) initialized to 0
    for i = 0 to n - 1:
        C[A[i]] = C[A[i]] + 1
    // Префиксные суммы
    for v = 1 to k:
        C[v] = C[v] + C[v - 1]
    // Сортировка
    for i = n - 1 downto 0:
        val = A[i]
        C[val] = C[val] - 1
        B[C[val]] = val
    // Копирование обратно
    for i = 0 to n - 1:
        A[i] = B[i]
```

**Сложность**  
- Время: \(O(n + k)\)  
- Память: \(O(k)\)

---

## 7. Цифровая сортировка (Radix Sort)

**Идея**  
- Сортируем числа поразрядно, начиная с наименее значимого (LSB) или наиболее значимого (MSB).  
- Используем устойчивую сортировку, например Counting Sort, на каждом разряде.

**Сложность**  
- \(O(d \times (n + k))\), где \(d\) — число разрядов, \(k\) — размер алфавита (обычно 10).

---

## 8. Стек

**Свойство**  
- LIFO (Last In, First Out).

**Основные операции**  
- push(x) — в вершину  
- pop() — из вершины  
- top() / peek() — посмотреть вершину

**Сложность**  
- Все операции за \(O(1)\).

---

## 9. Очередь

**Свойство**  
- FIFO (First In, First Out).

**Основные операции**  
- enqueue(x) — в хвост  
- dequeue() — из головы  
- front() — посмотреть голову

**Сложность**  
- Все операции за \(O(1)\).

---

## 10. Односвязный список

**Структура**  
- Узлы: {data, next}  
- Вставка/удаление за \(O(1)\), если знаем позицию

**Недостатки**  
- Поиск элемента за \(O(n)\)

---

## 11. Двусвязный список

**Структура**  
- Узлы: {data, next, prev}  
- Удобно идти влево и вправо.

**Операции**  
- insert_before(node, x), insert_after(node, x) → \(O(1)\)

---

## 12. Циклический список

**Что это**  
- Последний узел указывает на первый.

**Применение**  
- Моделирование круговых процессов, игр.

---

## 13. Стек на списках

**Идея**  
- Реализуем стек (LIFO) с помощью односвязного списка:
  - push(x) → вставить в голову,
  - pop() → удалить из головы.

---

## 14. Очередь на списках

**Идея**  
- Реализуем очередь (FIFO) с помощью списка:
  - enqueue(x) → вставить в хвост,
  - dequeue() → удалить из головы.

---

## 15. Бинарный поиск (Binary Search) — поиск по ответу, тернарный поиск

### Классический бинарный поиск

```
binary_search(A, left, right, x):
    while left <= right:
        mid = left + (right - left) // 2
        if A[mid] == x:
            return mid
        elif A[mid] < x:
            left = mid + 1
        else:
            right = mid - 1
    return -1 // не найден

```

- Ищем элемент x в **отсортированном** массиве.
- \(log n\) сравнений.

### Поиск по ответу (Binary Search on Answer)

```
binary_search_on_answer(L, R):
    while L < R:
        mid = L + (R - L) // 2
        if check(mid):
            R = mid
        else:
            L = mid + 1
    return L

```

- Ищем минимальное/максимальное значение, удовлетворящее условию `check(mid)`.
- Пример: минимальное время, в которое можно уложиться.

### Тернарный поиск (Ternary Search)

```
ternary_search(left, right, condition):
    while (right - left) > someEpsilon:
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3
        if condition(mid1) > condition(mid2):
            left = mid1
        else:
            right = mid2
    return (left + right) / 2

```

- Делим отрезок на 3 части, сравниваем f(mid1), f(mid2).
- Используется при **унемодальных функциях**.

**Применение:**

- Поиск экстремума (минимума/максимума) функции на отрезке.
- Оптимизация параметров в задачах с выпуклыми или вогнутыми функциями.

**Сложность:**
O(log(R−L)), аналогично бинарному поиску, но с константой в три раза большей.

---

## 16. Пирамида (Binary Heap) — просеивания, min-heap / max-heap

**Что это**  
- Полное бинарное дерево в массиве.
- **Max-Heap**: родитель ≥ дети, **Min-Heap**: родитель ≤ дети.

### Просеивание вниз (Sift-Down)
```
    sift_down_max(A, i, n):
        largest = i
        left = 2i + 1
        right = 2i + 2
        ...
        if largest != i:
            swap A[i], A[largest]
            sift_down_max(A, largest, n)
```
### Просеивание вверх (Sift-Up)
```
    sift_up_max(A, i):
        while i > 0 and A[parent(i)] < A[i]:
            swap A[i], A[parent(i)]
            i = parent(i)
```
**Сложность**  
- insert: \(O(log n)\)
- extract_max/min: \(O(log n)\)
- build_heap: \(O(n)\)

---

## 17. Пирамидальная сортировка (Heapsort)

**Идея**  
- Построить max-heap,
- многократно `extract_max` и ставить элемент в конец массива.

**Псевдокод**  
```
    heapsort(A, n):
        build_max_heap(A, n)
        for i in [n-1..1]:
            swap A[0], A[i]
            sift_down_max(A, 0, i)
```
**Сложность**  
- \(O(n log n)\)
- In-place
- Неустойчива

---

## 18. Приоритетная очередь

**Что это**  
- Поддерживает быстрый доступ к max или min элементу.

**Реализация**  
- Max-heap или min-heap.

**Сложность**  
- insert: \(O(log n)\)
- extract_max/min: \(O(log n)\)
- peek: \(O(1)\)

---

## 19. Двоичное дерево поиска (BST) — удаление + обходы pre/in/post

**Свойства**  
- Для каждого узла: левое поддерево < ключ, правое поддерево > ключ.

### Операции

#### Поиск (search) / Вставка (insert)
- Средний \(log n\), худший \(n\).

#### Удаление (delete)
```
    delete_bst(root, key):
        if root == null:
            return root
        if key < root.key:
            root.left = delete_bst(root.left, key)
        elif key > root.key:
            root.right = delete_bst(root.right, key)
        else:
            // нашёл узел
            if root.left == null:
                return root.right
            elif root.right == null:
                return root.left
            temp = find_min(root.right)
            root.key = temp.key
            root.right = delete_bst(root.right, temp.key)
        return root
```
#### Виды обходов (pre/in/post)

1. **Pre-order**: (Корень) → (Левое) → (Правое)
```
       pre_order(node):
           if node == null:
               return
           visit(node)
           pre_order(node.left)
           pre_order(node.right)
```
2. **In-order**: (Левое) → (Корень) → (Правое)
```
       in_order(node):
           if node == null:
               return
           in_order(node.left)
           visit(node)
           in_order(node.right)
```
3. **Post-order**: (Левое) → (Правое) → (Корень)
```
       post_order(node):
           if node == null:
               return
           post_order(node.left)
           post_order(node.right)
           visit(node)
```
**Значение in-order для BST**  
- Даёт отсортированный список ключей.

---

## 20. AVL — повороты (LL, RR, LR, RL)

**Что это**  
- Все основные операции за O(log(n))
- Самобалансирующееся BST: \(|height(left) - height(right)| \le 1\).

**Основные дисбалансы**

1. LL-случай: left rotation.
- Баланс-фактор родителя: +2.
- Баланс-фактор левого ребёнка: +1. 
 
2. RR-случай: right rotation.  
- Баланс-фактор родителя: -2.
- Баланс-фактор левого ребёнка: -1.  

3. LR-случай: big left rotation.  
- Баланс-фактор родителя: +2.
- Баланс-фактор левого ребёнка: -1.  

4. RL-случай: big right rotation.
- Баланс-фактор родителя: -2.
- Баланс-фактор левого ребёнка: +1.  


**Вставка/удаление**  
- После обычного BST-вставки/удаления проверяем баланс, выполняем нужный поворот.

**Сложность**  
- Поиск/вставка/удаление: \(O(log n)\).

---

## 21. Динамическое программирование (DP) — простые задачи (рюкзак, НВП, редакционное расстояние, знаки, черепашка, кузнечик)

**Идея**  
- Разбиваем задачу на подзадачи, храним результаты, не пересчитываем повторно.

### 21.1 Рюкзак (0-1)

    dp[w] = max(dp[w], dp[w - weight[i]] + cost[i])

### 21.2 НВП (LIS)

    dp[i] = 1 + max_{j < i, A[j] < A[i]} dp[j]

### 21.3 Редакционное расстояние

    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) // если s[i]!=t[j]

### 21.4 Расстановка скобок (матрицы)

    dp[i][j] = min over k of dp[i][k]+dp[k+1][j] + cost

### 21.5 Черепашка (Grid Path)

    dp[i][j] = dp[i-1][j] + dp[i][j-1]

### 21.6 Кузнечик (Frog Jump)

    dp[i] = dp[i-1] + dp[i-2]

---

## 22. Кодирование (Хаффман, Хемминг, арифметическое)

### 22.1 Хаффман

- Построение дерева на основе частот символов.
- Префиксные коды.

### 22.2 Хемминг

- Добавляем проверочные биты для обнаружения/исправления одиночных ошибок.

### 22.3 Арифметическое

- Интервал [0..1), сужается при каждом символе, даёт дробное число как код.

---
