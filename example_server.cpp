/*
 * Generated by erpcgen 1.13.0 on Tue Jul 23 17:26:28 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "example_server.hpp"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include <new>
#include "erpc_port.h"
#endif
#include "erpc_manually_constructed.hpp"

#if 11300 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;
using namespace erpcShim;

#if ERPC_NESTED_CALLS_DETECTION
bool nestingDetection;
#endif



IO_service::IO_service(IO_interface *_IO_interface)
    : erpc::Service(IO_interface::m_serviceId)
    , m_handler(_IO_interface)
{
}

IO_service::~IO_service()
{
}

// return service interface handler.
IO_interface* IO_service::getHandler(void)
{
    return m_handler;
}

// Call the correct server shim based on method unique ID.
erpc_status_t IO_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory, Transport * transport)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case IO_interface::m_set_ledId:
        {
            erpcStatus = set_led_shim(codec, messageFactory, transport, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for set_led of IO interface.
erpc_status_t IO_service::set_led_shim(Codec * codec, MessageBufferFactory *messageFactory, Transport * transport, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    LEDName whichLed;
    bool onOrOff;
    int32_t _tmp_local_i32;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(_tmp_local_i32);
    whichLed = static_cast<LEDName>(_tmp_local_i32);

    codec->read(onOrOff);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        m_handler->set_led(whichLed, onOrOff);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBufferRef(), transport->reserveHeaderSize());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset(transport->reserveHeaderSize());

        // Build response message.
        codec->startWriteMessage(message_type_t::kReplyMessage, IO_interface::m_serviceId, IO_interface::m_set_ledId, sequence);

        err = codec->getStatus();
    }

    return err;
}
