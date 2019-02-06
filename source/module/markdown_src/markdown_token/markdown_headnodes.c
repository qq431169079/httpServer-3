#include <stdio.h>
#include <stdlib.h>
#include "markdown_headnodes.h"
#include "../markdown_config.h"

void init_head_nodeList (struct head_nodelist *list) {
    if (list->is_init) {
        return;
    }
    for (int i = 0; i < NODE_LEN; ++i) {
        list->nodes[i].level = -1;
        memset(list->nodes[i].head_content, '\0', NODE_LEN);
    };
    list->l = 0;
    list->is_init = true;
}

void nodelist_insert (struct head_nodelist *list, head_node node) {
    if (list->l >= NODE_LEN) {
        printf("TOC异常\n");
        fflush(stdout);
        exit(1);
    }
    list->nodes[list->l++] = node;
}

void nodelist_remove (struct head_nodelist *list) {
    int l = list->l;
    list->is_init = false;
    for (int i = 0; i < l; ++i) {
        list->nodes[i].level = 0;
        memset(list->nodes[i].head_content, '\0', strlen(list->nodes[i].head_content));
    }
}
