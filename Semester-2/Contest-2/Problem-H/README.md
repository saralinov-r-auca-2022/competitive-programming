# Книги

> Time limit: 2000 ms \
> Memory Limit: 262144 kB

Когда у Валеры появляется свободное время, он идет в
библиотеку почитать книги. Сегодня у него t свободных
минут для чтения. Поэтому Валера взял в библиотеке n книг
и для каждой книги прикинул время, которое ему понадобится
на ее прочтение. Пронумеруем книги целыми числами от 1 до n.
Валере нужно a[i] минут, чтобы прочитать i-ю книгу.

Валера решил выбрать произвольную книгу с номером i и
читать книги одну за другой, начиная с этой книги.
Другими словами, он сначала прочитает книгу номер i,
затем книгу номер i + 1, затем книгу номер
i + 2 и так далее. Он продолжает процесс до тех пор,
пока либо у него не закончится свободное время, либо пока
он не дочитает n-ю книгу. Валера дочитывает каждую книгу
до конца, то есть он не приступает к чтению книги, если
у него недостаточно свободного времени, чтобы дочитать ее.

Распечатайте максимальное количество книг, которые сможет
прочитать Валера.

## Входные данные

В первой строке записаны два целых числа n и t
(1 ≤ n ≤ 105; 1 ≤ t ≤ 109)
— количество книг и количество свободных минут, которые
получил Валера. Во второй строке записана последовательность
из n целых чисел a1, a2,..., an (1 ≤ ai ≤ 104), где число
a[i] показывает количество минут, которое нужно ему для чтения i-й книги.

## Выходные данные

Выведите единственное целое число — максимальное
количество книг, которые может прочитать Валера.

## Пример

| Входные данные    | Выходные данные |
|:------------------|:----------------|
| 4 5 <br/> 3 1 2 1 | 3               |
| 3 3 <br/> 2 2 3   | 1               |
