// Copyright (c) 2014-2020, The Monero Project
// Copyright (c) 2020, The Xolentum Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#include "crypto/crypto.h"
#include <random>

namespace tools{
  class gamma_picker
  {
  public:
    uint64_t pick();
    gamma_picker(const std::vector<uint64_t> &rct_offsets);
    gamma_picker(const std::vector<uint64_t> &rct_offsets, double shape, double scale);

  private:
    struct gamma_engine
    {
      typedef uint64_t result_type;
      static constexpr result_type min() { return 0; }
      static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
      result_type operator()() { return crypto::rand<result_type>(); }
    } engine;

private:
    std::gamma_distribution<double> gamma;
    const std::vector<uint64_t> &rct_offsets;
    const uint64_t *begin, *end;
    uint64_t num_rct_outputs;
    double average_output_time;
  };
}
