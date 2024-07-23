#include "example_common.h"
#include "c_example_server.h"

#include "erpc_transport_setup.h"
#include "erpc_mbf_setup.h"
#include "erpc_server_setup.h"

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

// Implement the remote function.
char* say_hi(const char* name)
{
    char* str = malloc(4 + strlen(name));
    strcpy(str, "Hi, ");
    strcpy(str + 4, name);
    return str;
}


void example_server(void)
{
    erpc_transport_t transport;
    erpc_mbf_t message_buffer_factory;
    erpc_server_t server;
    erpc_service_t service = create_IO_service();

    /* Init eRPC server infrastructure */
    transport = erpc_transport_tcp_init("127.0.0.1", 5407, true);
    message_buffer_factory = erpc_mbf_dynamic_init();
    server = erpc_server_init(transport, message_buffer_factory);

    /* add custom service implementation to the server */
    erpc_add_service_to_server(server, service);

    // Run the server.
    erpc_server_run(server);

    /* deinit objects */
    destroy_IO_service(service);
    erpc_server_deinit(server);
    erpc_mbf_dynamic_deinit(message_buffer_factory);
    erpc_transport_tcp_deinit(transport);
}

int main()
{
    example_server();
    return 0;
}
