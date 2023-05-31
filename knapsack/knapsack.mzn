% Включаем данные из файла data.dzn
%include "data.dzn";

% Определяем переменные
int: N;
int: W;
array[1..N] of int: values;
array[1..N] of int: weights;

% Определяем переменные-решения
array[1..N] of var 0..1: x;

% Определяем функцию стоимости содержимого рюкзака
var int: cost=sum(i in 1..N)(x[i]*values[i]);

% Определяем ограничение на вес содержимого рюкзака
constraint sum(i in 1..N)(x[i]*weights[i])<=W;

% Указываем, что стоимость содержимого рюкзака должна быть максимальной
solve maximize cost;

% Выводим результаты
output["Total value: " ++ show(cost) ++ "\n"];
