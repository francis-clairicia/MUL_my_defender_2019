/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** load_grid.c
*/

#include <fcntl.h>
#include <unistd.h>
#include "defend.h"
#include "my.h"
#include "mylist.h"

static char **my_list_to_word_array(list_t *list)
{
    list_t *node = NULL;
    int nb_rows = my_list_size(list);
    int i = 0;
    char **array = malloc(sizeof(char *) * (nb_rows + 1));

    if (array == NULL)
        return (NULL);
    for (node = list; node != NULL; node = node->next)
        array[i++] = (char *)(node->data);
    array[nb_rows] = NULL;
    return (array);
}

void load_grid(level_t *level, char const *grid_txt)
{
    int fd = open(grid_txt, O_RDONLY);
    char *buffer = NULL;
    list_t *grid = NULL;

    while (get_next_line(&buffer, fd))
        my_append_to_list(&grid, (long)my_strdup(buffer));
    level->grid.db = my_list_to_word_array(grid);
    my_free_list(&grid, 0);
    close(fd);
}