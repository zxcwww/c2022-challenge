#include"list.h" 
void list::Add_List_Unit_After_List_Unit(int new_value) {
    if (next_p == NULL) {
        next_p = (list*)malloc(sizeof(list));
        next_p->next_p = NULL;
        next_p->value = new_value;
    }
    else {
        list* p_save = next_p;
        next_p = (list*)malloc(sizeof(list));
        next_p->value = new_value;
        next_p->next_p = p_save;
    }
}

void list::Delete_List_Unit_After_List_Unit() {
    if (next_p != NULL) {
        if (next_p->next_p != NULL) {
            list* p_save = next_p->next_p;
            free(next_p);
            next_p = p_save;
        }
        else {

            free(next_p);
        }
    }
}
void Change_Dirtionn(list* head_list) {
    list* p_0, * p_1, * p_2;
    p_0 = head_list->next_p;
    p_1 = p_0->next_p;
    p_2 = p_1->next_p;

    p_0->next_p = NULL; 

    while (1) {
        p_2 = p_1->next_p;
        p_1->next_p = p_0;

        if (p_2 != NULL) {

            p_0 = p_1;
            p_1 = p_2;

        }
        else {
            head_list->next_p = p_1;
            break;
        }

    }
    }
list* Creat_List_By_array(int* arr,int size) {
    list* p_mark = (list*)malloc(sizeof(list));
    list* p_head = p_mark;
    for (int i = 0;i<size; i++) {
        
        p_mark->Add_List_Unit_After_List_Unit(arr[i]);
        p_mark = p_mark->next_p;
    }
    p_mark->next_p = NULL;
    return p_head;

}
void Print_List(list* head_list) {
    list* p_mark=head_list->next_p;
    while (1) {
        if (p_mark != NULL) {
            printf("%d\n", p_mark->value);
            p_mark = p_mark->next_p;
        }
        else {
            break;
        }
    }
}
void Find_Value(list* head_list,int value) {
    list* p_mark = head_list->next_p;
    int found = 0;
    for (int i = 0;;i++) {
        if (p_mark != NULL) {
            if (p_mark->value == value) {
                found = 1;
                printf("%d,", i);
            }
            p_mark = p_mark->next_p;
        }
        else {
            break;
        }
    }
    if (!found) {
        printf("-1");
    }

}
