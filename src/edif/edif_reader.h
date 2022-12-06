/*
 * MIT License
 *
 * Copyright (c) 2022 Arnaud Caron <arn4ud@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LIBEDIF_EDIF_READER_
#define LIBEDIF_EDIF_READER_

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace edif {

class EdifLexer;
class EdifParser;

class EdifReader {
public:
    EdifReader();
    virtual ~EdifReader() = default;

    void read(const std::filesystem::path&); 

    virtual void visitModule(std::string&& moduleName) {} 

private:
    EdifLexer* lexer_;
    EdifParser* parser_;
};

}  // namespace edif

#endif  /* LIBEDIF_EDIF_READER_ */
