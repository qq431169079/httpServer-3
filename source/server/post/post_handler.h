#ifndef HTTPD_POST_HANDLER_H
#define HTTPD_POST_HANDLER_H
struct post_func {
    char *func_name;
    void *func;
};
typedef struct post_func post_func;



#endif //HTTPD_POST_HANDLER_H
