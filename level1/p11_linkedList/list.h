#pragma once
#include<stdio.h>
#include<stdlib.h>

struct list
{
    int value;
    list* next_p;

    void Add_List_Unit_After_List_Unit(int new_value);

    void Delete_List_Unit_After_List_Unit();
};

void Change_Dirtionn(list* head_list);
list* Creat_List_By_array(int* arr, int size);
void Print_List(list* head_list);
void Find_Value(list* head_list, int value);