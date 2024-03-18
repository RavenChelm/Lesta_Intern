### isEvenExample(int value) { return (value % 2) == 0 ; #
Плюс: Простая и понятная реализация;

Минус: Работает немного медленнее из-за вычисления результата операции %

### isEven(int value) { return !(value & 1); #
Плюс: Более эффективная реализация за счет использования операции & (побитовое И), так как берётся только последний бит числа

Минус: Менее интуитивная для понимания реализация