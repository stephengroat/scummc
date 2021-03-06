/* ScummC
 * Copyright (C) 2009  Alban Bedel
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

/**
 * @file scvm_actor.c
 * @ingroup scvm
 * @brief SCVM actors
 */

#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "scc_fd.h"
#include "scc_util.h"
#include "scc_param.h"
#include "scc_cost.h"
#include "scc_box.h"
#include "scvm_res.h"
#include "scvm_thread.h"
#include "scvm.h"

scvm_object_t* scvm_get_object(scvm_t* vm, unsigned id) {
    if(id >= vm->res[SCVM_RES_OBJECT].num)
        return NULL;
    return vm->res[SCVM_RES_OBJECT].idx[id].data;
}

int scvm_get_object_name(scvm_t* vm, unsigned id, unsigned char** name) {
    if(id < vm->num_actor) {
        *name = vm->actor[id].name;
        return 0;
    }
    if(id >= vm->res[SCVM_RES_OBJECT].num)
        return SCVM_ERR_BAD_OBJECT;
    *name = vm->object_pdata[id].name;
    return 0;
}

int scvm_get_object_position(scvm_t* vm, unsigned id, int* x, int* y) {
    scvm_object_t* obj;
    if(id < vm->num_actor) {
        if(x) *x = vm->actor[id].x;
        if(y) *y = vm->actor[id].y;
        return 0;
    }
    if(id >= vm->res[SCVM_RES_OBJECT].num)
        return SCVM_ERR_BAD_OBJECT;
    if(!(obj = vm->res[SCVM_RES_OBJECT].idx[id].data)) {
        if(x) *x = 0;
        if(y) *y = 0;
        return 1;
    }
    if(x) *x = obj->x;
    if(y) *y = obj->y;
    return 0;
}

scvm_object_t* scvm_get_object_at(scvm_t* vm, int x, int y) {
    unsigned i;
    if(!vm->room) return NULL;
    for(i = 0 ; i < vm->room->num_object ; i++) {
        scvm_object_t* obj = vm->room->object[i];
        if(!obj ||
	   (obj->parent && obj->parent->pdata->state != obj->parent_state))
	    continue;
        if(x >= obj->x && x < obj->x + obj->width &&
           y >= obj->y && y < obj->y + obj->height)
            return obj;
    }
    return NULL;
}

int scvm_get_object_verb_entry_point(scvm_t* vm, unsigned id,
                                     unsigned verb, unsigned *entry) {
    scvm_object_t* obj;
    unsigned i;
    if(!(obj = scvm_get_object(vm,id)) ||
       !(obj->loaded & SCVM_OBJ_OBCD))
        return SCVM_ERR_BAD_OBJECT;
    for(i = 0 ; i < obj->num_verb_entries ; i++)
        if(obj->verb_entries[i*2] == verb ||
           obj->verb_entries[i*2] == 0xFF) {
            *entry = obj->verb_entries[i*2+1];
            return 0;
        }
    *entry = 0;
    return 1;
}

int scvm_start_object_script(scvm_t* vm, unsigned id,
                             unsigned verb, unsigned flags,
                             unsigned* args) {
    int r;
    unsigned entry;
    scvm_object_t* obj;
    if((r = scvm_get_object_verb_entry_point(vm,id,verb,&entry)) < 0)
        return r;
    if(!entry) return SCVM_ERR_BAD_VERB;
    obj = scvm_get_object(vm,id);
    return scvm_start_thread(vm,obj->script,entry,flags,args);
}
