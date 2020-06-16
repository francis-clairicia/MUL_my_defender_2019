/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** return_to_menu.c
*/

#include "defend.h"

enum SCENE return_to_menu(tool_t *tools)
{
    cancel_changes(tools);
    return (MENU);
}