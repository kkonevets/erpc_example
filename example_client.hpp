/*
 * Generated by erpcgen 1.13.0 on Tue Jul 23 19:34:30 2024.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_example_client_hpp_)
#define _example_client_hpp_

#include "example_interface.hpp"

#include "erpc_client_manager.h"

namespace erpcShim
{

class IO_client: public IO_interface
{
    public:
        IO_client(erpc::ClientManager *manager);

        virtual ~IO_client();

        virtual char * say_hi(const char * name);

    protected:
        erpc::ClientManager *m_clientManager;
};

} // erpcShim


#endif // _example_client_hpp_
