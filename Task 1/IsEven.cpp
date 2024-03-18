bool isEvenExample(int value) { return (value % 2) == 0; } //Оригинальная функция

bool isEven(int value) { return !(value & 1); } //Решение