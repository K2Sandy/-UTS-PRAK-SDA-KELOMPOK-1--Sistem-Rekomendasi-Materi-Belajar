#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// ============================================================
// linked_list.h — Linked List (Daftar Belajar) & Insertion Sort
// ============================================================

#include "materi.h"

typedef struct ListNode {
    Materi           data;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} PlaylistLinkedList;

void initLinkedList        (PlaylistLinkedList* list);
void tambahMateri          (PlaylistLinkedList* list, Materi m);
void tampilkanPlaylist     (PlaylistLinkedList* list);
void insertionSortByDurasi  (PlaylistLinkedList* list);
void insertionSortByKesulitan(PlaylistLinkedList* list);

#endif // LINKED_LIST_H
