#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

// ============================================================
// linked_list.c — Implementasi Linked List & Insertion Sort
// ============================================================

void initLinkedList(PlaylistLinkedList* list) {
    list->head = NULL;
}

void tambahMateri(PlaylistLinkedList* list, Materi m) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = m;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    ListNode* temp = list->head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void tampilkanPlaylist(PlaylistLinkedList* list) {
    if (list->head == NULL) {
        printf("\n [-] Daftar belajarmu masih kosong.\n");
        return;
    }
    ListNode* temp = list->head;
    int no = 1;
    printf("\n =========================================================================\n");
    printf(" %-4s %-25s %-12s %-10s %s\n",
           "No", "Judul Materi", "Sulit(/100)", "Waktu(m)", "Keterangan");
    printf(" -------------------------------------------------------------------------\n");
    while (temp != NULL) {
        printf(" %-4d %-25s %-12d %-10d %s\n",
               no++, temp->data.nama,
               temp->data.tingkatKesulitan,
               temp->data.durasiMenit,
               temp->data.deskripsi);
        temp = temp->next;
    }
    printf(" =========================================================================\n");
}

// --- Insertion Sort: Durasi Tercepat ---
void insertionSortByDurasi(PlaylistLinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    ListNode* sorted  = NULL;
    ListNode* current = list->head;

    while (current != NULL) {
        ListNode* nextNode = current->next;
        if (sorted == NULL || sorted->data.durasiMenit >= current->data.durasiMenit) {
            current->next = sorted;
            sorted = current;
        } else {
            ListNode* temp = sorted;
            while (temp->next != NULL &&
                   temp->next->data.durasiMenit < current->data.durasiMenit)
                temp = temp->next;
            current->next = temp->next;
            temp->next    = current;
        }
        current = nextNode;
    }
    list->head = sorted;
}

// --- Insertion Sort: Kesulitan Termudah ---
void insertionSortByKesulitan(PlaylistLinkedList* list) {
    if (list->head == NULL || list->head->next == NULL) return;

    ListNode* sorted  = NULL;
    ListNode* current = list->head;

    while (current != NULL) {
        ListNode* nextNode = current->next;
        if (sorted == NULL || sorted->data.tingkatKesulitan >= current->data.tingkatKesulitan) {
            current->next = sorted;
            sorted = current;
        } else {
            ListNode* temp = sorted;
            while (temp->next != NULL &&
                   temp->next->data.tingkatKesulitan < current->data.tingkatKesulitan)
                temp = temp->next;
            current->next = temp->next;
            temp->next    = current;
        }
        current = nextNode;
    }
    list->head = sorted;
}
