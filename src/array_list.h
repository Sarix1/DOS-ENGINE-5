#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define FOR_EACH_ARRAY(DO) \
    DO("command", CommandNames) \
    DO("obj_type", ObjectNames) \

extern const char* ArrayNames[];
extern const char** ArrayList[];

#endif/* ARRAY_LIST_H */
