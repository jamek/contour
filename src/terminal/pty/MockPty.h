/**
 * This file is part of the "libterminal" project
 *   Copyright (c) 2019-2020 Christian Parpart <christian@parpart.family>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <terminal/pty/Pty.h>

namespace terminal {

/// Mock-PTY, to be used in unit tests.
class MockPty : public Pty
{
  public:
    explicit MockPty(Size const& windowSize);
    ~MockPty() override;

    int read(char* buf, size_t size) override;
    int write(char const* buf, size_t size) override;
    Size screenSize() const noexcept override;
    void resizeScreen(Size _cells, std::optional<Size> _pixels = std::nullopt) override;

    void prepareChildProcess() override;
    void prepareParentProcess() override;
    void close() override;

  private:
    Size size_;
    std::string inputBuffer_;
    std::string outputBuffer_;
};

} // end namespace
