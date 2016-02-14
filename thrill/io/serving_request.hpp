/*******************************************************************************
 * thrill/io/serving_request.hpp
 *
 * Copied and modified from STXXL https://github.com/stxxl/stxxl, which is
 * distributed under the Boost Software License, Version 1.0.
 *
 * Part of Project Thrill - http://project-thrill.org
 *
 * Copyright (C) 2002 Roman Dementiev <dementiev@mpi-sb.mpg.de>
 * Copyright (C) 2008 Andreas Beckmann <beckmann@cs.uni-frankfurt.de>
 *
 * All rights reserved. Published under the BSD-2 license in the LICENSE file.
 ******************************************************************************/

#pragma once
#ifndef THRILL_IO_SERVING_REQUEST_HEADER
#define THRILL_IO_SERVING_REQUEST_HEADER

#include <thrill/io/request.hpp>

namespace thrill {
namespace io {

//! \addtogroup reqlayer
//! \{

//! Request which serves an I/O by calling the synchronous routine of the file.
class ServingRequest final : public Request
{
    template <class base_file_type>
    friend class fileperblock_file;
    friend class RequestQueueImplQwQr;
    friend class RequestQueueImpl1Q;

public:
    ServingRequest(
        const CompletionHandler& on_cmpl,
        io::FileBase* f,
        void* buf,
        offset_type off,
        size_type b,
        ReadOrWriteType t);

protected:
    void serve();
};

//! \}

} // namespace io
} // namespace thrill

#endif // !THRILL_IO_SERVING_REQUEST_HEADER

/******************************************************************************/