#include "c_example_client.h"

#include <erpc_transport_setup.h>
#include <erpc_mbf_setup.h>
#include <erpc_client_setup.h>

#include <stdio.h>

void example_client(void)
{
    erpc_transport_t transport;
    erpc_mbf_t message_buffer_factory;
    erpc_client_t client_manager;

    /* Init eRPC client infrastructure */
    transport = erpc_transport_tcp_init("127.0.0.1", 5407, false);
    message_buffer_factory = erpc_mbf_dynamic_init();
    client_manager = erpc_client_init(transport, message_buffer_factory);

    /* init eRPC client IO service */
    initIO_client(client_manager);

    // Now we can call the remote function
    char* answer = say_hi("Kirill");
    printf("%s\n", answer);

    /* deinit objects */
    deinitIO_client();
    erpc_client_deinit(client_manager);
    erpc_mbf_dynamic_deinit(message_buffer_factory);
    erpc_transport_tcp_deinit(transport);
}

int main()
{
    example_client();
    return 0;
}
