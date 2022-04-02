#pragma once

#include "defines.h"

enum TextColor
{
    TEXT_COLOR_WHITE,
    TEXT_COLOR_GREEN,
    TEXT_COLOR_YELLOW,
    TEXT_COLOR_RED,
    TEXT_COLOR_LIGHT_RED,
};

struct HTTPConnection
{
    const char *name;
    const uint32_t connectionIdx;
};

struct Request
{
    const char *url;
    const char *method;
    const char *header;
    const uint32_t requestIdx;
};

const HTTPConnection platform_connect_to_server(char *serverName);

const Request platform_send_http_request(const HTTPConnection connection, char *url, char *header, char *method = "POST", char *data = 0);

bool platform_recieve_http_response(const Request request);

bool platform_recieve_http_data(const Request request, char *outBuffer, uint32_t bufferSize);

void platform_log(const char *msg, TextColor color);

char *platform_read_file(char *path, uint32_t *length);

unsigned long platform_write_file(
    const char *path,
    const char *buffer,
    const uint32_t size,
    bool overwrite);