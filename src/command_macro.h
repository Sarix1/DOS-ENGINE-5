#ifndef COMMAND_MACRO_H
#define COMMAND_MACRO_H

// x macro that generates command function enum
#define DECL_COMMAND_ENUM(enum_, str, func) enum_,
#define DECL_COMMAND_STRING(enum_, str, func) str,
#define DECL_COMMAND_FUNC(enum_, str, func) func,
#define DECL_COMMAND_PROTOTYPE(enum_, str, func) \
    int func(StringList_t args);

#endif/* COMMAND_MACRO_H */