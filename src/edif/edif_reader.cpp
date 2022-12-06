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

#include "edif_reader.h"

#include <fstream>

#include "edif_lexer.h"
#include "edif_parser.h"

namespace edif {

EdifReader::EdifReader()
    : lexer_(new EdifLexer())
    , parser_(new EdifParser(*lexer_, *this)) {}

void EdifReader::read(const std::filesystem::path& p){
    std::ifstream ifs(p);
    if (!ifs) {
        std::cerr << p << ": no such file\n";
    }
    lexer_->switch_streams(&ifs, nullptr);
    parser_->parse();
}

}  // namespace edif
