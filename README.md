# Лабараторная работа по внутренним сортировкам


## Теория:


### Сортировка вставками
- реализована в функции `insertion_sort()~

### Сортировка методом пузырька

- улучшения: 
- 1. Запоминаем были или не были перестановки. Если во время прохода не было ни одной перестановки, то процесс сортировки можно завершать
- 2. Если запомнить индекс элемента с последним обменом, то все элементы до этого индекса уже упорядоченны, а значит отсортированную часть можно увеличить. 

### Сортировка выбором
- реализована в функции `choice_sort()`

### Сортировка Шелла
- реализована в функции `shell_sort()`

### Сортировка Шейкерная

### Сортировка двоичным делением