
#ifndef MANOS_H
#define MANOS_H

#include "ev.h"
#include "eio.h"


typedef struct {
	int offset;
	int length;
	char* bytes;	
} bytebuffer_t;

typedef struct {
	struct ev_loop *loop;
	struct ev_idle eio_idle_watcher;
} manos_data_t;

typedef void (*length_cb) (void *gchandle, size_t length, int error);


manos_data_t *manos_init (struct ev_loop *loop);
void manos_shutdown (manos_data_t *data);


int manos_socket_connect (char *host, int port, int *err);
int manos_socket_listen (char *host, int port, int backlog, int *err);
int manos_socket_accept (int fd, int *err);
int manos_socket_accept_many (int fd, int *fds, int len, int *err);
int manos_socket_receive (int fd, char* data, int len, int *err);
int manos_socket_send (int fd, bytebuffer_t *buffers, int len, int *err);
int manos_socket_close (int fd, int *err);
int manos_socket_send_file (int socket, char *name, int chunked, size_t length, length_cb cb, void *gchandle);

int manos_file_get_length (char *path, length_cb cb, void *gchandle);

#endif

