//--------------------------------------------------------------------------
// Copyright (C) 2014-2019 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------
// http_msg_body_old.cc author Tom Peters <thopeter@cisco.com>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "http_msg_body_old.h"

using namespace HttpEnums;

void HttpMsgBodyOld::update_flow()
{
    // Always more body expected
    session_data->body_octets[source_id] = body_octets;
    update_depth();
}

#ifdef REG_TEST
void HttpMsgBodyOld::print_section(FILE* output)
{
    HttpMsgSection::print_section_title(output, "old-style body");
    fprintf(output, "octets seen %" PRIi64 "\n", body_octets);
    print_body_section(output);
}
#endif

