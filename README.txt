README.txt

int			get_next_line(int fd, char **line);
основная функция;
возвращает -1 если произошла ошибка.
возвращает 0, если достигли конца файла.
возвращает 1, если строка была прочитана.

int			ft_memsearch(char *mem);
ищет в строке mem символ '\n'. если находит, 
то возвращает 1, если не находит, то возвращает 0.

int			ft_free(char *mem);
чистит память mem и устанавливает указателю значение NULL.
если на вход приходит нулевой указатель, то сразу выходит.
всегда возвращает -1.

size_t		ft_strlen(char *s);
возвращает длину строки s.
если на вход приходит нулевой указатель, то сразу возвращает 0.

char		*ft_strjoin(char *s1, char *s2);
создает новую строку, используя malloc.
если на вход подали два нулевых указателя, то сразу выходит и возвращает 0.
если сущестует только одна из строк, то вернет ее копию.
передает в функцию ft_free строку s1, после копирования.

char			*ft_get_line(char *str);
функция создает копию строки от начала до '\n' или до '\0'.
использует malloc.
??? нужно ли чистить, если мы не смогли алоцировать новую память?????