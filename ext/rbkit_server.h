#ifndef RBKIT_TRACER_H
#define RBKIT_TRACER_H

#include "ruby/ruby.h"
#include "ruby/debug.h"
#include <stdio.h>
#include <assert.h>
#include "zmq.h"
#include "msgpack.h"

// Structure is used to store profiling data
typedef struct _rbkit_logger {
  VALUE hooks[3];
  VALUE enabled;
  VALUE sampling_profiler_enabled;
  void *data;
  st_table *object_table;
  st_table *str_table;
  VALUE newobj_trace;
  VALUE freeobj_trace;
  msgpack_sbuffer *sbuf;
  msgpack_packer *msgpacker;
  VALUE self;
} rbkit_logger;

char * tracer_string_recv(void *socket);

#endif
