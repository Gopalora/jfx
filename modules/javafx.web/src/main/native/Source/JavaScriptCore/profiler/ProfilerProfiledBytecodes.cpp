/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "ProfilerProfiledBytecodes.h"

#include "JSCInlines.h"
#include "ObjectConstructor.h"
#include "ProfilerDumper.h"

namespace JSC { namespace Profiler {

ProfiledBytecodes::ProfiledBytecodes(Bytecodes* bytecodes, CodeBlock* profiledBlock)
    : BytecodeSequence(profiledBlock)
    , m_bytecodes(bytecodes)
{
}

ProfiledBytecodes::~ProfiledBytecodes() = default;

Ref<JSON::Value> ProfiledBytecodes::toJSON(Dumper& dumper) const
{
    auto result = JSON::Object::create();
    result->setDouble(dumper.keys().m_bytecodesID, m_bytecodes->id());
    addSequenceProperties(dumper, result.get());
    return result;
}

} } // namespace JSC::Profiler

