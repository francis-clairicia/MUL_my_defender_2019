/*
** EPITECH PROJECT, 2020
** main
** File description:
** execute my_defender
*/

#include <stddef.h>
#include "my.h"

int my_defender(void);

static int valid_environment(char **envp)
{
    int i = 0;

    if (envp[0] == NULL)
        return (0);
    while (envp[i] != NULL) {
        if (my_strncmp(envp[i], "DISPLAY", my_strlen("DISPLAY")) == 0)
            return (1);
        i += 1;
    }
    return (0);
}

int main(int ac __attribute__((unused)),
    char **av __attribute__((unused)), char **envp)
{
    if (!valid_environment(envp))
        return (84);
    return (my_defender());
}