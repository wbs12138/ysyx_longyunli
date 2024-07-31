#ifndef WATCHPOINT_H
#define WATCHPOINT_H

#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
    int NO;
    struct watchpoint *next;

    // TODO: Add more members if necessary

    bool flag; // use / unuse
    char expr[100];
    int new_value;
    int old_value;

} WP;

static WP wp_pool[NR_WP] __attribute__((unused));
static WP *head __attribute__((unused));
static WP *free_ __attribute__((unused));

void init_wp_pool();
WP* new_wp();
void free_wp(WP *wp);
void sdb_watchpoint_display();
void delete_watchpoint(int no);
void create_watchpoint(char* args);


#endif