/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** clock.c
*/

#include <SFML/System/Clock.h>

int elapsed_time(float milliseconds, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    int output = 0;

    if ((time.microseconds / 1000.0) >= milliseconds) {
        output = 1;
        sfClock_restart(clock);
    }
    return (output);
}